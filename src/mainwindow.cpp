#include <QDir>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connectControls();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectControls()
{
    this->connect(ui->actionOpenProject, &QAction::triggered,
                  this, &MainWindow::openProject);
    this->connect(ui->actionCreateProject, &QAction::triggered,
                  this, &MainWindow::createProject);
    this->connect(ui->homepageWidget, &HomepageWidget::projectOpenRequested,
                  this, &MainWindow::openProject);
    this->connect(ui->homepageWidget, &HomepageWidget::projectCreationRequested,
                  this, &MainWindow::createProject);
    this->connect(this, SIGNAL(projectOpened(const QString &)),
                  ui->sidebarWidget, SLOT(openProject(const QString &)));
}

void MainWindow::openProject()
{
    ProjectHandler handler(this);
    QString path = handler.openProject();

    if (!path.isEmpty())
        emit projectOpened(path);
}

void MainWindow::createProject()
{
    ProjectHandler handler(this);
    QString path = handler.createProject();

    if (!path.isEmpty())
        emit projectOpened(path);
}
