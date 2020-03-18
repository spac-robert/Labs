#pragma once
#include <ostream>
class Shop {
private:
	char* date;
	int price;
	char* name;
public:
	Shop();//constructor implicit
	Shop(char*, char*, int);//constructor de initializare
	Shop(const Shop&);//constructor de copiere
	~Shop();//destructor
	//Getters
	char* get_name();
	char* get_date();
	int get_price();
	//Setters
	void set_name(char*);
	void set_date(char*);
	void set_price(int);
	//Overwrite operators '=' , "==" and "<<"
	Shop& operator =(const Shop&);
	bool operator==(const Shop& );
	friend std::ostream& operator << (std::ostream&, const Shop&);
};