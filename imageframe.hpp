//
// Created by Lenovo on 2024/8/11.
//

#ifndef CMX_IMAGEFRAME_HPP
#define CMX_IMAGEFRAME_HPP

#include <QWidget>
#include <QFile>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolBox>
#include <QPushButton>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <QStatusBar>
#include "ImgStack.hpp"
#include "QImage2Mat.hpp"
#include "ImgOperations.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
    class ImageFrame;
}
QT_END_NAMESPACE

class ImageFrame : public QWidget,Observer {
    Q_OBJECT

public:
    explicit ImageFrame(QWidget *parent = nullptr);
    ~ImageFrame() override;

    void setUpSize(int width, int height);
    void setUpSheet();
    void addWidget();
    void displayImg(const cv::Mat &img);

    void setPixmap(const QPixmap&pixmap);

    void update() override;

    void setImgOperations();
private:
    Ui::ImageFrame *ui;
    ImgStack *imgStack;
    Observer *observer;
    QPixmap pixmap;
    ImgOperations* imgOperations;
};


#endif//CMX_IMAGEFRAME_HPP
