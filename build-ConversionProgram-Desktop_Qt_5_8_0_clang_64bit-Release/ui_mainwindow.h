/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *VideoSourceButton;
    QLabel *fullOutputConversion;
    QProgressBar *progressBar;
    QTextBrowser *textBrowser;
    QPushButton *VideoDestination;
    QLineEdit *VideoDestinationEdit;
    QLineEdit *ConvertResultEdit;
    QLabel *label;
    QComboBox *filterOptions;
    QPushButton *ConvertButton;
    QLabel *conversionStatus;
    QLineEdit *VideoSourceEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(579, 446);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(579, 446));
        MainWindow->setMaximumSize(QSize(582, 447));
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 556, 388));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        VideoSourceButton = new QPushButton(layoutWidget);
        VideoSourceButton->setObjectName(QStringLiteral("VideoSourceButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(VideoSourceButton->sizePolicy().hasHeightForWidth());
        VideoSourceButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(VideoSourceButton, 0, 0, 1, 1);

        fullOutputConversion = new QLabel(layoutWidget);
        fullOutputConversion->setObjectName(QStringLiteral("fullOutputConversion"));

        gridLayout->addWidget(fullOutputConversion, 5, 1, 1, 1);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setMaximum(100);
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 4, 0, 1, 3);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(textBrowser, 6, 0, 1, 3);

        VideoDestination = new QPushButton(layoutWidget);
        VideoDestination->setObjectName(QStringLiteral("VideoDestination"));
        VideoDestination->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(VideoDestination->sizePolicy().hasHeightForWidth());
        VideoDestination->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(VideoDestination, 1, 0, 1, 1);

        VideoDestinationEdit = new QLineEdit(layoutWidget);
        VideoDestinationEdit->setObjectName(QStringLiteral("VideoDestinationEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(VideoDestinationEdit->sizePolicy().hasHeightForWidth());
        VideoDestinationEdit->setSizePolicy(sizePolicy4);
        VideoDestinationEdit->setReadOnly(false);

        gridLayout->addWidget(VideoDestinationEdit, 1, 1, 1, 2);

        ConvertResultEdit = new QLineEdit(layoutWidget);
        ConvertResultEdit->setObjectName(QStringLiteral("ConvertResultEdit"));
        ConvertResultEdit->setReadOnly(true);

        gridLayout->addWidget(ConvertResultEdit, 3, 1, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        filterOptions = new QComboBox(layoutWidget);
        filterOptions->setObjectName(QStringLiteral("filterOptions"));
        filterOptions->setEnabled(true);
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(filterOptions->sizePolicy().hasHeightForWidth());
        filterOptions->setSizePolicy(sizePolicy6);
        filterOptions->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(filterOptions, 2, 1, 1, 1);

        ConvertButton = new QPushButton(layoutWidget);
        ConvertButton->setObjectName(QStringLiteral("ConvertButton"));
        ConvertButton->setEnabled(false);
        ConvertButton->setAutoFillBackground(false);

        gridLayout->addWidget(ConvertButton, 2, 2, 1, 1);

        conversionStatus = new QLabel(layoutWidget);
        conversionStatus->setObjectName(QStringLiteral("conversionStatus"));

        gridLayout->addWidget(conversionStatus, 3, 0, 1, 1);

        VideoSourceEdit = new QLineEdit(layoutWidget);
        VideoSourceEdit->setObjectName(QStringLiteral("VideoSourceEdit"));
        sizePolicy4.setHeightForWidth(VideoSourceEdit->sizePolicy().hasHeightForWidth());
        VideoSourceEdit->setSizePolicy(sizePolicy4);
        VideoSourceEdit->setReadOnly(false);

        gridLayout->addWidget(VideoSourceEdit, 0, 1, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        filterOptions->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Conversion", Q_NULLPTR));
        VideoSourceButton->setText(QApplication::translate("MainWindow", "Video Source", Q_NULLPTR));
        fullOutputConversion->setText(QApplication::translate("MainWindow", "    Full Output of Conversion", Q_NULLPTR));
        VideoDestination->setText(QApplication::translate("MainWindow", "Video Destination", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "       Filter Options", Q_NULLPTR));
        filterOptions->clear();
        filterOptions->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Sepia", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Black and White", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Audio", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Video", Q_NULLPTR)
        );
        ConvertButton->setText(QApplication::translate("MainWindow", "Convert", Q_NULLPTR));
        conversionStatus->setText(QApplication::translate("MainWindow", "    Conversion Status", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
