#include "MainWindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _player = new QMediaPlayer;

    QEntry first("Renai Circulation", "Kana Hanazawa", "Bakemonogatari", 4, Entry::Type::OPENING, "C:\\Users\\cFAG\\Videos\\renai-circulation.mp4");
    addToPlaylist(first);

    QEntryDAO::getInstance().save(first);

    _videoWidget = new QVideoWidget(ui->mediaContainer);
    _player->setVideoOutput(_videoWidget);

    ui->mainLayout->addWidget(_videoWidget);
    std::cout << "Player error state: " << _player->error() << std::endl;

    _videoWidget->hide();

    connect(ui->buttonPlay, SIGNAL(clicked()), _player, SLOT(play()));
    connect(ui->buttonPause, SIGNAL(clicked()), _player, SLOT(pause()));
    connect(ui->buttonPrevious, SIGNAL(clicked()), this, SLOT(previousClicked()));
    connect(ui->buttonNext, SIGNAL(clicked()), this, SLOT(nextClicked()));
    connect(ui->buttonToggleVideo, SIGNAL(clicked()), this, SLOT(toggleVideo()));

    connect(_player, &QMediaPlayer::mediaStatusChanged, this, [&](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::LoadedMedia) randomPlace();
    });

    connect(_player, SIGNAL(positionChanged(qint64)), this, SLOT(handleCountdown(qint64)));

    _current = 0;
    std::cout << "Playing " << _playlist.at(_current).getName().toStdString() << std::endl;
    playFile(_playlist.at(_current).getPath());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _player;
    delete _videoWidget;
}

QString MainWindow::formatTitle() const
{
    const QEntry& currentTrack = _playlist.at(_current);

    return QString("%1 - %2 %3\n%4 - %5").arg(currentTrack.getAnime(),
                                            currentTrack.getShortType(),
                                            QString::number(currentTrack.getNumber()),
                                            currentTrack.getName(),
                                            currentTrack.getArtist());
}

void MainWindow::toggleVideo()
{
    if (_videoWidget->isHidden()) {
        _videoWidget->show();
        ui->buttonToggleVideo->setText("Hide");
        ui->chronoLabel->setText(formatTitle());
    }
    else {
        _videoWidget->hide();
        ui->buttonToggleVideo->setText("Show");
    }
}

void MainWindow::handleCountdown(qint64 position)
{
    if (_player->state() != QMediaPlayer::PausedState) {
        qint64 elapsedSeconds = (position - _startPosition) / 1000;
        qint64 remainingSeconds = 10 - elapsedSeconds;

        std::cout << "RemainingSeconds: " << remainingSeconds << std::endl;

        ui->chronoLabel->setText(QString::number(remainingSeconds) + "s");

        if (remainingSeconds < 0)
            showAnswer();

    }
}

void MainWindow::showAnswer()
{
    _player->pause();
    toggleVideo();  // Show video
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
    _startPosition = start;

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

/*
void MainWindow::addToPlaylist(const QUrl &file)
{
    _playlist << file;
}

void MainWindow::addToPlaylist(const QString &file)
{
    addToPlaylist(QUrl::fromLocalFile(file));
}*/

void MainWindow::addToPlaylist(const QEntry &file)
{
    _playlist << file;
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
        playFile(_playlist.at(--_current).getPath());
}

void MainWindow::nextClicked()
{
    if (_current < _playlist.size() - 1)
        playFile(_playlist.at(++_current).getPath());
}
