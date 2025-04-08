#pragma once

#include <QtWidgets/QMainWindow>
#include <QResizeEvent>
#include "ui_AddWindow.h"
#include <vector>
#include <qpushbutton.h>

class AddWindow : public QMainWindow
{
    Q_OBJECT

public:
    AddWindow(QWidget* parent = nullptr);
    ~AddWindow();

    void showWindow();

private:
    Ui::AddWindow ui;

    QSize baseSize;
    std::vector<QPushButton*> buttonList;
};