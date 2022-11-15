#include <QDir>
#include <QFileDialog>

#include "projecthandler.h"
#include "createprojectdialog.h"

ProjectHandler::ProjectHandler(QWidget *parent)
    : parent_(parent)
{

}

QString ProjectHandler::openProject()
{
    return QFileDialog::getExistingDirectory(this->parent_, "Open Project");
}

QString ProjectHandler::createProject()
{
    int ret;
    QString path;
    CreateProjectDialog *createProjectDialog = new CreateProjectDialog(this->parent_);

    ret = createProjectDialog->exec();

    if (ret == QDialog::Accepted) {
        QDir parent(createProjectDialog->getProjectParentDirPath());
        QString projectName = createProjectDialog->getProjectName();

        if (parent.exists(projectName) || parent.mkdir(projectName))
            path = parent.filePath(projectName);
    }

    return path;
}
