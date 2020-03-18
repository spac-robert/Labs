#include "Test.h"
#include "Repo.h"
#include <cassert>
void tests() {
	char* nume1 = new char[10], * person1 = new char[10];
	char* nume2 = new char[10], * person2 = new char[10];
	strcpy_s(nume1, sizeof "12.02.2020", "12.02.2020");
	strcpy_s(person1, sizeof "Ana", "Ana");
	Shop s1(person1,nume1, 23);
	strcpy_s(person2, sizeof "Alin", "ALin");
	Shop s2(person2,nume2, 14);
	Repo repo;
	Shop expence[2];
	expence[0] = s1;
	expence[1] = s2;

	repo.insert(s1);
	repo.insert(s2);
	assert(repo.get_len() == 2);
	for (int i = 0; i < repo.get_len(); i++) {
		assert(repo.get_all()[i] == expence[i]);
	}

}