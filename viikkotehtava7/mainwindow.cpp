#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentOperation("+")
{
    ui->setupUi(this);

    ui->num1->setFocus();

    if (ui->operationDisplay)
        ui->operationDisplay->setText(currentOperation);

    connect(ui->btnADD, &QPushButton::clicked, this, &MainWindow::on_btnADD_clicked);
    connect(ui->btnSUB, &QPushButton::clicked, this, &MainWindow::on_btnSUB_clicked);
    connect(ui->btnMUL, &QPushButton::clicked, this, &MainWindow::on_btnMUL_clicked);
    connect(ui->btnDIV, &QPushButton::clicked, this, &MainWindow::on_btnDIV_clicked);

    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::on_btnClear_clicked);
    connect(ui->btncount, &QPushButton::clicked, this, &MainWindow::on_btncount_clicked);
    connect(ui->btnreset, &QPushButton::clicked, this, &MainWindow::on_btnreset_clicked);
    connect(ui->btnEnter, &QPushButton::clicked, this, &MainWindow::on_btnEnter_clicked);

    QList<QPushButton*> numberButtons = { ui->btn0, ui->btn1, ui->btn2, ui->btn3, ui->btn4,
                                          ui->btn5, ui->btn6, ui->btn7, ui->btn8, ui->btn9 };

    for (QPushButton* button : numberButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_numberButton_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString value = button->text();
    qDebug() << "Klikattu numero:" << value;

    if (ui->num1->hasFocus() || ui->num1->text().isEmpty()) {
        if (ui->num1->text() == "0") ui->num1->clear();
        ui->num1->setText(ui->num1->text() + value);
    }
    else if (ui->num2->hasFocus() || !ui->num1->text().isEmpty()) {
        if (ui->num2->text() == "0") ui->num2->clear();
        ui->num2->setText(ui->num2->text() + value);
    }
}

void MainWindow::on_btnADD_clicked() { setOperation("+"); }
void MainWindow::on_btnSUB_clicked() { setOperation("-"); }
void MainWindow::on_btnMUL_clicked() { setOperation("*"); }
void MainWindow::on_btnDIV_clicked() { setOperation("/"); }

void MainWindow::setOperation(const QString &op)
{

    if (!ui->num1->text().isEmpty()) {
        currentOperation = op;
        if (ui->operationDisplay)
            ui->operationDisplay->setText(currentOperation);
        ui->num2->setFocus();
    }
}

void MainWindow::on_btnEnter_clicked()
{
    bool ok1, ok2;
    double num1 = ui->num1->text().toDouble(&ok1);
    double num2 = ui->num2->text().toDouble(&ok2);

    if (!ok1 || !ok2) {
        ui->result->setText("Virhe");
        return;
    }

    double result = 0;
    if (currentOperation == "+") result = num1 + num2;
    else if (currentOperation == "-") result = num1 - num2;
    else if (currentOperation == "*") result = num1 * num2;
    else if (currentOperation == "/") {
        if (num2 == 0) {
            ui->result->setText("Nollalla ei voi jakaa");
            return;
        }
        result = num1 / num2;
    } else {
        ui->result->setText("Virhe");
        return;
    }

    ui->result->setText(QString::number(result, 'f', 2));
    ui->num1->setText(QString::number(result, 'f', 2));
    ui->num2->clear();
    ui->num1->setFocus();
}

void MainWindow::on_btnClear_clicked()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
    if (ui->operationDisplay) ui->operationDisplay->setText("+");
    currentOperation = "+";
    ui->num1->setFocus();
}

void MainWindow::on_btncount_clicked()
{
    int count = ui->countDisplay->text().toInt();
    ui->countDisplay->setText(QString::number(count + 1));
}

void MainWindow::on_btnreset_clicked()
{
    ui->countDisplay->setText("0");
}
