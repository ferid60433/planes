#ifndef __CLICKABLE_LABEL__
#define __CLICKABLE_LABEL__

#include <QLabel>
#include <QString>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel { 
    Q_OBJECT 

public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();
    
    void setSelected(bool selected);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
    

};

#endif
