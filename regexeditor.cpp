#include "regexeditor.h"
#include "ui_regexeditor.h"

RegExEditor::RegExEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegExEditor)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,50);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
}

RegExEditor::~RegExEditor()
{
    delete ui;
}
