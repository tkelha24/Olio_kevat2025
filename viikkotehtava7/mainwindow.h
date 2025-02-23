#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_numberButton_clicked();
    void on_btnADD_clicked();
    void on_btnSUB_clicked();
    void on_btnMUL_clicked();
    void on_btnDIV_clicked();
    void on_btnEnter_clicked();
    void on_btnClear_clicked();
    void on_btncount_clicked();
    void on_btnreset_clicked();

private:
    Ui::MainWindow *ui;
    QString currentOperation;


    void setOperation(const QString &op);
};

#endif // MAINWINDOW_H
