#include "Obj.h"
#include <vector>

bool Obj::initializeObjs(std::vector<Obj*>* objsVector) {
	Obj::objsVector = objsVector;
	if (Obj::objsVector == NULL) {
		printf("Obj objsvector not loaded\n");
		return false;
	}
	return true;
};

std::vector<Obj*>* Obj::objsVector = NULL;