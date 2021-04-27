#include "DatabaseWindow.h"
#include "ui_DatabaseWindow.h"

DatabaseWindow::DatabaseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DatabaseWindow)
{
    ui->setupUi(this);
}

DatabaseWindow::~DatabaseWindow()
{
    delete ui;
}
