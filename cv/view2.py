from cv2 import cv2 as cv
import numpy as np
import math
from PIL import Image
import sys
import os
import time
import random
import tensorflow as tf


template = ['0','1','2','3','4','5','6','7','8','9',
            'A','B','C','D','E','F','G','H','J','K','M','N','P','Q','R','S','T','U','V','W','X','Y','Z','L',
            '陕','宁','鄂','藏','蒙','京','甘','川','赣','贵','桂','沪','黑','吉','冀','津','晋','辽','鲁','闽',
            '青','琼','苏','皖','湘','新','渝','豫','粤','云','浙']

def cv_show(name,img):
    cv.imshow(name,img)
    cv.waitKey()
    cv.destroyAllWindows()


#读取文件夹
def read_directory(directory_name):
    referImg_list = []
    for filename in os.listdir(directory_name):
        referImg_list.append(directory_name + "/" + filename)

    return referImg_list

'''
#垂直定位
def ver_locate(image):
    h, w = image.shape[:2]
    # 定义搜索窗口的长度和宽度
    window_h = h
    window_w = h * 6  # 因为我国车牌的标准尺寸为440mm*140mm 所以根据已有的高度，预估车牌区域的宽度
    result = False
    ver_start = 0
    ver_end = 0
    candidate_list = []
    while len(candidate_list) != 1:
        h, w = image.shape[:2]
        for i in range(0, w - window_w, 3):
            result = isvalid(image, i, i + window_w)
            if result is False:
                continue
            ver_start = i
            ver_end = i + window_w
            candidate_list.append((ver_start, ver_end))
            result = False

        print(len(candidate_list))
        if len(candidate_list) == 0:
            image = image[0 + 1:h - 1, 0:w]
        if len(candidate_list) > 1:
            window_w = window_w - 3
            candidate_list = []  # 重置候选区域
    return ver_start, ver_end

#水平定位
def hor_locate(image):
    jump_list = []
    flag = False
    for x in range(h):
        jump = 0
        start = image[x][0]
        for y in range(w):
            if abs(int(image[x][y]) - start) > 250:
                jump += 1
                start = image[x][y]
        jump_list.append(jump)
    jump_list.reverse()
    flag1 = False
    flag2 = False
    area = []
    license_hor_start = 0
    license_hor_end = 0
    for i in range(len(jump_list)):
        if flag1 is False and jump_list[i] >= 14:
            license_hor_start = i
            flag1 = True
        if flag1 is True and jump_list[i] < 14:
            license_hor_end = i - 1
            flag1 = False
        if license_hor_end - license_hor_start > 20:
            flag2 = True
            result_start = license_hor_start
            result_end = license_hor_end
        if flag2 is False:
            continue
        break
    # print(jump_list[result_start: result_end])
    return result_start, result_end
'''
#数字模板匹配
def template2_making():
    c_words = []
    for i in range(0,33):
        c_word = read_directory('./refer1/chars2/' + template[i])
        c_words.append(c_word)
    #循环的从文件中读取图片
    for j in range(3,8):
        img = cv.imread("./char/"+ str(j) + '.png')
        # 高斯滤波
        orgimg = cv.GaussianBlur(img, (3, 3), 0)
        # 灰度处理
        gray_orgimg = cv.cvtColor(orgimg, cv.COLOR_RGB2GRAY)
        # 阈值处理
        ret, orgimg = cv.threshold(gray_orgimg, 0, 255, cv.THRESH_OTSU)
        #模板匹配
        best_score = []
        for c_word in c_words:
            score = []
            for word in c_word:
                #图片类型转换
                template_img = cv.imdecode(np.fromfile(word,dtype=np.uint8),1)
                template_img =cv.cvtColor(template_img,cv.COLOR_RGB2GRAY)
                ret,template_img = cv.threshold(template_img,0,255,cv.THRESH_OTSU)
                height,width = template_img.shape
                image = img.copy()
                image1 = cv.resize(orgimg,(width,height))
                result = cv.matchTemplate(image1,template_img,cv.TM_CCOEFF)
                score.append(result[0][0])
            best_score.append(max(score))

        num2 = best_score.index(max(best_score))
        print(template[0 + num2])






#英文模板匹配
def template1_making():
    c_words = []
    for i in range(10,33):
        c_word = read_directory('./refer1/chars2/' + template[i])
        c_words.append(c_word)
    #读取文件
    img = cv.imread("./char/2.png")
    # 高斯滤波
    orgimg = cv.GaussianBlur(img, (3, 3), 0)
    # 灰度处理
    gray_orgimg = cv.cvtColor(orgimg, cv.COLOR_RGB2GRAY)
    # 阈值处理
    ret, orgimg = cv.threshold(gray_orgimg, 0, 255, cv.THRESH_OTSU)
    #模板匹配
    best_score = []
    for c_word in c_words:
        score = []
        for word in c_word:
            #图片类型转换
            template_img = cv.imdecode(np.fromfile(word,dtype=np.uint8),1)
            template_img =cv.cvtColor(template_img,cv.COLOR_RGB2GRAY)
            ret,template_img = cv.threshold(template_img,0,255,cv.THRESH_OTSU)
            height,width = template_img.shape
            image = img.copy()
            image1 = cv.resize(orgimg,(width,height))
            result = cv.matchTemplate(image1,template_img,cv.TM_CCOEFF)
            score.append(result[0][0])
        best_score.append(max(score))

    num1 = best_score.index(max(best_score))
    print(template[10 + num1])


def template_making():
    #匹配中文
    c_words = []
    for i in range(34,64):
        c_word = read_directory('./refer1/charsChinese/' + template[i])
        c_words.append(c_word)
    #读取文件
    img = cv.imread("./char/1.png")
    #高斯滤波
    orgimg = cv.GaussianBlur(img,(3,3),0)
    #灰度处理
    gray_orgimg = cv.cvtColor(orgimg,cv.COLOR_RGB2GRAY)
    #阈值处理
    ret ,orgimg= cv.threshold(gray_orgimg,0,255,cv.THRESH_OTSU)
    #模板匹配
    best_score = []
    for c_word in c_words:
        score = []
        for word in c_word:
            #图片类型转换
            template_img = cv.imdecode(np.fromfile(word,dtype=np.uint8),1)
            template_img =cv.cvtColor(template_img,cv.COLOR_RGB2GRAY)
            ret,template_img = cv.threshold(template_img,0,255,cv.THRESH_OTSU)
            height,width = template_img.shape
            image = img.copy()
            image1 = cv.resize(orgimg,(width,height))
            result = cv.matchTemplate(image1,template_img,cv.TM_CCOEFF)
            score.append(result[0][0])
        best_score.append(max(score))

    num = best_score.index(max(best_score))
    print(template[34+num])

def char_making(img):
    # 字符提取
    orgimg = cv.GaussianBlur(img, (3, 3), 0)
    # 灰度处理
    gray_img = cv.cvtColor(orgimg, cv.COLOR_RGB2GRAY)
    # 自适应的阈值处理
    ret, orgimg = cv.threshold(gray_img, 0, 255, cv.THRESH_OTSU)
    # 计算二值图像黑白点个数
    area_white = 0
    area_black = 0

    height, weight = orgimg.shape
    print(orgimg.shape)

    for i in range(height):
        for j in range(weight):
            if orgimg[i, j] == 255:
                area_white += 1
            else:
                area_black += 1

    if area_white > area_black:
        rect, orgimg = cv.threshold(gray_img, 0, 255, cv.THRESH_OTSU | cv.THRESH_BINARY_IN)
    # 闭运算
    kernel = cv.getStructuringElement(cv.MORPH_RECT, (2, 2))
    orgimg = cv.dilate(orgimg, kernel)
    # 轮廓检测
    contours, hierarchy = cv.findContours(orgimg, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    # 轮廓绘制
    orgimg1 = rawImage2.copy()
    cv.drawContours(orgimg1, contours, -1, (0, 255, 0), 5)
    #筛选字符
    words = []
    for item in contours:
        word = []
        rect = cv.boundingRect(item)
        x = rect[0]
        y = rect[1]
        weight = rect[2]
        height = rect[3]
        word.append(x)
        word.append(y)
        word.append(weight)
        word.append(height)
        words.append(word)

    words = sorted(words,key = lambda s:s[0],reverse=False)
    print(words)
    i = 0
    for word in words:
        if(word[3] > (word[2] * 1.8)) and (word[3] < (word[2] * 2.3)):
            i = i+1
            orgimg = rawImage2[word[1]:word[1] + word[3],word[0]:word[0] + word[2]]
            cv.imwrite('./char/'+str(i)+'.png', orgimg)

    #读取文件夹下的所有模板
    c_img1 = cv.GaussianBlur(img,(3,3),0)


def car_making(img):
    #高斯去噪
    orgimg = cv.GaussianBlur(img,(3,3),0)
    #灰度处理
    gray_img = cv.cvtColor(orgimg,cv.COLOR_RGB2GRAY)
    #sobel边缘检测
    sobel_x = cv.Sobel(gray_img,cv.CV_16S,1,0)
    absx = cv.convertScaleAbs(sobel_x)
    orgimg = absx
    #自适应的阈值处理
    ret,orgimg = cv.threshold(orgimg,0,255,cv.THRESH_OTSU)
    #闭运算
    kernelX = cv.getStructuringElement(cv.MORPH_RECT,(17,5))
    print(kernelX)
    orgimg = cv.morphologyEx(orgimg,cv.MORPH_CLOSE,kernelX,iterations= 3)
    #中值滤波
    #轮廓检测
    contours,hierarchy = cv.findContours(orgimg,cv.RETR_EXTERNAL,cv.CHAIN_APPROX_SIMPLE)
    #绘制轮廓
    orgimg1 = rawImage.copy()
    cv.drawContours(orgimg1,contours,-1,(0,255,0),5)
    #筛选车牌
    for item in contours:
        rect = cv.boundingRect(item)
        x = rect[0]
        y = rect[1]
        weight = rect[2]
        height = rect[3]
        if (weight > (height * 3)) and (weight < (height * 4)):
            orgimg = rawImage[y:y + height,x:x +weight]
    cv_show("ORG",orgimg)
    cv.imwrite("./car_nub/car_lic.jpg",orgimg)


if __name__ == '__main__':
    #车牌提取
    rawImage = cv.imread("./init_pic/car.jpg")
    car_making(rawImage)
    #字符提取
    rawImage2 = cv.imread("./car_nub/car_lic.jpg")
    char_making(rawImage2)
    #模板匹配
    template_making()
    #英文模板匹配
    template1_making()
    #数字匹配
    template2_making()
