#ifndef MEMBER_INFO_ENTRY_H
#define MEMBER_INFO_ENTRY_H

#include <QWidget>
#include <QFormLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include "date_input.h"
#include "date_labels.h"
#include "next_steps_info_entry.h"
#include "incentives_entry.h"
#include "crud_input.h"
#include <QtSql>
#include<QDebug>

class MemberInfoEntry : public QWidget
{
    Q_OBJECT
public:
    explicit MemberInfoEntry(QWidget *parent = nullptr);
    static void setQuery(QSqlQuery* q) {query = q;}

signals:

public slots:
    void previewSelected(int m_id);
    void addMember();
    void updateMember();
    void deleteMember();

private:
    QGridLayout* layout;
    QFormLayout* infoLayout;
    QWidget* formInput;
    QLabel* idLabel;
    QLineEdit* firstNameInput;
    QLineEdit* lastNameInput;
    QLineEdit* facilityInput;
    QLineEdit* phoneInput;
    QLineEdit* emailInput;
    DateInput* birthDateInput;
    QComboBox* isActiveInput;
    QComboBox* isAlumniInput;
    QLineEdit* statusInput;
    QLineEdit* totalMilesInput;
    QLineEdit* shoeSizeInput;
    QLineEdit* shirtSizeInput;
    DateLabels* dateLabels;
    DateInput* gearDateInput;
    DateInput* winterDateInput;
    DateInput* orientationDateInput;
    QComboBox* hasResumeInput;
    NextStepsInfoEntry* nextStepsInput;
    IncentivesEntry* incentivesInput;
    CrudInput* crud;
    static QSqlQuery* query;

};

#endif // MEMBER_INFO_ENTRY_H
