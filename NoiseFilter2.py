import cv2
import numpy as np
import matplotlib.pyplot as plt


# Load image
img = cv2.imread("noisy.jpg")


img_float = img.astype(np.float32)
mean = cv2.blur(img_float, (3,3))
diff = np.abs(img_float - mean)
threshold = 70 #can have a seperate thresshold for each colour but doesn't help.
               #since all colours are almost equal in noise
mask = diff > threshold
img_float[mask] = mean[mask]
adaptive = np.uint8(img_float)


cv2.imshow("Original",img)
cv2.imshow("Adaptive",adaptive)


cv2.waitKey(0)
cv2.destroyAllWindows()


cv2.imwrite("noisy_cleaned.jpg",adaptive)


print("Processing complete. Cleaned image saved as 'noisy_cleaned.jpg'")



