#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <vector>
#include <string>

#include "../classes/dispatcher.hpp"
#include "../classes/record.hpp"
#include "../classes/database.hpp"

namespace Globals {
    namespace Consts {
        static const std::vector<std::string> TESTLIST_COLUMNS = {
            "ID","DateTime","OrderNum","SerialNum"
        };
        static const QStringList RECORD_COLUMNS = {
            "ID","DateTime","Customer","OrderNum","StationType","StationClass","SerialNum","CurrentRat","CurrentMinLim","CurrentMaxLim",
            "Timer","Operator","DataStages","ResultID","Verdict","Information","Note","Stand","d1","d2","d3","d4","d5"
        };
        static const QStringList STATION_INFO_COLUMNS = {
            "Producer","Name","Inom","Imax","Pnom","Usec","MaxRPM","MinRPM"
        };

    }
    namespace Vars {
        QObject* root_wnd = nullptr;
        Dispatcher *dispatcher = nullptr;
        QString path_to_db = "/home/aesma/Develop/db/TCS.sqlite";
        Record* record = nullptr;
        Record* stationType = nullptr;
    }



}

#endif // GLOBALS_HPP
