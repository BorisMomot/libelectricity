//
// Created by boris on 23.10.16.
//

#ifndef LIBELECTRICITY_ACTIVELOADDIVIDER_H
#define LIBELECTRICITY_ACTIVELOADDIVIDER_H

/**
 * \brief вспомогательный класс для разделения мощности между источниками
 * Функциям класса передается массив из источников и мощность, которую нужно разделить - он делит на основании
 * внутреннего сопротивления источников.
 * Еще умеет считать внутреннее сопротивление истоников и количество источников, подключенных к шинам ГРУ
 */

#include <string>
#include <map>
#include "Source.h"
#include "GRU_functions.h"


class AllLoadDivider {
public:

    /**
     * функция для деления активной нагрузки
     * @param sources - мап истоынков эл. энергии
     * @param PTotalLoad - активная мощность, которую нужно между ними разделить
     * @param dTime - время с момента последнего вызова данной функции
     */
    static void DivideActiveLoadBetweenSources(std::map<std::string, Source*> &sources, double PTotalLoad, std::chrono::milliseconds dTime);

    /**
     * функция для деления реактивной нагрузки
     * @param sources - мап истоынков эл. энергии
     * @param QTotalLoad - реактивная мощность, которую нужно между ними разделить
     * @param dTime - время с момента последнего вызова данной функции
     */
    static void DivideReactiveLoadBetweenSources(std::map<std::string, Source*> &sources, double QTotalLoad, std::chrono::milliseconds dTime);

        /**
     * Считает внутреннее сопротивление для всех источников из переданного массива
     * @param sources - мап из источников
     * @param dTime - время с последнего вызова функции
     * @return - сумма всех внутренних сопротивлений для источников подключенных к шинам ГРУ
     */
    static double computeRinSourceSum(std::map<std::string, Source *> &sources, std::chrono::milliseconds dTime);
    //функция вычисляющая количество источников подключенных к шинам ГРУ
    /**
     * Считает количество источников подключенных к ГРУ
     * @param sources - мап из источников
     * @return - количество источников
     */
    static int computeAmountOfConnectedSources(std::map<std::string, Source*> &sources);

private:
    /**
     * делит активную мощность на основании внутреннего сопротивления
     */
    static void divideActivePowerBaseOnRinternal(std::map<std::string, Source *> &sources, double PTotalLoad,
                                                 double RintSum, int AmountOFConnectedSources);
    /**
     * делит реактивную мощность на основании внутреннего сопротивления
     */
    static void divideReactivePowerBaseOnRinternal(std::map<std::string, Source *> &sources, double QTotalLoad,
                                                 double RintSum, int AmountOFConnectedSources);

};
#endif //LIBELECTRICITY_ACTIVELOADDIVIDER_H
