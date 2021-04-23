#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QGraphicsVideoItem>
#include <QPushButton>

#include <QList>

#include <QRandomGenerator64>
#include <QThread>

#include <iostream>

#include "QEntry.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void playFile(const QUrl& file);
    //void addToPlaylist(const QUrl& file);
    //void addToPlaylist(const QString& file);
    void addToPlaylist(const QEntry& file);

    void randomPlace();

    void showAnswer();


public slots:
    void playClicked();
    void pauseClicked();
    void previousClicked();
    void nextClicked();
    void toggleVideo();
    void handleCountdown(qint64 position);

private:
    QString formatTitle() const;

    Ui::MainWindow *ui;
    QMediaPlayer *_player;
    QVideoWidget *_videoWidget;

    quint32 _startPosition;

    int _current;
    //QList<QUrl> _playlist;
    QList<QEntry> _playlist;
};
#endif // MAINWINDOW_H
