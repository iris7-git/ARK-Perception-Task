import cv2
import numpy as np


MIN_COMPONENT_AREA = 6.5   #6.5 is choosen by trial andS error


img = cv2.imread("iron_man_noisy.jpg", cv2.IMREAD_GRAYSCALE)

if img is None:
    print("Error: Image not found.")
    exit()


#print(np.unique(img)) was used to check threshold
_, binary = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY) #127 is the mid value


# STEP 3: Connected Component Analysis

num_labels, labels, stats, centroids = cv2.connectedComponentsWithStats(
    binary,
    connectivity=8
)

# Create blank output image
cleaned = np.zeros_like(binary)

# Skip label 0 (background)
for i in range(1, num_labels):
    area = stats[i, cv2.CC_STAT_AREA]

    # Keep only sufficiently large components
    if area >= MIN_COMPONENT_AREA:
        cleaned[labels == i] = 255


# STEP 4: Save Output
#cv2.imwrite("iron_man_cleaned.jpg", cleaned)

# STEP 5: Display Comparison
cv2.imshow("Original", img)
cv2.imshow("Cleaned", cleaned)

cv2.waitKey(0)
cv2.destroyAllWindows()

print("Processing complete. Cleaned image saved as 'iron_man_cleaned.jpg'")
