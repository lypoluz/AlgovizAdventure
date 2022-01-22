//
// Created by tobia on 19.01.2022.
//

#ifndef ALGOVIZADVENTURE_LOGGER_HPP
#define ALGOVIZADVENTURE_LOGGER_HPP

#include <fstream>
#include <string>

struct Logger{

    static void logln(std::string input){
        log(input + "\n");
    }

    static void log(std::string input){
        std::ofstream file("logfile.log", std::ios::app);
        file << input;
        file.close();
    }

    //puts logs into new file
    static void logToNew(std::string input, std::string newName) {
        std::ofstream file(newName+".log");
        file << input << "\n";
        file.close();
    }

    static void clearFile(){
        std::ofstream file("logfile.log");
        file << "";
        file.close();
    }

};

#endif //ALGOVIZADVENTURE_LOGGER_HPP
