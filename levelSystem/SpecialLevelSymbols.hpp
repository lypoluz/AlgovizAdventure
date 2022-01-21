//
// Created by tobia on 20.01.2022.
//

#ifndef ALGOVIZADVENTURE_SPECIALLEVELSYMBOLS_HPP
#define ALGOVIZADVENTURE_SPECIALLEVELSYMBOLS_HPP

#include <string>

class SpecialLevelSymbols{


public:

    static std::string interpretSymbol(std::string symbol) {
        //place symbol here
        if (symbol.substr(0, (symbol.find(' ')-1) ) == "enemy") {
            // enemy code
            return "";
        }else if (symbol.substr(0, (symbol.find(' ')-1) ) == "roomlink") {
            // roomlink code
            return "";
        }else if (symbol.substr(0, (symbol.find(' ')-1) ) == "spawnPoint" ){
            // place floor
            return "";
        }else if (symbol.substr(0, (symbol.find(' ')-1) ) == "item"){
            // item code
            return "";
        }
        return "";

    }

};

#endif //ALGOVIZADVENTURE_SPECIALLEVELSYMBOLS_HPP
