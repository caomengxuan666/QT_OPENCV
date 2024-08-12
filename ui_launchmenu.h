/********************************************************************************
** Form generated from reading UI file 'launchmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHMENU_H
#define UI_LAUNCHMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_launchMenu
{
public:
    QWidget *centralwidget;
    QToolButton *image;
    QToolButton *video;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *launchMenu)
    {
        if (launchMenu->objectName().isEmpty())
            launchMenu->setObjectName("launchMenu");
        launchMenu->resize(650, 320);
        centralwidget = new QWidget(launchMenu);
        centralwidget->setObjectName("centralwidget");
        image = new QToolButton(centralwidget);
        image->setObjectName("image");
        image->setGeometry(QRect(10, 0, 250, 250));
        video = new QToolButton(centralwidget);
        video->setObjectName("video");
        video->setGeometry(QRect(390, 0, 250, 250));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 270, 70, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, 270, 69, 19));
        launchMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(launchMenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 650, 24));
        launchMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(launchMenu);
        statusbar->setObjectName("statusbar");
        launchMenu->setStatusBar(statusbar);

        retranslateUi(launchMenu);

        QMetaObject::connectSlotsByName(launchMenu);
    } // setupUi

    void retranslateUi(QMainWindow *launchMenu)
    {
        launchMenu->setWindowTitle(QCoreApplication::translate("launchMenu", "launchMenu", nullptr));
        image->setText(QString());
        video->setText(QCoreApplication::translate("launchMenu", "...", nullptr));
        label->setText(QCoreApplication::translate("launchMenu", "\345\233\276\345\203\217\345\244\204\347\220\206", nullptr));
        label_2->setText(QCoreApplication::translate("launchMenu", "\350\247\206\351\242\221\345\244\204\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class launchMenu: public Ui_launchMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHMENU_H
