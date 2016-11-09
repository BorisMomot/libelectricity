//
// Created by boris on 08.11.16.
//

#include "ModelRunner.h"
using namespace std;

ModelRunner::ModelRunner(std::chrono::milliseconds sleepTime): sleepTime(sleepTime) {
    currentTime = prevTime = chrono::steady_clock::now();
}

void ModelRunner::addModel(AbstractModel *model) {
    models.push_front(model);
}

void ModelRunner::run() {
    while (true) {
        currentTime = chrono::steady_clock::now();
        for (auto &&model:models) {
            mutex s;
            s.lock();
            model->precalculate(chrono::duration_cast<chrono::milliseconds>(currentTime - prevTime));
            model->calculate(chrono::duration_cast<chrono::milliseconds>(currentTime - prevTime));
            model->aftercalculation(chrono::duration_cast<chrono::milliseconds>(currentTime - prevTime));
            s.unlock();
        }
        prevTime = currentTime;
        this_thread::sleep_for(sleepTime);
    }
}

void ModelRunner::operator()() {
    run();
}
