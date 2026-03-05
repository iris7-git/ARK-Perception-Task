import cv2
vid = cv2.VideoCapture("Medial Axis/1.mp4")

fgbg = cv2.createBackgroundSubtractorMOG2()

while(1):
    ret, frame = vid.read()
    if not ret: 
        print('Video Ended.')
        break
    fgmask = fgbg.apply(frame)
    cv2.imshow('frame',fgmask)
    k = cv2.waitKey(30) & 0xff #for Esc
    if k == 27:
        break


vid.release()
cv2.destroyAllWindows()