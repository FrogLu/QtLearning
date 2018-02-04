#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::showUserAgeDialog);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    QToolBar *toolBar2 = addToolBar(tr("&Test"));
    toolBar2->addAction(openAction);

    statusBar() ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
//    QMessageBox::information(this, tr("Information"), tr("Open"));

//    QDialog dialog(this);                           //建立在栈上
//    dialog.setWindowTitle(tr("Hello, dialog!"));    //对话框会一闪而过
//    dialog.show();
                //exec()应用级模态窗，open()窗口级模态窗，show()非模态窗
    QDialog *dialog = new QDialog;                  //建立在堆上
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle(tr("Hello, dialog!"));   //对话框不会一闪而过
    dialog->show();
}

// in dialog:
void UserAgeDialog::accept()
{
    emit userAgeChanged(newAge); // newAge is an int
    QDialog::accept();
}

// in main window:
void MainWindow::showUserAgeDialog()
{
    UserAgeDialog *dialog = new UserAgeDialog(this);
    connect(dialog, &UserAgeDialog::userAgeChanged, this, &MainWindow::setUserAge);
    dialog->show();
}

// ...

void MainWindow::setUserAge(int age)
{
    userAge = age;
}
