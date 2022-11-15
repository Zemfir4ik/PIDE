#ifndef FILETREEVIEW_H
#define FILETREEVIEW_H

#include <QTreeView>
#include <QFileSystemModel>

class FileTreeView : public QTreeView
{
public:
    FileTreeView(QWidget *parent = nullptr);

public:
    void setProjectPath(const QString& path);

private:
    void createControls();

private:
    QFileSystemModel *model_;
};

#endif // FILETREEVIEW_H
