#ifndef CRUD_INPUT_H
#define CRUD_INPUT_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class CrudInput : public QWidget
{
    Q_OBJECT
public:
    explicit CrudInput(QWidget *parent = nullptr);
    QPushButton* getAddButton() {return addButton;}
    QPushButton* getUpdateButton() {return updateButton;}
    QPushButton* getDeleteButton() {return deleteButton;}
    QPushButton* getExportButton() {return exportButton;}
    QPushButton* getPrintButton() {return printButton;}

signals:

public slots:

private:
    QPushButton* addButton;
    QPushButton* updateButton;
    QPushButton* deleteButton;
    QPushButton* exportButton;
    QPushButton* printButton;
    QHBoxLayout* layout;
};

#endif // CRUD_INPUT_H
