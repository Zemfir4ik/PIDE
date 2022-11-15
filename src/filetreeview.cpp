#include "filetreeview.h"

FileTreeView::FileTreeView(QWidget *parent)
    : QTreeView(parent)
{
    this->createControls();
}

void FileTreeView::setProjectPath(const QString& path)
{
    QModelIndex index = model_->index(path);

    model_->setRootPath(path);
    this->setRootIndex(index);
}

void FileTreeView::createControls()
{
    model_ = new QFileSystemModel(this);
    model_->setReadOnly(false);
    this->setModel(model_);

    for (int i = 1; i < model_->columnCount(); ++i)
        this->hideColumn(i);

    this->setHeaderHidden(true);
}
