#ifndef HOMEPAGEWIDGET_H
#define HOMEPAGEWIDGET_H

#include <QWidget>

#include "projecthandler.h"

namespace Ui {
class HomepageWidget;
}

class HomepageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomepageWidget(QWidget *parent = nullptr);
    ~HomepageWidget();

private:
    void paintEvent(QPaintEvent *event) override;

signals:
    void projectOpenRequested();
    void projectCreationRequested();

private:
    Ui::HomepageWidget *ui;
};

#endif // HOMEPAGEWIDGET_H
