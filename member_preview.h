#ifndef MEMBER_PREVIEW_H
#define MEMBER_PREVIEW_H

#include <qwidget.h>
#include <QPainter>
#include <QPaintEvent>
#include <QLabel>
#include <QString>
#include <QHBoxLayout>
#include <QtSql>

class MemberPreview : public QLabel
{
    Q_OBJECT

public:
    explicit MemberPreview(const QString &infoText = "No Info", int id = -1, QWidget* parent = nullptr);
    //~MemberPreview();
    void setMemberInfo(const QString&);
    static void setQuery(QSqlQuery* q) {query = q;}
    int getID() const {return m_id;}
    void formatPreview();
    bool getIsSelected() {return m_isSelected;}
    void setIsSelected(bool selected) {m_isSelected = selected;}
    QSize sizeHint() const override;

signals:
    void isClicked();
    void isSelected(int m_id);
    void isUnSelected();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;

private:
    int m_id;
    bool m_isSelected;
    static QSqlQuery* query;
};

#endif // MEMBER_PREVIEW_H
