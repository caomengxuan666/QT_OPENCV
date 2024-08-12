//
// Created by Lenovo on 2024/8/12.
//

#ifndef CMX_QIMAGE2MAT_HPP
#define CMX_QIMAGE2MAT_HPP

#include <QImage>
#include <opencv2/opencv.hpp>

static cv::Mat QImageTocvMat(const QImage &image) {
    cv::Mat mat;
    switch (image.format()) {
        case QImage::Format_Grayscale8://灰度图，每个像素点1个字节（8位）
        case QImage::Format_Indexed8:  //Mat构造：行数，列数，存储结构，数据，step每行多少字节
            mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void *) image.constBits(), image.bytesPerLine());
            break;
        case QImage::Format_ARGB32:
        case QImage::Format_RGB32:
        case QImage::Format_ARGB32_Premultiplied:
            mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void *) image.constBits(), image.bytesPerLine());
            break;
        case QImage::Format_RGB888://RR,GG,BB字节顺序存储
            mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void *) image.constBits(), image.bytesPerLine());
            cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);//opencv需要转为BGR的字节顺序
            break;
    }
    return mat;
}

static void convertRGBAtoRGB(const cv::Mat &rgbaImage, cv::Mat &rgbImage) {
    if (rgbaImage.channels() == 4) {
        // Convert from RGBA to RGB
        cv::cvtColor(rgbaImage, rgbImage, cv::COLOR_RGBA2RGB);
    } else {
        // If the image is not RGBA, just copy it
        rgbImage = rgbaImage.clone();
    }
}

static QImage cvMatToQImage(const cv::Mat &mat) {
    // 处理灰度图像
    if (mat.type() == CV_8UC1) {
        // CV_8UC1 表示单通道8位无符号图像
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
    }

    // 处理RGB图像
    if (mat.type() == CV_8UC3) {
        // CV_8UC3 表示三通道8位无符号图像
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888).rgbSwapped();
    }

    // 处理RGBA图像
    if (mat.type() == CV_8UC4) {
        // CV_8UC4 表示四通道8位无符号图像
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGBA8888);
    }

    // 如果图像类型不受支持，则返回空QImage
    qWarning() << "Unsupported cv::Mat format";
    return QImage();
}

#endif//CMX_QIMAGE2MAT_HPP
