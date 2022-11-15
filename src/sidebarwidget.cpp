#include <QDir>

#include "sidebarwidget.h"
#include "ui_sidebarwidget.h"

SidebarWidget::SidebarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SidebarWidget)
{
    ui->setupUi(this);

    this->createControls();
    this->connectControls();
}

SidebarWidget::~SidebarWidget()
{
    delete ui;
}

void SidebarWidget::createControls()
{
    ui->sidebarSplitter->setCollapsible(this->kFileTreeViewIndex, true);
    ui->sidebarSplitter->setCollapsible(this->kGitTreeViewIndex, true);
    ui->baseLayout->setAlignment(Qt::AlignTop);
}

void SidebarWidget::connectControls()
{
    this->connect(ui->fileHeaderWidget, SIGNAL(expanded(bool)),
                  this, SLOT(expandSidebarProject(bool)));
    this->connect(ui->gitHeaderWidget, SIGNAL(expanded(bool)),
                  this, SLOT(expandSidebarGit(bool)));
}

void SidebarWidget::expandSidebarWidget(bool expand, int index)
{
    if (ui->sidebarSplitter->widget(index) == nullptr)
        return;

    QList<int> sidebarSizes = ui->sidebarSplitter->sizes();

    sidebarSizes[index] = expand ? 1 : 0;
    ui->sidebarSplitter->widget(index)->setVisible(expand);
    ui->sidebarSplitter->setSizes(sidebarSizes);
}

void SidebarWidget::expandSidebarProject(bool expand)
{
    expandSidebarWidget(expand, kFileTreeViewIndex);
}

void SidebarWidget::expandSidebarGit(bool expand)
{
    expandSidebarWidget(expand, kGitTreeViewIndex);
}

void SidebarWidget::updateProject(const QString &path)
{
    ui->fileHeaderWidget->setHeaderTitle(QDir(path).dirName());
    ui->fileTreeView->setProjectPath(path);
}
