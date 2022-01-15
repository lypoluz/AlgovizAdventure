#ifndef ALGOVIZADVENTURE_GTIME_HPP
#define ALGOVIZADVENTURE_GTIME_HPP

#include "chrono"


class GTime {
    std::chrono::time_point<std::chrono::system_clock> startTime{};
    std::chrono::time_point<std::chrono::system_clock> lastTime{};
    double lastDelta{};
    long timeFactor{};

    GTime() = default;

public:

    static GTime* getInstance() {
        static GTime instance;
        return &instance;
    }

    void setTimeFactor(long timeFactor=1000000000) {
        this->timeFactor = timeFactor;
    }

    void setStart() {
        startTime = std::chrono::high_resolution_clock::now();
        lastTime = startTime;
    }

    void setDelta() {
        auto now = std::chrono::high_resolution_clock::now();
        lastDelta = (double) (now - lastTime).count() / timeFactor;
        lastTime = now;

    }

    // returns the time difference in seconds between last two time points
    double deltaTime() {
        return lastDelta;
    }

    // returns total run time
    double runTime() {
        return (double) (lastTime - startTime).count() / timeFactor;
    }

};

#endif // ALGOVIZADVENTURE_GTIME_HPP