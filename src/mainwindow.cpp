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

    QSplitter *sidebarSplitter = new QSplitter(Qt::Vertical);
    FileTreeView *fileTreeView = new FileTreeView();
    GitTreeView *gitTreeView = new GitTreeView();
    sidebarSplitter->addWidget(fileTreeView);
    sidebarSplitter->addWidget(gitTreeView);

    QSplitter *mainSplitter = new QSplitter(Qt::Vertical);
    HomepageWidget *homepageWidget = new HomepageWidget(this);
    mainSplitter->addWidget(homepageWidget);

    QSplitter *baseSplitter = new QSplitter(Qt::Horizontal);
    baseSplitter->addWidget(sidebarSplitter);
    baseSplitter->addWidget(mainSplitter);

    this->setCentralWidget(baseSplitter);
}

MainWindow::~MainWindow()
{
    delete ui;
}
