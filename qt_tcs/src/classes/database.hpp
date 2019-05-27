#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sqlite3.h>

class DataBase {
public:
    explicit DataBase(const std::string &path_to_db) : _path_to_db(path_to_db) {}
    ~DataBase() = default;

    //typedef nullptr DBNull;
    typedef std::string DBValue;
    typedef std::vector<DBValue> DBRow;
    typedef std::vector<DBRow> DBTable;

    bool ExecuteSqlQuery(const std::string &sql_query);
    bool ExecuteSqlQuery(const std::string &sql_query, DBValue &output);
    bool ExecuteSqlQuery(const std::string &sql_query, DBRow &output);
    bool ExecuteSqlQuery(const std::string &sql_query, DBTable &output);

private:
    sqlite3* _db;
    std::string _path_to_db;

    typedef int (*callback_function)(void*, int, char**, char**);

    template<typename T>
    bool _RunSequence(const std::string &sql_query, T &output);

    static int _CALLBACK_CALLS;
    static int _CallbackDBValue(void*, int, char**, char**);
    static int _CallbackDBRow(void*, int, char**, char**);
    static int _CallbackDBTable(void*, int, char**, char**);
};
#endif // DATABASE_HPP

