#include "crud_input.h"

CrudInput::CrudInput(QWidget *parent) : QWidget(parent)
{
     addButton = new QPushButton;
     addButton->setText("ADD");
     updateButton = new QPushButton;
     updateButton->setText("UPDATE");
     deleteButton = new QPushButton;
     deleteButton->setText("DELETE");
     exportButton = new QPushButton;
     exportButton->setText("EXPORT");
     printButton = new QPushButton;
     printButton->setText("PRINT");

     layout = new QHBoxLayout;
     layout->addWidget(addButton);
     layout->addWidget(updateButton);
     layout->addWidget(deleteButton);
     layout->addWidget(exportButton);
     layout->addWidget(printButton);

     this->setLayout(layout);

}
