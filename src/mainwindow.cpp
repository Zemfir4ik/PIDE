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
    delete handler_;
}

void MainWindow::createControls()
{
    handler_ = new ProjectHandler(this);
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
    handler_->openProject();
    this->updateProject();
}

void MainWindow::createProject()
{
    handler_->createProject();
    this->updateProject();
}

void MainWindow::updateProject()
{
    QString projectPath = handler_->projectPath();

    if (projectPath.isEmpty()) {
        ui->sidebarWidget->hide();
    } else {
        ui->sidebarWidget->setProjectPath(projectPath);
        ui->sidebarWidget->show();
    }

    this->updateWindowTitle();
}

void MainWindow::updateWindowTitle()
{
    QString projectPath = handler_->projectPath();

    if (projectPath.isEmpty()) {
        this->setWindowTitle("PIDE");
    } else {
        QString title = QString("PIDE | %1").arg(QDir(projectPath).dirName());
        this->setWindowTitle(title);
    }
}
