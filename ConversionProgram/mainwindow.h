#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QProcess>
#include <QTextStream>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QRegExp>
#include <QStandardPaths>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_VideoSourceButton_clicked();

    void on_VideoDestination_clicked();

    void on_ConvertButton_clicked();

    void progress();

    void complete();


//    void on_showFullOutput_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *myprocess;
    QStringList SourceFileName;
    QStringList DestinationPath;
    QString fullFilePath;
    QString baseFileName;
    QString fileExtension;
    QString destDirectory;
    QRegExp duration;
    QRegExp time;
    QString QProcessOutput;
    int durResult;
    int timeResult;
    QString finalName;
    QString ffmpegPath;

};

#endif // MAINWINDOW_H
