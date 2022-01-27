import cv2
import imutils

green_l = (29, 86, 6)
green_u = (64, 255, 255)

def ball_det(img):

    blur = cv2.GaussianBlur(img, (7, 7), 0)
    hsv = cv2.cvtColor(blur, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(hsv, green_l, green_u)
    cv2.erode(mask, None, iterations=2)
    cv2.dilate(mask, None, iterations=2)

    cnt, hier = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnt = imutils.grab_contours(cnt)
    center = None

    if len(cnt) > 0:
        c = max(cnt, key=cv2.contourArea)
        ((x, y), radius) = cv2.minEnclosingCircle(c)
        center = (int(x), int(y))

    return center
    