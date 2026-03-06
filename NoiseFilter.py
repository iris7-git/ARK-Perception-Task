import cv2
import numpy as np


MIN_COMPONENT_AREA = 6.5   #6.5 is choosen by trial and error


img = cv2.imread("iron_man_noisy.jpg", cv2.IMREAD_GRAYSCALE)

if img is None:
    print("Error: Image not found.")
    exit()


# print(np.unique(img)) was used to check threshold
_, binary = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY) #127 is the mid value


num_labels, labels, stats, centroids = cv2.connectedComponentsWithStats(
    binary,
    connectivity=8
)

cleaned = np.zeros_like(binary)

# label 0 (background)
for i in range(1, num_labels):
    area = stats[i, cv2.CC_STAT_AREA]

    if area >= MIN_COMPONENT_AREA:
        cleaned[labels == i] = 255


cv2.imwrite("iron_man_cleaned.jpg", cleaned)


cv2.imshow("Original", img)
cv2.imshow("Cleaned", cleaned)

cv2.waitKey(0)
cv2.destroyAllWindows()

print("Processing complete. Cleaned image saved as 'iron_man_cleaned.jpg'")
