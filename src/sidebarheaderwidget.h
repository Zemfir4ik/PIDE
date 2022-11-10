#ifndef SIDEBARHEADERWIDGET_H
#define SIDEBARHEADERWIDGET_H

#include <QWidget>

namespace Ui {
class SidebarHeaderWidget;
}

class SidebarHeaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SidebarHeaderWidget(QWidget *parent = nullptr);
    ~SidebarHeaderWidget();

public:
    void setHeaderTitle(const QString& title);

private:
    void paintEvent(QPaintEvent *);

signals:
    void expanded(bool value);

private:
    Ui::SidebarHeaderWidget *ui;
};

#endif // SIDEBARHEADERWIDGET_H
