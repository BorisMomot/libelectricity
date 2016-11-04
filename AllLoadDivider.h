//
// Created by boris on 23.10.16.
//

#ifndef LIBELECTRICITY_ACTIVELOADDIVIDER_H
#define LIBELECTRICITY_ACTIVELOADDIVIDER_H

#include <string>
#include <map>
#include "Source.h"
#include "GRU_functions.h"


class AllLoadDivider {
public:
    //функции для деления нагрузки
    static void DivideActiveLoadBetweenSources(std::map<std::string, Source*> &sources, double PTotalLoad, unsigned int dTime);
    static void DivideReactiveLoadBetweenSources(std::map<std::string, Source*> &sources, double QTotalLoad, unsigned int dTime);

    //функция вычисляющая суммарное внутреннее сопротивелние всех источников
    static double computeRinSourceSum(std::map<std::string, Source *> &sources, unsigned int dTime);
    //функция вычисляющая количество источников подключенных к шинам ГРУ
    static int computeAmountOfConnectedSources(std::map<std::string, Source*> &sources);

private:
    //функция выставляющая потребление для каждого источника
    static void divideActivePowerBaseOnRinternal(std::map<std::string, Source *> &sources, double PTotalLoad,
                                                 double RintSum, int AmountOFConnectedSources);
    static void divideReactivePowerBaseOnRinternal(std::map<std::string, Source *> &sources, double QTotalLoad,
                                                 double RintSum, int AmountOFConnectedSources);

};
#endif //LIBELECTRICITY_ACTIVELOADDIVIDER_H
