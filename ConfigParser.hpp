// Created by Lypoluz (Dominik) on 17.01.2022.

#ifndef ALGOVIZADVENTURE_CONFIGPARSER_HPP
#define ALGOVIZADVENTURE_CONFIGPARSER_HPP

#include <string>
#include <map>

struct ConfigParser {
    const std::map<std::string, std::string> *config;
    explicit ConfigParser(const std::map<std::string, std::string> *config) : config(config) {}

    std::string getValue(const std::string& key) const {
        std::string value;
        try {
            value = config->at(key);
        } catch(std::out_of_range&) {
            value = "default";
        }
        return value;
    }

    bool stringToBoolOrDefault(const std::string& key, bool d=false) const {
        std::string value = getValue(key);
        if(value == "default") return d;
        return value == "true";
    }

    int stringToIntOrDefault(const std::string& key, int d=0) const {
        std::string value = getValue(key);
        if(value == "default") return d;
        return std::stoi(value);
    }

    float stringToFloatOrDefault(const std::string& key, float d=0) const {
        std::string value = getValue(key);
        if(value == "default") return d;
        return std::stof(value);
    }
};

#endif //ALGOVIZADVENTURE_CONFIGPARSER_HPP
