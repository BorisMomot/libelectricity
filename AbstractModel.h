//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_ABSTRACTMODEL_H
#define LIBELECTRICITY_ABSTRACTMODEL_H

#include <chrono>

/**
 * \brief Интерфейсный класс для всех моделей
 * В классе определено ранжирование функций по времени выполнения
 */
class AbstractModel
{
public:
    AbstractModel();
    /**
     * Функция вызывается до вызова основной функции с расчетами
     * @param dTime время прошедшее со времени последнего вызова функции в миллисекундах
     */
    virtual void precalculate(std::chrono::milliseconds dTime) = 0;
    /**
     * Функция для основных расчетов в модели
     * @param dTime время прошедшее со времени последнего вызова функции в миллисекундах
     */
    virtual void calculate(std::chrono::milliseconds dTime) = 0;
    /**
     * Функция вызывается после вызова основной функции с расчетами
     * @param dTime время прошедшее со времени последнего вызова функции в миллисекундах
     */
    virtual void aftercalculation(std::chrono::milliseconds dTime) = 0;
    virtual ~AbstractModel();
};
#endif //LIBELECTRICITY_ABSTRACTMODEL_H
