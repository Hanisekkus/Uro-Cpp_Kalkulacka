#include <QLabel>
#include <QLineEdit>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QButtonGroup>
#include <QRadioButton>
#include <QSpinBox>
#include <QGroupBox>
#include <QPushButton>
#include <QMessageBox>

#include "calculator.h"

#define MIN_BUT_WIDTH 30
#define MIN_BUT_HEIGHT 30
#define MAX_BUT_WIDTH 50
#define MAX_BUT_HEIGHT 50
#define NORMAL_FONT_SIZE 8
#define BIG_FONT_SIZE 18

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{

    // vytvoreni hlavniho Grid Layoutu - rozmisteni komponent v okne
    layout = new QGridLayout;

    // panel pro display
    panel = new QVBoxLayout;
    display = new QLineEdit("0",this);
    display->setReadOnly(true);
    display->setAlignment( Qt::AlignRight);
    panel->addWidget(display);
    layout->addLayout(panel, 0, 0, 1, 4);

    //panel pro radiobuttony
    hbox = new QHBoxLayout();
    radioButtons = new QGroupBox(this);
    norRBut = new QRadioButton(QString("Normal"),radioButtons);
    bigRBut = new QRadioButton(QString("Big"),radioButtons);
    norRBut->setChecked(true);
    hbox->addWidget(norRBut);
    hbox->addWidget(bigRBut);
    radioButtons->setLayout(hbox);
    radioButtons->setMaximumHeight(40);
    layout->addWidget(radioButtons, 1, 0, 1, 4);
    connect(norRBut,SIGNAL(clicked()),this,SLOT(clickNorButton()));
    connect(bigRBut,SIGNAL(clicked()),this,SLOT(clickBigButton()));
    
    //jednotliva tlacitka
    but1 = new QPushButton("1",this);
    but2 = new QPushButton("2",this);
    but3 = new QPushButton("3",this);
    but4 = new QPushButton("4",this);
    but5 = new QPushButton("5",this);
    but6 = new QPushButton("6",this);
    but7 = new QPushButton("7",this);
    but8 = new QPushButton("8",this);
    but9 = new QPushButton("9",this);
    but0 = new QPushButton("0",this);
    butCls = new QPushButton("Cls", this);
    butDott = new QPushButton(",", this);
    butSlash = new QPushButton("/", this);
    butPower = new QPushButton("*", this);
    butMinus = new QPushButton("-", this);
    butPlus = new QPushButton("+", this);
    butResolve = new QPushButton("=", this);


    but1->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    but2->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    but3->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    but4->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    but5->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    but6->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    but7->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    but8->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    but9->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    but0->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    butCls->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    butDott->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    butSlash->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    butPower->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    butMinus->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    butPlus->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);
    butResolve->setMinimumSize(MIN_BUT_WIDTH, MIN_BUT_HEIGHT);


    butResolve->setStyleSheet("height: 100%;");
    butPlus->setStyleSheet("height: 100%;");

    // -- but1->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));

    connect(but1,SIGNAL(clicked()),this,SLOT(clickButton1()));
    connect(but2,SIGNAL(clicked()),this,SLOT(clickButton2()));
    connect(but3,SIGNAL(clicked()),this,SLOT(clickButton3()));
    connect(but4,SIGNAL(clicked()),this,SLOT(clickButton4()));
    connect(but5,SIGNAL(clicked()),this,SLOT(clickButton5()));
    connect(but6,SIGNAL(clicked()),this,SLOT(clickButton6()));
    connect(but7,SIGNAL(clicked()),this,SLOT(clickButton7()));
    connect(but8,SIGNAL(clicked()),this,SLOT(clickButton8()));
    connect(but9,SIGNAL(clicked()),this,SLOT(clickButton9()));
    connect(but0,SIGNAL(clicked()),this,SLOT(clickButton0()));
    connect(butSlash,SIGNAL(clicked()),this,SLOT(clickButtonSlash()));
    connect(butPower,SIGNAL(clicked()),this,SLOT(clickButtonPower()));
    connect(butMinus,SIGNAL(clicked()),this,SLOT(clickButtonMinus()));
    connect(butPlus,SIGNAL(clicked()),this,SLOT(clickButtonPlus()));
    connect(butResolve,SIGNAL(clicked()),this,SLOT(clickButtonResolve()));
    connect(butDott,SIGNAL(clicked()),this,SLOT(clickButtonDott()));
    connect(butCls,SIGNAL(clicked()),this,SLOT(clickButtonCls()));

    layout->addWidget(butCls,2,0);
    layout->addWidget(butSlash,2,1);
    layout->addWidget(butPower,2,2);
    layout->addWidget(butMinus,2,3);
    layout->addWidget(but7, 3, 0);
    layout->addWidget(but8, 3, 1);
    layout->addWidget(but9, 3, 2);
    layout->addWidget(butPlus, 3, 3, 2, 1);
    layout->addWidget(but4, 4, 0);
    layout->addWidget(but5, 4, 1);
    layout->addWidget(but6, 4, 2);
    layout->addWidget(but1, 5, 0);
    layout->addWidget(but2, 5, 1);
    layout->addWidget(but3, 5, 2);
    layout->addWidget(butResolve, 5, 3, 2, 1);
    layout->addWidget(but0, 6, 0, 1, 2);
    layout->addWidget(butDott, 6, 2);

    setLayout( layout );
}

Calculator::~Calculator()
{

}

void Calculator::insNumeral(char c){
                QString txt = display->text();
                txt.append(c);
                display->setText(txt);
}

void Calculator::clickButton1() {    
        insNumeral('1');
}
void Calculator::clickButton2() {
        insNumeral('2');
}
void Calculator::clickButton3() {
        insNumeral('3');
}
void Calculator::clickButton4() {
        insNumeral('4');
}
void Calculator::clickButton5() {
        insNumeral('5');
}
void Calculator::clickButton6() {
        insNumeral('6');
}
void Calculator::clickButton7() {
        insNumeral('7');
}
void Calculator::clickButton8() {
        insNumeral('8');
}
void Calculator::clickButton9() {
        insNumeral('9');
}
void Calculator::clickButton0() {
        insNumeral('0');
}
void Calculator::clickButtonCls() {
        display->setText("0");
        operation = 'C';
        prevNums = 0;
}
void Calculator::clickButtonPower() {
    if(operation != '*' || operation != '/' || operation != '+' || operation != '-' )
        {
        prevNums = display->text().toInt();
        operation = '*';
        display->setText("0");
        }
}
void Calculator::clickButtonPlus() {
    if(operation != '*' || operation != '/' || operation != '+' || operation != '-' )
        {
        prevNums = display->text().toInt();
        operation = '+';
        display->setText("0");
        }
}
void Calculator::clickButtonSlash() {
    if(operation != '*' || operation != '/' || operation != '+' || operation != '-' )
        {
        prevNums = display->text().toInt();
        operation = '/';
        display->setText("0");
        }
}
void Calculator::clickButtonMinus() {
    if(operation != '*' || operation != '/' || operation != '+' || operation != '-' )
        {
        prevNums = display->text().toInt();
        operation = '-';
        display->setText("0");
        }
}
void Calculator::clickButtonResolve() {
    switch (operation) {
        case '+': display->setText(QString::number(prevNums + display->text().toInt()));break;
        case '-': display->setText(QString::number(prevNums - display->text().toInt()));break;
        case '*': display->setText(QString::number(prevNums * display->text().toInt()));break;
        case '/': display->setText(QString::number(prevNums / display->text().toInt()));break;
    default: operation = 'C'; prevNums = 0;break;
    }
}
void Calculator::clickButtonDott() {
        // -- insNumeral(',');
}

void Calculator::clickNorButton(){

    // -- display->setText("normal");
    display->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    but1->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    but2->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    but3->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    but4->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    but5->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    but6->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    but7->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    but8->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    but9->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    but0->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    norRBut->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    bigRBut->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    butCls->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    butDott->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    butSlash->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    butPower->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    butMinus->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    butPlus->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));
    butResolve->setFont(QFont("SanSerif", NORMAL_FONT_SIZE, QFont::Normal));


}
void Calculator::clickBigButton(){

    // -- display->setText("big");
    display->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    but1->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    but2->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    but3->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    but4->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    but5->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    but6->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    but7->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    but8->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    but9->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    but0->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    norRBut->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    bigRBut->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    butCls->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    butDott->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    butSlash->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    butPower->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    butMinus->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    butPlus->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));
    butResolve->setFont(QFont("SanSerif", BIG_FONT_SIZE, QFont::Bold));

}
