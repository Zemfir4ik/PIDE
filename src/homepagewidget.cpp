#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <QFileDialog>

#include "homepagewidget.h"
#include "ui_homepagewidget.h"

HomepageWidget::HomepageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomepageWidget)
{
    ui->setupUi(this);

    this->connect(ui->openProjectButton, &QPushButton::released,
                  this, &HomepageWidget::openProject);
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

void HomepageWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
