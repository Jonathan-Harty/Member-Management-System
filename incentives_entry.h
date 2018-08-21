#ifndef INCENTIVES_ENTRY_H
#define INCENTIVES_ENTRY_H

#include <QWidget>
#include <QVBoxLayout>
#include "member_incentives.h"
#include "incentives_labels.h"
#include <QtSql>

class IncentivesEntry : public QWidget
{
    Q_OBJECT
public:
    explicit IncentivesEntry(QWidget *parent = nullptr);
    void addMemberIncentives(QSqlQuery* q);

signals:

public slots:

private:
    IncentivesLabels* labels;
    MemberIncentives* boxes5;
    MemberIncentives* boxes25;
    MemberIncentives* boxes50;
    MemberIncentives* boxes75;
    MemberIncentives* boxes100;
    MemberIncentives* boxes175;
    MemberIncentives* boxes200;
    MemberIncentives* boxes375;
    QVBoxLayout* layout;
};

#endif // INCENTIVES_ENTRY_H
