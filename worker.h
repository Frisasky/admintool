#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QTableWidgetItem>
#include "rcon.h"

class RulesInfo;
class InfoReply;
class PlayerInfo;
class LogHandler;

class Worker : public QThread
{
    Q_OBJECT

public slots:
    void getServerInfo(ServerInfo *, QTableWidgetItem *item);
    void getPlayerInfo(ServerInfo *, QTableWidgetItem *item);
    void getRulesInfo(ServerInfo *, QTableWidgetItem *item);
    void setupUPnP(LogHandler *);

signals:
    void serverInfoReady(ServerInfo *info, InfoReply *reply, QTableWidgetItem *item);
    void playerInfoReady(QList<PlayerInfo> *, QTableWidgetItem *item);
    void rulesInfoReady(QList<RulesInfo> *, QTableWidgetItem *item);
    void UPnPReady();
};

#endif // THREAD_H