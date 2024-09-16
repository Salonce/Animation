#include <vector>

#include "Obj.h"
#include <cstdio>

bool Obj::initializeObjs(std::vector<Obj*>* objsVector) {
	Obj::objsVector = objsVector;
	if (Obj::objsVector == nullptr) {
		printf("Obj objsvector not loaded\n");
		return false;
	}
	return true;
};

std::vector<Obj*>* Obj::objsVector = nullptr;