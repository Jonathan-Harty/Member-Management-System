#include "date_input.h"

DateInput::DateInput(QWidget *parent) : QWidget(parent)
{
    dayInput = new QComboBox;
    fillDay(dayInput);
    monthInput = new QComboBox;
    fillMonth(monthInput);
    yearInput = new QComboBox;
    fillYear(yearInput);

    dateLayout = new QHBoxLayout;
    dateLayout->addWidget(dayInput);
    dateLayout->addWidget(monthInput);
    dateLayout->addWidget(yearInput);

    this->setLayout(dateLayout);
}

void DateInput::fillDay(QComboBox* day)
{
    for(int i = 1; i < 32; i++)
    {
        day->addItem(QString::number(i));
    }
}

void DateInput::fillMonth(QComboBox* month)
{
    month->addItem("January");
    month->addItem("February");
    month->addItem("March");
    month->addItem("April");
    month->addItem("May");
    month->addItem("June");
    month->addItem("July");
    month->addItem("August");
    month->addItem("September");
    month->addItem("October");
    month->addItem("November");
    month->addItem("December");
}

void DateInput::fillYear(QComboBox* year)
{
    for(int i = 2018; i > 1950; i--)
    {
        year->addItem(QString::number(i));
    }
}

QString DateInput::getDate()
{
    QString date = "";
    date += dayInput->currentText() + " ";
    date += monthInput->currentText() + " ";
    date += yearInput->currentText();

    return date;
}

void DateInput::setDate(const QString &date)
{
    QString day = "", month = "", year = "";


}
