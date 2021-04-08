#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer;


    videoWidget = new QVideoWidget(ui->mediaContainer);
    player->setVideoOutput(videoWidget);

    ui->mainLayout->addWidget(videoWidget);
    std::cout << "Player error state: " << player->error() << std::endl;

    connect(ui->buttonPlay, SIGNAL(clicked()), this, SLOT(playClicked()));
    connect(ui->buttonPause, SIGNAL(clicked()), this, SLOT(pauseClicked()));
    connect(ui->buttonPrevious, SIGNAL(clicked()), this, SLOT(previousClicked()));
    connect(ui->buttonNext, SIGNAL(clicked()), this, SLOT(nextClicked()));

    playFile(QUrl::fromLocalFile("/home/rubytox/Vidéos/CL/Episodes/Saison1/output.mp4"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playFile(const QUrl &file)
{
    player->setMedia(file);
    player->play();
}


void MainWindow::playClicked()
{
    player->play();
}

void MainWindow::pauseClicked()
{
    player->pause();
}

void MainWindow::previousClicked()
{

}

void MainWindow::nextClicked()
{

}
