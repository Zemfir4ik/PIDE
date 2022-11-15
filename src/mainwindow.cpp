#include <QDir>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->createControls();
    this->connectControls();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createControls()
{
    ui->sidebarWidget->hide();
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
}

void MainWindow::openProject()
{
    ProjectHandler handler(this);
    QString path = handler.openProject();

    if (!path.isEmpty()) {
        projectPath_ = path;
        this->updateProject();
    }
}

void MainWindow::createProject()
{
    ProjectHandler handler(this);
    QString path = handler.createProject();

    if (!path.isEmpty()) {
        projectPath_ = path;
        this->updateProject();
    }
}

void MainWindow::updateProject()
{
    if (projectPath_.isEmpty()) {
        ui->sidebarWidget->hide();
    } else {
        ui->sidebarWidget->updateProject(projectPath_);
        ui->sidebarWidget->show();
    }

    this->updateWindowTitle();
}

void MainWindow::updateWindowTitle()
{
    if (projectPath_.isEmpty()) {
        this->setWindowTitle("PIDE");
    } else {
        QString title = QString("PIDE | %1").arg(QDir(projectPath_).dirName());
        this->setWindowTitle(title);
    }
}
