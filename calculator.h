#ifndef CONVERTER_H
#define CONVERTER_H

#include <QWidget>

class QLineEdit;
class QSpinBox;
class QRadioButton;
class QPushButton;
class QGridLayout;
class QVBoxLayout;
class QHBoxLayout;
class QGroupBox;



class Calculator : public QWidget
{
    Q_OBJECT

    QGridLayout *layout;
    QVBoxLayout *panel;
    QHBoxLayout *hbox;
    QLineEdit  *display;
    QGroupBox *radioButtons;
    QRadioButton *norRBut, *bigRBut;
    QPushButton *but1, *but2, *but3, *but4,
    *but5, *but6, *but7, *but8, *but9, *but0,
    *butCls, *butSlash, *butPower, *butMinus,
    *butPlus, *butResolve, *butDott;
    QPushButton *addBut;

    bool newNumExpected;
    bool fltPoint;
    double opA;
    double opB;
    char idOp;
    int prevNums;
    char operation;

public:
    Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    void insNumeral(char c);

private slots:
    void clickButton0();
    void clickButton1();
    void clickButton2();
    void clickButton3();
    void clickButton4();
    void clickButton5();
    void clickButton6();
    void clickButton7();
    void clickButton8();
    void clickButton9();
    void clickButtonCls();
    void clickButtonSlash();
    void clickButtonPower();
    void clickButtonMinus();
    void clickButtonPlus();
    void clickButtonResolve();
    void clickButtonDott();
    void clickNorButton();
    void clickBigButton();

};

#endif // CONVERTER_H
