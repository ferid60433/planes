#ifndef PLANESGSVIEW_H
#define PLANESGSVIEW_H

#include <QWidget>

#include "leftpane.h"
#include "rightpane.h"
#include "planegrid.h"
#include "planeroundjavafx.h"


class PlanesGSView : public QWidget
{
    Q_OBJECT
public:
    explicit PlanesGSView(PlaneGrid *pGrid, PlaneGrid* cGrid, ComputerLogic* cLogic, PlaneRoundJavaFx *rd, QWidget *parent = 0);

signals:

public slots:

    inline void activateBoardEditingTab() {
        m_LeftPane->activateEditorTab();
    }

    void displayStatusMsg(const std::string& str);

private:

    //PlaneGrid objects manage the logic of a set of planes on a grid
    //as well as various operations: save, remove, search, etc.
    PlaneGrid* m_playerGrid;
    PlaneGrid* m_computerGrid;

    //PlaneRound is the object that coordinates the game
    PlaneRoundJavaFx* m_round;

    LeftPane* m_LeftPane;
    RightPane* m_RightPane;
};

#endif // PLANESGSVIEW_H
