#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>
#include <QColorDialog>
#include <QString>
#include <QSlider>
#include <QLineEdit>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("1.RGB-LAB-CMYK");
    ui->comboBox->addItem("2.RGB-CMYK-HLS");
    ui->comboBox->addItem("3.RGB-XYZ-LAB");
    ui->comboBox->addItem("4.RGB-HSV-LAB");
    ui->comboBox->addItem("5.CMYK-LAB-HSV");
    ui->comboBox->addItem("6.CMYK-RGB-HLS");
    ui->comboBox->addItem("7.CMYK-RGB-HSV");
    ui->comboBox->addItem("8.RGB-XYZ-HSV");
    ui->comboBox->addItem("9.HSV-XYZ-LAB");
    ui->comboBox->addItem("10.CMYK-LAB-RGB");
    ui->comboBox->addItem("11.XYZ-LAB-HLS");
    ui->comboBox->addItem("12.RGB-XYZ-HLS");
    ui->comboBox->addItem("13.RGB-XYZ-CMYK");
    ui->comboBox->addItem("14.CMYK-LAB-XYZ");
    ui->comboBox->addItem("15.RGB-CMYK-HSV");
    ui->comboBox->addItem("16.CMYK-HLS-XYZ");
    ui->comboBox->addItem("17.RGB-HLS-LAB");
    ui->comboBox->addItem("18.CMYK-XYZ-RGB");

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));

    setStartVisual();

    connect(ui->horizontalSlider_1,&QSlider::sliderMoved,this,[=]{rgbChanchedByLineR(); fromRGBtoCMYK(); fromRGBtoXYZ(); fromRGBtoHSV(); fromRGBtoHSL();});
    connect(ui->lineEdit_1,&QLineEdit::textChanged,this,[=]{rgbChangedByEditR();fromRGBtoCMYK(); fromRGBtoXYZ(); fromRGBtoHSV(); fromRGBtoHSL();});
    connect(ui->horizontalSlider_2,&QSlider::sliderMoved,this,[=]{rgbChanchedByLineG();fromRGBtoCMYK(); fromRGBtoXYZ();fromRGBtoHSV();fromRGBtoHSL();});
    connect(ui->lineEdit_2,&QLineEdit::textChanged,this,[=]{rgbChangedByEditG();fromRGBtoCMYK(); fromRGBtoXYZ(); fromRGBtoHSV(); fromRGBtoHSL();});
    connect(ui->horizontalSlider_3,&QSlider::sliderMoved,this,[=]{rgbChanchedByLineB();fromRGBtoCMYK();fromRGBtoXYZ();fromRGBtoHSV();fromRGBtoHSL();});
    connect(ui->lineEdit_3,&QLineEdit::textChanged,this,[=]{rgbChangedByEditB();fromRGBtoCMYK(); fromRGBtoXYZ(); fromRGBtoHSV(); fromRGBtoHSL();});

    connect(ui->horizontalSlider_7,&QSlider::sliderMoved,this,[=]{cmykChanchedByLineC();fromCMYKtoRGB();});
    connect(ui->lineEdit_7,&QLineEdit::textChanged,this,[=]{cmykChangedByEditC();fromCMYKtoRGB();});
    connect(ui->horizontalSlider_8,&QSlider::sliderMoved,this,[=]{cmykChanchedByLineM();fromCMYKtoRGB();});
    connect(ui->lineEdit_8,&QLineEdit::textChanged,this,[=]{cmykChangedByEditM();fromCMYKtoRGB();});
    connect(ui->horizontalSlider_9,&QSlider::sliderMoved,this,[=]{cmykChanchedByLineY();fromCMYKtoRGB();});
    connect(ui->lineEdit_9,&QLineEdit::textChanged,this,[=]{cmykChangedByEditY();fromCMYKtoRGB();});
    connect(ui->horizontalSlider_10,&QSlider::sliderMoved,this,[=]{cmykChanchedByLineK();fromCMYKtoRGB();});
    connect(ui->lineEdit_10,&QLineEdit::textChanged,this,[=]{cmykChangedByEditK();fromCMYKtoRGB();});

    connect(ui->horizontalSlider_4,&QSlider::sliderMoved,this,[=]{labChanchedByLineL(); fromLABtoXYZ();});
    connect(ui->lineEdit_4,&QLineEdit::textChanged,this,[=]{labChangedByEditL();fromLABtoXYZ();});
    connect(ui->horizontalSlider_5,&QSlider::sliderMoved,this,[=]{labChanchedByLineA();fromLABtoXYZ();});
    connect(ui->lineEdit_5,&QLineEdit::textChanged,this,[=]{labChangedByEditA();fromLABtoXYZ();});
    connect(ui->horizontalSlider_6,&QSlider::sliderMoved,this,[=]{labChanchedByLineB();fromLABtoXYZ();});
    connect(ui->lineEdit_6,&QLineEdit::textChanged,this,[=]{labChangedByEditB();fromLABtoXYZ();});

    connect(ui->horizontalSlider_17,&QSlider::sliderMoved,this,[=]{xyzChanchedByLineX(); fromXYZtoRGB(); fromXYZtoLAB();});
    connect(ui->lineEdit_17,&QLineEdit::textChanged,this,[=]{xyzChangedByEditX();fromXYZtoRGB(); fromXYZtoLAB();});
    connect(ui->horizontalSlider_18,&QSlider::sliderMoved,this,[=]{xyzChanchedByLineY();fromXYZtoRGB();fromXYZtoLAB();});
    connect(ui->lineEdit_18,&QLineEdit::textChanged,this,[=]{xyzChangedByEditY();fromXYZtoRGB(); fromXYZtoLAB();});
    connect(ui->horizontalSlider_19,&QSlider::sliderMoved,this,[=]{xyzChanchedByLineZ();fromXYZtoRGB();fromXYZtoLAB();});
    connect(ui->lineEdit_19,&QLineEdit::textChanged,this,[=]{xyzChangedByEditZ();fromXYZtoRGB(); fromXYZtoLAB();});

    connect(ui->horizontalSlider_11,&QSlider::sliderMoved,this,[=]{hlsChanchedByLine(); fromHSLtoRGB();});
    connect(ui->lineEdit_11,&QLineEdit::textChanged,this,[=]{hlsChangedByEdit();fromHSLtoRGB();});
    connect(ui->horizontalSlider_12,&QSlider::sliderMoved,this,[=]{hlsChanchedByLine();fromHSLtoRGB();});
    connect(ui->lineEdit_12,&QLineEdit::textChanged,this,[=]{hlsChangedByEdit();fromHSLtoRGB();});
    connect(ui->horizontalSlider_13,&QSlider::sliderMoved,this,[=]{hlsChanchedByLine();fromHSLtoRGB();});
    connect(ui->lineEdit_13,&QLineEdit::textChanged,this,[=]{hlsChangedByEdit();fromHSLtoRGB();});

    connect(ui->horizontalSlider_14,&QSlider::sliderMoved,this,[=]{hsvChanchedByLine(); fromHSVtoRGB();});
    connect(ui->lineEdit_14,&QLineEdit::textChanged,this,[=]{hsvChangedByEdit();fromHSVtoRGB();});
    connect(ui->horizontalSlider_15,&QSlider::sliderMoved,this,[=]{hsvChanchedByLine(); fromHSVtoRGB();});
    connect(ui->lineEdit_15,&QLineEdit::textChanged,this,[=]{hsvChangedByEdit();fromHSVtoRGB();});
    connect(ui->horizontalSlider_16,&QSlider::sliderMoved,this,[=]{hsvChanchedByLine(); fromHSVtoRGB();});
    connect(ui->lineEdit_16,&QLineEdit::textChanged,this,[=]{hsvChangedByEdit();fromHSVtoRGB();});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    painter.setPen(QColor(0, 0, 0));
    painter.setBrush(color);
    painter.drawRect(QRect(rectX, 10, 80, 80));
}
void MainWindow::indexChanged(int index)
{
    if(index == 0){
        rgbInWindow(1);
        labInWindow(2);
        cmykInWindow(3);
        hsvInWindow(4);
        hslInWindow(4);
        xyzInWindow(4);
    }
    if(index == 1){
        rgbInWindow(1);
        labInWindow(4);
        cmykInWindow(2);
        hsvInWindow(4);
        hslInWindow(3);
        xyzInWindow(4);
    }
    if(index == 2){
        rgbInWindow(1);
        labInWindow(3);
        cmykInWindow(4);
        hsvInWindow(4);
        hslInWindow(4);
        xyzInWindow(2);
    }
    if(index == 3){
        rgbInWindow(1);
        labInWindow(3);
        cmykInWindow(4);
        hsvInWindow(2);
        hslInWindow(4);
        xyzInWindow(4);
    }
    if(index == 4){
        rgbInWindow(4);
        labInWindow(2);
        cmykInWindow(1);
        hsvInWindow(3);
        hslInWindow(4);
        xyzInWindow(4);
    }
    if(index == 5){
        rgbInWindow(2);
        labInWindow(4);
        cmykInWindow(1);
        hsvInWindow(4);
        hslInWindow(3);
        xyzInWindow(4);
    }
    if(index == 6){
        rgbInWindow(2);
        labInWindow(4);
        cmykInWindow(1);
        hsvInWindow(3);
        hslInWindow(4);
        xyzInWindow(4);
    }
    if(index == 7){
        rgbInWindow(1);
        labInWindow(4);
        cmykInWindow(4);
        hsvInWindow(3);
        hslInWindow(4);
        xyzInWindow(2);
    }
    if(index == 8){
        rgbInWindow(4);
        labInWindow(3);
        cmykInWindow(4);
        hsvInWindow(1);
        hslInWindow(4);
        xyzInWindow(2);
    }
    if(index == 9){
        rgbInWindow(3);
        labInWindow(2);
        cmykInWindow(1);
        hsvInWindow(4);
        hslInWindow(4);
        xyzInWindow(4);
    }
    if(index == 10){
        rgbInWindow(4);
        labInWindow(2);
        cmykInWindow(4);
        hsvInWindow(4);
        hslInWindow(3);
        xyzInWindow(1);
    }
    if(index == 11){
        rgbInWindow(1);
        labInWindow(4);
        cmykInWindow(4);
        hsvInWindow(4);
        hslInWindow(3);
        xyzInWindow(2);
    }
    if(index == 12){
        rgbInWindow(1);
        labInWindow(4);
        cmykInWindow(3);
        hsvInWindow(4);
        hslInWindow(4);
        xyzInWindow(2);
    }
    if(index == 13){
        rgbInWindow(4);
        labInWindow(2);
        cmykInWindow(1);
        hsvInWindow(4);
        hslInWindow(4);
        xyzInWindow(3);
    }
    if(index == 14){
        rgbInWindow(1);
        labInWindow(4);
        cmykInWindow(2);
        hsvInWindow(3);
        hslInWindow(4);
        xyzInWindow(4);
    }
    if(index == 15){
        rgbInWindow(4);
        labInWindow(4);
        cmykInWindow(1);
        hsvInWindow(4);
        hslInWindow(2);
        xyzInWindow(3);
    }
    if(index == 16){
        rgbInWindow(1);
        labInWindow(3);
        cmykInWindow(4);
        hsvInWindow(4);
        hslInWindow(2);
        xyzInWindow(4);
    }
    if(index == 17){
        rgbInWindow(3);
        labInWindow(4);
        cmykInWindow(1);
        hsvInWindow(4);
        hslInWindow(4);
        xyzInWindow(2);
    }
}

void MainWindow::on_pushButton_clicked()
{
    QColorDialog *colordialog = new QColorDialog;
    color = QColorDialog::getColor();
    rValueRGB = color.red();
    gValueRGB = color.green();
    bValueRGB = color.blue();
    setRGBvalues();
    fromRGBtoCMYK();
    fromRGBtoXYZ();
    fromRGBtoHSV();
    fromRGBtoHSL();
}

void MainWindow::setRGBvalues()
{
    ui->lineEdit_1->blockSignals(true);
    ui->lineEdit_2->blockSignals(true);
    ui->lineEdit_3->blockSignals(true);
    color = QColor(rValueRGB, gValueRGB, bValueRGB);
    if(rValueRGB > 255){
        ui->horizontalSlider_1->setValue(255);
        ui->lineEdit_1->setText(QString::number(255));
    }else if(rValueRGB < 0){
        ui->horizontalSlider_1->setValue(0);
        ui->lineEdit_1->setText(QString::number(0));
    }else{
        ui->horizontalSlider_1->setValue(rValueRGB);
        ui->lineEdit_1->setText(QString::number(rValueRGB));
    }
    if(gValueRGB > 255){
        ui->horizontalSlider_2->setValue(255);
        ui->lineEdit_2->setText(QString::number(255));
    }else if(gValueRGB < 0){
        ui->horizontalSlider_2->setValue(0);
        ui->lineEdit_2->setText(QString::number(0));
    }else{
        ui->horizontalSlider_2->setValue(gValueRGB);
        ui->lineEdit_2->setText(QString::number(gValueRGB));
    }
    if(bValueRGB > 255){
        ui->horizontalSlider_3->setValue(255);
        ui->lineEdit_3->setText(QString::number(255));
    }else if(bValueRGB < 0){
        ui->horizontalSlider_3->setValue(0);
        ui->lineEdit_3->setText(QString::number(0));
    }else{
        ui->horizontalSlider_3->setValue(bValueRGB);
        ui->lineEdit_3->setText(QString::number(bValueRGB));
    }
    ui->lineEdit_1->blockSignals(false);
    ui->lineEdit_2->blockSignals(false);
    ui->lineEdit_3->blockSignals(false);
}

void MainWindow::setLABvalues()
{
    ui->lineEdit_4->blockSignals(true);
    ui->lineEdit_5->blockSignals(true);
    ui->lineEdit_6->blockSignals(true);
    if(lValueLAB > 100){
        ui->horizontalSlider_4->setValue(100);
        ui->lineEdit_4->setText(QString::number(100));
    }else if(lValueLAB < 0){
        ui->horizontalSlider_4->setValue(0);
        ui->lineEdit_4->setText(QString::number(0));
    }else{
        ui->horizontalSlider_4->setValue(lValueLAB);
        ui->lineEdit_4->setText(QString::number(lValueLAB));
    }
    if(aValueLAB > 128){
        ui->horizontalSlider_5->setValue(128);
        ui->lineEdit_5->setText(QString::number(128));
    }else if(aValueLAB < -128){
        ui->horizontalSlider_5->setValue(-128);
        ui->lineEdit_5->setText(QString::number(-128));
    }else{
        ui->horizontalSlider_5->setValue(aValueLAB);
        ui->lineEdit_5->setText(QString::number(aValueLAB));
    }
    if(bValueLAB > 128){
        ui->horizontalSlider_6->setValue(128);
        ui->lineEdit_6->setText(QString::number(128));
    }else if(bValueLAB < -128){
        ui->horizontalSlider_6->setValue(-128);
        ui->lineEdit_6->setText(QString::number(-128));
    }else{
        ui->horizontalSlider_6->setValue(bValueLAB);
        ui->lineEdit_6->setText(QString::number(bValueLAB));
    }
    ui->lineEdit_4->blockSignals(false);
    ui->lineEdit_5->blockSignals(false);
    ui->lineEdit_6->blockSignals(false);
}

void MainWindow::setCMYKvalues()
{
    ui->lineEdit_7->blockSignals(true);
    ui->lineEdit_8->blockSignals(true);
    ui->lineEdit_9->blockSignals(true);
    ui->lineEdit_10->blockSignals(true);
    if(cValueCMYK > 100){
        ui->lineEdit_7->setText(QString::number(100));
        ui->horizontalSlider_7->setValue(100);
    }else if(cValueCMYK < 0){
        ui->lineEdit_7->setText(QString::number(0));
        ui->horizontalSlider_7->setValue(0);
    }else{
        ui->lineEdit_7->setText(QString::number(cValueCMYK));
        ui->horizontalSlider_7->setValue(cValueCMYK);
    }
    if(mValueCMYK > 100){
        ui->lineEdit_8->setText(QString::number(100));
        ui->horizontalSlider_8->setValue(100);
    }else if(mValueCMYK < 0){
        ui->lineEdit_8->setText(QString::number(0));
        ui->horizontalSlider_8->setValue(0);
    }else{
        ui->lineEdit_8->setText(QString::number(mValueCMYK));
        ui->horizontalSlider_8->setValue(mValueCMYK);
    }
    if(yValueCMYK > 100){
        ui->lineEdit_9->setText(QString::number(100));
        ui->horizontalSlider_9->setValue(100);
    }else if(yValueCMYK < 0){
        ui->lineEdit_9->setText(QString::number(0));
        ui->horizontalSlider_9->setValue(0);
    }else{
        ui->lineEdit_9->setText(QString::number(yValueCMYK));
        ui->horizontalSlider_9->setValue(yValueCMYK);
    }
    if(kValueCMYK > 100){
        ui->lineEdit_10->setText(QString::number(100));
        ui->horizontalSlider_10->setValue(100);
    }else if(kValueCMYK < 0){
        ui->lineEdit_10->setText(QString::number(0));
        ui->horizontalSlider_10->setValue(0);
    }else{
        ui->lineEdit_10->setText(QString::number(kValueCMYK));
        ui->horizontalSlider_10->setValue(kValueCMYK);
    }
    ui->lineEdit_7->blockSignals(false);
    ui->lineEdit_8->blockSignals(false);
    ui->lineEdit_9->blockSignals(false);
    ui->lineEdit_10->blockSignals(false);
}

void MainWindow::setXYZvalues()
{
    ui->lineEdit_17->blockSignals(true);
    ui->lineEdit_18->blockSignals(true);
    ui->lineEdit_19->blockSignals(true);
    if(xValueXYZ > 109){
        ui->horizontalSlider_17->setValue(109);
        ui->lineEdit_17->setText(QString::number(109));
    }else if(xValueXYZ < 0){
        ui->horizontalSlider_17->setValue(0);
        ui->lineEdit_17->setText(QString::number(0));
    }else{
        ui->horizontalSlider_17->setValue(xValueXYZ);
        ui->lineEdit_17->setText(QString::number(xValueXYZ));
    }
    if(yValueXYZ > 109){
        ui->horizontalSlider_18->setValue(109);
        ui->lineEdit_18->setText(QString::number(109));
    }else if(yValueXYZ < 0){
        ui->horizontalSlider_18->setValue(0);
        ui->lineEdit_18->setText(QString::number(0));
    }else{
        ui->horizontalSlider_18->setValue(yValueXYZ);
        ui->lineEdit_18->setText(QString::number(yValueXYZ));
    }
    if(zValueXYZ > 109){
        ui->horizontalSlider_19->setValue(109);
        ui->lineEdit_19->setText(QString::number(109));
    }else if(zValueXYZ < 0){
        ui->horizontalSlider_19->setValue(0);
        ui->lineEdit_19->setText(QString::number(0));
    }else{
        ui->horizontalSlider_19->setValue(zValueXYZ);
        ui->lineEdit_19->setText(QString::number(zValueXYZ));
    }
    ui->lineEdit_17->blockSignals(false);
    ui->lineEdit_18->blockSignals(false);
    ui->lineEdit_19->blockSignals(false);
}

void MainWindow::setHSVvalues()
{
    ui->lineEdit_14->blockSignals(true);
    ui->lineEdit_15->blockSignals(true);
    ui->lineEdit_16->blockSignals(true);
    if(hValueHSV > 360){
        ui->horizontalSlider_14->setValue(360);
        ui->lineEdit_14->setText(QString::number(360));
    }else if(hValueHSV < 0){
        ui->horizontalSlider_14->setValue(0);
        ui->lineEdit_14->setText(QString::number(0));
    }else{
        ui->horizontalSlider_14->setValue(hValueHSV);
        ui->lineEdit_14->setText(QString::number(hValueHSV));
    }
    if(sValueHSV > 100){
        ui->horizontalSlider_15->setValue(100);
        ui->lineEdit_15->setText(QString::number(100));
    }else if(sValueHSV < 0){
        ui->horizontalSlider_15->setValue(0);
        ui->lineEdit_15->setText(QString::number(0));
    }else{
        ui->horizontalSlider_15->setValue(sValueHSV);
        ui->lineEdit_15->setText(QString::number(sValueHSV));
    }
    if(vValueHSV > 100){
        ui->horizontalSlider_16->setValue(100);
        ui->lineEdit_16->setText(QString::number(100));
    }else if(vValueHSV < 0){
        ui->horizontalSlider_16->setValue(0);
        ui->lineEdit_16->setText(QString::number(0));
    }else{
        ui->horizontalSlider_16->setValue(vValueHSV);
        ui->lineEdit_16->setText(QString::number(vValueHSV));
    }
    ui->lineEdit_14->blockSignals(false);
    ui->lineEdit_15->blockSignals(false);
    ui->lineEdit_16->blockSignals(false);
}

void MainWindow::setHSLvalues()
{
    ui->lineEdit_11->blockSignals(true);
    ui->lineEdit_12->blockSignals(true);
    ui->lineEdit_13->blockSignals(true);
    if(hValueHSL > 360){
        ui->horizontalSlider_11->setValue(360);
        ui->lineEdit_11->setText(QString::number(360));
    }else if(hValueHSL < 0){
        ui->horizontalSlider_11->setValue(0);
        ui->lineEdit_11->setText(QString::number(0));
    }else{
        ui->horizontalSlider_11->setValue(hValueHSL);
        ui->lineEdit_11->setText(QString::number(hValueHSL));
    }
    if(sValueHSL > 100){
        ui->horizontalSlider_12->setValue(100);
        ui->lineEdit_12->setText(QString::number(100));
    }else if(sValueHSL < 0){
        ui->horizontalSlider_12->setValue(0);
        ui->lineEdit_12->setText(QString::number(0));
    }else{
        ui->horizontalSlider_12->setValue(sValueHSL);
        ui->lineEdit_12->setText(QString::number(sValueHSL));
    }
    if(lValueHSL > 100){
        ui->horizontalSlider_13->setValue(100);
        ui->lineEdit_13->setText(QString::number(100));
    }else if(lValueHSL < 0){
        ui->horizontalSlider_13->setValue(0);
        ui->lineEdit_13->setText(QString::number(0));
    }else{
        ui->horizontalSlider_13->setValue(lValueHSL);
        ui->lineEdit_13->setText(QString::number(lValueHSL));
    }
    ui->lineEdit_11->blockSignals(false);
    ui->lineEdit_12->blockSignals(false);
    ui->lineEdit_13->blockSignals(false);
}

void MainWindow::setStartVisual()
{
    rgbInWindow(1);
    labInWindow(2);
    cmykInWindow(3);
    hslInWindow(4);
    hsvInWindow(4);
    xyzInWindow(4);
}

void MainWindow::rgbInWindow(int pos)
{
    int posX, posY;
    if(pos == 1){
        posX = firstX;
        posY = firstY;
    }
    if(pos == 2){
        posX = secondX;
        posY = secondY;
    }
    if(pos == 3){
        posX = thirdX;
        posY = thirdY;
    }
    if(pos == 4){
        posX = 10000;
        posY = 10000;
    }
    ui->label->move(posX, posY);
    ui->label_2->move(posX, posY + labelHeight);
    ui->label_3->move(posX, posY + 2*labelHeight);
    ui->horizontalSlider_1->move(posX + labelWidth, posY + 13);
    ui->horizontalSlider_2->move(posX + labelWidth, posY + labelHeight + 13);
    ui->horizontalSlider_3->move(posX + labelWidth, posY + 2*labelHeight + 13);
    ui->lineEdit_1->move(posX + labelWidth + lineWidth, posY + 6);
    ui->lineEdit_2->move(posX + labelWidth + lineWidth, posY + labelHeight + 6);
    ui->lineEdit_3->move(posX + labelWidth + lineWidth, posY + 2*labelHeight + 6);
}

void MainWindow::cmykInWindow(int pos)
{
    int posX, posY;
    if(pos == 1){
        posX = firstX;
        posY = firstY;
    }
    if(pos == 2){
        posX = secondX;
        posY = secondY;
    }
    if(pos == 3){
        posX = thirdX;
        posY = thirdY;
    }
    if(pos == 4){
        posX = 10000;
        posY = 10000;
    }
    ui->label_7->move(posX, posY);
    ui->label_8->move(posX, posY + labelHeight);
    ui->label_9->move(posX, posY + 2*labelHeight);
    ui->label_10->move(posX, posY + 3*labelHeight);
    ui->horizontalSlider_7->move(posX + labelWidth, posY + 13);
    ui->horizontalSlider_8->move(posX + labelWidth, posY + labelHeight + 13);
    ui->horizontalSlider_9->move(posX + labelWidth, posY + 2*labelHeight + 13);
    ui->horizontalSlider_10->move(posX + labelWidth, posY + 3*labelHeight + 13);
    ui->lineEdit_7->move(posX + labelWidth + lineWidth, posY + 6);
    ui->lineEdit_8->move(posX + labelWidth + lineWidth, posY + labelHeight + 6);
    ui->lineEdit_9->move(posX + labelWidth + lineWidth, posY + 2*labelHeight + 6);
    ui->lineEdit_10->move(posX + labelWidth + lineWidth, posY + 3*labelHeight + 6);
}

void MainWindow::labInWindow(int pos)
{
    int posX, posY;
    if(pos == 1){
        posX = firstX;
        posY = firstY;
    }
    if(pos == 2){
        posX = secondX;
        posY = secondY;
    }
    if(pos == 3){
        posX = thirdX;
        posY = thirdY;
    }
    if(pos == 4){
        posX = 10000;
        posY = 10000;
    }
    ui->label_4->move(posX, posY);
    ui->label_5->move(posX, posY + labelHeight);
    ui->label_6->move(posX, posY + 2*labelHeight);
    ui->horizontalSlider_4->move(posX + labelWidth, posY + 13);
    ui->horizontalSlider_5->move(posX + labelWidth, posY + labelHeight + 13);
    ui->horizontalSlider_6->move(posX + labelWidth, posY + 2*labelHeight + 13);
    ui->lineEdit_4->move(posX + labelWidth + lineWidth, posY + 6);
    ui->lineEdit_5->move(posX + labelWidth + lineWidth, posY + labelHeight + 6);
    ui->lineEdit_6->move(posX + labelWidth + lineWidth, posY + 2*labelHeight + 6);
}

void MainWindow::hslInWindow(int pos)
{
    int posX, posY;
    if(pos == 1){
        posX = firstX;
        posY = firstY;
    }
    if(pos == 2){
        posX = secondX;
        posY = secondY;
    }
    if(pos == 3){
        posX = thirdX;
        posY = thirdY;
    }
    if(pos == 4){
        posX = 10000;
        posY = 10000;
    }
    ui->label_11->move(posX, posY);
    ui->label_12->move(posX, posY + labelHeight);
    ui->label_13->move(posX, posY + 2*labelHeight);
    ui->horizontalSlider_11->move(posX + labelWidth, posY + 13);
    ui->horizontalSlider_12->move(posX + labelWidth, posY + labelHeight + 13);
    ui->horizontalSlider_13->move(posX + labelWidth, posY + 2*labelHeight + 13);
    ui->lineEdit_11->move(posX + labelWidth + lineWidth, posY + 6);
    ui->lineEdit_12->move(posX + labelWidth + lineWidth, posY + labelHeight + 6);
    ui->lineEdit_13->move(posX + labelWidth + lineWidth, posY + 2*labelHeight + 6);
}

void MainWindow::hsvInWindow(int pos)
{
    int posX, posY;
    if(pos == 1){
        posX = firstX;
        posY = firstY;
    }
    if(pos == 2){
        posX = secondX;
        posY = secondY;
    }
    if(pos == 3){
        posX = thirdX;
        posY = thirdY;
    }
    if(pos == 4){
        posX = 10000;
        posY = 10000;
    }
    ui->label_14->move(posX, posY);
    ui->label_15->move(posX, posY + labelHeight);
    ui->label_16->move(posX, posY + 2*labelHeight);
    ui->horizontalSlider_14->move(posX + labelWidth, posY + 13);
    ui->horizontalSlider_15->move(posX + labelWidth, posY + labelHeight + 13);
    ui->horizontalSlider_16->move(posX + labelWidth, posY + 2*labelHeight + 13);
    ui->lineEdit_14->move(posX + labelWidth + lineWidth, posY + 6);
    ui->lineEdit_15->move(posX + labelWidth + lineWidth, posY + labelHeight + 6);
    ui->lineEdit_16->move(posX + labelWidth + lineWidth, posY + 2*labelHeight + 6);
}

void MainWindow::xyzInWindow(int pos)
{
    int posX, posY;
    if(pos == 1){
        posX = firstX;
        posY = firstY;
    }
    if(pos == 2){
        posX = secondX;
        posY = secondY;
    }
    if(pos == 3){
        posX = thirdX;
        posY = thirdY;
    }
    if(pos == 4){
        posX = 10000;
        posY = 10000;
    }
    ui->label_17->move(posX, posY);
    ui->label_18->move(posX, posY + labelHeight);
    ui->label_19->move(posX, posY + 2*labelHeight);
    ui->horizontalSlider_17->move(posX + labelWidth, posY + 13);
    ui->horizontalSlider_18->move(posX + labelWidth, posY + labelHeight + 13);
    ui->horizontalSlider_19->move(posX + labelWidth, posY + 2*labelHeight + 13);
    ui->lineEdit_17->move(posX + labelWidth + lineWidth, posY + 6);
    ui->lineEdit_18->move(posX + labelWidth + lineWidth, posY + labelHeight + 6);
    ui->lineEdit_19->move(posX + labelWidth + lineWidth, posY + 2*labelHeight + 6);
}

void MainWindow::rgbChanchedByLineR()
{
    rValueRGB = ui->horizontalSlider_1->value();
    color = QColor(rValueRGB, gValueRGB, bValueRGB);
    ui->lineEdit_1->setText(QString::number(rValueRGB));
}

void MainWindow::rgbChangedByEditR()
{
    rValueRGB = ui->lineEdit_1->text().toInt();
    color = QColor(rValueRGB, gValueRGB, bValueRGB);
    ui->horizontalSlider_1->setValue(rValueRGB);
}

void MainWindow::rgbChanchedByLineG()
{
    gValueRGB = ui->horizontalSlider_2->value();
    color = QColor(rValueRGB, gValueRGB, bValueRGB);
    ui->lineEdit_2->setText(QString::number(gValueRGB));
}

void MainWindow::rgbChangedByEditG()
{
    gValueRGB = ui->lineEdit_2->text().toInt();
    color = QColor(rValueRGB, gValueRGB, bValueRGB);
    ui->horizontalSlider_2->setValue(gValueRGB);
}

void MainWindow::rgbChanchedByLineB()
{
    bValueRGB = ui->horizontalSlider_3->value();
    color = QColor(rValueRGB, gValueRGB, bValueRGB);
    ui->lineEdit_3->setText(QString::number(bValueRGB));
}

void MainWindow::rgbChangedByEditB()
{
    bValueRGB = ui->lineEdit_3->text().toInt();
    color = QColor(rValueRGB, gValueRGB, bValueRGB);
    ui->horizontalSlider_3->setValue(bValueRGB);
}

void MainWindow::cmykChanchedByLineK()
{
    kValueCMYK = ui->horizontalSlider_10->value();
    ui->lineEdit_10->setText(QString::number(kValueCMYK));
}

void MainWindow::cmykChangedByEditK()
{
    kValueCMYK = ui->lineEdit_10->text().toInt();
    ui->horizontalSlider_10->setValue(kValueCMYK);
}

void MainWindow::cmykChanchedByLineC()
{
    cValueCMYK = ui->horizontalSlider_7->value();
    ui->lineEdit_7->setText(QString::number(cValueCMYK));
}

void MainWindow::cmykChangedByEditC()
{
    cValueCMYK = ui->lineEdit_7->text().toInt();
    ui->horizontalSlider_7->setValue(cValueCMYK);
}

void MainWindow::cmykChanchedByLineM()
{
    mValueCMYK = ui->horizontalSlider_8->value();
    ui->lineEdit_8->setText(QString::number(mValueCMYK));
}

void MainWindow::cmykChangedByEditM()
{
    mValueCMYK = ui->lineEdit_8->text().toInt();
    ui->horizontalSlider_8->setValue(mValueCMYK);
}

void MainWindow::cmykChanchedByLineY()
{
    yValueCMYK = ui->horizontalSlider_9->value();
    ui->lineEdit_9->setText(QString::number(yValueCMYK));
}

void MainWindow::cmykChangedByEditY()
{
    yValueCMYK = ui->lineEdit_9->text().toInt();
    ui->horizontalSlider_9->setValue(yValueCMYK);
}

void MainWindow::labChanchedByLineL()
{
    lValueLAB = ui->horizontalSlider_4->value();
    ui->lineEdit_4->setText(QString::number(lValueLAB));
}

void MainWindow::labChangedByEditL()
{
    lValueLAB = ui->lineEdit_4->text().toInt();
    ui->horizontalSlider_4->setValue(lValueLAB);
}

void MainWindow::labChanchedByLineA()
{
    aValueLAB = ui->horizontalSlider_5->value();
    ui->lineEdit_5->setText(QString::number(aValueLAB));
}

void MainWindow::labChangedByEditA()
{
    aValueLAB = ui->lineEdit_5->text().toInt();
    ui->horizontalSlider_5->setValue(aValueLAB);
}

void MainWindow::labChanchedByLineB()
{
    bValueLAB = ui->horizontalSlider_6->value();
    ui->lineEdit_6->setText(QString::number(bValueLAB));
}

void MainWindow::labChangedByEditB()
{
    bValueLAB = ui->lineEdit_6->text().toInt();
    ui->horizontalSlider_6->setValue(bValueLAB);
}

void MainWindow::xyzChanchedByLineX()
{
    xValueXYZ = ui->horizontalSlider_17->value();
    ui->lineEdit_17->setText(QString::number(xValueXYZ));
}

void MainWindow::xyzChanchedByLineY()
{
    yValueXYZ = ui->horizontalSlider_18->value();
    ui->lineEdit_18->setText(QString::number(yValueXYZ));
}

void MainWindow::xyzChanchedByLineZ()
{
    zValueXYZ = ui->horizontalSlider_19->value();
    ui->lineEdit_19->setText(QString::number(zValueXYZ));
}

void MainWindow::xyzChangedByEditX()
{
    xValueXYZ = ui->lineEdit_17->text().toInt();
    ui->horizontalSlider_17->setValue(xValueXYZ);
}

void MainWindow::xyzChangedByEditY()
{
    yValueXYZ = ui->lineEdit_18->text().toInt();
    ui->horizontalSlider_18->setValue(yValueXYZ);
}

void MainWindow::xyzChangedByEditZ()
{
    zValueXYZ = ui->lineEdit_19->text().toInt();
    ui->horizontalSlider_19->setValue(zValueXYZ);
}

void MainWindow::hlsChanchedByLine()
{
    hValueHSL = ui->horizontalSlider_11->value();
    ui->lineEdit_11->setText(QString::number(hValueHSL));
    sValueHSL = ui->horizontalSlider_12->value();
    ui->lineEdit_12->setText(QString::number(sValueHSL));
    lValueHSL = ui->horizontalSlider_13->value();
    ui->lineEdit_13->setText(QString::number(lValueHSL));
}

void MainWindow::hlsChangedByEdit()
{
    hValueHSL = ui->lineEdit_11->text().toInt();
    sValueHSL = ui->lineEdit_12->text().toInt();
    lValueHSL = ui->lineEdit_13->text().toInt();
    ui->horizontalSlider_11->setValue(hValueHSL);
    ui->horizontalSlider_12->setValue(sValueHSL);
    ui->horizontalSlider_13->setValue(lValueHSL);
}

void MainWindow::hsvChanchedByLine()
{
    hValueHSV = ui->horizontalSlider_14->value();
    ui->lineEdit_14->setText(QString::number(hValueHSV));
    sValueHSV = ui->horizontalSlider_15->value();
    ui->lineEdit_15->setText(QString::number(sValueHSV));
    vValueHSV = ui->horizontalSlider_16->value();
    ui->lineEdit_16->setText(QString::number(vValueHSV));
}

void MainWindow::hsvChangedByEdit()
{
    hValueHSV = ui->lineEdit_14->text().toInt();
    sValueHSV = ui->lineEdit_15->text().toInt();
    vValueHSV = ui->lineEdit_16->text().toInt();
    ui->horizontalSlider_14->setValue(hValueHSV);
    ui->horizontalSlider_15->setValue(sValueHSV);
    ui->horizontalSlider_16->setValue(vValueHSV);
}

void MainWindow::fromRGBtoCMYK()
{
    double tmpK1 = 1 - rValueRGB/255;
    double tmpK2 = 1 - gValueRGB/255;
    double tmpK3 = 1 - bValueRGB/255;
    if(tmpK1 < tmpK2){
        if(tmpK1 < tmpK3){
            kValueCMYK = tmpK1;
        }else{
            kValueCMYK = tmpK3;
        }
    }else{
        if(tmpK2 < tmpK3){
            kValueCMYK = tmpK2;
        }else{
            kValueCMYK = tmpK3;
        }
    }
    cValueCMYK = (1 - rValueRGB/255 - kValueCMYK)/(1 - kValueCMYK) * 100;
    mValueCMYK = (1 - gValueRGB/255 - kValueCMYK)/(1 - kValueCMYK) * 100;
    yValueCMYK = (1 - bValueRGB/255 - kValueCMYK)/(1 - kValueCMYK) * 100;
    kValueCMYK = kValueCMYK * 100;
    setCMYKvalues();
}

void MainWindow::fromCMYKtoRGB()
{
    rValueRGB = 255 * (1 - cValueCMYK/100) * (1 - kValueCMYK/100);
    gValueRGB = 255 * (1 - mValueCMYK/100) * (1 - kValueCMYK/100);
    bValueRGB = 255 * (1 - yValueCMYK/100) * (1 - kValueCMYK/100);
    setRGBvalues();
    fromRGBtoXYZ();
    fromXYZtoLAB();
    fromRGBtoHSV();
    fromRGBtoHSL();
}

void MainWindow::fromRGBtoXYZ()
{
    double rn = countFforFromRGBtoXYZ(rValueRGB/255)*100;
    double gn = countFforFromRGBtoXYZ(gValueRGB/255)*100;
    double bn = countFforFromRGBtoXYZ(bValueRGB/255)*100;
    xValueXYZ = 0.412453 * rn + 0.357580 * gn + 0.180423 * bn;
    yValueXYZ = 0.212671 * rn + 0.715160 * gn + 0.072169 * bn;
    zValueXYZ = 0.019334 * rn + 0.119193 * gn + 0.950227 * bn;
    setXYZvalues();
    fromXYZtoLAB();
}

void MainWindow::fromXYZtoRGB()
{
    double rn = 3.2406*xValueXYZ/100 - 1.5372*yValueXYZ/100 - 0.4986*zValueXYZ/100;
    double gn = -0.9687*xValueXYZ/100 + 1.8758*yValueXYZ/100 + 0.0415*zValueXYZ/100;
    double bn = 0.0557*xValueXYZ/100 - 0.2040*yValueXYZ/100 + 1.0570*zValueXYZ/100;
    rValueRGB = countFforFromXYZtoRGB(rn) * 255;
    gValueRGB = countFforFromXYZtoRGB(gn) * 255;
    bValueRGB = countFforFromXYZtoRGB(bn) * 255;
    setRGBvalues();
    fromRGBtoCMYK();
    fromRGBtoHSL();
    fromRGBtoHSV();
}

double MainWindow::countFforFromRGBtoXYZ(double x)
{
    if(x >= 0.04045){
        return qPow(((x+0.055)/1.005), 2.4);
    }else{
        return(x/12.92);
    }
}

double MainWindow::countFforFromXYZtoRGB(double x)
{
    if(x >= 0.0031308){
        return qPow((x), 1/2.4)*1.055 - 0.055;
    }else{
        return(x*12.92);
    }
}

void MainWindow::fromXYZtoLAB()
{
    double nx = xValueXYZ/95.047;
    double ny = yValueXYZ/100;
    double nz = zValueXYZ/108.883;
    lValueLAB = 116 * countFforFromXYZtoLAB(ny) - 16;
    aValueLAB = 500 * (countFforFromXYZtoLAB(nx) - countFforFromXYZtoLAB(ny));
    bValueLAB = 200 * (countFforFromXYZtoLAB(ny) - countFforFromXYZtoLAB(nz));
    setLABvalues();
}

double MainWindow::countFforFromXYZtoLAB(double x)
{
    if(x >= 0.008856){
        return qPow(x, 1/3);
    }else{
        return (x*7.787 + 16/116);
    }
}

void MainWindow::fromLABtoXYZ()
{
    yValueXYZ = countFforFromLABtoXYZ((lValueLAB+16)/116) * 95.047;
    xValueXYZ = countFforFromLABtoXYZ(aValueLAB/500 + (lValueLAB+16)/116) * 100;
    zValueXYZ = countFforFromLABtoXYZ((lValueLAB+16)/116 - bValueLAB/200) * 108.883;
    setXYZvalues();
    fromXYZtoRGB();
}

double MainWindow::countFforFromLABtoXYZ(double x)
{
    if(x >= 0.008856){
        return qPow(x, 3);
    }else{
        return ((x - 16/116)/7.787 );
    }
}

void MainWindow::fromHSVtoRGB()
{
    double nh = hValueHSV;
    double ns = sValueHSV/100;
    double nv = vValueHSV/100;
    if(ns == 0){
        rValueRGB = gValueRGB = bValueRGB = nv;
    }else{
        double nh = nh/60;
        int i = (int)nh;
        double c = nh - i;

        double x = nv*(1 - ns);
        double y = nv*(1 - ns*c);
        double z = nv*(1 - ns*(1-c));

        switch(i){
        case 0: rValueRGB = nv; gValueRGB = z; bValueRGB = x; break;
        case 1: rValueRGB = y; gValueRGB = nv; bValueRGB = x; break;
        case 2: rValueRGB = x; gValueRGB = nv; bValueRGB = z; break;
        case 3: rValueRGB = x; gValueRGB = y; bValueRGB = nv; break;
        case 4: rValueRGB = z; gValueRGB = x; bValueRGB = nv; break;
        case 5: rValueRGB = nv; gValueRGB = x; bValueRGB = y; break;
        }
    }

    rValueRGB *= 100;
    gValueRGB *= 100;
    bValueRGB *= 100;
    setRGBvalues();
    fromRGBtoCMYK();
    fromRGBtoXYZ();
    fromRGBtoHSL();
}

void MainWindow::fromRGBtoHSV()
{
    double max, min;
    double nr = rValueRGB/100;
    double ng = gValueRGB/100;
    double nb = bValueRGB/100;

    max = min = nr;
    if(ng > max){
        max = ng;
    }
    if(max < nb){
        max = nb;
    }

    if(min > ng){
        min = ng;
    }
    if(min > nb){
        min = nb;
    }

    vValueHSV = max;
    if(max == 0){
        sValueHSV = 0;
    }else{
        sValueHSV = 1 - min/max;
    }

    if(max == min)
        hValueHSV = 0;
    else if(max == nr && ng>=nb)
        hValueHSV = 60*((nr-ng)/(max-min));
    else if(max ==nr && ng<nb)
        hValueHSV = 60*((ng-nb)/(max-min)) + 360;
    else if(max == ng)
        hValueHSV = 60*((nb-nr)/(max-min)) + 120;
    else if(max == nb)
        hValueHSV = 60*((nr-ng)/(max-min)) + 240;

    vValueHSV *= 100;
    sValueHSV *= 100;

    setHSVvalues();
}

void MainWindow::fromRGBtoHSL()
{
    double nr = rValueRGB/255;
    double ng = gValueRGB/255;
    double nb = bValueRGB/255;

    double min, max;
    min = max = nr;

    if(ng > max){
        max = ng;
    }
    if(max < nb){
        max = nb;
    }

    if(min > ng){
        min = ng;
    }
    if(min > nb){
        min = nb;
    }

    double delta = max - min;

    if(delta == 0){
        hValueHSL = 0;
    }else if(max == nr){
        double tmp = (ng - nb)/delta;
        hValueHSL = 60 * fmod(tmp, 6);
    }else if(max == ng){
        hValueHSL = 60 * ((nb - nr)/delta + 2);
    }else if(max == nb){
        hValueHSL = 60 * ((nr - ng)/delta + 4);
    }

    lValueHSL = (max + min)/2;

    if(delta == 0){
        sValueHSL = 0;
    }else{
        sValueHSL = delta/(1 - abs(2*lValueHSL - 1));
    }

    sValueHSL *= 100;
    lValueHSL *= 100;

    setHSLvalues();
}

void MainWindow::fromHSLtoRGB()
{
    double c = (1 - abs(2*lValueHSL/100 - 1));
    double x = c * (1 - abs(fmod(hValueHSL/(60 * 100), 2) - 1));
    double m = lValueHSL/100 - c/2;

    double nr, ng, nb;
    if(hValueHSL >= 0 && hValueHSL < 60){
        nr = c;
        ng = x;
        nb = 0;
    }else if(hValueHSL >= 60 && hValueHSL < 120){
        nr = x;
        ng = c;
        nb = 0;
    }else if(hValueHSL >= 120 && hValueHSL < 180){
        nr = 0;
        ng = c;
        nb = x;
    }else if(hValueHSL >= 180 && hValueHSL < 240){
        nr = 0;
        ng = x;
        nb = c;
    }else if(hValueHSL >= 240 && hValueHSL < 300){
        nr = x;
        ng = 0;
        nb = c;
    }else if(hValueHSL >= 300 && hValueHSL < 360){
        nr = c;
        ng = 0;
        nb = x;
    }

    rValueRGB = (nr + m) * 255;
    gValueRGB = (ng + m) * 255;
    bValueRGB = (nb + m) * 255;

    setRGBvalues();
    fromRGBtoCMYK();
    fromRGBtoHSV();
    fromRGBtoXYZ();
}



