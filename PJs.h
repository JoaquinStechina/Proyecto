#ifndef PJS_H
#define PJS_H
#include "Stats.h"

class PJs : public Stats {
public:
	PJs();
	bool Esquivar(int &damage);
	void Atacar(PJs &x);
};

#endif
