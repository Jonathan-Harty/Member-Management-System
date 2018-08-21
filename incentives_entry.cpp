#include "incentives_entry.h"

IncentivesEntry::IncentivesEntry(QWidget *parent) : QWidget(parent)
{
    labels = new IncentivesLabels;
    boxes5 = new MemberIncentives;
    boxes25 = new MemberIncentives;
    boxes50 = new MemberIncentives;
    boxes75 = new MemberIncentives;
    boxes100 = new MemberIncentives;
    boxes175 = new MemberIncentives;
    boxes200 = new MemberIncentives;
    boxes375 = new MemberIncentives;
    layout = new QVBoxLayout;

    layout->addWidget(labels);
    layout->addWidget(boxes5);
    layout->addWidget(boxes25);
    layout->addWidget(boxes50);
    layout->addWidget(boxes75);
    layout->addWidget(boxes100);
    layout->addWidget(boxes175);
    layout->addWidget(boxes200);
    layout->addWidget(boxes375);

    this->setLayout(layout);
}

void IncentivesEntry::addMemberIncentives(QSqlQuery *query)
{
    query->bindValue(":e5", boxes5->getEarned());
    query->bindValue(":r5", boxes5->getReceived());

    query->bindValue(":e25", boxes25->getEarned());
    query->bindValue(":r25", boxes25->getReceived());

    query->bindValue(":e50", boxes50->getEarned());
    query->bindValue(":r50", boxes50->getReceived());

    query->bindValue(":e75", boxes75->getEarned());
    query->bindValue(":r75", boxes75->getReceived());

    query->bindValue(":e100", boxes100->getEarned());
    query->bindValue(":r100", boxes100->getReceived());

    query->bindValue(":e175", boxes175->getEarned());
    query->bindValue(":r175", boxes175->getReceived());

    query->bindValue(":e200", boxes200->getEarned());
    query->bindValue(":r200", boxes200->getReceived());

    query->bindValue(":e375", boxes375->getEarned());
    query->bindValue(":r375", boxes375->getReceived());
}
