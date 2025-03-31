#include "Checklist.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Checklist w;
    w.show();
    return a.exec();
}
