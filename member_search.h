#ifndef MEMBER_SEARCH_H
#define MEMBER_SEARCH_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>
#include <QLineEdit>

class MemberSearch : public QWidget
{
    Q_OBJECT
public:
    explicit MemberSearch(QWidget *parent = nullptr);
    QGridLayout* getLayout() {return layout;}

signals:

public slots:

private:
    QPushButton* searchFacility;
    QPushButton* searchName;
    QPushButton* filter;
    QPushButton* searchAll;
    QPushButton* updateSearch;
    QComboBox* filterOptions;
    QLineEdit* searchBar;
    QGridLayout* layout;
};

#endif // MEMBER_SEARCH_H
