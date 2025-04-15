#include "Checklist.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{

    /// There is some funky stuff (basically "circling" classes (check .h of ButtonHandler and Checklist,
    /// which kinda just call themselves) which (most likely) could've been solved using smart pointers.
    /// I understand, however, I've wanted to do this with ""normal"" pointers. If you see this and there
    /// ARE smart pointers used, this message is forgotten here (oops). If not, do know that they will be
    /// used eventually. It is on my *checklist*. Hah!

    QApplication a(argc, argv);
    Checklist w;
    w.show();
    return a.exec();
}
