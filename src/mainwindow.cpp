#include <QSplitter>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "filetreeview.h"
#include "gittreeview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSplitter *baseSplitter = new QSplitter(Qt::Horizontal);

    QSplitter *sidebarSplitter = new QSplitter(Qt::Vertical);
    FileTreeView *fileTreeView = new FileTreeView();
    GitTreeView *gitTreeView = new GitTreeView();

    QSplitter *mainSplitter = new QSplitter(Qt::Vertical);

    baseSplitter->addWidget(sidebarSplitter);
    baseSplitter->addWidget(mainSplitter);

    sidebarSplitter->addWidget(fileTreeView);
    sidebarSplitter->addWidget(gitTreeView);
    this->setCentralWidget(baseSplitter);
}

MainWindow::~MainWindow()
{
    delete ui;
}
