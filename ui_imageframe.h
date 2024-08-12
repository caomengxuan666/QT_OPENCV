/********************************************************************************
** Form generated from reading UI file 'imageframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEFRAME_H
#define UI_IMAGEFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageFrame
{
public:
    QLabel *rawFrame;
    QLabel *currentFrame;
    QToolBox *toolBox;
    QWidget *filePage;

    void setupUi(QWidget *ImageFrame)
    {
        if (ImageFrame->objectName().isEmpty())
            ImageFrame->setObjectName("ImageFrame");
        ImageFrame->resize(1920, 1080);
        rawFrame = new QLabel(ImageFrame);
        rawFrame->setObjectName("rawFrame");
        rawFrame->setGeometry(QRect(0, 0, 700, 700));
        currentFrame = new QLabel(ImageFrame);
        currentFrame->setObjectName("currentFrame");
        currentFrame->setGeometry(QRect(800, 0, 700, 700));
        toolBox = new QToolBox(ImageFrame);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(1602, 260, 221, 191));
        filePage = new QWidget();
        filePage->setObjectName("filePage");
        filePage->setGeometry(QRect(0, 0, 221, 157));
        toolBox->addItem(filePage, QString::fromUtf8("\345\267\245\345\205\267\346\240\217"));

        retranslateUi(ImageFrame);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ImageFrame);
    } // setupUi

    void retranslateUi(QWidget *ImageFrame)
    {
        ImageFrame->setWindowTitle(QCoreApplication::translate("ImageFrame", "ImageFrame", nullptr));
        rawFrame->setText(QCoreApplication::translate("ImageFrame", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">\345\216\237\345\247\213\345\233\276\345\203\217</span></p></body></html>", nullptr));
        currentFrame->setText(QCoreApplication::translate("ImageFrame", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">\345\275\223\345\211\215\345\233\276\345\203\217</span></p></body></html>", nullptr));
        toolBox->setItemText(toolBox->indexOf(filePage), QCoreApplication::translate("ImageFrame", "\345\267\245\345\205\267\346\240\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageFrame: public Ui_ImageFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEFRAME_H
