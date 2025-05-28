#include "Checklist.h"
#include "ButtonHandler.h"
#include "AddWindow.h"

Checklist::Checklist(QWidget* parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.centralWidget->setLayout(new QVBoxLayout);

    // qDebug() << "first";

    addW = new AddWindow();

    // qDebug() << addW;

    buttonHandler = new ButtonHandler(ui, addW, this);
    addW->setButtonHandler(buttonHandler);

    // qDebug() << "second";

    this->setMinimumSize(QSize(600, 400));
    
    connect(ui.addButton, &QPushButton::clicked, buttonHandler, &ButtonHandler::addButton);
    connect(ui.delButton, &QPushButton::clicked, buttonHandler, &ButtonHandler::delButton);
    //connect(ui.showAllButton, &QPushButton::clicked, buttonHandler, &ButtonHandler::showAllButton);

    connect(addW->getAdd(), &QPushButton::clicked, buttonHandler, &ButtonHandler::addTask);
    connect(addW->getCancel(), &QPushButton::clicked, buttonHandler, &ButtonHandler::cancelOperation);

    /// The reason for this tomfoolery is because closeEvent() (check below) is not being called upon clicking the "X" button
    /// at the top of the screen. No idea why. Destructor was not called either. Regardless, this fixes both issues,
    /// and they now execute. (order being closeEvent() -> destructor).
    /// 
    /// 
    /// The way this is done is the following : we connect the instance to the aboutToQuit signal, but instead of passing 
    /// a slot and a connection, we just pass a lambda function with an empty capture and an empty parameter list that runs "{}".
    /// 
    /// Three cheers for C++11 !
    
    connect(QApplication::instance(), &QApplication::aboutToQuit, []() {});


    buttonList.push_back(ui.addButton);
    buttonList.push_back(ui.delButton);
    //buttonList.push_back(ui.showAllButton);
}

Checklist::~Checklist()
{
    /// Deleting here again in ANY case . . .

    if (addW)
    {
        delete addW;
        addW = nullptr;
    }
    if (buttonHandler)
    {
        delete buttonHandler;
        buttonHandler = nullptr;
    }
}

void Checklist::setAddWindow(AddWindow* addw)
{
    /// "read access violation" exceptions hate this one trick !
    /// 
    /// while this is just a setter
    /// it also fixes some delete shenanigans that probably are not even a question
    /// if using smart pointers or signals or other stuff.
    /// this works though and will probably be changed later

    addW = addw;
}

void Checklist::resizeEvent(QResizeEvent* event)
{
    QSize size = event->size();

    for (int i = 1; i <= buttonList.size(); i++)
    {
        buttonList[i - 1]->resize(size.width() / 2.5, size.height() / 8);
        buttonList[i - 1]->setGeometry(
            QRect(
                    size.width() - 15 - buttonList[i - 1]->size().width(),
                    15 + (i - 1) * (buttonList[i - 1]->size().height() + 15),   
                    buttonList[i - 1]->geometry().width(),
                    buttonList[i - 1]->geometry().height()
                )
        );
    }


    ui.taskBox->resize(QSize(size.width() / 3 - 10, size.height() - 50));

    ui.taskDesc->resize(size.width() / 1.714, size.height() / 3.076);
    ui.taskDesc->setGeometry(QRect(
        size.width() - 15 - ui.taskDesc->size().width(),
        size.height() - ui.taskDesc->height() - 40,
        ui.taskDesc->geometry().width(),
        ui.taskDesc->geometry().height()
    ));

    ui.scrollArea->resize(QSize(ui.taskBox->width() - 5, ui.taskBox->height() - 30));
    ui.sAreaContent->resize(ui.scrollArea->size());

    QMap<QPushButton*, TaskEntity> moddedList = buttonHandler->taskRepo.getTasks();


    QPushButton* prevButton;
    int nr = 1;
    prevButton = nullptr;

    for (auto i = moddedList.begin(); i != moddedList.end(); ++i)
    {
        i.key()->resize(QSize(ui.scrollArea->size().width() - 30, size.height() / 12));
    }
    


    buttonHandler->taskRepo.setTasks(moddedList);

    qDebug() << ui.taskDesc->x() << " ||| " << ui.taskDesc->y();

    QMainWindow::resizeEvent(event);
}

void Checklist::closeEvent(QCloseEvent* event)
{
    qDebug() << buttonHandler;

    if (addW)
    {
        delete addW;
        addW = nullptr;
    }
    if (buttonHandler)
    {
        delete buttonHandler;
        buttonHandler = nullptr;
    }
}

