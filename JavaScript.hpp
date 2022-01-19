// Created by Lypoluz (Dominik) on 19.01.2022.

#ifndef ALGOVIZADVENTURE_JAVASCRIPT_HPP
#define ALGOVIZADVENTURE_JAVASCRIPT_HPP

#include <string>
#include <utility>
#include <iostream>
#include "xeus/xjson.hpp"
#include "xcpp/xdisplay.hpp"

bool ranOnce = false;

class JavaScript {
    explicit JavaScript(std::string cmd) : cmd(std::move(cmd)) {}
public:
    std::string cmd;
    static void run(const std::string& str) {
        if (not ranOnce) {
            JavaScript load = JavaScript("<script src='JupyterInteraction.js'></script>");
            xcpp::display(load);
            ranOnce = true;
        }
        JavaScript js = JavaScript(std::string("<script>" + str + "</script>"));
        xcpp::display(js);
    }
};

xeus::xjson mime_bundle_repr(const JavaScript& js) {
    auto bundle = xeus::xjson::object();
    bundle["text/html"] = js.cmd;
    return bundle;
}

#endif //ALGOVIZADVENTURE_JAVASCRIPT_HPP
