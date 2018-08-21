 #ifndef MEMBERSELECTION_H
#define MEMBERSELECTION_H

#include <qwidget.h>
#include <QVBoxLayout>
#include <QScrollArea>
#include "member_preview.h"
#include "member_search.h"
#include <QGroupBox>

class MemberSelection : public QWidget
{
    Q_OBJECT
public:
    explicit MemberSelection(QWidget *parent = nullptr);
    //~MemberSelection();
    void addPreview(MemberPreview* preview);
    QVBoxLayout* getSelectionLayout() const {return selectionLayout;}
    QWidget* getSelectionArea() const {return selectionArea;}
    QVector<MemberPreview*>* getSelectedPreviews() {return &previewList;}
    void formatPreviews();


signals:

public slots:
    void checkIfOthersClicked();

private:
    QVBoxLayout* layout;
    QVBoxLayout* selectionLayout;
    QWidget* selectionArea;
    MemberSearch* searchArea;
    QScrollArea* previewArea;
    QVector<MemberPreview*> previewList;
};

#endif // MEMBERSELECTION_H
