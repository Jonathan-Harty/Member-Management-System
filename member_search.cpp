#include "member_search.h"

MemberSearch::MemberSearch(QWidget *parent) : QWidget(parent)
{
    searchFacility = new QPushButton;
    searchFacility->setText("Search Facility");
    //searchFacility->setStyleSheet("QPushButton {border-radius: 2px;}");

    searchName = new QPushButton;
    searchName->setText("Search Name");
    //searchName->setStyleSheet("QPushButton {border-radius: 2px;}");

    filter = new QPushButton;
    filter->setText("Filter");
    //filter->setStyleSheet("QPushButton {border-radius: 2px;}");

    searchAll = new QPushButton;
    searchAll->setText("Search All");

    updateSearch = new QPushButton;
    updateSearch->setText("Update Search");

    filterOptions = new QComboBox;
    filterOptions->addItem("Select");
    filterOptions->addItem("Active");
    filterOptions->addItem("Next Steps");
    filterOptions->addItem("Alumni");

    searchBar = new QLineEdit;
    //searchBar->setStyleSheet("QLineEdit {border-radius: 2px;}");


    layout = new QGridLayout;
    layout->addWidget(searchFacility, 0, 1, 1, 1);
    layout->addWidget(searchName, 0, 0, 1, 1);
    layout->addWidget(filter, 1, 1, 1, 1);
    layout->addWidget(searchAll, 1, 3, 1, 1);
    layout->addWidget(updateSearch, 0, 3, 1, 1);
    layout->addWidget(filterOptions, 1, 0, 1, 1);
    layout->addWidget(searchBar, 0, 2, 1, 1);

    this->setLayout(layout);
}
