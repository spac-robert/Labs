#pragma once
#include "Repo.h"

class Book_repo :public Repo<Carte> {


public:

	int find_pozition_by_title(char* titlu) {

		for (int i = 0; i < this->get_len(); i++) {

			if (strcmp(this->get_all()[i].get_titlu(), titlu) == 0) {

				return i;
			}
		}
		return -1;
	}

	void update_book(Carte carte) {

		int index = this->find_pozition_by_title(carte.get_titlu());
		this->array[index] = carte;

	}

	Carte get_book_by_title(char* titlu) {

		int index = this->find_pozition_by_title(titlu);
		return this->array[index];
	}
};