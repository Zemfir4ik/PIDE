#ifndef CREATEPROJECTDIALOG_H
#define CREATEPROJECTDIALOG_H

#include <QDialog>
#include <QDir>

namespace Ui {
class CreateProjectDialog;
}

class CreateProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProjectDialog(QWidget *parent = nullptr);
    ~CreateProjectDialog();

public:
    QString getProjectParentDirPath() const;
    QString getProjectName() const;

public slots:
    void setProjectName(const QString &name);

private:
    void connectControls();
    void selectProjectPath();
    void updateProjectPath();

private:
    Ui::CreateProjectDialog *ui;
    QString projectParentDirPath_ = QDir::homePath();;
    QString projectName_;
};

#endif // CREATEPROJECTDIALOG_H
