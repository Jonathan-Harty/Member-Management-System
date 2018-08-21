#ifndef NEXT_STEPS_INFO_ENTRY_H
#define NEXT_STEPS_INFO_ENTRY_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPlainTextEdit>

class NextStepsInfoEntry : public QWidget
{
    Q_OBJECT
public:
    explicit NextStepsInfoEntry(QWidget *parent = nullptr);
    QString getPaperwork();
    QString getOneOnOne();
    QString getRefNotes();
    QString getOrientation();

signals:

public slots:

private:
    QFormLayout* nsInputLayout;
    QVBoxLayout* layout;
    QLabel* nsTitle;
    QLineEdit* nsOrientationInput;
    QLineEdit* nsPaperworkInput;
    QLineEdit* ns1on1Input;
    QWidget* nsInput;
    QLabel* referralNotesLabel;
    QPlainTextEdit* referralNotesInput;

};

#endif // NEXT_STEPS_INFO_ENTRY_H
