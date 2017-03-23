#include "regexeditor.h"
#include "ui_regexeditor.h"

#include <iostream>

RegExEditor::RegExEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegExEditor),
    qNAM(this)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,50);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
}

RegExEditor::~RegExEditor()
{
    delete ui;
}

void RegExEditor::on_pushButton_clicked()
{
     QUrl qurl(ui->lineEdit->text());
     if (!qurl.isValid()) {
         QMessageBox::warning(this,"Invalid URL",qurl.errorString());
     } else {
         qNR.reset(qNAM.get(QNetworkRequest(qurl)));
         connect(qNR.get(),&QNetworkReply::finished,this,&RegExEditor::on_NetworkResponse);  //Should I do this just once?
     }
}

void RegExEditor::on_NetworkResponse() {
    if (qNR->error()!=QNetworkReply::NoError) {
         QMessageBox::warning(this,"NetworkReply Error",qNR->errorString());
    } else {
        ui->textBrowser->setPlainText(QString::fromStdString(qNR->readAll().toStdString()));
    }
    disconnect(qNR.get(),&QNetworkReply::finished,this,&RegExEditor::on_NetworkResponse); //Is this necessary?
}

void RegExEditor::on_lineEdit_returnPressed()
{
    this->on_pushButton_clicked();
}
