//
// Created by Lenovo on 2024/8/12.
//

#ifndef CMX_CV_GRAY_HPP
#define CMX_CV_GRAY_HPP

#include "CV_OBJECT.hpp"
#include <opencv2/opencv.hpp>

class cv_gray : public CV_OBJECT {
public:
    //调用父类构造
    cv_gray(const cv::Mat &img) : CV_OBJECT(img) {}
    ~cv_gray() = default;
    void setRequireMents() override;
    const cv::Mat getProcessedImg() override;
};


#endif//CMX_CV_GRAY_HPP
