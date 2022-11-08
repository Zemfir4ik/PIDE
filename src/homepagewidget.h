#ifndef HOMEPAGEWIDGET_H
#define HOMEPAGEWIDGET_H

#include <QWidget>

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
    void openProject();
    void paintEvent(QPaintEvent* event) override;

signals:
    void projectOpened(const QString& path);

private:
    Ui::HomepageWidget *ui;
};

#endif // HOMEPAGEWIDGET_H
