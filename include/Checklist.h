#pragma once

#include <QtWidgets/QMainWindow>
#include <QResizeEvent>
#include "ui_Checklist.h"
// #include "ButtonHandler.h"
#include <vector>
#include <qpushbutton.h>

class AddWindow;
class ButtonHandler;

class Checklist : public QMainWindow
{
    Q_OBJECT

public:
    Checklist(QWidget* parent = nullptr);
    ~Checklist();

    void setAddWindow(AddWindow* add);

private:
    Ui::Checklist ui;
    ButtonHandler* buttonHandler;
    AddWindow* addW;

    QSize baseSize;
    std::vector<QPushButton*> buttonList;


    void resizeEvent(QResizeEvent* resizeEvent);
    void closeEvent(QCloseEvent* closeEvent);
};