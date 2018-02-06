#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);

    saveAction = new QAction(QIcon(":/images/doc-save"), tr("&Save..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);


//    QToolBar *toolBar2 = addToolBar(tr("&Test"));
//    toolBar2->addAction(openAction);
//    toolBar2->addAction(saveAction);

    statusBar() ;

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
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

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()) {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Read File"), tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(this, tr("Path"), tr("You did not select any file."));
    }
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()) {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Write File"), tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    } else {
        QMessageBox::warning(this, tr("Path"), tr("You did not select any file."));
    }
}

void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Move: (%1, %2)</h1></center>")              //不能是两个%1，但%1，%2和%1，%3是可以的
                  .arg(QString::number(event->x()), QString::number(event->y()))); //x,y均为int
}

void EventLabel::mousePressEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Press: (%1, %3)</h1></center>")
                  .arg(QString::number(event->x()), QString::number(event->y())));
}

void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("<center><h1>Release: (%d, %d)</h1></center>",
                event->x(), event->y());
    this->setText(msg);
}


