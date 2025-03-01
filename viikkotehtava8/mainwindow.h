#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    void timeout();
    void startGame();
    void stopGame();
    void switchPlayer();
    void updateProgressBar();
    void setGameInfoText(const QString &text, short size);

private:
    short player1Time;
    short player2Time;
    short currentPlayer;
    QTimer *gameTimer;

    QProgressBar *player1Bar;
    QProgressBar *player2Bar;
    QLabel *infoLabel;

    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *switchButton1;
    QPushButton *switchButton2;
};

#endif // MAINWINDOW_H
