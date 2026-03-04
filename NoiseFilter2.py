import cv2
import numpy as np

# Load image (color)
img = cv2.imread("noisy.jpg")

# Step 1: Median filter
median = cv2.medianBlur(img, 5)

# Step 2: Bilateral filter
cleaned = cv2.bilateralFilter(median, d=2, sigmaColor=100, sigmaSpace=75)


cv2.imshow("Original",img)
cv2.imshow("scenary_cleaned", cleaned)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("noisy_cleaned.jpg",cleaned)
print("Processing complete. Cleaned image saved as 'noisy_cleaned.jpg'")

