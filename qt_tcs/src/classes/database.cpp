#include "database.hpp"
/* ************************************************************************************************************************ */
bool DataBase::ExecuteSqlQuery(const std::string &sql_query)
{
    int n = 0;
    return _RunSequence(sql_query, n);
}
bool DataBase::ExecuteSqlQuery(const std::string &sql_query, DataBase::DBValue &output)
{
    return _RunSequence(sql_query, output);
}
bool DataBase::ExecuteSqlQuery(const std::string &sql_query, DataBase::DBRow &output)
{
    return _RunSequence(sql_query, output);
}
bool DataBase::ExecuteSqlQuery(const std::string &sql_query, DataBase::DBTable &output)
{
    return _RunSequence(sql_query, output);
}

template<typename T>
bool DataBase::_RunSequence(const std::string &sql_query, T &output)
{
    bool result = false;        // флаг результата выполнения функции
    // проверка - файл базы существует
    if (FILE *db_file = fopen(_path_to_db.c_str(), "r")) {
        fclose(db_file);
        // проверка - запрос не пуст
        if (!sql_query.empty()) {
            char* err;              // указатель на ошибку
            bool is_open = false;   // флаг открытия БД
            try {
                //открываем БД
                is_open = sqlite3_open(_path_to_db.c_str(), &_db) == 0;
                if (is_open) {
                    callback_function callback = nullptr;
                    // проверяем тип возвращаемого значения и привязываем соответствующий колбэк
                    if (typeid (output) == typeid (DBValue)) {
                        callback = _CallbackDBValue;
                    } else if (typeid (output) == typeid (DBRow)) {
                        callback = _CallbackDBRow;
                    } else if (typeid (output) == typeid (DBTable)) {
                        _CALLBACK_CALLS = 0;
                        callback = _CallbackDBTable;
                    }
                    // выполняем запрос
                    result = sqlite3_exec(_db, sql_query.c_str(), callback, &output, &err) == 0;
                    // в случае ошибки выводим информацию об онной
                    if (!result)
                        std::cerr << "_RunSequence::error: " << err << std::endl;
                    // закрываем БД
                    sqlite3_close(_db);
                }
            } catch (int ex) {
                std::cerr << "_RunSequence::error(" << ex << ") " << err << std::endl;
                // если БД успела открытьтся до ошибки - закрываем БД
                if (is_open)
                    sqlite3_close(_db);
            }
        }
    } else {
        std::cerr << "_RunSequence::error: Database file " << _path_to_db << " not exist \n";
    }

    return result;
}

int DataBase::_CALLBACK_CALLS = 0;
int DataBase::_CallbackDBValue(void* output, int argc, char** argv, char** col_names) {
    try {
        DBValue* v = static_cast<DBValue*>(output);
        for(int i=0; i < argc; ++i) {
            v->append(argv[i]);
        }

        return 0;
    } catch (int ex) {
        std::cerr << "_CallbackDBValue::error(" << ex << ")\n";
        return -1;
    }
}
int DataBase::_CallbackDBRow(void* output, int argc, char** argv, char** col_names) {
    DBRow* r = static_cast<DBRow*>(output);
    for(int i=0; i < argc; ++i) {
        r->push_back(argv[i]);
    }

    return 0;
}
int DataBase::_CallbackDBTable(void* output, int argc, char** argv, char** col_names) {
    DBTable *t = static_cast<DBTable*>(output);
    DBRow r;
    for (int i = 0; i < argc; ++i) {
        r.push_back(argv[i]);
    }
    t->push_back(r);
    ++_CALLBACK_CALLS;

    return 0;
}
/* ************************************************************************************************************************ */
