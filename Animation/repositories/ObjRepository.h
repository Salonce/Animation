#ifndef OBJ_REPOSITORY_H
#define OBJ_REPOSITORY_H

#include <vector>
#include "Obj.h"
#include <Repository.h>

class ObjRepository : public Repository<Obj>{

	std::vector<Obj*> storage;

public:
	ObjRepository() {}

	void add(Obj* obj) override {
		if (obj != nullptr)
			storage.push_back(obj);
	}

	std::vector<Obj*>& getAll() override {
		return storage;
	}
};

#endif