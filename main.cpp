#include <iostream>
#include <QApplication>
#include "launchmenu.hpp"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    launchMenu launchMenu;
    launchMenu.show();
    return app.exec();
}
