import cv2
import numpy as np

vid = cv2.VideoCapture("Medial Axis/1.mp4")

fgbg = cv2.createBackgroundSubtractorMOG2(detectShadows=False)

while(1):
    ret, frame = vid.read()
    if not ret: 
        print('Video Ended.')
        break
    fgmask = fgbg.apply(frame)
    # remove weak gray noise
    #_, fgmask = cv2.threshold(fgmask, 200, 255, cv2.THRESH_BINARY)
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(7,7))
    opening = cv2.morphologyEx(fgmask, cv2.MORPH_OPEN, kernel)
    #closing = cv2.morphologyEx(opening, cv2.MORPH_CLOSE, kernel)

    cv2.imshow('frame',opening)
    k = cv2.waitKey(30) & 0xff #for Esc
    if k == 27:
        break


vid.release()
cv2.destroyAllWindows()