#include "about.h"
#include "ui_about.h"
#include <QDesktopServices>
#include <QUrl>

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}

void About::on_paypal_clicked()
{
    QString link = "https://paypal.me/gargadon";
    QDesktopServices::openUrl(QUrl(link));
}

void About::on_myweb_clicked()
{
    QString link = "https://www.gargadon.info/";
    QDesktopServices::openUrl(QUrl(link));
}

void About::on_pushButton_clicked()
{
    close();
}
