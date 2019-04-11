#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QByteArray>
#include <QFile>
#include "crc32.h"
#include "about.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->showMessage(tr("Ready."));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openfiles_clicked()
{
    ui->archivos->clear();
    QStringList filename = QFileDialog::getOpenFileNames(this,tr("Seleccionar archivos"),
                                                    ui->archivos->toPlainText(),
                                                    tr("Todos los archivos (*.*)"));

    if(!filename.isEmpty()){
    for(auto &data :filename)
        ui->archivos->append(data);
    }
}

void MainWindow::on_escanear_clicked()
{
    if(!ui->archivos->toPlainText().isEmpty())
    {
        ui->salida->clear();
        QString origen2 = ui->archivos->toPlainText();
        QString prefijo;
        QSysInfo osname;
        QString os = osname.productType();
        if(os=="windows")
        {
            prefijo="";


        }
        else {
            prefijo="/";

        }
        QStringList archivo = origen2.replace("file:///",prefijo).split(QRegExp("[\n]"),QString::SkipEmptyParts);
        int final = archivo.count();
        Crc32 crc32;
        for (int i=0;i<final;i++)
        {
            QString crc = QString::number(crc32.calculateFromFile(archivo[i]),16).toUpper().rightJustified(8, '0');
            ui->salida->append(archivo[i] + " -> " + crc);
        }
        createStatusBar();
    }
    else {
        errorVacio();
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_md5_clicked()
{
    if(!ui->archivos->toPlainText().isEmpty())
    {
        ui->salida->clear();
        QString origen2 = ui->archivos->toPlainText();
        QString prefijo;
        QSysInfo osname;
        QString os = osname.productType();
        if(os=="windows")
        {
            prefijo="";


        }
        else {
            prefijo="/";

        }
        QStringList archivo = origen2.replace("file:///",prefijo).split(QRegExp("[\n]"),QString::SkipEmptyParts);
        QCryptographicHash hash(QCryptographicHash::Md5);
        int final = archivo.count();
        for(int i=0;i<final;i++)
        {
            QFile file(archivo[i]);
            file.open(QFile::ReadOnly);
            while(!file.atEnd())
            {
                hash.addData(file.read(8192));
            }
            QString md5 = hash.result().toHex();
            file.close();
            // Creamos el archivo md5
            QString extension = ".md5";
            QString salidafile = archivo[i] + extension;
            QFile suma(salidafile);
            suma.open(QIODevice::WriteOnly);
            QTextStream stream(&suma);
            stream << md5;
            suma.close();
            ui->salida->append(archivo[i] + " -> " + md5);
        }
        createStatusBar();
    }
    else {
        errorVacio();
    }
}


void MainWindow::on_sha1_clicked()
{
    if(!ui->archivos->toPlainText().isEmpty())
    {
        ui->salida->clear();
        QString origen2 = ui->archivos->toPlainText();
        QString prefijo;
        QSysInfo osname;
        QString os = osname.productType();
        if(os=="windows")
        {
            prefijo="";


        }
        else {
            prefijo="/";

        }
        QStringList archivo = origen2.replace("file:///",prefijo).split(QRegExp("[\n]"),QString::SkipEmptyParts);
        QCryptographicHash hash(QCryptographicHash::Sha1);
        int final = archivo.count();
        for(int i=0;i<final;i++)
        {
            QFile file(archivo[i]);
            file.open(QFile::ReadOnly);
            while(!file.atEnd())
            {
                hash.addData(file.read(8192));
            }
            QString sha1 = hash.result().toHex();
            file.close();
            // Creamos el archivo sha1
            QString extension = ".sha1";
            QString salidafile = archivo[i] + extension;
            QFile suma(salidafile);
            suma.open(QIODevice::WriteOnly);
            QTextStream stream(&suma);
            stream << sha1;
            suma.close();
            ui->salida->append(archivo[i] + " -> " + sha1);
        }
        createStatusBar();
    }
    else {
        errorVacio();
    }
}

void MainWindow::on_sha256_clicked()
{
    if(!ui->archivos->toPlainText().isEmpty())
    {
        ui->salida->clear();
        QString origen2 = ui->archivos->toPlainText();
        QString prefijo;
        QSysInfo osname;
        QString os = osname.productType();
        if(os=="windows")
        {
            prefijo="";


        }
        else {
            prefijo="/";

        }
        QStringList archivo = origen2.replace("file:///",prefijo).split(QRegExp("[\n]"),QString::SkipEmptyParts);
        QCryptographicHash hash(QCryptographicHash::Sha256);
        int final = archivo.count();
        for(int i=0;i<final;i++)
        {
            QFile file(archivo[i]);
            file.open(QFile::ReadOnly);
            while(!file.atEnd())
            {
                hash.addData(file.read(8192));
            }
            QString sha256 = hash.result().toHex();
            file.close();
            // Creamos el archivo sha256
            QString extension = ".sha256";
            QString salidafile = archivo[i] + extension;
            QFile suma(salidafile);
            suma.open(QIODevice::WriteOnly);
            QTextStream stream(&suma);
            stream << sha256;
            suma.close();
            ui->salida->append(archivo[i] + " -> " + sha256);
        }
        createStatusBar();
    }
    else {
        errorVacio();
    }
}

void MainWindow::on_sha512_clicked()
{
    ui->salida->clear();
    if(!ui->archivos->toPlainText().isEmpty())
    {
        ui->salida->clear();
        QString origen2 = ui->archivos->toPlainText();
        QString prefijo;
        QSysInfo osname;
        QString os = osname.productType();
        if(os=="windows")
        {
            prefijo="";


        }
        else {
            prefijo="/";

        }
        QStringList archivo = origen2.replace("file:///",prefijo).split(QRegExp("[\n]"),QString::SkipEmptyParts);
        QCryptographicHash hash(QCryptographicHash::Sha512);
        int final = archivo.count();
        for(int i=0;i<final;i++)
        {
            QFile file(archivo[i]);
            file.open(QFile::ReadOnly);
            while(!file.atEnd())
            {
                hash.addData(file.read(8192));
            }
            QString sha512 = hash.result().toHex();
            file.close();
            // Creamos el archivo sha512
            QString extension = ".sha512";
            QString salidafile = archivo[i] + extension;
            QFile suma(salidafile);
            suma.open(QIODevice::WriteOnly);
            QTextStream stream(&suma);
            stream << sha512;
            suma.close();
            ui->salida->append(archivo[i] + " -> " + sha512);
        }
        createStatusBar();
    }
    else {
        errorVacio();
    }
}

void MainWindow::errorVacio()
{
    QMessageBox MSGBOX;
    MSGBOX.critical(this,tr("Error"),
                    tr("Can't do this without a file."));
    statusBar()->showMessage(tr("Can't do this without a file."));
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Done."));
}

void MainWindow::on_actionAbout_triggered()
{
    About acerca;
    acerca.setModal(true);
    acerca.exec();
}

void MainWindow::on_putcrc32_clicked()
{
    if(!ui->archivos->toPlainText().isEmpty())
    {
        ui->salida->clear();
        QString origen2 = ui->archivos->toPlainText();
        QString prefijo;
        QSysInfo osname;
        QString os = osname.productType();
        if(os=="windows")
        {
            prefijo="";


        }
        else {
            prefijo="/";

        }
        QStringList archivo = origen2.replace("file:///",prefijo).split(QRegExp("[\n]"),QString::SkipEmptyParts);
        int final = archivo.count();
        Crc32 crc32;
        for (int i=0;i<final;i++)
        {
            QString crc = QString::number(crc32.calculateFromFile(archivo[i]),16).toUpper().rightJustified(8, '0');
            ui->salida->append(crc);
            QFileInfo fi(archivo[i]);
            QString path = fi.canonicalPath();
            path = path + "/";
            QString basename = fi.completeBaseName();
            basename = basename + " [" + crc + "]";
            QString extension = fi.suffix();
            extension = "." + extension;
            QString valorfinal = path + basename + extension;
            QFile file(archivo[i]);
            file.rename(valorfinal);
        }
        createStatusBar();
    }
    else {
        errorVacio();
    }
}
