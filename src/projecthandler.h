#ifndef PROJECTHANDLER_H
#define PROJECTHANDLER_H

#include <QWidget>
#include <QString>


class ProjectHandler
{
public:
    ProjectHandler(QWidget *parent = nullptr);

public:
    QString projectPath() const;
    void openProject();
    void createProject();

private:
    QWidget *parent_;
    QString projectPath_;
};

#endif // PROJECTHANDLER_H
