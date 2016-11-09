//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_ABSTRACTELMODEL_H
#define LIBELECTRICITY_ABSTRACTELMODEL_H

#include "AbstractModel.h"

class AbstractElModel: public AbstractModel
{
public:
    AbstractElModel();
    virtual inline bool setP(double power);
    virtual inline bool setQ(double reactpower);
    virtual inline bool setF(unsigned int frequency);
    virtual inline bool setU(unsigned int voltage);

    virtual inline bool connectToGRU(){isConnected = true; return true;}
    virtual inline bool disconnectToGRU(){isConnected = false; return true;}
    inline bool getIsConnected(){return isConnected;}

    virtual inline double getP(){return P;}
    virtual inline double getQ(){return Q;}
    virtual inline double getS(){return S;}
    virtual inline double getPa(){return Pa;}
    virtual inline double getPb(){return Pb;}
    virtual inline double getPc(){return Pc;}
    virtual inline double getQa(){return Qa;}
    virtual inline double getQb(){return Qb;}
    virtual inline double getQc(){return Qc;}
    virtual inline double getSa(){return Sa;}
    virtual inline double getSb(){return Sb;}
    virtual inline double getSc(){return Sc;}
    virtual inline double getf(){return f;}
    virtual inline double getI(){return I;}
    virtual inline double getU(){return U;}
    virtual inline double getIa(){return Ia;}
    virtual inline double getIb(){return Ib;}
    virtual inline double getIc(){return Ic;}
    virtual inline double getUa(){return Ua;}
    virtual inline double getUb(){return Ub;}
    virtual inline double getUc(){return Uc;}
    double getUbus() const { return Ubus; }
    double getFbus() const { return Fbus; }
    void setUbus(double Ubus) { AbstractElModel::Ubus = Ubus; }
    void setFbus(double Fbus) { AbstractElModel::Fbus = Fbus; }

    virtual void calculatePowers();
    virtual void calculateCurrents();

    virtual void precalculate(std::chrono::milliseconds dTime) override {}
    virtual void calculate(std::chrono::milliseconds dTime) override;
    virtual void aftercalculation(std::chrono::milliseconds dTime) override {}

    virtual ~AbstractElModel() = 0;
protected:
    virtual void resetParameterToZero();
    double P={0},Q={0},S={0};
    double Pa,Pb,Pc,Qa,Qb,Qc,Sa,Sb,Sc;
    double f={0},I={0},U={0};
    double Ia,Ib,Ic,Ua,Ub,Uc;
    bool isConnected={false}; //подключен ли потребитель к шинам ГРУ
    double Ubus={0}, Fbus={0};//напряжение и частота на шинах
};


#endif //LIBELECTRICITY_ABSTRACTELMODEL_H
