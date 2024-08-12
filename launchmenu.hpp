//
// Created by Lenovo on 2024/8/11.
//

#ifndef CMX_LAUNCHMENU_HPP
#define CMX_LAUNCHMENU_HPP

#include "imageframe.hpp"
#include <QMainWindow>
#include <QMessageBox>
#include <QStringListModel>
#include <memory>
#include <QComboBox>


QT_BEGIN_NAMESPACE
namespace Ui {
    class launchMenu;
}
QT_END_NAMESPACE

class launchMenu : public QMainWindow {
    Q_OBJECT

public:
    explicit launchMenu(QWidget *parent = nullptr);
    ~launchMenu() override;

private slots:
    void on_image_clicked();
    void on_video_clicked();

private:
    Ui::launchMenu *ui;
    std::unique_ptr<ImageFrame> m_imageFrame;
};


#endif//CMX_LAUNCHMENU_HPP
