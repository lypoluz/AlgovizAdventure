//
// Created by tobia on 19.01.2022.
//

#ifndef ALGOVIZADVENTURE_LOGGER_HPP
#define ALGOVIZADVENTURE_LOGGER_HPP

#include <fstream>
#include <string>

struct Logger{

    static void log(std::string input){
        std::ofstream file("logfile.txt");
        file << input << "\n";
        file.close();
    }

};

#endif //ALGOVIZADVENTURE_LOGGER_HPP
