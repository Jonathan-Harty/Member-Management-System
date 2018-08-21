#include "member_selection.h"
#include <QtDebug>

MemberSelection::MemberSelection(QWidget *parent) : QWidget(parent)
{

    layout = new QVBoxLayout;

    selectionLayout = new QVBoxLayout;
    selectionLayout->setContentsMargins(0, 0, 0, 0);
    selectionLayout->setSpacing(0);

    selectionArea = new QWidget;
    selectionArea->setLayout(selectionLayout);

    searchArea = new MemberSearch;

    previewArea = new QScrollArea;
    previewArea->setWidgetResizable(true);
    previewArea->setWidget(selectionArea);

    layout->addWidget(searchArea);
    layout->addWidget(previewArea);

    this->setLayout(layout);
}

void MemberSelection::addPreview(MemberPreview* preview)
{
    selectionLayout->addWidget(preview);
}

void MemberSelection::formatPreviews()
{
    for(int i = 0; i < previewList.size(); i++)
    {
        previewList.at(i)->formatPreview();
    }
}

void MemberSelection::checkIfOthersClicked()
{
    for(int i = 0; i < previewList.size(); i++)
    {
        if(previewList.at(i)->getIsSelected())
        {
            previewList.at(i)->setFrameShadow(QFrame::Plain);
            previewList.at(i)->setStyleSheet("QLabel {background-color: #ffffff;}");
            previewList.at(i)->setIsSelected(false);
        }
    }
}
