#include "Shop.h"
#include <cstring>
Shop::Shop() {
	this->name = 0;
	this->price = 0;
	this->date = NULL;
}
Shop::Shop(char* name, char* date, int price) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->date = new char[strlen(date)+1];
	strcpy_s(this->date, 1 + strlen(date), date);
	this->price=price;
}
Shop::Shop(const Shop& expence) {
	this->name = new char[strlen(expence.name) + 1];
	strcpy_s(this->name, 1 + strlen(expence.name), expence.name);
	this->date = new char[strlen(expence.date) + 1];
	strcpy_s(this->date, 1 + strlen(expence.date), expence.date);
	this->price = expence.price;
}
Shop::~Shop() {
	if (this->date) {
		delete[] this->date;
		this->date = NULL;
	}
}
//Getters
char* Shop::get_name() {
	return this->name;
}
int Shop::get_price() {
	return this->price;
}
char* Shop::get_date() {
	return this->date;
}
//Setters
void Shop::set_name(char* new_name) {
	this->name = new char[strlen(new_name) + 1];
	strcpy_s(this->name, 1 + strlen(new_name), new_name);
}
void Shop::set_date(char* new_date) {
	this->date = new char[strlen(new_date) + 1];
	strcpy_s(this->date, 1 + strlen(new_date), new_date);
}
void Shop::set_price(int new_price) {
	this->price = new_price;
}
Shop& Shop:: operator =(const Shop& expence) {
	this->set_name(expence.name);
	this->set_price(expence.price);
	this->set_date(expence.date);
	return *this;
}
bool Shop:: operator==(const Shop& s) {
	return strcmp(this->date, s.date) == 0 and this->price == s.price and strcmp(this->name,s.name)==0 ;
}
std::ostream& operator <<(std::ostream& os, const Shop& expence) {
	os <<std::endl<< "Name: " << expence.name << " Date: " <<expence.date << " Price: " << expence.price<<std::endl;
	return os;
}