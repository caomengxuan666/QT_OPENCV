//
// Created by Lenovo on 2024/8/12.
//

#ifndef CMX_CV_OBJECT_HPP
#define CMX_CV_OBJECT_HPP

#include <opencv2/opencv.hpp>
#include <stdexcept>

enum required_channels {
    NONE = 0,
    CHANNELS_1 = 1,
    CHANNELS_3 = 3,
    CHANNELS_4 = 4
};

// 定义一个函数来检测图像的通道数
static required_channels check_image_channels(const cv::Mat& mat) {
    int channels = mat.channels();
    if (channels == 1) return CHANNELS_1;
    else if (channels == 3) return CHANNELS_3;
    else if (channels == 4) return CHANNELS_4;
    else return NONE;
}


class CV_OBJECT {
public:
    virtual void setRequireMents()=0;
    CV_OBJECT(cv::Mat inputImg);
    virtual const cv::Mat getProcessedImg()=0;
    virtual ~CV_OBJECT()=default;

protected:
    size_t required_channels;
    cv::Mat inputImg;
};

// 自定义异常类
class UnsupportedChannelsException : public std::exception {
public:
    explicit UnsupportedChannelsException(const char* message) : msg_(message) {}
    [[nodiscard]] const char* what() const noexcept override {
        return msg_;
    }
private:
    const char* msg_="The number of channel is not supported！";
};


#endif//CMX_CV_OBJECT_HPP
