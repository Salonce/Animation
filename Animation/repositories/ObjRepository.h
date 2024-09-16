#ifndef OBJ_REPOSITORY_H
#define OBJ_REPOSITORY_H

#include <vector>
#include "Obj.h";

class ObjRepository {

	std::vector<Obj*> storage;

public:
	ObjRepository() {}

	void add(Obj* obj) {
		if (obj != NULL)
			storage.push_back(obj);
	}

	std::vector<Obj*>& getAll() {
		return storage;
	}
};

#endif