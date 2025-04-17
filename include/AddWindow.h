#pragma once

#include <QtWidgets/QMainWindow>
#include <QResizeEvent>
#include "ui_AddWindow.h"
#include <vector>
#include <qpushbutton.h>
#include "ButtonHandler.h"
#include "exception"

class AddWindow : public QMainWindow
{
    Q_OBJECT

public:
    AddWindow(QWidget* parent = nullptr);
    ~AddWindow();

    void showWindow();
    void setButtonHandler(ButtonHandler* bttnH);

    QPushButton* getAdd();
    QPushButton* getCancel();

    QPlainTextEdit* getDesc();
    QPlainTextEdit* getTitle();

private:
    Ui::AddWindow ui;

    QSize baseSize;
    std::vector<QPushButton*> buttonList;

    ButtonHandler* buttonHandler;
};