//
// Created by boris on 08.11.16.
//

#ifndef LIBELECTRICITY_MODELRUNNER_H
#define LIBELECTRICITY_MODELRUNNER_H

#include <ctime>
#include <chrono>
#include <iomanip>
#include <forward_list>
#include "AbstractModel.h"
#include <future>
#include <atomic>

class ModelRunner {
public:
    ModelRunner(std::chrono::milliseconds sleepTime);
    void addModel(AbstractModel* model);
    void operator()();
    void run();
    const std::chrono::milliseconds &getSleepTime() const {        return sleepTime;    }
    void setSleepTime(const std::chrono::milliseconds &sleepTime) {        ModelRunner::sleepTime = sleepTime;    }

private:
    std::chrono::milliseconds sleepTime;
    std::forward_list<AbstractModel*> models;
    std::chrono::steady_clock::time_point currentTime, prevTime;
};


#endif //LIBELECTRICITY_MODELRUNNER_H
