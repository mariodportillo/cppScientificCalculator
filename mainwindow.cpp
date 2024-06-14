#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include<cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _ScreenValue = 0;
    ui->Display->setText(QString::number(_ScreenValue));
    _String = "0";
    _FirstValue = 0;
    _SecondValue = 0;
    _Operator = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay()
{
    ui->Display->setText(_String.isEmpty() ? "0" : _String);
}

void MainWindow::appendDigit(const QString& digit)
{
    if (_String == "0") {
        _String = digit;
    } else {
        _String += digit;
    }
    updateDisplay();
}

void MainWindow::on_PushButtonOne_clicked()
{
    appendDigit("1");
}

void MainWindow::on_PushButtonTwo_clicked()
{
    appendDigit("2");
}

void MainWindow::on_PushButtonThree_clicked()
{
    appendDigit("3");
}

void MainWindow::on_PushButtonFour_clicked()
{
    appendDigit("4");
}

void MainWindow::on_PushButtonFive_clicked()
{
    appendDigit("5");
}

void MainWindow::on_PushButtonSix_clicked()
{
    appendDigit("6");
}

void MainWindow::on_PushButtonSeven_clicked()
{
    appendDigit("7");
}

void MainWindow::on_PushButtonEight_clicked()
{
    appendDigit("8");
}

void MainWindow::on_PushButtonNine_clicked()
{
    appendDigit("9");
}

void MainWindow::on_PushButtonZero_clicked()
{
    if (_String != "0") {
        appendDigit("0");
    }
}

void MainWindow::on_PushButtonClear_clicked()
{
    _ScreenValue = 0;
    _FirstValue = 0;
    _SecondValue = 0;
    _String = "0";
    updateDisplay();
}

void MainWindow::on_PushButtonDot_clicked()
{
    if (!_String.contains('.')) {
        if (_String.isEmpty()) {
            _String = "0.";
        } else {
            _String += ".";
        }
        updateDisplay();
    }
}

// Call this function when you need to use the input as a double value
double MainWindow::getScreenValueAsDouble() const
{
    return _String.toDouble();
}

void MainWindow::on_PushButtonPlus_clicked()
{
    _FirstValue = getScreenValueAsDouble();
    _ScreenValue = 0;
    _String = "0";
    updateDisplay();
    _Operator = "+";
}

void MainWindow::on_PushButtonMinus_clicked()
{
    _FirstValue = getScreenValueAsDouble();
    _ScreenValue = 0;
    _String = "0";
    updateDisplay();
    _Operator = "-";
}


void MainWindow::on_PushButtonMultiply_clicked()
{
    _FirstValue = getScreenValueAsDouble();
    _ScreenValue = 0;
    _String = "0";
    updateDisplay();
    _Operator = "*";
}

void MainWindow::on_PushButtonDivide_clicked()
{
    _FirstValue = getScreenValueAsDouble();
    _ScreenValue = 0;
    _String = "0";
    updateDisplay();
    _Operator = "/";
}

void MainWindow::on_PushButtonRaiseTo_clicked()
{
    _FirstValue = getScreenValueAsDouble();
    _ScreenValue = 0;
    _String = "0";
    updateDisplay();
    _Operator = "^";
}

void MainWindow::on_PushButtonSquareRoot_clicked()
{
    _ScreenValue = getScreenValueAsDouble();
    _String = QString::number(std::sqrt(_ScreenValue));
    updateDisplay();
}

void MainWindow::on_PushButtonPlusMinus_clicked()
{
    if (_String.startsWith("-")){
        _String.remove(0, 1);
    }else if (_String != "0"){
        _String.prepend("-");
    }
    updateDisplay();
}

double MainWindow::factorialGenHard(double num) {
    if (num < 0) {
        // Factorial of negative numbers is not defined
        return std::numeric_limits<double>::quiet_NaN();
    }
    return std::tgamma(num + 1);
}

double MainWindow::factorialGen(double num){
    if (num < 0){
        return 0;
    }

    if (num == 0) {
        return 1;
    }
    return num*factorialGen(num-1);
}


void MainWindow::on_PushButtonFactorial_clicked()
{
    _ScreenValue = getScreenValueAsDouble();

    if (QString::number(_ScreenValue).contains(".")){
        _String = QString::number(factorialGenHard(_ScreenValue));
    }else {
        _String = QString::number(factorialGen(_ScreenValue));
    }

    updateDisplay();
}

void MainWindow::on_PushButtonPercent_clicked()
{
    _ScreenValue = getScreenValueAsDouble() * 0.01;
    _String = QString::number(_ScreenValue);
    updateDisplay();
}

void MainWindow::on_PushButtonEqual_clicked()
{
    _SecondValue = getScreenValueAsDouble();

    if (_Operator.isEmpty()) {
        return; // No operation to perform
    }

    if (_Operator == "+") {
        _ScreenValue = _FirstValue + _SecondValue;
    } else if (_Operator == "-") {
        _ScreenValue = _FirstValue - _SecondValue;
    } else if (_Operator == "*") {
        _ScreenValue = _FirstValue * _SecondValue;
    } else if (_Operator == "/") {
        if (_SecondValue != 0) {
            _ScreenValue = _FirstValue / _SecondValue;
        } else {
            ui->Display->setText("Error: Division by zero");
            return;
        }
    } else if (_Operator == "^"){
        _ScreenValue = std::pow(_FirstValue, _SecondValue);
    }

    _FirstValue = 0;
    _SecondValue = 0;
    _Operator = "";
    _String = QString::number(_ScreenValue);
    updateDisplay();
}




