import cv2
import numpy as np
from matplotlib import pyplot as plt


def readImg(filename):
    """"
    Color image loaded by OpenCV is in BGR mode, but Matplotlib displays in RGB mode.
    cv2.imread(path, style)
        1 - cv2.IMREAD_COLOR
        0 - cv2.IMREAD_GRAYSCALE
        -1 - cv2.IMREAD_UNCHANGED
    """
    img = cv2.imread(filename, 1)

    print img[100, 100] # the simple accessing each and every pixel values and modifying it will be very slow and it is discouraged
    print img.item(100, 100, 1) # img.item - get the access to B\G\R, img.itemset - modify the value

    crop = img[100:200, 100:200]

    cv2.imshow('image', crop)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    # cv2.destroyWindow('image')

    # cv2.imwrite('tmp.png', img)

    print img.shape, crop.shape
    print img.size, crop.size
    # Note: img.dtype is very important while debugging because a large number of errors in OpenCV-Python code is caused by invalid datatype
    print img.dtype, crop.dtype

    # Warning: cv2.split() is a costly operation (in terms of time). So do it only if you need it. Otherwise go for Numpy indexing.
    b,g,r = cv2.split(img)
    tmp =  cv2.merge((b,g,r))
    tmp[:,:,2] = 0 # set all the red pixels to zero.
    # print tmp[:,:,2]
    return img

img1 = readImg('pic/ArtRoom.png')          # queryImage
img2 = readImg('pic/ArtRoom_0.75_cr.png') # trainImage

# Initiate SIFT detector
sift = cv2.xfeatures2d.SIFT_create()

# find the keypoints and descriptors with SIFT
kp1, des1 = sift.detectAndCompute(img1,None)
kp2, des2 = sift.detectAndCompute(img2,None)
print len(kp1)
print len(kp2)

# BFMatcher with default params
bf = cv2.BFMatcher()

# match(queryImage, trainImage)
matches = bf.match(des1,des2)


# def nothing(x):
#     pass
#
# # Create a black image, a window
# img = np.zeros((300,512,3), np.uint8)
# cv2.namedWindow('image')
#
# # create trackbars for color change
# cv2.createTrackbar('R','image',0,255,nothing)
# cv2.createTrackbar('G','image',0,255,nothing)
# cv2.createTrackbar('B','image',0,255,nothing)
#
# # create switch for ON/OFF functionality
# switch = '0 : OFF \n1 : ON'
# cv2.createTrackbar(switch, 'image',0,1,nothing)
#
# while(1):
#     cv2.imshow('image',img)
#     k = cv2.waitKey(1) & 0xFF
#     if k == 27:
#         break
#
#     # get current positions of four trackbars
#     r = cv2.getTrackbarPos('R','image')
#     g = cv2.getTrackbarPos('G','image')
#     b = cv2.getTrackbarPos('B','image')
#     s = cv2.getTrackbarPos(switch,'image')
#
#     if s == 0:
#         img[:] = 0
#     else:
#         img[:] = [b,g,r]
#
# cv2.destroyAllWindows()

# for m in matches:
#     print m.distance
#     print m.queryIdx, '-', kp1[m.queryIdx].pt
#     print m.trainIdx, '-', kp2[m.trainIdx].pt
#     print m.imgIdx
#     print '   -   '

# print dir(kp1[0])
# print kp1[0].size
# print kp1[0].angle
# print kp1[0].class_id
# print kp1[0].octave
# print kp1[0].overlap
# print kp1[0].pt
# print kp1[0].response

# cv2.drawMatchesKnn expects list of lists as matches.
# img3 = cv2.drawMatchesKnn(img1,kp1,img2,kp2,matches,None,flags=2)
#
# plt.imshow(img3),plt.show()

# 4800
# 3971

# 4756
# 3918

# 4800
# 3971

# 4756
# 3918