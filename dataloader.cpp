#include "dataloader.h"
#include <QFile>
#include <QFileDialog>
#include <iostream>

DataLoader::DataLoader()
{

}

QJsonDocument DataLoader::getTeam(const QString &path)
{
    try {
        QFile file(path);
        QByteArray data;
        file.open(QIODevice::ReadOnly);
        data = file.readAll();
        QJsonDocument settings_doc = QJsonDocument::fromJson(data);
        QJsonObject team_obj = settings_doc.object();
        Team m_team;
        m_team.name = team_obj.value("TeamName").toString();
        ;
        return settings_doc;
    }  catch (...) {
        std::cout << "some fail..." << std::endl;
    }
}
