#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QString>
#include <iostream>
#include <QScreen>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setStyleSheet("background-color: #00bfff;");

    MemberSelection* memberSelection = new MemberSelection;
    QSizePolicy spSelection(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spSelection.setHorizontalStretch(1);
    memberSelection->setSizePolicy(spSelection);
    ui->layout->addWidget(memberSelection, 0, 0, 1, 1);

    MemberInfoEntry* infoEntry = new MemberInfoEntry;
    QSizePolicy spEdit(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spEdit.setHorizontalStretch(2);
    infoEntry->setSizePolicy(spEdit);
    ui->layout->addWidget(infoEntry, 0, 1, 1, 1);


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("member_data");
    db.setUserName("root");
    db.setPassword("BOMFBill2018");
    bool ok = db.open();
    if(ok)
    {
        qDebug() << "Good";
    }

    QSqlQuery* query = new QSqlQuery;
    MemberPreview::setQuery(query);
    MemberInfoEntry::setQuery(query);

    query->exec("Select * FROM members");

    while(query->next())
    {
        QString memberInfo = "";
        memberInfo += query->value(0).toString() + " ";
        int id = memberInfo.toInt();
        memberInfo += query->value(1).toString() + " ";
        memberInfo += query->value(2).toString() + " ";
        memberInfo += query->value(3).toString() + " ";
        memberInfo += query->value(4).toString() + " ";
        memberInfo += query->value(5).toString() + " ";
        memberInfo += query->value(6).toString();

        MemberPreview* member = new MemberPreview(memberInfo, id);
        connect(member, SIGNAL(isClicked()), memberSelection, SLOT(checkIfOthersClicked()));
        connect(member, SIGNAL(isSelected(int)), infoEntry, SLOT(previewSelected(int)));
        memberSelection->addPreview(member);

        memberSelection->getSelectedPreviews()->append(member);
    }

    memberSelection->formatPreviews();

}

MainWindow::~MainWindow()
{
    delete ui;
}
