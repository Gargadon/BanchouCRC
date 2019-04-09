#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "crc32.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openfiles_clicked();

    void on_escanear_clicked();

    void on_actionExit_triggered();

    void on_md5_clicked();

    void on_sha1_clicked();

    void on_sha256_clicked();

    void on_sha512_clicked();

    void errorVacio();

    void createStatusBar();

    void on_actionAbout_triggered();

    void on_putcrc32_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
