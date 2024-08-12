//
// Created by Lenovo on 2024/8/12.
//

#include "cv_gray.hpp"

void cv_gray::setRequireMents() {
    this->required_channels=CHANNELS_3;
}

//進行灰度化
const cv::Mat cv_gray::getProcessedImg() {
   cv::Mat gray;
   cv::cvtColor(this->inputImg,gray,cv::COLOR_BGR2GRAY);
   return gray;
}