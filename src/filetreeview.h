#ifndef FILETREEVIEW_H
#define FILETREEVIEW_H

#include <QTreeView>

class FileTreeView : public QTreeView
{
public:
    FileTreeView(QWidget *parent = nullptr);

public:
    void setProjectPath(QString projectPath);

private:
    void createControls();
    void createModel();

private:
    QString projectPath_;
};

#endif // FILETREEVIEW_H
