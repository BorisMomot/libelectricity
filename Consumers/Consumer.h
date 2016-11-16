//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_CONSUMER_H
#define LIBELECTRICITY_CONSUMER_H

/**
 * \brief Класс для моделирования самого простого потребителя
 * Если подключен к шинам - потребляет номинальную мощность
 */

#include "AbstractElModel.h"

class Consumer: public AbstractElModel
{
public:
    Consumer(unsigned int Pnominal, unsigned int Qnominal = 0);
    virtual ~Consumer(){}
    virtual void precalculate(std::chrono::milliseconds dTime) override {}
    /**
     * Если подключен к шинам - выставляет тукущую мощность как номинальную, на этом основании расчитывает все эл. параметры
     * @param dTime - время с последнего вызова функции
     */
    virtual void calculate(std::chrono::milliseconds dTime) override ;
    virtual void aftercalculation(std::chrono::milliseconds dTime) override {}

    double getPnom() const { return Pnom; }
    double getQnom() const { return Qnom; }
    double getSnom() const { return Snom; }
    virtual bool connectToGRU() override;
    virtual bool disconnectToGRU() override;

protected:
    /**
     * номинальные мощности потребителя
     */
    double Pnom, Qnom, Snom;
};


#endif //LIBELECTRICITY_CONSUMER_H
