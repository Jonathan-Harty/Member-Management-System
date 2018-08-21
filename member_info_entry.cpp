#include "member_info_entry.h"
#include <iostream>

QSqlQuery* MemberInfoEntry::query = nullptr;

MemberInfoEntry::MemberInfoEntry(QWidget *parent) : QWidget(parent)
{
    idLabel = new QLabel;
    idLabel->setText("Member Profile: No Member Selected");
    idLabel->setFrameStyle(QFrame::Panel | QFrame::Plain);
    idLabel->setStyleSheet("background-color: #ffffff;");
    firstNameInput = new QLineEdit;
    lastNameInput = new QLineEdit;
    facilityInput = new QLineEdit;
    phoneInput = new QLineEdit;
    emailInput = new QLineEdit;
    birthDateInput = new DateInput;
    hasResumeInput = new QComboBox;
    hasResumeInput->addItem("Select");
    hasResumeInput->addItem("Yes");
    hasResumeInput->addItem("No");
    isActiveInput = new QComboBox;
    isActiveInput->addItem("Select");
    isActiveInput->addItem("Yes");
    isActiveInput->addItem("No");
    isAlumniInput = new QComboBox;
    isAlumniInput->addItem("Select");
    isAlumniInput->addItem("Yes");
    isAlumniInput->addItem("No");
    statusInput = new QLineEdit;
    totalMilesInput = new QLineEdit;
    shoeSizeInput = new QLineEdit;
    shirtSizeInput = new QLineEdit;
    dateLabels = new DateLabels;
    gearDateInput = new DateInput;
    winterDateInput = new DateInput;
    orientationDateInput = new DateInput;
    nextStepsInput = new NextStepsInfoEntry;
    incentivesInput = new IncentivesEntry;
    crud = new CrudInput;

    connect(crud->getAddButton(), SIGNAL(clicked()), this, SLOT(addMember()));

    infoLayout = new QFormLayout;
    infoLayout->addRow(tr("&First Name"), firstNameInput);
    infoLayout->addRow(tr("&Last Name"), lastNameInput);
    infoLayout->addRow(tr("&Facility"), facilityInput);
    infoLayout->addRow(tr("&Phone"), phoneInput);
    infoLayout->addRow(tr("&Email"), emailInput);
    infoLayout->addRow(tr("&Resume"), hasResumeInput);
    infoLayout->addRow(tr("&Active"), isActiveInput);
    infoLayout->addRow(tr("&Alumni"), isAlumniInput);
    infoLayout->addRow(tr("&Status"), statusInput);
    infoLayout->addRow(tr("&Total Miles"), totalMilesInput);
    infoLayout->addRow(tr("&Shoe Size"), shoeSizeInput);
    infoLayout->addRow(tr("&Shirt Size"), shirtSizeInput);
    infoLayout->addRow(tr("&"), dateLabels);
    infoLayout->addRow(tr("&Birth Date"), birthDateInput);
    infoLayout->addRow(tr("&Gear Date"), gearDateInput);
    infoLayout->addRow(tr("&Winter Gear Date"), winterDateInput);
    infoLayout->addRow(tr("&Orientation Date"), orientationDateInput);

    formInput = new QWidget;
    formInput->setLayout(infoLayout);

    layout = new QGridLayout;
    layout->addWidget(idLabel, 0, 0, 1, 2);
    layout->addWidget(formInput, 1, 0, 1, 1);
    layout->addWidget(nextStepsInput, 1, 1, 1, 1);
    layout->addWidget(incentivesInput, 2, 0, 1, 2);
    layout->addWidget(crud, 3, 0, 1, 2);

    this->setLayout(layout);
}


void MemberInfoEntry::previewSelected(int m_id)
{
    std::cout << m_id << std::endl;
    if(!query)
    {
        std::cout << "Query can not be completed\n";
    }
    else
    {
        query->exec("SELECT * FROM members WHERE ID = " + QString::number(m_id));


        while(query->next())
        {
            idLabel->setText("Member Profile: " + query->value(0).toString());
            firstNameInput->setText(query->value(1).toString());
            lastNameInput->setText(query->value(2).toString());
            facilityInput->setText(query->value(3).toString());
            phoneInput->setText(query->value(4).toString());
            emailInput->setText(query->value(5).toString());
            birthDateInput->setDate(query->value(5).toString());
            //isActiveInput->setBox(query->value(5).toString());
        }
    }


}

void MemberInfoEntry::addMember()
{
    qDebug() << "Added";
    QString queryString = "INSERT INTO members (First_Name, Last_Name, Facility, Cell_Phone, Email, Birthday, Active, Alumni, "
                          "Member_Status, Total_Miles, Shirt_Size, Shoe_Size, Gear_Date, Orientation_Date, Winter_Gear_Date, "
                          "Resume, Referral_Notes, Next_Steps_Orientation, Next_Steps_Goal_Setting_Paperwork, Next_Steps_One_On_One, "
                          "Earned_5_Miles, Received_5_Miles, Earned_25_Miles, Received_25_Miles, Earned_50_Miles, Received_50_Miles, "
                          "Earned_75_Miles, Received_75_Miles, Earned_100_Miles, Received_100_Miles, Earned_175_Miles, Received_175_Miles, "
                          "Earned_200_Miles, Received_200_Miles, Earned_375_Miles, Received_375_Miles)"
                          "VALUES (:firstName, :lastName, :facility, :cell, :email, :bday, :active, :alum, :memStatus, :totalMiles, :shirtSize, "
                          ":shoeSize, :gearDate, :orienDate, :winGearDate, :resume, :nsRefNotes, :nsOrientation, :nsPaperwork, :ns1on1, :e5, :r5,"
                          ":e25, :r25, :e50, :r50, :e75, :r75, :e100, :r100, :e175, :r175, :e200, :r200, :e375, :r375)";

    query->prepare(queryString);

    query->bindValue(":firstName", firstNameInput->text());
    query->bindValue(":lastName", lastNameInput->text());
    query->bindValue(":facility", facilityInput->text());
    query->bindValue(":cell", phoneInput->text());
    query->bindValue(":email", emailInput->text());
    query->bindValue(":bday", birthDateInput->getDate());
    query->bindValue(":active", isActiveInput->currentText());
    query->bindValue(":alum", isAlumniInput->currentText());
    query->bindValue(":memStatus", statusInput->text());
    query->bindValue(":totalMiles", totalMilesInput->text());
    query->bindValue(":shirtSize", shirtSizeInput->text());
    query->bindValue(":shoeSize", shoeSizeInput->text());
    query->bindValue(":gearDate", gearDateInput->getDate());
    query->bindValue(":orienDate", orientationDateInput->getDate());
    query->bindValue(":winGearDate", winterDateInput->getDate());
    query->bindValue(":resume", hasResumeInput->currentText());
    query->bindValue(":nsRefNotes", nextStepsInput->getRefNotes());
    query->bindValue(":nsOrientation", nextStepsInput->getOrientation());
    query->bindValue(":nsPaperwork", nextStepsInput->getPaperwork());
    query->bindValue(":ns1on1", nextStepsInput->getOneOnOne());

    incentivesInput->addMemberIncentives(query);

    if(!query->exec())
    {
        qDebug() << "Bad";
    }

}

void MemberInfoEntry::updateMember()
{

}

void MemberInfoEntry::deleteMember()
{

}

