#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createControls();
    void connectControls();
    void openProject();
    void createProject();
    void updateProject();
    void updateWindowTitle();

signals:
    void projectOpened(const QString &);

private:
    Ui::MainWindow *ui;
    QString projectPath_;
};
#endif // MAINWINDOW_H
