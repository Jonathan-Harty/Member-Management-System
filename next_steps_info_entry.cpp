#include "next_steps_info_entry.h"

NextStepsInfoEntry::NextStepsInfoEntry(QWidget *parent) : QWidget(parent)
{
    nsInputLayout = new QFormLayout;
    nsTitle = new QLabel("Next Steps:");
    nsOrientationInput = new QLineEdit;
    nsPaperworkInput = new QLineEdit;
    ns1on1Input = new QLineEdit;
    referralNotesLabel = new QLabel("Referral Notes:");
    referralNotesInput = new QPlainTextEdit;

    nsInputLayout->addRow(tr("&Next Steps Orientation"), nsOrientationInput);
    nsInputLayout->addRow(tr("&Next Steps Paperwork"), nsPaperworkInput);
    nsInputLayout->addRow(tr("&Next Steps one-on-one"), ns1on1Input);

    nsInput = new QWidget;
    nsInput->setLayout(nsInputLayout);

    layout = new QVBoxLayout;
    layout->addWidget(nsTitle);
    layout->addWidget(nsInput);
    layout->addWidget(referralNotesLabel);
    layout->addWidget(referralNotesInput);

    this->setLayout(layout);
}

QString NextStepsInfoEntry::getPaperwork()
{
    QString nsPaperwork = nsPaperworkInput->text();
    return nsPaperwork;
}

QString NextStepsInfoEntry::getOneOnOne()
{
    QString ns1on1 = ns1on1Input->text();
    return ns1on1;
}

QString NextStepsInfoEntry::getRefNotes()
{
    QString nsRefNotes = referralNotesInput->toPlainText();
    return nsRefNotes;
}

QString NextStepsInfoEntry::getOrientation()
{
    QString nsOrientation = nsOrientationInput->text();
    return nsOrientation;
}
