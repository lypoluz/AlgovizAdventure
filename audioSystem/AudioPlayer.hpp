// Created by Lypoluz (Dominik) on 15.01.2022.
// based upon xeus-cling audio example: https://github.com/jupyter-xeus/xeus-cling/blob/master/notebooks/xcpp.ipynb

#ifndef ALGOVIZADVENTURE_AUDIOPLAYER_HPP
#define ALGOVIZADVENTURE_AUDIOPLAYER_HPP

#include <string>
#include <fstream>
#include <utility>
#include <sstream>

#include "xtl/xbase64.hpp"
#include "xeus/xjson.hpp"
#include "xcpp/xdisplay.hpp"


struct AudioPlayer {
    float volume = 1;
    std::string fileName = "";
    AudioPlayer(const std::string& fn, float v) {
        volume = v;
        fileName = fn;
        std::string musicRoot = "sounds/";
        std::ifstream fin(musicRoot+fn, std::ios::binary);
        m_buffer << fin.rdbuf();
    }

    std::stringstream m_buffer;

    static void play(const std::string& fn, float v=1) {
        AudioPlayer audio(fn, v);
        xcpp::display(audio);
    }
};


xeus::xjson mime_bundle_repr(const AudioPlayer& a) {
    auto bundle = xeus::xjson::object();
    bundle["text/html"] =
            std::string(
                    "<audio autoplay id=\"" +
                    a.fileName +
                    "\"><source src=\"data:audio/mp3;base64," +
                    xtl::base64encode(a.m_buffer.str()) +
                    "\" type=\"audio/mp3\" /></audio><script>var audio = document.getElementById(\"" +
                    std::string(a.fileName) +
                    "\"); audio.volume = " +
                    std::to_string(a.volume) +
                    ";</script>");
    return bundle;
}


#endif //ALGOVIZADVENTURE_AUDIOPLAYER_HPP
