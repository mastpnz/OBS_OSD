#include "dataloader.h"
#include <QFile>
#include <QFileDialog>
#include <iostream>
#include <QJsonArray>
#include <QJsonParseError>
#include <QDebug>

DataLoader::DataLoader(QObject *parent)
    : QObject(parent)
{
}

DataLoader::Team DataLoader::getTeam(const QString &path)
{
    try {
        QFile file(path);
        QByteArray data;
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        data = file.readAll();
        QJsonParseError error;
        QJsonDocument settings_doc = QJsonDocument::fromJson(data);
        qDebug() << "Error: " << error.errorString() << error.offset << error.error;
        QJsonObject json = settings_doc.object();
        Team team;
        team.name = json.value("TeamName").toString();
        team.city = json.value("City").toString();
        team.region = json.value("Region").toString();
        team.country = json.value("Country").toString();
        QJsonArray playerobj = json.value("Players").toArray();
        for(auto player : playerobj) {
            Player pl;
            pl.name = player.toObject().value("name").toString();
            pl.surname = player.toObject().value("surname").toString();
            pl.secname = player.toObject().value("secname").toString();
            pl.number = player.toObject().value("number").toString().toInt();
            QStringList poslist;
            poslist << "LF" << "CF" << "RF" << "LD" << "RD" << "G";
            switch (poslist.indexOf(player.toObject().value("position").toString())) {
                case 0: pl.position = PlayerPosition::LF; break;
                case 1: pl.position = PlayerPosition::CF; break;
                case 2: pl.position = PlayerPosition::RF; break;
                case 3: pl.position = PlayerPosition::LD; break;
                case 4: pl.position = PlayerPosition::RD; break;
                case 5: pl.position = PlayerPosition::G; break;
                default: pl.position = PlayerPosition::NOTSET; break;
            }
            QStringList rolelist;
            rolelist << "C" << "A";
            switch (rolelist.indexOf(player.toObject().value("role").toString())) {
                case 0: pl.role = PlayerRole::C; break;
                case 1: pl.role = PlayerRole::A; break;
                default: pl.role = PlayerRole::NOTSET; break;
            }
            team.players.append(pl);
        }
        return team;
    }  catch (...) {
        std::cout << "some fail..." << std::endl;
    }
}

void DataLoader::setTeamToGUI(DataLoader::Team team){

    QVariantList varlist;
    foreach (auto &pl, team.players) {
        QVariantMap map;
        map.insert("name",pl.name + " " + pl.surname);
        map.insert("number",QString("%1").arg(pl.number));
        switch (pl.position) {
            case PlayerPosition::LF:
            case PlayerPosition::CF:
            case PlayerPosition::RF: map.insert("position","F"); break;
            case PlayerPosition::LD:
            case PlayerPosition::RD: map.insert("position","D"); break;
            case PlayerPosition::G: map.insert("position","G"); break;
            case PlayerPosition::NOTSET:
            default: map.insert("position",""); break;
        }
        switch (pl.role) {
            case PlayerRole::C: map.insert("role","C"); break;
            case PlayerRole::A: map.insert("role","A"); break;
            case PlayerRole::NOTSET:
            default: map.insert("role",""); break;
        }
        varlist.append(map);
    }
    emit rightTeamSetted(QVariant::fromValue(varlist));
}

void DataLoader::callMe(const QString &path) {
    setTeamToGUI(getTeam(path));
}
