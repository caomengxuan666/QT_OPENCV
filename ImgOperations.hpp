//
// Created by Lenovo on 2024/8/12.
//

#ifndef CMX_IMGOPERATIONS_HPP
#define CMX_IMGOPERATIONS_HPP

#include "cv_gray.hpp"

class ImgOperations {
public:
    //用模板函数生成一个对象，然后返回一个Mat类
     cv::Mat getProcessedImg(const cv::Mat& img, CV_OBJECT*op){
        return op->getProcessedImg();
    }

};

#endif//CMX_IMGOPERATIONS_HPP
