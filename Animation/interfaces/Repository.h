#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <vector>


template<typename T>
class Repository {


public:


	virtual void add(T* t) = 0;
	virtual std::vector<T*>& getAll() = 0;

};

#endif