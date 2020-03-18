#pragma once
#include "Shop.h"
class Repo {
private:
	Shop array[101];
	int len;
public:
	Repo();
	~Repo();
	void insert(Shop);
	int get_len();
	Shop* get_all();
};