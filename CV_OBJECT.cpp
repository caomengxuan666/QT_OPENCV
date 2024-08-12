//
// Created by Lenovo on 2024/8/12.
//

#include "CV_OBJECT.hpp"

CV_OBJECT::CV_OBJECT(cv::Mat inputImg) {
    try {
        auto result = check_image_channels(inputImg);
        if (result == required_channels::NONE) {
            throw UnsupportedChannelsException("Unsupported number of channels.");
        }
        this->inputImg = inputImg;
        // 立即对图像进行灰度化处理
    } catch (const UnsupportedChannelsException& e) {
        // 处理自定义异常
        std::cerr << "UnsupportedChannelsException caught in CV_OBJECT constructor: " << e.what() << std::endl;
        throw; // 重新抛出异常
    } catch (const std::exception& e) {
        // 处理其他异常
        std::cerr << "Exception caught in CV_OBJECT constructor: " << e.what() << std::endl;
        throw; // 重新抛出异常
    }
}
