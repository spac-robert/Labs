#include "Service.h"

void Service::insert_service(char* name, char* date, int price) {
	Shop shop(name,date,price);
	repo.insert(shop);
}
Shop* Service::get_all() {
	return this->repo.get_all();
}
int Service::get_len() {
	return this->repo.get_len();
}