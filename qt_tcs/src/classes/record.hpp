#ifndef RECORD_HPP
#define RECORD_HPP

#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

class Record
{
public:
    struct Pair {
        QString Name;
        QString Value;
    };
    Record(const QString path_to_db, const QString &table, const QStringList &columns);
    //Record(const QString path_to_db, const QString command) : _PATH_TO_DB(path_to_db), _command(command) {}
    ~Record() = default;

    bool read(const int &id);
    bool save(const int &id = 0);

    QString getValue(const QString &name) const;
    bool setValue(const QString &name, const QString value);

    QList<Pair> pairs() const { return _pairs; }
private:
    const QString _PATH_TO_DB;
    const QString _TABLE;

    QSqlDatabase _db;
    QList<Pair> _pairs;

    bool _is_new = true;
    QString _command;

    QString _buildSelectCommand(const QStringList &columns);
    QString _buildInsertCommand(const QList<Pair> &pairs);
    QString _buildUpdateCommand(const QList<Pair> &pairs);

    int _executeInsert(const QString &command);
    bool _readPairs(const int &id);
};
#endif // RECORD_HPP

