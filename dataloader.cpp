#include "dataloader.h"
#include <QFile>
#include <QFileDialog>
#include <iostream>
#include <QJsonArray>
#include <QJsonParseError>
#include <QDebug>

DataLoader::DataLoader()
{

}

QJsonDocument DataLoader::getTeam(const QString &path)
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

        for(auto pl:json.value("Players").toObject()) {
            bool a = pl.isObject();
            std::cout << "1";
            ;

        }
        return settings_doc;
    }  catch (...) {
        std::cout << "some fail..." << std::endl;
    }
}
