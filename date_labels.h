#ifndef DATE_LABELS_H
#define DATE_LABELS_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class DateLabels : public QWidget
{
    Q_OBJECT
public:
    explicit DateLabels(QWidget *parent = nullptr);

signals:

public slots:

private:
    QHBoxLayout* layout;
    QLabel* day;
    QLabel* month;
    QLabel* year;
};

#endif // DATE_LABELS_H
