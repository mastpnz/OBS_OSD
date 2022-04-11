#ifndef DATALOADER_H
#define DATALOADER_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonObject>
#include <QVariantList>

class QJsonDocument;


class DataLoader
{
public:
    enum class PlayerRole {
        C,
        A
    };

    enum class PlayerPosition {
        LF,
        CF,
        RF,
        LD,
        RD,
        G
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
    DataLoader();
    static QJsonDocument getTeam(const QString &path);
};

#endif // DATALOADER_H
