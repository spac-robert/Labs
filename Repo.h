#pragma once
#include "Carte.h"
#include <deque>
#include <fstream>
#include <iostream>

template <typename T>

class Repo {

protected:
	std::deque <T> array;

public:

	Repo();
	~Repo();

	void insert(T);
	int get_len();
	void update_book_by_poz(int,T);
	void delete_book_by_poz(int);
	std::deque<T> get_all();
};

template <typename T>
Repo<T>::Repo() {


}

template <typename T>
Repo<T>::~Repo() {

}

template <typename T>
void Repo<T>::insert(T book) {

	this->array.push_back(book);
}

template <typename T>
int Repo<T>::get_len() {
	return this->array.size();
}

template <typename T>
std::deque<T> Repo<T>::get_all() {

	return this->array;
}

template <typename T>
void Repo<T>::update_book_by_poz(int poz,T carte) {

	this->array[poz] = carte;
}

template <typename T>
void Repo<T>::delete_book_by_poz(int poz) {

	if (poz > -1)
		this->array.erase(this->array.begin() + poz);
}
