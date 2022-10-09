import cv2
base_path = 'people.jpg'#待检测图像的文件路径
img=cv2.imread(base_path)
hog = cv2.HOGDescriptor()  #初始化HOG描述子
# 设置支持向量机，其为一个预先训练好的行人检测器
hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())
#检测行人
rects, wei = hog.detectMultiScale(img, winStride=(4, 4), padding=(8, 8), scale=1.05) 
for (x, y, w, h) in rects: 
    cv2.rectangle(img, (x, y), (x + w, y + h), (0, 0, 255), 2) #将检测结果在图像中圈出来
cv2.imshow("people detect", img) #显示图像
cv2.waitKey(0)
