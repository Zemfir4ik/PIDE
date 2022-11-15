#ifndef SIDEBARWIDGET_H
#define SIDEBARWIDGET_H

#include <QWidget>
#include <QVariantAnimation>

namespace Ui {
class SidebarWidget;
}

class SidebarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SidebarWidget(QWidget *parent = nullptr);
    ~SidebarWidget();

public slots:
    void expandSidebarProject(bool expand);
    void expandSidebarGit(bool expand);

public:
    void updateProject(const QString &path);

private:
    const int kFileTreeViewIndex = 1;
    const int kGitTreeViewIndex = 3;

private:
    void createControls();
    void connectControls();
    void expandSidebarWidget(bool expand, int index);

private:
    Ui::SidebarWidget *ui;
};

#endif // SIDEBARWIDGET_H
