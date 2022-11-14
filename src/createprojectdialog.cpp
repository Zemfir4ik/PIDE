#include <QFileDialog>

#include "createprojectdialog.h"
#include "ui_createprojectdialog.h"

CreateProjectDialog::CreateProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateProjectDialog)
{
    ui->setupUi(this);

    ui->buttonBox->button(ui->buttonBox->Ok)->setDisabled(true);
    this->updateProjectPath();
    this->connectControls();
}

CreateProjectDialog::~CreateProjectDialog()
{
    delete ui;
}

void CreateProjectDialog::connectControls()
{
    this->connect(ui->projectPathButton, &QPushButton::released,
                  this, &CreateProjectDialog::selectProjectPath);
    this->connect(ui->projectNameEdit, SIGNAL(textChanged(const QString &)),
                  this, SLOT(setProjectName(const QString &)));
}

QString CreateProjectDialog::getProjectParentDirPath() const
{
    return this->projectParentDirPath_;
}

QString CreateProjectDialog::getProjectName() const
{
    return this->projectName_;
}

void CreateProjectDialog::setProjectName(const QString &name)
{
    projectName_ = name;
    this->updateProjectPath();
}

void CreateProjectDialog::selectProjectPath()
{
    QString path = QFileDialog::getExistingDirectory(this, "Select Project Directory");

    if (!path.isEmpty()) {
        projectParentDirPath_ = path;
        this->updateProjectPath();
    }
}

void CreateProjectDialog::updateProjectPath()
{
    QDir parent(projectParentDirPath_);
    ui->projectPathEdit->setText(parent.filePath(projectName_));

    bool bIsPathValid = !projectName_.isEmpty() && !parent.exists(projectName_);
    ui->buttonBox->button(ui->buttonBox->Ok)->setEnabled(bIsPathValid);
}
