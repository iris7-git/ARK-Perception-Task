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
    kernel = np.ones((5,5),np.uint8)
    erosion = cv2.erode(fgmask,kernel,iterations = 1)


    cv2.imshow('frame',erosion)
    k = cv2.waitKey(30) & 0xff #for Esc
    if k == 27:
        break


vid.release()
cv2.destroyAllWindows()