#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PushButtonOne_clicked();

    void on_PushButtonTwo_clicked();

    void on_PushButtonThree_clicked();

    void on_PushButtonFour_clicked();

    void on_PushButtonFive_clicked();

    void on_PushButtonSix_clicked();

    void on_PushButtonSeven_clicked();

    void on_PushButtonEight_clicked();

    void on_PushButtonNine_clicked();

    void on_PushButtonZero_clicked();

    void on_PushButtonClear_clicked();

    void on_PushButtonDot_clicked();

    void updateDisplay();

    void appendDigit(const QString& digit);

    double getScreenValueAsDouble() const;

    void on_PushButtonPlus_clicked();

    void on_PushButtonEqual_clicked();

    void on_PushButtonMinus_clicked();

    void on_PushButtonMultiply_clicked();

    void on_PushButtonDivide_clicked();

    void on_PushButtonRaiseTo_clicked();

    void on_PushButtonSquareRoot_clicked();

    void on_PushButtonPlusMinus_clicked();

    void on_PushButtonFactorial_clicked();

    void on_PushButtonPercent_clicked();

private:
    Ui::MainWindow *ui;
    double _ScreenValue;
    QString _String;
    double _FirstValue;
    double _SecondValue;
    QString _Operator;
    double factorialGenHard(double num);
    double factorialGen(double num);

};
#endif // MAINWINDOW_H
