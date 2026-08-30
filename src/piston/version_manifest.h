#pragma once


#include <QString>
#include <QList>
#include <QTime>
#include <QJsonObject>
#include <QJsonValueRef>
#include <QJsonArray>
#include <QMetaEnum>

struct Latest {
    QString release;
    QString snapshot;
};


class ReleaseTypeHelper : public QObject {
Q_OBJECT
public:
    enum ReleaseType {
        Release = 0,
        Snapshot,
        OldBeta,
        OldAlpha
    };
    Q_ENUM(ReleaseType)

    static QString toString(ReleaseType type) {
        QMetaEnum metaEnum = QMetaEnum::fromType<ReleaseType>();
        return metaEnum.valueToKey(type);
    }

    static ReleaseType fromString(const QString& str) {
        QMetaEnum metaEnum = QMetaEnum::fromType<ReleaseType>();
        return static_cast<ReleaseType>(metaEnum.keyToValue(str.toUtf8()));
    }
};

struct Version {
    QString id;
    ReleaseTypeHelper::ReleaseType type;
    QString url;
    QDateTime time;
    QDateTime releaseTime;
    QString sha1;
    uint16_t compliance_level;

};

struct ManifestV2 {
    Latest latest;
    QList<Version> versions;

    static ManifestV2 from_json(QJsonObject &object) {
        ManifestV2 manifest;
        Latest latest;

        QJsonObject latestObj = object["latest"].toObject();
        latest.release = latestObj["release"].toString();
        latest.snapshot = latestObj["snapshot"].toString();
        manifest.latest = latest;

        QJsonArray arr = object["versions"].toArray();
        for (const auto &item: arr) {
            QJsonObject itemObj = item.toObject();
            Version version;
            version.id = itemObj["id"].toString();
            version.type = ReleaseTypeHelper::fromString(itemObj["type"].toString());
            version.url = itemObj["url"].toString();
            version.time = QDateTime::fromString(itemObj["time"].toString(), Qt::ISODate);
            version.releaseTime = QDateTime::fromString(itemObj["release_time"].toString(), Qt::ISODate);
            version.sha1 = itemObj["sha1"].toString();
            version.compliance_level = itemObj["compliance_level"].toInt();
            manifest.versions.append(version);
        }
        return manifest;
    }
};