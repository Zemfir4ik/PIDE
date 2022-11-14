#ifndef PROJECTHANDLER_H
#define PROJECTHANDLER_H

#include <QWidget>
#include <QString>


class ProjectHandler
{
public:
    ProjectHandler(QWidget *parent = nullptr);

public:
    QString openProject();
    QString createProject();

private:
    QWidget *parent_;
};

#endif // PROJECTHANDLER_H
