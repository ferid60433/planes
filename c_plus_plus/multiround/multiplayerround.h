#ifndef __MULTIPLAYER_ROUND__
#define __MULTIPLAYER_ROUND__

#include <QObject>
#include <QNetworkAccessManager>
#include <QSettings>
#include <QJsonObject>
#include <QNetworkReply>
#include "abstractplaneround.h"
#include "global/globaldata.h"
#include "communicationobjects/creategamecommobj.h"
#include "communicationobjects/connecttogamecommobj.h"
#include "communicationobjects/refreshgamestatuscommobj.h"
#include "communicationobjects/logincommobj.h"
#include "communicationobjects/registercommobj.h"
#include "communicationobjects/norobotcommobj.h"
#include "communicationobjects/sendplanepositionscommobj.h"
#include "communicationobjects/acquireopponentpositionscommobj.h"
#include "communicationobjects/sendmovecommobj.h"
#include "communicationobjects/requestopponentmovescommobj.h"
#include "communicationobjects/cancelroundcommobj.h"
#include "communicationobjects/startnewroundcommobj.h"
#include "communicationobjects/sendwinnercommobj.h"

class MultiplayerRound : public QObject, public AbstractPlaneRound  {
    Q_OBJECT
    
private:
    
    //TODO: computer moves with index so that it also works when replies come in different order as they were sent
    //player and computer moves with index
    //when requesting moves send a list of indices that need to be sent
    //when error on send move send again
    //when sending allow multiple moves to be sent
    //save indices that were succesfully sent
    int m_PlayerMoveIndex = 0;
    int m_ComputerMoveIndex = 0;
    QNetworkAccessManager* m_NetworkManager;
    GlobalData* m_GlobalData;
    QSettings* m_Settings;
    
    bool m_IsSinglePlayer = false;
    
    CreateGameCommObj* m_CreateGameObj;
    ConnectToGameCommObj* m_ConnectToGameObj;
    RefreshGameStatusCommObj* m_RefreshGameStatusCommObj;
    LoginCommObj* m_LoginCommObj;
    RegisterCommObj* m_RegisterCommObj;
    NoRobotCommObj* m_NoRobotCommObj;
    SendPlanePositionsCommObj* m_SendPlanePositionsCommObj;
    AcquireOpponentPositionsCommObj* m_AcquireOpponentPlanePositions;
    SendMoveCommObj* m_SendMoveCommObj;
    //RequestOpponentMovesCommObj* m_RequestOpponentMovesObj;
    CancelRoundCommObj* m_CancelRoundCommObj;
    StartNewRoundCommObj* m_StartNewRoundCommObj;
    SendWinnerCommObj* m_SendWinnerCommObj;

    std::vector<int> m_NotSentMoves;
    std::vector<int> m_ReceivedMoves;
    
private slots:    
    void connectedToGameSlot(const QString& gameName, const QString& firstPlayerName, const QString& secondPlayerName, const QString& currentRoundId);
    
signals:
    void opponentMoveGenerated(const GuessPoint& gp);
    void roundWasCancelled();
    void newRoundStarted();

    void gameCreated(const QString& gameName, const QString& userName);
    void gameConnectedTo(const QString& gameName, const QString& firstPlayerName, const QString& secondPlayerName, const QString& currentRoundId);
    void refreshStatus(const QString& gameName, const QString& firstPlayerName, const QString& secondPlayerName, const QString& currentRoundId);
    void loginCompleted();
    void noRobotRegistration(const std::vector<QString>& images, const QJsonObject& request);
    void registrationFailed();
    void registrationComplete();
    
    void opponentPlanePositionsReceived();
    void waitForOpponentPlanePositions();
    void winnerSent(bool isPlayerWinner, bool draw);
    void gameStatsUpdated(const GameStatistics& gameStats);
    
public:
    MultiplayerRound(int rows, int cols, int planeNo, QNetworkAccessManager* networkManager, GlobalData* globalData, QSettings* settings);
    void reset() override;
    void initRound() override;

    void playerGuess(const GuessPoint& gp, PlayerGuessReaction& pgr) override;
    void playerGuessIncomplete(int row, int col, GuessPoint::Type& guessRes, PlayerGuessReaction& pgr) override;
    
    void addOpponentMove(GuessPoint& gp, int moveIndex);
    
    long int getRoundId() {
        return m_GlobalData->m_GameData.m_RoundId;
    }
    
    void getPlayerPlaneNo(int pos, Plane& pl);
    bool setComputerPlanes(int plane1_x, int plane1_y, Plane::Orientation plane1_orient, int plane2_x, int plane2_y, Plane::Orientation plane2_orient, int plane3_x, int plane3_y, Plane::Orientation plane3_orient); 
    
    //TODO to add method also in normal round
    void setRoundCancelled();
    
    //Requests to server
    void createGame(const QString& gameName);
    void connectToGame(const QString& gameName);
    void refreshGameStatus(const QString& gameName);
    void login(const QString& username, const QString& password);
    void registerUser(const QString& username, const QString& password);
    void noRobotRegister(const QString& requestId, const QString& answer);
    void sendPlanePositions();
    void acquireOpponentPlanePositions();
    void sendMove(const GuessPoint& gp, int ownMoveIndex, int opponentMoveIndex);
    void requestOpponentMoves();
    void cancelRound();
    void startNewRound();
    void sendWinner(bool draw, long int winnerId);
    
    void deleteFromNotSentList(int value); 
    void addToNotSentList(int value);
    bool moveAlreadyReceived(int moveIndex);
    void addToReceivedList(int value);
    
private:
    bool validateOpponentMovesReply(const QJsonObject& reply);
    void startNewRound(long int desiredRoundId);
    bool checkRoundEnd(bool& draw, long int& winnerId, bool& isPlayerWinner);
};













#endif
