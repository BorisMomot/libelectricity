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

class ModelRunner {
public:
    ModelRunner();
    void addModel(AbstractModel* model);
    void operator()();
    void run();
private:
    std::forward_list<AbstractModel*> models;
    std::chrono::steady_clock::time_point currentTime, prevTime;
};


#endif //LIBELECTRICITY_MODELRUNNER_H
