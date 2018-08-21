#ifndef DATE_INPUT_H
#define DATE_INPUT_H

#include <QWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

class DateInput : public QWidget
{
    Q_OBJECT
public:
    explicit DateInput(QWidget *parent = nullptr);
    void fillDay(QComboBox*);
    void fillMonth(QComboBox*);
    void fillYear(QComboBox*);
    QString getDate();
    void setDate(const QString&);

signals:

public slots:

private:
    QVBoxLayout* layout;
    QHBoxLayout* dateLayout;
    QComboBox* dayInput;
    QComboBox* monthInput;
    QComboBox* yearInput;
};

#endif // DATE_INPUT_H
