#pragma once
#include "Repo.h"
class Service {
private:
	Repo repo;
public:
	void insert_service(char*, char*, int);
	int get_len();
	Shop* get_all();
};