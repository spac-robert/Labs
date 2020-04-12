#pragma once
#include "Repo.h"
#include "Repo_file.h"

class Service {

private:

	Repo_file<Carte> repo;

public:
	Service() {

	}
	~Service() {

	}

	void insert_service(char*, char*, bool);
	int get_len();
	void update_carte(char*, char*, bool);
	int find_pozition_by_title(char*);
	void delete_book(char*);
	void load_from_file(const char*);
	void save_to_file(const char*);
	void carte_returnata(char*, int&);
	void borrowed_book(char*, int&);

	std::deque<Carte> find_all_books_by_author_available(char*);
	std::deque<Carte> get_all();
};