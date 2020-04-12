#include "Service.h"
#include <cstring>


void Service::insert_service(char* name, char* date, bool price) {

	Carte book(name, date, price);
	repo.insert(book);

}

std::deque<Carte> Service::get_all() {

	return this->repo.get_all();
}

int Service::get_len() {

	return this->repo.get_len();
}

int Service::find_pozition_by_title(char* titlu) {

	for (int i = 0; i < this->get_len(); i++) {

		if (strcmp(this->get_all()[i].get_titlu(), titlu) == 0) {

			return i;
		}
	}
	return -1;
}

void Service::update_carte(char* titlu, char* autor, bool status) {

	Carte carte(titlu, autor, status);

	int i = this->find_pozition_by_title(titlu);
	this->repo.update_book_by_poz(i, carte);
}

void Service::delete_book(char* titlu) {

	int i = find_pozition_by_title(titlu);
	this->repo.delete_book_by_poz(i);
}

void Service::load_from_file(const char* file_name) {

	this->repo.load_from_file(file_name);
}

void Service::save_to_file(const char* file_name) {

	this->repo.save_to_file(file_name);
}

std::deque<Carte> Service::find_all_books_by_author_available(char* titlu) {

	std::deque<Carte> array_by_title;
	std::deque<Carte> books = this->repo.get_all();
	for (int i = 0; i < this->repo.get_len(); i++) {

		if (strcmp(titlu, books[i].get_autor()) == 0 and books[i].get_status()==0) {
			array_by_title.push_back(books[i]);
		}
	}
	return array_by_title;
}


void Service::borrowed_book(char* titlu, int& contor) {

	int index = this->find_pozition_by_title(titlu);
	if (index != -1) {
		Carte carte = repo.get_book_by_title(titlu);
		if (carte.get_status() == 0) {

			carte.set_status(1);
			this->repo.update_book_by_poz(index, carte);
			contor = 1;
		}
		else
		{
			if (find_all_books_by_author_available(carte.get_autor()).size()) {

				contor = 0;
			}
			else {
				contor = 2;
			}
		}
	}
	if (index == -1) {
		contor = 4;
	}
}


void Service::carte_returnata(char* titlu, int& contor) {

	int index = this->find_pozition_by_title(titlu);

	if (index != -1) {

		Carte carte = repo.get_book_by_title(titlu);
		if (carte.get_status() == 1) {

			carte.set_status(0);
			this->repo.update_book(carte);
			contor = 1;
		}
		else
			contor = 0;
	}
	else
		if (index == -1) {
			contor = 2;
		}
}