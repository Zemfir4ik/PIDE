#include <QSplitter>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "filetreeview.h"
#include "gittreeview.h"
#include "homepagewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Stub
    ui->fileTreeView->setProjectPath("../Pide");
}

MainWindow::~MainWindow()
{
    delete ui;
}
