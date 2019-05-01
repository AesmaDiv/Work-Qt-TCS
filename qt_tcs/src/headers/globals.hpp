#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <vector>
#include <string>

#include "../classes/dispatcher.hpp"
#include "../classes/database.hpp"

namespace Globals {
    namespace Consts {
        static const std::vector<std::string> TESTLIST_COLUMNS = {
            "ID","EndDT","OrderNum","SerialNum"
        };
        static const std::vector<std::string> RECORD_COLUMNS = {
            "ID","BeginDT","EndDT","Customer","OrderNum","StationType","StationClass","SerialNum","CurrentRat","CurrentMinLim","CurrentMaxLim",
            "Timer","Operator","DataStages","ResultID","Verdict","Information","Note","Stand","d1","d2","d3","d4","d5"
        };
        static const std::vector<std::string> TYPE_COLUMNS = {
            "ID","Producer","StationType","Inom","Imax","Pnom","Usec","MaxRPM","MinRPM","EngineControl","IsSpeedChanging","Instruction"
        };
    }
    namespace Vars {
        QObject* root_wnd = nullptr;
        Dispatcher *dispatcher = nullptr;
        std::string path_to_db = "/home/aesma/Developer/db/TCS.sqlite";

    }
}

#endif // GLOBALS_HPP
