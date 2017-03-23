#ifndef REGEXEDITOR_H
#define REGEXEDITOR_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QMessageBox>
#include <QNetworkReply>
#include <memory>

namespace Ui {
class RegExEditor;
}

class RegExEditor : public QWidget
{
    Q_OBJECT

public:
    explicit RegExEditor(QWidget *parent = 0);
    ~RegExEditor();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_NetworkResponse();

private:
    Ui::RegExEditor *ui;
    QNetworkAccessManager qNAM;
    std::unique_ptr<QNetworkReply> qNR;
};

#endif // REGEXEDITOR_H
