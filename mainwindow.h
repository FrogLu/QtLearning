#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QDebug>
#include <QObject>
#include <QLabel>
#include <QEvent>
#include <QPushButton>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class QTextEdit;



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event)
    {
        qDebug() << "MainWindow";
    }

private:
    Ui::MainWindow *ui;

    void open();
    void openFile();
    void saveFile();

    void closeEvent(QCloseEvent *event);

    QAction *openAction;
    QAction *saveAction;

    QTextEdit *textEdit;
};

class EventLabel : public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

////////// newspaper.h
class Newspaper : public QObject
{
    Q_OBJECT
public:
    Newspaper(const QString & name) :
        m_name(name)
    {
    }

    void send() const
    {
        emit newPaper(m_name);
    }

signals:
    void newPaper(const QString &name) const;

private:
    QString m_name;
};

////////// reader.h
//#include <QObject>
//#include <QDebug>

class Reader : public QObject
{
    Q_OBJECT
public:
    Reader() {}

    void receiveNewspaper(const QString & name) const
    {
        qDebug() << "Receives Newspaper: " << name;
    }
};

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    CustomButton(QWidget *parent) : QPushButton(parent)
    {
    }
protected:
    void mousePressEvent(QMouseEvent *event)
    {
        qDebug() << "CustomButton";
    }
};

class CustomButtonEx : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonEx(QWidget *parent) : CustomButton(parent)
    {
    }
protected:
    bool event(QEvent *e);
    void mousePressEvent(QMouseEvent *event)
    {
        event->ignore();
        qDebug() << "CustomButtonEx";
    }
};

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    CustomWidget(QWidget *parent) : QWidget(parent)
    {
    }
protected:
    bool event(QEvent *e);
    void mousePressEvent(QMouseEvent *event)
    {
        event->ignore();
        qDebug() << "CustomWidget";
    }
};


#endif // MAINWINDOW_H
