#ifndef INCENTIVES_LABELS_H
#define INCENTIVES_LABELS_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class IncentivesLabels : public QWidget
{
    Q_OBJECT
public:
    explicit IncentivesLabels(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel* space;
    QLabel* earnedLabel;
    QLabel* receivedLabel;
    QHBoxLayout* layout;
};

#endif // INCENTIVES_LABELS_H
