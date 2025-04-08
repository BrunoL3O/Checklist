#pragma once

#include <QtWidgets/QMainWindow>
#include <QResizeEvent>
#include "ui_Checklist.h"
#include "ButtonHandler.h"
#include <vector>
#include <qpushbutton.h>

class Checklist : public QMainWindow
{
    Q_OBJECT

public:
    Checklist(QWidget* parent = nullptr);
    ~Checklist();

private:
    Ui::Checklist ui;
    ButtonHandler* buttonHandler;

    QSize baseSize;
    std::vector<QPushButton*> buttonList;


    void resizeEvent(QResizeEvent* resizeEvent);
    void closeEvent(QCloseEvent* closeEvent);
};