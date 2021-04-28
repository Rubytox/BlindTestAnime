#include "DatabaseWindow.h"
#include "ui_DatabaseWindow.h"

DatabaseWindow::DatabaseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DatabaseWindow)
{
    ui->setupUi(this);

    _model = QEntryDAO::getInstance().getModel();

    ui->entriesTable->setModel(_model);
    ui->entriesTable->hideColumn(0);
    ui->entriesTable->horizontalHeader()->moveSection(4, 5);
    ui->entriesTable->show();
}

DatabaseWindow::~DatabaseWindow()
{
    delete ui;
    delete _model;
}
