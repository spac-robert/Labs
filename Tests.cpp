#include "Service.h"
#include "Repo.h"
#include <cassert>
#include "Tests.h"


void test_service() {

	char* titlu = new char[20], * autor = new char[20]; bool statut = true;
	char* titlu1 = new char[20], * autor1 = new char[20], statut1 = false;
	char* titlu_updated = new char[20], * autor_updated = new char[20], statut_updated = false;
	Service service;

	//Carte1
	strcpy_s(titlu, sizeof "Razboi", "Razboi");
	strcpy_s(autor, sizeof "Ana", "Ana");

	//Carte2
	strcpy_s(titlu1, sizeof "Live", "Live");
	strcpy_s(autor1, sizeof "Diana", "Diana");

	//Add

	Carte carte(titlu, autor, statut), carte1(titlu1, autor1, statut1);
	Carte array[2];
	array[0] = carte;
	array[1] = carte1;

	service.insert_service(titlu, autor, statut);
	service.insert_service(titlu1, autor1, statut1);

	for (int i = 0; i < service.get_len(); i++) {

		assert(array[i] == service.get_all()[i]);
	}

	//Update

	strcpy_s(titlu_updated, sizeof "Razboi", "Razboi");
	strcpy_s(autor_updated, sizeof "Valeria", "Valeria");
	Carte carte_updated(titlu_updated, autor_updated, statut_updated);
	array[0] = carte_updated;

	service.update_carte(titlu_updated, autor_updated, statut_updated);

	for (int i = 0; i < service.get_len(); i++) {
		assert(array[i] == service.get_all()[i]);
	}

	//finde pozition by title

	int poz = service.find_pozition_by_title(titlu_updated);
	assert(poz == 0);

	//Delete

	service.delete_book(titlu_updated);
	array[0] = carte1;
	for (int i = 0; i < service.get_len(); i++) {
		assert(array[i] == service.get_all()[i]);
	}

	//find_all_objects_by_author_array
	std::deque<Carte>vector = service.find_all_books_by_author_available(autor1);
	for (int i = 0; i<int(vector.size()); i++) {
		assert(vector[i] == carte1);
	}
}

void test_repo_Book_repo() {

	char* titlu = new char[20], * autor = new char[20]; bool statut = true;
	char* titlu1 = new char[20], * autor1 = new char[20], statut1 = false;
	char* titlu_updated = new char[20], * autor_updated = new char[20], statut_updated = false;
	Book_repo repo;

	//Carte1
	strcpy_s(titlu, sizeof "Razboi", "Razboi");
	strcpy_s(autor, sizeof "Ana", "Ana");

	//Carte2
	strcpy_s(titlu1, sizeof "Live", "Live");
	strcpy_s(autor1, sizeof "Diana", "Diana");

	//Add

	Carte carte(titlu, autor, statut), carte1(titlu1, autor1, statut1);
	Carte array[2];
	array[0] = carte;
	array[1] = carte1;
	repo.insert(carte);
	repo.insert(carte1);

	for (int i = 0; i < repo.get_len(); i++) {
		assert(array[i] == repo.get_all()[i]);
	}

	//Update

	strcpy_s(titlu_updated, sizeof "Razboi", "Razboi");
	strcpy_s(autor_updated, sizeof "Valeria", "Valeria");
	Carte carte_updated(titlu_updated, autor_updated, statut_updated);
	array[0] = carte_updated;

	repo.update_book_by_poz(0, carte_updated);

	for (int i = 0; i < repo.get_len(); i++) {
		assert(array[i] == repo.get_all()[i]);
	}

	//Delete

	array[0] = carte1;
	repo.delete_book_by_poz(0);

	for (int i = 0; i < repo.get_len(); i++) {
		assert(array[i] == repo.get_all()[i]);
	}

	//Book_repo
	carte1.set_status(1);
	array[0] = carte1;
	repo.update_book(carte1);

	for (int i = 0; i < repo.get_len(); i++) {
		assert(array[i] == repo.get_all()[i]);
	}

}

void test_load_from_file_service() {

	char* titlu = new char[20], * autor = new char[20]; bool statut = true;
	char* titlu1 = new char[20], * autor1 = new char[20], statut1 = false;

	//Carte1
	strcpy_s(titlu, sizeof "Razboi", "Razboi");
	strcpy_s(autor, sizeof "Ana", "Ana");

	//Carte2
	strcpy_s(titlu1, sizeof "Live", "Live");
	strcpy_s(autor1, sizeof "Diana", "Diana");

	Carte carte(titlu, autor, statut), carte1(titlu1, autor1, statut1);
	Carte array[2];
	array[0] = carte;
	array[1] = carte1;

	Service service;
	service.load_from_file("Biblioteca_load.txt");

	//Find pozition by title

	int poz = service.find_pozition_by_title(titlu1);
	assert(poz == 1);

	for (int i = 0; i < service.get_len(); i++) {
		assert(array[i] == service.get_all()[i]);
	}

	//Test Imprumutarea unei carti

	int contor = 0;
	//titlu - razboi

	service.borrowed_book(titlu1, contor);
	assert(contor == 1);

	service.borrowed_book(titlu, contor);
	assert(contor == 2);

	//Test Returnarea unei carti

	service.carte_returnata(titlu1, contor);
	assert(contor == 1);

	service.carte_returnata(titlu, contor);
	assert(contor == 1);

}

void test_load_from_file_repo() {

	char* titlu = new char[20], * autor = new char[20]; bool statut = true;
	char* titlu1 = new char[20], * autor1 = new char[20], statut1 = false;

	//Carte1
	strcpy_s(titlu, sizeof "Razboi", "Razboi");
	strcpy_s(autor, sizeof "Ana", "Ana");

	//Carte2
	strcpy_s(titlu1, sizeof "Live", "Live");
	strcpy_s(autor1, sizeof "Diana", "Diana");

	Carte carte(titlu, autor, statut), carte1(titlu1, autor1, statut1);
	Carte array[2];

	array[0] = carte;
	array[1] = carte1;


	Repo_file<Carte> repo;
	repo.load_from_file("Biblioteca_load.txt");

	for (int i = 0; i < repo.get_len(); i++) {
		assert(array[i] == repo.get_all()[i]);
	}

}
void tests() {
	test_load_from_file_service();
	test_load_from_file_repo();
	test_repo_Book_repo();
	test_service();
}