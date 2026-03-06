import cv2
import numpy as np

vid = cv2.VideoCapture("Medial Axis/3.mp4")

fgbg = cv2.createBackgroundSubtractorMOG2(detectShadows=False)

while(1):
    ret, frame = vid.read()
    if not ret: 
        print('Video Ended.')
        break
    fgmask = fgbg.apply(frame)
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(6,6))
    opening = cv2.morphologyEx(fgmask, cv2.MORPH_OPEN, kernel)

    gray = opening

    blur = cv2.GaussianBlur(gray,(3,3),0)

    sobelx = cv2.Sobel(blur, cv2.CV_64F, 1, 0, ksize=3)
    sobely = cv2.Sobel(blur, cv2.CV_64F, 0, 1, ksize=3)

    abs_x = cv2.convertScaleAbs(sobelx)
    abs_y = cv2.convertScaleAbs(sobely)

    edges = cv2.addWeighted(abs_x,0.5,abs_y,0.5,0)
    _, edges = cv2.threshold(edges, 80, 255, cv2.THRESH_BINARY)

    # Manual Hough Transform
    height, width = edges.shape

    diag_len = int(np.sqrt(height*height + width*width))

    rhos = np.arange(-diag_len, diag_len, 1)
    thetas = np.deg2rad(np.arange(-90, 90,4))

    accumulator = np.zeros((len(rhos), len(thetas)), dtype=np.uint64)

    y_idxs, x_idxs = np.nonzero(edges)

    for i in range(len(x_idxs)):
        x = x_idxs[i]
        y = y_idxs[i]

        for t_idx in range(len(thetas)):
            rho = int(x*np.cos(thetas[t_idx]) + y*np.sin(thetas[t_idx]))
            accumulator[rho + diag_len, t_idx] += 1

    # Detect strongest lines
    threshold = 120

    lines = []

    for r in range(accumulator.shape[0]):
        for t in range(accumulator.shape[1]):
            if accumulator[r,t] > threshold:
                lines.append((accumulator[r,t],r,t))

    lines = sorted(lines, reverse=True)

    top_lines = lines[:6]

    # ---- MEDIAL AXIS FROM HOUGH LINES ----

    if len(top_lines) >= 2:

        vote1, r1, t1 = top_lines[0]
        vote2, r2, t2 = top_lines[1]

        rho1 = rhos[r1]
        theta1 = thetas[t1]

        rho2 = rhos[r2]
        theta2 = thetas[t2]

        # average line parameters
        rho_mid = (rho1 + rho2) / 2
        theta_mid = (theta1 + theta2) / 2

        a = np.cos(theta_mid)
        b = np.sin(theta_mid)

        x0 = a * rho_mid
        y0 = b * rho_mid

        x1 = int(x0 + 1000*(-b))
        y1 = int(y0 + 1000*(a))

        x2 = int(x0 - 1000*(-b))
        y2 = int(y0 - 1000*(a))

        cv2.line(frame,(x1,y1),(x2,y2),(0,255,0),3)  # GREEN medial axis

    for vote,r,t in top_lines:

        rho = rhos[r]
        theta = thetas[t]

        a = np.cos(theta)
        b = np.sin(theta)

        x0 = a*rho
        y0 = b*rho

        x1 = int((x0 + 1000*(-b)))
        y1 = int((y0 + 1000*(a)))

        x2 = int((x0 - 1000*(-b)))
        y2 = int((y0 - 1000*(a)))

        cv2.line(frame,(x1,y1),(x2,y2),(0,0,255),2)


    cv2.imshow('frame',frame)
    #cv2.imshow("Edges", edges)
    k = cv2.waitKey(30) & 0xff #for Esc
    if k == 27:
        break


vid.release()
cv2.destroyAllWindows()