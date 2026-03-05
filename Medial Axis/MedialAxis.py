import cv2
vid = cv2.VideoCapture("1.mp4")

count, success = 0, True
while success:
    success, image = vid.read() # Read frame
    if success: 
        cv2.imwrite(f"frame{count}.jpg", image) # Save frame
        count += 1

vid.release()