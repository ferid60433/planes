#ifndef __NOROBOT_COMM_OBJ__
#define __NOROBOT_COMM_OBJ__


#include "basiscommobj.h"

class NoRobotCommObj : public BasisCommObj {
    Q_OBJECT
    
public:
    NoRobotCommObj(const QString& requestPath, const QString& actionName, QNetworkAccessManager* networkManager, QSettings* settings, bool isSinglePlayer, GlobalData* globalData):
        BasisCommObj(requestPath, actionName, networkManager, settings, isSinglePlayer, globalData) {}
    
    bool makeRequest(const QString& requestId, const QString& answer);
    bool validateReply(const QJsonObject& retJson) override;
    
public slots:
    void finishedRequest() override;   
    void errorRequest(QNetworkReply::NetworkError code) override;
    
    
signals:
    void registrationFailed();
    void registrationComplete();
};















#endif
