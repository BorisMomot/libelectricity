//
// Created by boris on 24.10.16.
//

#ifndef LIBELECTRICITY_DG_H
#define LIBELECTRICITY_DG_H

#include "Source.h"

class DG: public Source {
public:
	DG(unsigned int Pnominal, unsigned int Qnominal, unsigned int Unominal=400);
	virtual ~DG(){}
};


#endif //LIBELECTRICITY_DG_H