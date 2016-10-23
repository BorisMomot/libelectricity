//
// Created by boris on 23.10.16.
//

#ifndef LIBELECTRICITY_ACTIVELOADDIVIDER_H
#define LIBELECTRICITY_ACTIVELOADDIVIDER_H

#include <string>
#include <map>
#include "Source.h"

template <typename MapType, typename Functor>
void doSmthWithMapValues(std::map<std::string, MapType *> _map, Functor function){
    for (auto&& Item : _map) {
        function(Item.second);
    }
}

class ActiveLoadDivider {
public:
    //главная функция для деления нагрузки
    static void DivideActiveLoadBetweenSources(std::map<std::string, Source*> &sources, double PTotalLoad);

    //функция для определения суммарной номинальной мощности всех источников подключенных к ГРУ
//    static double computePnom(std::map<std::string, Source*> &sources);

    //функция вычисляющая суммарное внутреннее сопротивелние всех источников
    static double computeRinSourceSum(std::map<std::string, Source *> &sources);

    //функция вычисляющая количество источников подключенных к шинам ГРУ
    static int computeAmountOfConnectedSources(std::map<std::string, Source*> &sources);

    //функция выставляющая потребление для каждого источника
    static void divideBaseOnRinternal(std::map<std::string, Source*> &sources, double PTotalLoad, double RintSum, int AmountOFConnectedSources);

};


#endif //LIBELECTRICITY_ACTIVELOADDIVIDER_H
