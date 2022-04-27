#ifndef DATALOADER_H
#define DATALOADER_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonObject>
#include <QVariantList>
#include <QObject>

class QJsonDocument;

class DataLoader : public QObject
{
    Q_OBJECT
//    Q_DISABLE_COPY(DataLoader)
public:
    explicit DataLoader(QObject *parent = nullptr);
    enum class PlayerRole {
        C,
        A,
        NOTSET
    };
    enum class PlayerPosition {
        LF,
        CF,
        RF,
        LD,
        RD,
        G,
        NOTSET
    };
    enum class StuffPosition {
        general_coach,
        coach,
        coach_assistant,
        administrator,
        medic
    };
    struct Player {
        QString name;
        QString surname;
        QString secname;
        int number;
        PlayerRole role;
        PlayerPosition position;
    };
    struct Stuff {
        QString name;
        QString surname;
        QString secname;
        StuffPosition position;
    };
    struct Team {
        QString name;
        QString city;
        QString region;
        QString country;
        QList<Player> players;
        QList<Stuff> stuffs;
    };
    DataLoader::Team getTeam(const QString &path);
    void setTeamToGUI(DataLoader::Team team);
signals:
    void rightTeamSetted(QVariant rightSquad);
public slots:
    void callMe(const QString &path);
};

#endif // DATALOADER_H
