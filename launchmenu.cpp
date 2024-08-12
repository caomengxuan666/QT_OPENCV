#include "launchmenu.hpp"
#include "ui_launchMenu.h"

launchMenu::launchMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::launchMenu) {
    ui->setupUi(this);

    // 设置窗口为不可缩放
    setFixedSize(width(), height());

    ui->image->setText("图像处理");
    ui->image->setIcon(QIcon(":/qrc/image.jpg"));
    ui->image->setIconSize(QSize(250, 250));

    ui->video->setText("视频处理");
    ui->video->setIcon(QIcon(":/qrc/video.jpg"));
    ui->video->setIconSize(QSize(250, 250));

    // 设置样式表以调整间距
    ui->image->setStyleSheet("QToolButton { padding-top: 10px; }");
    ui->video->setStyleSheet("QToolButton { padding-top: 10px; }");

    // 调整控件尺寸
    ui->image->setMinimumSize(QSize(250, 300));
    ui->video->setMinimumSize(QSize(250, 300));
}

launchMenu::~launchMenu() {
    delete ui;
}

void launchMenu::on_image_clicked() {
    //构造一个下拉式的QSTRINGLIST MODEL
    QStringListModel *model = new QStringListModel(this);
    //提供选项，选择分辨率大小，后续以QSIZE的形式加载新窗口
    QStringList list;
    int WindowsWidth = 0;
    int WindowsHeight = 0;

    list <<"请选择初始窗口的分辨率大小"<<"1280x720" << "1920x1080" << "3840x2160";
    model->setStringList(list);
    QComboBox *comboBox = new QComboBox;
    comboBox->setWindowTitle("选择窗口的分辨率大小");
    comboBox->setModel(model);
    comboBox->setCurrentIndex(0);
    comboBox->setStyleSheet("QComboBox { border: 1px solid gray; }");
    comboBox->setMinimumSize(QSize(250, 50));
    comboBox->setMaximumSize(QSize(250, 50));
    comboBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    //展示MODEL
    comboBox->show();
    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [&](int index)mutable {
        switch (index) {
            case 0:{
                break;
        }
        case 1:{
            WindowsHeight=720;
            WindowsWidth=1280;
            break;
        }
            case 2:
                WindowsHeight=1080;
                WindowsWidth=1920;
                break;
            case 3:
                WindowsHeight=2160;
                WindowsWidth=3840;
                break;
            default:
                break;
        }
    });
    //如果没有选则，那么进行阻塞、
    while (comboBox->currentIndex() == 0) {
        QCoreApplication::processEvents();
    }
    comboBox->close();
    if (m_imageFrame) {
        m_imageFrame->show();
        return;
    } else {
        auto *imageFrame = new ImageFrame;
        //将指针控制权移交给unique_ptr
        m_imageFrame.reset(imageFrame);
        imageFrame->setUpSize(WindowsWidth,WindowsHeight);
        imageFrame->show();
    }
    this->close();

}
void launchMenu::on_video_clicked() {
}
