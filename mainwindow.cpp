#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

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
//    QDialog *dialog = new QDialog;                  //建立在堆上
//    dialog->setAttribute(Qt::WA_DeleteOnClose);
//    dialog->setWindowTitle(tr("Hello, dialog!"));   //对话框不会一闪而过
//    dialog->show();


//    if (QMessageBox::Yes == QMessageBox::question(this,
//                                                  tr("Question"),
//                                                  tr("Are you OK?"),
//                                                  QMessageBox::Yes | QMessageBox::No,
//                                                  QMessageBox::Yes)) {
//        QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
//    } else {
//        QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
//    }

//    QMessageBox::warning(this, tr("warning"), tr("Open"));

//    QMessageBox::critical(this, tr("critical"), tr("Open"));

//    QMessageBox::about(this, tr("About"), tr("Open"));

//    QMessageBox::aboutQt(this, tr("AboutQt"));

    QMessageBox msgBox;
    msgBox.setText(tr("The document has been modified."));
    msgBox.setInformativeText(tr("Do you want to save your changes?"));
    msgBox.setDetailedText(tr("Differences here..."));
    msgBox.setStandardButtons(QMessageBox::Save
                              | QMessageBox::Discard
                              | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        qDebug() << "Save document!";
        break;
    case QMessageBox::Discard:
        qDebug() << "Discard changes!";
        break;
    case QMessageBox::Cancel:
        qDebug() << "Close document!";
        break;
    }
}


