#include "date_labels.h"

DateLabels::DateLabels(QWidget *parent) : QWidget(parent)
{
    day = new QLabel("Day");
    day->setAlignment(Qt::AlignCenter);
    month = new QLabel("Month");
    month->setAlignment(Qt::AlignCenter);
    year = new QLabel("Year");
    year->setAlignment(Qt::AlignCenter);

    layout = new QHBoxLayout;
    layout->addWidget(day);
    layout->addWidget(month);
    layout->addWidget(year);

    this->setLayout(layout);
}
