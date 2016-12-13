//
// Created by boris on 04.11.16.
//

#ifndef LIBELECTRICITY_Q_H
#define LIBELECTRICITY_Q_H
/**
 * \brief Модель очень простого выключателя и интерфейс для других выключателей
 * Ничего не проверяет - всегда включается и всегда выключается
 */
#include "AbstractModel.h"
#include <atomic>

class Q : public AbstractModel {
public:
    virtual void precalculate(std::chrono::milliseconds dTime) override {}
    virtual void calculate(std::chrono::milliseconds dTime) override{}
    virtual void aftercalculation(std::chrono::milliseconds dTime) override{}
	/**
	 * Функция для включения
	 * @param U - напряжение на подключаемых шинах
	 * @param f - частота на подключаемых шинах
	 * @return - true, если подключился
	 */
    virtual bool connectTo(double U, double f);
	/**
	 * Функция для отключения
	 * @return - true, если отклчился
	 */
    virtual bool disconnect();
    bool isIsConnected() const {        return isConnected;    }
protected:
	/**
	 * Внутреннее состояние - включен ли.
	 */
    std::atomic<bool> isConnected={0};
};


#endif //LIBELECTRICITY_Q_H
