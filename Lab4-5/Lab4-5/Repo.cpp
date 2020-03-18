#include "Repo.h"

Repo::Repo() {
	this->len = 0;
}
Repo::~Repo() {
	this->len = 0;
}
void Repo::insert(Shop expence) {
	this->array[this->len++] = expence;
}
int Repo::get_len() {
	return this->len;
}
Shop* Repo::get_all() {
	return this->array;
}
