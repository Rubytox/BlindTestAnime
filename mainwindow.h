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
    void addToPlaylist(const QUrl& file);
    void addToPlaylist(const QString& file);

    void randomPlace();


public slots:
    void playClicked();
    void pauseClicked();
    void previousClicked();
    void nextClicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *_player;
    QVideoWidget *_videoWidget;

    int _current;
    QList<QUrl> _playlist;
};
#endif // MAINWINDOW_H
