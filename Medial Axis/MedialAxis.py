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

    #cv2.imshow('frame',opening)
    cv2.imshow("Edges", edges)
    k = cv2.waitKey(30) & 0xff #for Esc
    if k == 27:
        break


vid.release()
cv2.destroyAllWindows()