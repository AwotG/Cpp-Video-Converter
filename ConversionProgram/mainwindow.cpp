#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //first initialize the regex object with the portion we want, and to split up what gets saved for later
    duration.setPattern("Duration: (\\d\\d):(\\d\\d):(\\d\\d).\\d\\d,");
    time.setPattern("time=(\\d\\d):(\\d\\d):(\\d\\d).\\d\\d");

    //Initialize QProcess with relevant signals and slots that respond to it
    myprocess = new QProcess();
    myprocess->setReadChannel(QProcess::ProcessChannel::StandardError);
    connect(myprocess,SIGNAL(readyRead()),this,SLOT(progress()));
    connect(myprocess,SIGNAL(finished(int)),this,SLOT(complete()));
    ffmpegPath = QDir(QCoreApplication::applicationDirPath()).filePath("ffmpeg");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_VideoSourceButton_clicked()
{
    QStringList supportedMimeTypes;
    //Add more Mime types so you're not limited
    supportedMimeTypes << "video/mp4";

    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Movie"));
    fileDialog.setMimeTypeFilters(supportedMimeTypes);

    //Sets directory in a way thats cross platform
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));

    if (fileDialog.exec() == QDialog::Accepted) {

        SourceFileName = fileDialog.selectedFiles();
        //Submitted URL's are actually a list, meaning its possible to receive multiple at once. For now, you're only allowed one to convert
        ui->VideoSourceEdit->setText(SourceFileName[0]);

        QFileInfo fi(SourceFileName[0]);
        //Used later to rebuild the output name
        fullFilePath = fi.fileName();
        baseFileName = fi.baseName();
        fileExtension = fi.suffix();

        ui->VideoDestination->setEnabled(true);
    }
}

void MainWindow::on_VideoDestination_clicked()
{

    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::Directory);
    fileDialog.setWindowTitle(tr("Open Movie"));
    //Sets directory in a way thats cross platform
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
    if (fileDialog.exec() == QDialog::Accepted) {

        DestinationPath = fileDialog.selectedFiles();
        destDirectory = DestinationPath[0];
        ui->VideoDestinationEdit->setText(destDirectory);
        ui->ConvertButton->setEnabled(true);
    }
}

void MainWindow::on_ConvertButton_clicked()
{
    QString finalOutputPath;
    QString format;
    QStringList arguments;

    //temporarily turn off convert button until QProcess signals its completed
    ui->ConvertButton->setEnabled(false);

    //Constructs ffmpeg command line parameters based on option
    if (ui->filterOptions->currentText() == "Sepia") {
        format = "colorchannelmixer=.393:.769:.189:0:.349:.686:.168:0:.272:.534:.131"; //colormatrix way to make sepia
        finalName = baseFileName + "_sepia." + fileExtension;
        finalOutputPath = QDir(destDirectory).filePath(finalName);
        arguments<<"-i" << SourceFileName[0] << "-y" << "-vf" << format << finalOutputPath;

    } else if (ui->filterOptions->currentText() == "Black and White"){
        format = "colorchannelmixer=.3:.4:.3:0:.3:.4:.3:0:.3:.4:.3"; //colormatrix way to make gray
        finalName = baseFileName + "_BW." + fileExtension;
        finalOutputPath = QDir(destDirectory).filePath(finalName);
        arguments<<"-i" << SourceFileName[0] << "-y" << "-vf" << format << finalOutputPath;

    } else if (ui->filterOptions->currentText()=="Audio") {
        finalName = baseFileName + "_Audio." + fileExtension;
        finalOutputPath = QDir(destDirectory).filePath(finalName);
        arguments<<"-i" << SourceFileName[0] << "-y" <<"-vn" << "-acodec" << "copy"  << finalOutputPath;

    }  else if (ui->filterOptions->currentText()=="Video") {
        finalName = baseFileName + "_Video." + fileExtension;
        finalOutputPath = QDir(destDirectory).filePath(finalName);
        arguments<<"-i" << SourceFileName[0] << "-y" <<"-an" << "-acodec" << "copy" << finalOutputPath;

    } else {
        ui->ConvertResultEdit->setText("Huh, something went wrong!");
    }

    //Begin conversion process and end function. Runs in the "background." Uses Slots/Signals to notify GUI when done
    myprocess->start(ffmpegPath,arguments);
    ui->ConvertResultEdit->setText("Conversion has begun for: " + finalName);
}


void MainWindow::progress() {
    QProcessOutput = QString(myprocess->readAllStandardError());
    durResult = duration.indexIn(QProcessOutput);
    timeResult = time.indexIn(QProcessOutput);

    if (durResult > -1) {
        //enters if able to find Duration time of video. Will then convert to total seconds and adjusts progress bar
        bool ok;
        int durationHours = duration.cap(1).toInt(&ok,10);
        int durationMinutes = duration.cap(2).toInt(&ok,10);
        int durationSeconds = duration.cap(3).toInt(&ok,10);
        int totalDurationSeconds = durationHours*3600 + durationMinutes*60 + durationSeconds*1;
        ui->progressBar->setMaximum(totalDurationSeconds);

    }

    if (timeResult > -1) {
        //Entered if current time of conversion occurs. Converts to total seconds and adjusts progress bar
        bool ok;
        int timeHours = time.cap(1).toInt(&ok,10);
        int timeMinutes = time.cap(2).toInt(&ok,10);
        int timeSeconds = time.cap(3).toInt(&ok,10);
        int totalTimeSeconds = timeHours*3600 + timeMinutes*60 + timeSeconds*1;
        ui->progressBar->setValue(totalTimeSeconds);
    }
    ui->textBrowser->append(QProcessOutput);
}
void MainWindow::complete() {
    ui->ConvertButton->setEnabled(true);
    ui->progressBar->setValue(0);
    ui->ConvertResultEdit->setText("You've finished converting:  " + finalName);
}



