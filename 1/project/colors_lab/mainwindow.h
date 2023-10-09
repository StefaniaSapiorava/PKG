#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);

private slots:
    void indexChanged(int index);
    void on_pushButton_clicked();

    void setRGBvalues();
    void setLABvalues();
    void setCMYKvalues();
    void setXYZvalues();
    void setHSVvalues();
    void setHSLvalues();

    void setStartVisual();
    void rgbInWindow(int pos);
    void cmykInWindow(int pos);
    void labInWindow(int pos);
    void hslInWindow(int pos);
    void hsvInWindow(int pos);
    void xyzInWindow(int pos);

    void rgbChanchedByLineR();
    void rgbChangedByEditR();
    void rgbChanchedByLineG();
    void rgbChangedByEditG();
    void rgbChanchedByLineB();
    void rgbChangedByEditB();

    void cmykChanchedByLineC();
    void cmykChangedByEditC();
    void cmykChanchedByLineM();
    void cmykChangedByEditM();
    void cmykChanchedByLineY();
    void cmykChangedByEditY();
    void cmykChanchedByLineK();
    void cmykChangedByEditK();

    void labChanchedByLineL();
    void labChangedByEditL();
    void labChanchedByLineA();
    void labChangedByEditA();
    void labChanchedByLineB();
    void labChangedByEditB();

    void xyzChanchedByLineX();
    void xyzChanchedByLineY();
    void xyzChanchedByLineZ();
    void xyzChangedByEditX();
    void xyzChangedByEditY();
    void xyzChangedByEditZ();

    void hlsChanchedByLine();
    void hlsChangedByEdit();

    void hsvChanchedByLine();
    void hsvChangedByEdit();

    void fromRGBtoCMYK();
    void fromCMYKtoRGB();
    void fromRGBtoXYZ();
    void fromXYZtoRGB();
    double countFforFromRGBtoXYZ(double x);
    double countFforFromXYZtoRGB(double x);
    void fromXYZtoLAB();
    double countFforFromXYZtoLAB(double x);
    void fromLABtoXYZ();
    double countFforFromLABtoXYZ(double x);
    void fromHSVtoRGB();
    void fromRGBtoHSV();
    void fromRGBtoHSL();
    void fromHSLtoRGB();

private:
    QColor color = QColor(255, 255, 255);

    int rectX = 10;

    double rValueRGB = 255;
    double gValueRGB = 255;
    double bValueRGB = 255;

    double cValueCMYK = 0;
    double mValueCMYK = 0;
    double yValueCMYK = 0;
    double kValueCMYK = 0;

    double lValueLAB = 100;
    double aValueLAB = 0;
    double bValueLAB = 0;

    double hValueHSL = 100;
    double sValueHSL = 0;
    double lValueHSL = 0;

    double hValueHSV = 0;
    double sValueHSV = 0;
    double vValueHSV = 100;

    double xValueXYZ = 95;
    double yValueXYZ = 100;
    double zValueXYZ = 108;

    int deleteFromWindowX = 10000;
    int deleteFromWindowY = 10000;
    int firstX = 40;
    int firstY = 140;
    int secondX = 40;
    int secondY = 300;
    int thirdX = 40;
    int thirdY = 460;
    int labelWidth = 9;
    int labelHeight = 38;
    int lineWidth = 255;
    int lineHeight = 15;
    int editWidth = 79;
    int editHeight = 24;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
