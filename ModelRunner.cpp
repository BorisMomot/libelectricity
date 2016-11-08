//
// Created by boris on 08.11.16.
//

#include "ModelRunner.h"
using namespace std;

ModelRunner::ModelRunner() {
    currentTime = prevTime = chrono::steady_clock::now();
}

void ModelRunner::addModel(AbstractModel *model) {
    models.push_front(model);
}

void ModelRunner::run() {
    currentTime = chrono::steady_clock::now();
    for(auto&& model:models){
        model->precalculate( chrono::duration_cast<chrono::milliseconds>(currentTime - prevTime) );
        model->calculate( chrono::duration_cast<chrono::milliseconds>(currentTime - prevTime) );
        model->aftercalculation( chrono::duration_cast<chrono::milliseconds>(currentTime - prevTime) );
    }
    prevTime = currentTime;
}

void ModelRunner::operator()() {
    run();
}
