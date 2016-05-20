#include "../../src/header/mainwindow.h"
#include <QApplication>

/**
 * @brief main function of the Qt Application
 * @param argc [IN] number of arguments
 * @param argv [IN] list of arguments
 * @return exit code of application, 0 if no error
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
