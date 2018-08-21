#include "member_preview.h"
#include <iostream>
#include <QDebug>

QSqlQuery* MemberPreview::query = nullptr;

MemberPreview::MemberPreview(const QString &infoText, int id, QWidget* parent)
    : QLabel(parent), m_id(id), m_isSelected(false)
{
    this->setAttribute(Qt::WA_Hover, true);
    this->setMemberInfo(infoText);
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    QVBoxLayout* lay = new QVBoxLayout;
    this->setLayout(lay);
}


void MemberPreview::setMemberInfo(const QString &infoText)
{
    this->setText(infoText);
}

void MemberPreview::formatPreview()
{
    this->setFrameStyle(QFrame::Panel | QFrame::Plain);
    this->setLineWidth(1);
    this->setStyleSheet("QLabel {background-color: #ffffff;}");

    this->setAlignment(Qt::AlignCenter);
}


QSize MemberPreview::sizeHint() const
{
    return QSize(100, 25);
}


void MemberPreview::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(!m_isSelected)
        {
            this->setFrameShadow(QFrame::Sunken);
            this->setStyleSheet("QLabel {background-color: #b4eeb4;}");
            emit isClicked();
            emit isSelected(m_id);
            m_isSelected = true;
        }
        else
        {
            this->setFrameShadow(QFrame::Plain);
            this->setStyleSheet("QLabel {background-color: #ffffff;}");
            m_isSelected = false;
        }
    }
}


void MemberPreview::enterEvent(QEvent *event)
{
    if(!m_isSelected)
    {
        this->setFrameShadow(QFrame::Raised);
        this->setStyleSheet("QLabel {background-color: #c0c0c0;}");
    }
    else
    {
        this->setFrameShadow(QFrame::Raised);
        this->setStyleSheet("QLabel {background-color: #548B54;}");
    }

}


void MemberPreview::leaveEvent(QEvent *event)
{
    if(!m_isSelected)
    {
        this->setFrameShadow(QFrame::Plain);
        this->setStyleSheet("QLabel {background-color: #ffffff;}");
    }
    else
    {
        this->setFrameShadow(QFrame::Sunken);
        this->setStyleSheet("QLabel {background-color: #b4eeb4;}");
    }
}

