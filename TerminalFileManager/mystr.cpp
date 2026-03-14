#include "mystr.hpp"
#include <string.h>

Mystr::Mystr()
{
}

Mystr::Mystr(const char* symbols)
{
	this->size = strlen(symbols);
	this->symbols = new char[this->size + 1];

	memcpy(this->symbols, symbols, size + 1);
}

Mystr::Mystr(Mystr& other)
{
	this->size = other.size;
	this->symbols = new char[this->size + 1];

	memcpy(this->symbols, other.symbols, this->size + 1);
}

Mystr::~Mystr()
{
	delete[] this->symbols;
}

size_t Mystr::str_size()
{
	return this->size;
}


Mystr& Mystr::operator=(const Mystr& other)
{
	if (this == &other) 
		return *this;

	delete[] symbols;

	size = other.size;
	symbols = new char[size + 1];

	memcpy(symbols, other.symbols, size + 1); 

	return *this;
}

char Mystr::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index out of range");
	}

	return symbols[index];
}

Mystr Mystr::operator+(const Mystr& other) const{
	
	Mystr new_str;
	new_str.size = this->size + other.size;
	new_str.symbols = new char[new_str.size + 1];

	for (int i = 0; i < this->size; i++)
		new_str.symbols[i] = this->symbols[i];
	for (int i = 0; i < other.size; i++)
		new_str.symbols[i + this->size] = other.symbols[i];

	new_str.symbols[new_str.size] = '\0';
	return new_str;
}

std::ostream& operator<<(std::ostream& os, const Mystr& str)
{
	os << str.symbols;
	return os;
}
