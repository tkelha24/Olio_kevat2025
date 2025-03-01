#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), player1Time(120), player2Time(120), currentPlayer(1) {

    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &MainWindow::timeout);

    player1Bar = new QProgressBar(this);
    player2Bar = new QProgressBar(this);
    player1Bar->setValue(100);
    player2Bar->setValue(100);

    infoLabel = new QLabel("Select playtime and press start game!", this);

    startButton = new QPushButton("START GAME", this);
    stopButton = new QPushButton("STOP GAME", this);
    switchButton1 = new QPushButton("Switch player", this);
    switchButton2 = new QPushButton("Switch player", this);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::stopGame);
    connect(switchButton1, &QPushButton::clicked, this, &MainWindow::switchPlayer);
    connect(switchButton2, &QPushButton::clicked, this, &MainWindow::switchPlayer);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(player1Bar);
    layout->addWidget(switchButton1);
    layout->addWidget(player2Bar);
    layout->addWidget(switchButton2);
    layout->addWidget(infoLabel);
    layout->addWidget(startButton);
    layout->addWidget(stopButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::timeout() {
    if (currentPlayer == 1) {
        player1Time--;
        player1Bar->setValue((player1Time * 100) / 120);
    } else {
        player2Time--;
        player2Bar->setValue((player2Time * 100) / 120);
    }
    updateProgressBar();
    if (player1Time == 0 || player2Time == 0) {
        stopGame();
        setGameInfoText(currentPlayer == 1 ? "Player 2 WON!!" : "Player 1 WON!!", 14);
    }
}

void MainWindow::startGame() {
    gameTimer->start(1000);
    setGameInfoText("Game ongoing", 12);
}

void MainWindow::stopGame() {
    gameTimer->stop();
    setGameInfoText("New game via start button", 12);
    player1Time = 120;
    player2Time = 120;
    player1Bar->setValue(100);
    player2Bar->setValue(100);
}

void MainWindow::switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void MainWindow::updateProgressBar() {
    player1Bar->setValue((player1Time * 100) / 120);
    player2Bar->setValue((player2Time * 100) / 120);
}

void MainWindow::setGameInfoText(const QString &text, short size) {
    QFont font = infoLabel->font();
    font.setPointSize(size);
    infoLabel->setFont(font);
    infoLabel->setText(text);
}
