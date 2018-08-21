#include "member_incentives.h"

MemberIncentives::MemberIncentives(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout;

    incentiveType = new QLabel("Label");
    earnedBox = new QCheckBox;
    receivedBox = new QCheckBox;

    layout->addWidget(incentiveType);
    layout->addWidget(earnedBox);
    layout->addWidget(receivedBox);

    this->setLayout(layout);
}

int MemberIncentives::getEarned()
{
    if(earnedBox->isChecked())
    {
        return 1;
    }

    return 0;
}

int MemberIncentives::getReceived()
{
    if(receivedBox->isChecked())
    {
        return 1;
    }

    return 0;
}
