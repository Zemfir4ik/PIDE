#include <QFileSystemModel>

#include "filetreeview.h"

FileTreeView::FileTreeView(QWidget *parent)
    : QTreeView(parent)
{
    this->createControls();
}

void FileTreeView::createControls()
{
    this->createModel();
}

void FileTreeView::setProjectPath(QString projectPath)
{
    this->projectPath_ = projectPath;
    this->createModel();
}

void FileTreeView::createModel()
{
    QModelIndex index;
    QFileSystemModel *model = new QFileSystemModel(this);

    model->setReadOnly(false);
    model->setRootPath(this->projectPath_);
    this->setModel(model);

    index = model->index(this->projectPath_);
    this->setRootIndex(index);

    // We need only "Name" column
    for (int i = 1; i < model->columnCount(); ++i)
        this->hideColumn(i);

    this->setHeaderHidden(true);
}
