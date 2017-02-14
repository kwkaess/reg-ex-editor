#include "regexeditor.h"
#include "ui_regexeditor.h"

RegExEditor::RegExEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegExEditor)
{
    ui->setupUi(this);
}

RegExEditor::~RegExEditor()
{
    delete ui;
}
