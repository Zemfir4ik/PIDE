#include <QDir>
#include <QFileDialog>

#include "projecthandler.h"
#include "createprojectdialog.h"

ProjectHandler::ProjectHandler(QWidget *parent)
    : parent_(parent)
{

}

QString ProjectHandler::projectPath() const
{
    return projectPath_;
}

void ProjectHandler::openProject()
{
    QString path = QFileDialog::getExistingDirectory(
                this->parent_, "Open Project",
                projectPath_.isEmpty() ? QDir::homePath() : projectPath_);

    if (!path.isEmpty())
        projectPath_ = path;
}

void ProjectHandler::createProject()
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

    if (!path.isEmpty())
        projectPath_ = path;
}
