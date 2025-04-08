#include "Checklist.h"

Checklist::Checklist(QWidget* parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.centralWidget->setLayout(new QVBoxLayout);

    buttonHandler = new ButtonHandler(ui);


    connect(ui.addButton, &QPushButton::clicked, buttonHandler, &ButtonHandler::addButton);
    connect(ui.delButton, &QPushButton::clicked, buttonHandler, &ButtonHandler::delButton);
    connect(ui.showAllButton, &QPushButton::clicked, buttonHandler, &ButtonHandler::showAllButton);


    /// The reason for this tomfoolery is because closeEvent() (check below) is not being called upon clicking the "X" button
    /// at the top of the screen. No idea why. Destructor was not called either. Regardless, this fixes both issues,
    /// and they now execute. (order being closeEvent() -> destructor).
    /// 
    /// This is necessary due to ButtonHandler completely handling the separate window.
    /// 
    /// The way this is done is the following : we connect the instance to the aboutToQuit signal, but instead of passing 
    /// a slot and a connection, we just pass a parameterless lambda function with an empty parameter list that runs "{}".
    /// 
    /// Three cheers for C++11 !
    
    connect(QApplication::instance(), &QApplication::aboutToQuit, []() {});


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

void Checklist::closeEvent(QCloseEvent* event)
{
    qDebug() << buttonHandler;
    delete buttonHandler;
}

