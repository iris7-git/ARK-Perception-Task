import cv2
import numpy as np
import matplotlib.pyplot as plt

# Load image
img = cv2.imread("noisy.jpg")

# METHOD 1: Median + Bilateral //Rejected

median = cv2.medianBlur(img, 5)
bilateral = cv2.bilateralFilter(median, 2, 100, 75)

# METHOD 2: Non-Local Means

nlm = cv2.fastNlMeansDenoisingColored(img, None, 25, 10, 7, 20)


# METHOD 3: Adaptive Deviation Filter

img_float = img.astype(np.float32)
mean = cv2.blur(img_float, (3,3))
diff = np.abs(img_float - mean)
threshold = 70
mask = diff > threshold
img_float[mask] = mean[mask]
adaptive = np.uint8(img_float)


# METHOD 4: Frequency Low-Pass (Color)

def low_pass(channel, radius=65):
    f = np.float32(channel)
    dft = cv2.dft(f, flags=cv2.DFT_COMPLEX_OUTPUT)
    dft_shift = np.fft.fftshift(dft)

    rows, cols = channel.shape
    crow, ccol = rows//2, cols//2

    mask = np.zeros((rows, cols, 2), np.uint8)
    cv2.circle(mask, (ccol, crow), radius, (1,1), -1)

    fshift = dft_shift * mask
    f_ishift = np.fft.ifftshift(fshift)

    img_back = cv2.idft(f_ishift)
    img_back = cv2.magnitude(img_back[:,:,0], img_back[:,:,1])
    img_back = cv2.normalize(img_back, None, 0, 255, cv2.NORM_MINMAX)

    return np.uint8(img_back)

b, g, r = cv2.split(img)
b_f = low_pass(b)
g_f = low_pass(g)
r_f = low_pass(r)
freq = cv2.merge((b_f, g_f, r_f))


# Save Results

cv2.imwrite("output_bilateral.png", bilateral)
cv2.imwrite("output_nlm.png", nlm)
cv2.imwrite("output_adaptive.png", adaptive)
cv2.imwrite("output_frequency.png", freq)


# Display Comparison

titles = ["Original", "Bilateral", "Non-Local Means", "Adaptive", "Frequency LPF"]
images = [img, bilateral, nlm, adaptive, freq]

plt.figure(figsize=(15,8))
for i in range(5):
    plt.subplot(2,3,i+1)
    plt.imshow(cv2.cvtColor(images[i], cv2.COLOR_BGR2RGB))
    plt.title(titles[i])
    plt.axis("off")

plt.tight_layout()
plt.show()