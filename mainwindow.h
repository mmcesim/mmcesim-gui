#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QSettings>
#include <QLineEdit>
#include <QCursor>
#include <QToolButton>
#include <QIcon>
#include <QFontDatabase>

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
    Ui::MainWindow *ui;
    QLineEdit* line_search;
    QToolButton* button_search;
    QLabel* label_spacer;
};
#endif // MAINWINDOW_H
