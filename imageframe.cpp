//
// Created by Lenovo on 2024/8/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ImageFrame.h" resolved

#include "imageframe.hpp"
#include "ui_ImageFrame.h"

#include "iostream"
ImageFrame::ImageFrame(QWidget *parent) : QWidget(parent), ui(new Ui::ImageFrame),imgStack(new ImgStack()) {
    ui->setupUi(this);
    addWidget();
    setUpSheet();

    //增加状态栏，显示图像大小
    auto statusBar = new QStatusBar(this);
    //statusBar->showMessage("图像大小：" + QString::number(ui->rawFrame->width()) + "x" + QString::number(ui->rawFrame->height()));

    // 创建一个垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *frameLayout = new QHBoxLayout(this);

    // 添加控件到布局中
    frameLayout->addWidget(ui->rawFrame);
    frameLayout->addWidget(ui->currentFrame);
    frameLayout->addWidget(ui->toolBox);


    // 设置控件的扩展策略
    ui->rawFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->currentFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->toolBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->rawFrame->setScaledContents(true);
    // 设置stretch因子

    frameLayout->setStretchFactor(ui->rawFrame, 3);
    frameLayout->setStretchFactor(ui->currentFrame, 3);
    frameLayout->setStretchFactor(ui->toolBox, 1);

    // 设置窗口的布局
    mainLayout->addLayout(frameLayout);
    mainLayout->addWidget(statusBar);
    setLayout(mainLayout);
}

ImageFrame::~ImageFrame() {
    delete ui;
}

void ImageFrame::setUpSize(int width, int height) {
    this->resize(width, height);
}

void ImageFrame::setUpSheet() {

    ui->rawFrame->setStyleSheet(
            "background-color: rgb(0, 0, 0);"
            "border: 1px solid rgb(255, 255, 255);"
            "border-radius: 5px;"
            "padding: 5px;"
            "margin: 5px;"
            "color: rgb(255, 255, 255);"
            "font: 12pt \"Microsoft YaHei UI\";"
            "text-align: center;"
            "vertical-align: middle;"
            "background-color: rgb(0, 0, 0);"
            "border: 1px solid rgb(255, 255, 255);");


    ui->currentFrame->setStyleSheet(
            "background-color: rgb(0, 0, 0);"
            "border: 1px solid rgb(255, 255, 255);"
            "border-radius: 5px;"
            "padding: 5px;"
            "margin: 5px;"
            "color: rgb(255, 255, 255);"
            "font: 12pt \"Microsoft YaHei UI\";"
            "text-align: center;"
            "vertical-align: middle;"
            "background-color: rgb(0, 0, 0);"
            "border: 1px solid rgb(255, 255, 255);");

}

void ImageFrame::addWidget() {
    //给toolBox内部加一个按钮用来打开文件
    auto toolBoxWidget= new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(toolBoxWidget);

QPushButton *openButton = new QPushButton("选择图像文件", this);
connect(openButton, &QPushButton::clicked, [=]() {
    // 修改文件对话框来选择所有图像格式
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp *.gif *.jpeg *.tif *.tiff)"));

    if (!fileName.isEmpty()) {
        //清空栈
        imgStack->clear();
        // 加载图像文件
        QImage qImage=QImage(fileName);
        cv::Mat image = QImageTocvMat(qImage);
        // Convert the image if it is RGBA

        if (image.type() == CV_8UC4) {
            cv::Mat rgbImage;
            convertRGBAtoRGB(image, rgbImage);
            displayImg(rgbImage);
        } else {
            displayImg(image);
        }
    }
});

    QPushButton *saveButton = new QPushButton("保存图像文件", this);
    connect(saveButton, &QPushButton::clicked, [=]() {
        QString fileName = QFileDialog::getSaveFileName();
    });
    layout->addWidget(openButton);
    layout->addWidget(saveButton);

    toolBoxWidget->setLayout(layout);
    ui->toolBox->addItem(toolBoxWidget, "图像文件");
}


void ImageFrame::displayImg(const cv::Mat &img) {
    //转换成qImage
    QImage qImage = cvMatToQImage(img);

    setPixmap(QPixmap::fromImage(qImage));
}

void ImageFrame::setPixmap(const QPixmap &pixmap) {
    this->pixmap = pixmap;
    update();
}

void ImageFrame::update() {
    ui->rawFrame->setPixmap(pixmap);
    //convert pixmap to QImage
    QImage image = pixmap.toImage();
    auto mat=QImageTocvMat(image);
    imgStack->addToStack(mat);
}
