//
// Created by tobia on 19.01.2022.
//

#ifndef ALGOVIZADVENTURE_LOGGER_HPP
#define ALGOVIZADVENTURE_LOGGER_HPP

#include <fstream>
#include <string>

struct Logger{

    static void log(std::string input){
        std::ofstream file("logfile.txt", std::ios::app);
        file << input << "\n";
        file.close();
    }

    //puts logs into new file
    static void logToNew(std::string input, std::string newName) {
        std::ofstream file(newName+".txt");
        file << input << "\n";
        file.close();
    }

};

#endif //ALGOVIZADVENTURE_LOGGER_HPP
