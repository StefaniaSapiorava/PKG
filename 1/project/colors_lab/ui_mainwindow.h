/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QSlider *horizontalSlider_1;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_6;
    QSlider *horizontalSlider_5;
    QSlider *horizontalSlider_7;
    QSlider *horizontalSlider_8;
    QSlider *horizontalSlider_10;
    QSlider *horizontalSlider_9;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_10;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_14;
    QSlider *horizontalSlider_16;
    QSlider *horizontalSlider_15;
    QSlider *horizontalSlider_14;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_13;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_14;
    QLabel *label_17;
    QLabel *label_19;
    QLabel *label_18;
    QSlider *horizontalSlider_17;
    QSlider *horizontalSlider_18;
    QSlider *horizontalSlider_19;
    QSlider *horizontalSlider_11;
    QSlider *horizontalSlider_13;
    QSlider *horizontalSlider_12;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(470, 643);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(470, 0));
        MainWindow->setMaximumSize(QSize(470, 1000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 10, 81, 81));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(230, 40, 151, 24));
        horizontalSlider_1 = new QSlider(centralwidget);
        horizontalSlider_1->setObjectName("horizontalSlider_1");
        horizontalSlider_1->setGeometry(QRect(50, 170, 255, 15));
        horizontalSlider_1->setMaximum(255);
        horizontalSlider_1->setValue(255);
        horizontalSlider_1->setSliderPosition(255);
        horizontalSlider_1->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(50, 210, 255, 15));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setValue(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(centralwidget);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setGeometry(QRect(50, 250, 255, 15));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setValue(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 200, 9, 38));
        label_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 160, 9, 38));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 240, 9, 38));
        label_3->setAlignment(Qt::AlignCenter);
        lineEdit_1 = new QLineEdit(centralwidget);
        lineEdit_1->setObjectName("lineEdit_1");
        lineEdit_1->setGeometry(QRect(310, 170, 79, 24));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(310, 240, 79, 24));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(310, 200, 79, 24));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 440, 9, 38));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(32, 474, 9, 38));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 520, 9, 38));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 550, 9, 38));
        label_10->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 310, 9, 38));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 350, 9, 38));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 380, 9, 38));
        label_6->setAlignment(Qt::AlignCenter);
        horizontalSlider_4 = new QSlider(centralwidget);
        horizontalSlider_4->setObjectName("horizontalSlider_4");
        horizontalSlider_4->setGeometry(QRect(50, 320, 255, 15));
        horizontalSlider_4->setMaximum(100);
        horizontalSlider_4->setValue(100);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        horizontalSlider_6 = new QSlider(centralwidget);
        horizontalSlider_6->setObjectName("horizontalSlider_6");
        horizontalSlider_6->setGeometry(QRect(50, 390, 255, 15));
        horizontalSlider_6->setMinimum(-128);
        horizontalSlider_6->setMaximum(128);
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        horizontalSlider_5 = new QSlider(centralwidget);
        horizontalSlider_5->setObjectName("horizontalSlider_5");
        horizontalSlider_5->setGeometry(QRect(50, 360, 255, 15));
        horizontalSlider_5->setMinimum(-128);
        horizontalSlider_5->setMaximum(128);
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        horizontalSlider_7 = new QSlider(centralwidget);
        horizontalSlider_7->setObjectName("horizontalSlider_7");
        horizontalSlider_7->setGeometry(QRect(51, 452, 255, 15));
        horizontalSlider_7->setMaximum(100);
        horizontalSlider_7->setOrientation(Qt::Horizontal);
        horizontalSlider_8 = new QSlider(centralwidget);
        horizontalSlider_8->setObjectName("horizontalSlider_8");
        horizontalSlider_8->setGeometry(QRect(50, 490, 255, 15));
        horizontalSlider_8->setMaximum(100);
        horizontalSlider_8->setOrientation(Qt::Horizontal);
        horizontalSlider_10 = new QSlider(centralwidget);
        horizontalSlider_10->setObjectName("horizontalSlider_10");
        horizontalSlider_10->setGeometry(QRect(50, 560, 255, 15));
        horizontalSlider_10->setMaximum(100);
        horizontalSlider_10->setOrientation(Qt::Horizontal);
        horizontalSlider_9 = new QSlider(centralwidget);
        horizontalSlider_9->setObjectName("horizontalSlider_9");
        horizontalSlider_9->setGeometry(QRect(50, 530, 255, 15));
        horizontalSlider_9->setMaximum(100);
        horizontalSlider_9->setOrientation(Qt::Horizontal);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(310, 310, 79, 24));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(310, 350, 79, 24));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(310, 390, 79, 24));
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(310, 450, 79, 24));
        lineEdit_9 = new QLineEdit(centralwidget);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(310, 520, 79, 24));
        lineEdit_8 = new QLineEdit(centralwidget);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(310, 490, 79, 24));
        lineEdit_10 = new QLineEdit(centralwidget);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(310, 550, 79, 24));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(542, 346, 9, 38));
        label_16->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(542, 324, 9, 38));
        label_15->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(542, 302, 9, 38));
        label_14->setAlignment(Qt::AlignCenter);
        horizontalSlider_16 = new QSlider(centralwidget);
        horizontalSlider_16->setObjectName("horizontalSlider_16");
        horizontalSlider_16->setGeometry(QRect(570, 370, 255, 15));
        horizontalSlider_16->setMinimum(0);
        horizontalSlider_16->setMaximum(100);
        horizontalSlider_16->setValue(100);
        horizontalSlider_16->setOrientation(Qt::Horizontal);
        horizontalSlider_15 = new QSlider(centralwidget);
        horizontalSlider_15->setObjectName("horizontalSlider_15");
        horizontalSlider_15->setGeometry(QRect(570, 340, 255, 15));
        horizontalSlider_15->setMinimum(0);
        horizontalSlider_15->setMaximum(100);
        horizontalSlider_15->setValue(0);
        horizontalSlider_15->setOrientation(Qt::Horizontal);
        horizontalSlider_14 = new QSlider(centralwidget);
        horizontalSlider_14->setObjectName("horizontalSlider_14");
        horizontalSlider_14->setGeometry(QRect(570, 310, 255, 15));
        horizontalSlider_14->setMaximum(360);
        horizontalSlider_14->setValue(0);
        horizontalSlider_14->setSliderPosition(0);
        horizontalSlider_14->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(542, 174, 9, 38));
        label_12->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(542, 152, 9, 38));
        label_11->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(542, 196, 9, 38));
        label_13->setAlignment(Qt::AlignCenter);
        lineEdit_15 = new QLineEdit(centralwidget);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(830, 330, 79, 24));
        lineEdit_16 = new QLineEdit(centralwidget);
        lineEdit_16->setObjectName("lineEdit_16");
        lineEdit_16->setGeometry(QRect(830, 360, 79, 24));
        lineEdit_14 = new QLineEdit(centralwidget);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(830, 300, 79, 24));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(542, 452, 9, 38));
        label_17->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(542, 496, 9, 38));
        label_19->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(542, 474, 9, 38));
        label_18->setAlignment(Qt::AlignCenter);
        horizontalSlider_17 = new QSlider(centralwidget);
        horizontalSlider_17->setObjectName("horizontalSlider_17");
        horizontalSlider_17->setGeometry(QRect(570, 440, 255, 15));
        horizontalSlider_17->setMaximum(109);
        horizontalSlider_17->setValue(95);
        horizontalSlider_17->setSliderPosition(95);
        horizontalSlider_17->setOrientation(Qt::Horizontal);
        horizontalSlider_18 = new QSlider(centralwidget);
        horizontalSlider_18->setObjectName("horizontalSlider_18");
        horizontalSlider_18->setGeometry(QRect(570, 470, 255, 15));
        horizontalSlider_18->setMaximum(109);
        horizontalSlider_18->setValue(100);
        horizontalSlider_18->setOrientation(Qt::Horizontal);
        horizontalSlider_19 = new QSlider(centralwidget);
        horizontalSlider_19->setObjectName("horizontalSlider_19");
        horizontalSlider_19->setGeometry(QRect(570, 510, 255, 15));
        horizontalSlider_19->setMaximum(109);
        horizontalSlider_19->setValue(108);
        horizontalSlider_19->setOrientation(Qt::Horizontal);
        horizontalSlider_11 = new QSlider(centralwidget);
        horizontalSlider_11->setObjectName("horizontalSlider_11");
        horizontalSlider_11->setGeometry(QRect(570, 160, 255, 15));
        horizontalSlider_11->setMaximum(360);
        horizontalSlider_11->setValue(100);
        horizontalSlider_11->setSliderPosition(100);
        horizontalSlider_11->setOrientation(Qt::Horizontal);
        horizontalSlider_13 = new QSlider(centralwidget);
        horizontalSlider_13->setObjectName("horizontalSlider_13");
        horizontalSlider_13->setGeometry(QRect(570, 220, 255, 15));
        horizontalSlider_13->setMaximum(100);
        horizontalSlider_13->setValue(0);
        horizontalSlider_13->setOrientation(Qt::Horizontal);
        horizontalSlider_12 = new QSlider(centralwidget);
        horizontalSlider_12->setObjectName("horizontalSlider_12");
        horizontalSlider_12->setGeometry(QRect(570, 190, 255, 15));
        horizontalSlider_12->setMaximum(100);
        horizontalSlider_12->setValue(0);
        horizontalSlider_12->setOrientation(Qt::Horizontal);
        lineEdit_11 = new QLineEdit(centralwidget);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(830, 150, 79, 24));
        lineEdit_13 = new QLineEdit(centralwidget);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(830, 210, 79, 24));
        lineEdit_12 = new QLineEdit(centralwidget);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(830, 180, 79, 24));
        lineEdit_17 = new QLineEdit(centralwidget);
        lineEdit_17->setObjectName("lineEdit_17");
        lineEdit_17->setGeometry(QRect(830, 440, 79, 24));
        lineEdit_18 = new QLineEdit(centralwidget);
        lineEdit_18->setObjectName("lineEdit_18");
        lineEdit_18->setGeometry(QRect(830, 470, 79, 24));
        lineEdit_19 = new QLineEdit(centralwidget);
        lineEdit_19->setObjectName("lineEdit_19");
        lineEdit_19->setGeometry(QRect(830, 500, 79, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 470, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Choose color", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        lineEdit_1->setText(QCoreApplication::translate("MainWindow", "255", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "255", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "255", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "M", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "S", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "S", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        lineEdit_15->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_16->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        lineEdit_14->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_17->setText(QCoreApplication::translate("MainWindow", "95", nullptr));
        lineEdit_18->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        lineEdit_19->setText(QCoreApplication::translate("MainWindow", "108", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
