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

    if (ui->fileTreeView->getProjectPath().isEmpty()) {
        ui->fileTreeView->hide();
        ui->gitTreeView->hide();
    }

    this->connect(ui->homepageWidget,
                  SIGNAL(projectOpened(const QString&)),
                  this,
                  SLOT(openProject(const QString&)));
}

void MainWindow::openProject(const QString &path)
{
    ui->fileTreeView->setProjectPath(path);
    ui->fileTreeView->show();
    ui->gitTreeView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
