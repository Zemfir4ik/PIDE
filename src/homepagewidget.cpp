#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <QFileDialog>

#include "homepagewidget.h"
#include "ui_homepagewidget.h"
#include "createprojectdialog.h"

HomepageWidget::HomepageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomepageWidget)
{
    ui->setupUi(this);

    this->connect(ui->openProjectButton, &QPushButton::released,
                  this, &HomepageWidget::openProject);
    this->connect(ui->createProjectButton, &QPushButton::released,
                  this, &HomepageWidget::createProject);
}

HomepageWidget::~HomepageWidget()
{
    delete ui;
}

void HomepageWidget::openProject()
{
    QString projectPath = QFileDialog::getExistingDirectory(this, "Open Project");

    if (!projectPath.isEmpty())
        emit projectOpened(projectPath);
}

void HomepageWidget::createProject()
{
    int ret;
    CreateProjectDialog *createProjectDialog = new CreateProjectDialog(this);

    ret = createProjectDialog->exec();

    if (ret == QDialog::Accepted) {
        QDir parent(createProjectDialog->getProjectParentDirPath());
        QString projectName = createProjectDialog->getProjectName();

        if (!parent.exists(projectName) && !parent.mkdir(projectName))
            return;

        emit projectOpened(parent.filePath(projectName));
    }
}

void HomepageWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
