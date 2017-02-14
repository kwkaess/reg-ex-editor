#ifndef REGEXEDITOR_H
#define REGEXEDITOR_H

#include <QWidget>

namespace Ui {
class RegExEditor;
}

class RegExEditor : public QWidget
{
    Q_OBJECT

public:
    explicit RegExEditor(QWidget *parent = 0);
    ~RegExEditor();

private:
    Ui::RegExEditor *ui;
};

#endif // REGEXEDITOR_H
