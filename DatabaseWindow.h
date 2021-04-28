#ifndef DATABASEWINDOW_H
#define DATABASEWINDOW_H

#include <QMainWindow>

#include <QSqlTableModel>

#include "QEntryDAO.h"

namespace Ui {
class DatabaseWindow;
}

class DatabaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DatabaseWindow(QWidget *parent = nullptr);
    ~DatabaseWindow();

private:
    Ui::DatabaseWindow *ui;

    QSqlTableModel* _model;
};

#endif // DATABASEWINDOW_H
