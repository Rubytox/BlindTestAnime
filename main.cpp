#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    /*
    QApplication a(argc, argv);

    QWidget *mainWidget = new QWidget();
    mainWidget->setGeometry(0, 0, 1920, 1080);

    QVideoWidget *widget = new QVideoWidget(mainWidget);
    widget->setGeometry(0, 0, 1920, 1080);

    QMediaPlayer *player = new QMediaPlayer;
    QUrl localUrl = QUrl::fromLocalFile("/home/rubytox/Vidéos/CL/Episodes/Saison1/output.mp4");
    player->setMedia(localUrl);
    std::cout << "Player error state: " << player->error() << std::endl;
    std::cout << "Media supported state: " << QMediaPlayer::hasSupport("video/mp4") << std::endl;
    player->setVideoOutput(widget);

    mainWidget->show();

    player->play();

    return a.exec();
    */
}
