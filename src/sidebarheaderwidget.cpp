#include <QPainter>
#include <QStyle>
#include <QStyleOption>

#include "sidebarheaderwidget.h"
#include "ui_sidebarheaderwidget.h"

SidebarHeaderWidget::SidebarHeaderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SidebarHeaderWidget)
{
    ui->setupUi(this);
    this->connect(ui->collapseButton, SIGNAL(toggled(bool)), this, SIGNAL(expanded(bool)));
}

SidebarHeaderWidget::~SidebarHeaderWidget()
{
    delete ui;
}

void SidebarHeaderWidget::setHeaderTitle(const QString &title)
{
    ui->projectLabel->setText(title);
}

void SidebarHeaderWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
