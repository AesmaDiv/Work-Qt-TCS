#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <vector>
#include <string>

#include "dispatcher.hpp"
#include "record.hpp"
#include "database.hpp"
#include "testlistrow.hpp"

class Globals {
public:
    class Consts {
    public:
        const std::vector<std::string> TESTLIST_COLUMNS = {
            "ID","DateTime","OrderNum","SerialNum"
        };
        const QStringList TEST_RECORD_COLUMNS = {
            "ID","DateTime","Customer","OrderNum","StationType","StationClass","SerialNum","CurrentRat","CurrentMinLim","CurrentMaxLim",
            "Timer","Operator","DataStages","ResultID","Verdict","Information","Note","Stand","d1","d2","d3","d4","d5"
        };
        const QStringList STATION_RECORD_COLUMNS = {
            "ID","Producer","StationType","Inom","Imax","Pnom","Usec","MaxRPM","MinRPM"
        };
        const QStringList TEST_INFO_COLUMNS = {
            "DateTime","OrderNum","SerialNum","Customer"
        };
        const QStringList STATION_INFO_COLUMNS = {
            "Producer","StationType","Inom","Imax","Pnom","Usec","MaxRPM","MinRPM"
        };
        const QString TEST_INFO_QUERY =
                "Select "
                "Customers.Name as Customer,"
                "Tests.ID,DateTime,OrderNum,StationType,StationClass,SerialNum,"
                "CurrentRat,CurrentMinLim,CurrentMaxLim,Timer,Operator,DataStages,"
                "ResultID,Verdict,Information,Note,Stand,d1,d2,d3,d4,d5 "
                "From Tests "
                "Join Customers On Tests.Customer = Customers.ID "
                "Where Tests.ID=";
        const QString STATION_INFO_QUERY =
                "Select "
                "Producers.Name as Producer,"
                "StationTypes.Name as StationType,"
                "Inom, Imax, Pnom, Usec, MaxRPM, MinRPM "
                "From StationTypes "
                "Join Producers On StationTypes.Producer = Producers.ID "
                "Where StationTypes.ID=";

    };
    class Vars
    {
    public:
        QObject* root_wnd = nullptr;
        Dispatcher* dispatcher = nullptr;
        QString path_to_db = "/home/aesma/Develop/db/TCS.sqlite";
        Record* currentTest = nullptr;
        Record* stationType = nullptr;
        Record* newTest = nullptr;
        bool isCreatingNewRecord = false;
    };

    Consts consts;
    Vars vars;
};
/* ************************************************************************************************************************ */
/* ************************************************************************************************************************ */

/* ************************************************************************************************************************ */
#endif // GLOBALS_HPP
