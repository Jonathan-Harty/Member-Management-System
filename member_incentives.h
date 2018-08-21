#ifndef MEMBER_INCENTIVES_H
#define MEMBER_INCENTIVES_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QHBoxLayout>

class MemberIncentives : public QWidget
{
    Q_OBJECT
public:
    explicit MemberIncentives(QWidget *parent = nullptr);
    int getEarned();
    int getReceived();

signals:

public slots:

private:
    QHBoxLayout* layout;
    QLabel* incentiveType;
    QCheckBox* earnedBox;
    QCheckBox* receivedBox;
};

#endif // MEMBER_INCENTIVES_H
