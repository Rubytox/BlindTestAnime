#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _player = new QMediaPlayer;

    QString baseUrl = "/home/rubytox/Vidéos/CL/Episodes/Saison1/";
    addToPlaylist(baseUrl + "output.mp4");
    addToPlaylist(baseUrl + "CODE LYOKO - EP01 - Teddy Gozilla-QCGixQKvTpA.mkv");
    addToPlaylist(baseUrl + "CODE LYOKO - EP02 - Le voir pour le croire-d3EiLxiGYgs.mkv");
    addToPlaylist(baseUrl + "CODE LYOKO - EP03 - Vacances dans la brume-I4AE3BvIxMQ.mkv");
    addToPlaylist(baseUrl + "CODE LYOKO - EP04 - Carnet de bord-5nsklx84-jE.mkv");
    addToPlaylist(baseUrl + "CODE LYOKO - EP05 - Big Bogue-SWnxzc-hOL8.mkv");

    _videoWidget = new QVideoWidget(ui->mediaContainer);
    _player->setVideoOutput(_videoWidget);

    ui->mainLayout->addWidget(_videoWidget);
    std::cout << "Player error state: " << _player->error() << std::endl;

    connect(ui->buttonPlay, SIGNAL(clicked()), _player, SLOT(play()));
    connect(ui->buttonPause, SIGNAL(clicked()), _player, SLOT(pause()));
    connect(ui->buttonPrevious, SIGNAL(clicked()), this, SLOT(previousClicked()));
    connect(ui->buttonNext, SIGNAL(clicked()), this, SLOT(nextClicked()));

    connect(_player, &QMediaPlayer::mediaStatusChanged, this, [&](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::LoadedMedia) randomPlace();
    });

    _current = 0;
    std::cout << "Playing " << _playlist.at(_current).toString().toStdString() << std::endl;
    playFile(_playlist.at(_current));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _player;
    delete _videoWidget;
}

void MainWindow::playFile(const QUrl &file)
{
    _player->setMedia(file);
}

void MainWindow::randomPlace()
{
    quint32 length = _player->duration();
    quint32 span = 10000;  // 10s
    quint32 start = QRandomGenerator64::global()->bounded(length - span);

    std::cout << "Now playing " << _player->currentMedia().request().url().toString().toStdString() << " of length " << length << std::endl;
    _player->setPosition(start);
    int seconds = start / 1000;
    int minutes = seconds / 60;
    seconds %= 60;
    std::cout << "Starting at position " << minutes << ":" << seconds << std::endl;

    _player->play();
    std::cout << "Player status: " << _player->error() << std::endl;
    std::cout << "Media status: " << _player->mediaStatus() << std::endl;
}

void MainWindow::addToPlaylist(const QUrl &file)
{
    _playlist << file;
}

void MainWindow::addToPlaylist(const QString &file)
{
    addToPlaylist(QUrl::fromLocalFile(file));
}


void MainWindow::playClicked()
{
    _player->play();
}

void MainWindow::pauseClicked()
{
    _player->pause();
}

void MainWindow::previousClicked()
{
    if (_current > 0)
        playFile(_playlist.at(--_current));
}

void MainWindow::nextClicked()
{
    if (_current < _playlist.size() - 1)
        playFile(_playlist.at(++_current));
}
