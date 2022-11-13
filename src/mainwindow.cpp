#include <QDir>

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

    this->connect(ui->homepageWidget, SIGNAL(projectOpened(const QString &)),
                  ui->sidebarWidget, SLOT(openProject(const QString &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
