#include "Checklist.h"

Checklist::Checklist(QWidget* parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.centralWidget->setLayout(new QVBoxLayout);

    ButtonHandler* buttonHandler = new ButtonHandler(ui);


    connect(ui.addButton, &QPushButton::clicked, buttonHandler, &ButtonHandler::addButton);
    connect(ui.delButton, &QPushButton::clicked, buttonHandler, &ButtonHandler::delButton);
    connect(ui.showAllButton, &QPushButton::clicked, buttonHandler, &ButtonHandler::showAllButton);
    buttonList.push_back(ui.addButton);
    buttonList.push_back(ui.delButton);
    buttonList.push_back(ui.showAllButton);

}

Checklist::~Checklist()
{

}

void Checklist::resizeEvent(QResizeEvent* event)
{
    QSize size = event->size();

    for (int i = 1; i <= buttonList.size(); i++)
    {
        buttonList[i - 1]->resize(size.width() / 2.5, size.height() / 8);
        buttonList[i - 1]->setGeometry(
            QRect(size.width() - 15 - buttonList[i - 1]->size().width(),
                15 + (i - 1) * (buttonList[i - 1]->size().height() + 15),
                buttonList[i - 1]->geometry().width(),
                buttonList[i - 1]->geometry().height())
        );
    }

    ui.taskBox->resize(QSize(ui.taskBox->width(), size.height() - 50));

    QMainWindow::resizeEvent(event);
}

void resizeButtons()
{

}
