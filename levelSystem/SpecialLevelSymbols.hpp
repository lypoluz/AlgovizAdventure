//
// Created by tobia on 20.01.2022.
//

#ifndef ALGOVIZADVENTURE_SPECIALLEVELSYMBOLS_HPP
#define ALGOVIZADVENTURE_SPECIALLEVELSYMBOLS_HPP

#include <string>
#include "../Logger.hpp"

class SpecialLevelSymbols{


public:

    static std::string interpretSymbol(std::string symbol) {
        //place symbol here
        Logger::logToNew(symbol.substr(0, symbol.find(' ')), "small_test_log");
        if (symbol.substr(0, symbol.find(' ') ) == "enemy") {
            // enemy code
            return "";
        }else if (symbol.substr(0, symbol.find(' ') ) == "roomlink") {
            // roomlink code
            return "";
        }else if (symbol.substr(0, symbol.find(' ') ) == "spawnPoint" ){
            // place floor
            return "spawnPoint";
        }else if (symbol.substr(0, symbol.find(' ') ) == "item"){
            // item code
            return "";
        }
        return "nope";

    }

};

#endif //ALGOVIZADVENTURE_SPECIALLEVELSYMBOLS_HPP
