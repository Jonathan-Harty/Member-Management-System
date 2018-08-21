#include "incentives_labels.h"

IncentivesLabels::IncentivesLabels(QWidget *parent) : QWidget(parent)
{
    space = new QLabel;
    earnedLabel = new QLabel("Earned");
    //earnedLabel->setAlignment(Qt::AlignCenter);
    receivedLabel = new QLabel("Received");
    //receivedLabel->setAlignment(Qt::AlignCenter);

    layout = new QHBoxLayout;
    layout->addWidget(space);
    layout->addWidget(earnedLabel);
    layout->addWidget(receivedLabel);

    this->setLayout(layout);
}
