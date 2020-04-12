#include "Carte.h"
#include <cstring>

Carte::Carte() {

	this->titlu = NULL;
	this->autor = NULL;
	this->status = false;
}

Carte::Carte(char* title, char* author, bool status) {

	this->titlu = new char[strlen(title) + 1];
	strcpy_s(this->titlu, 1 + strlen(title), title);

	this->autor = new char[strlen(author) + 1];
	strcpy_s(this->autor, 1 + strlen(author), author);

	this->status = status;
}

Carte::Carte(const Carte& expence) {

	this->titlu = new char[strlen(expence.titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(expence.titlu), expence.titlu);

	this->autor = new char[strlen(expence.autor) + 1];
	strcpy_s(this->autor, 1 + strlen(expence.autor), expence.autor);

	this->status = expence.status;
}

Carte::~Carte() {

	if (this->titlu) {

		free(this->titlu);
		this->titlu = NULL;
	}
	if (this->autor)
	{
		free(this->autor);
		this->autor = NULL;
	}
}

//Getters

char* Carte::get_titlu() {

	return this->titlu;
}

char* Carte::get_autor() {
	return this->autor;
}

bool Carte::get_status() {
	return this->status;
}

//Setters

void Carte::set_titlu(char* new_title) {

	if (this->titlu)
	{
		delete[] this->titlu;
		this->titlu = NULL;
	}
	this->titlu = new char[strlen(new_title) + 1];
	strcpy_s(this->titlu, 1 + strlen(new_title), new_title);
}

void Carte::set_autor(char* new_autor) {
	if (this->autor)
	{
		delete[] this->autor;
		this->autor = NULL;
	}

	this->autor = new char[strlen(new_autor) + 1];
	strcpy_s(this->autor, 1 + strlen(new_autor), new_autor);
}

void Carte::set_status(bool new_status) {

	this->status = new_status;
}

Carte& Carte:: operator =(const Carte& expence) {

	this->set_titlu(expence.titlu);
	this->set_autor(expence.autor);
	this->set_status(expence.status);

	return *this;
}

bool Carte:: operator==(const Carte& s) {

	return strcmp(this->titlu, s.titlu) == 0 and strcmp(this->autor, s.autor) == 0 and this->status == s.status;
}

std::ostream& operator <<(std::ostream& os, const Carte& expence) {
	os << "Titlu: " << expence.titlu << " Autor: " << expence.autor << " Status: " << expence.status << std::endl;
	return os;
}