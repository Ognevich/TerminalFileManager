#include "mystr.hpp"
#include <string.h>

Mystr::Mystr(const char* symbols)
{
	this->size = strlen(symbols);
	this->symbols = new char[this->size + 1];

	memcpy(this->symbols, symbols, size + 1);
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

std::ostream& operator<<(std::ostream& os, const Mystr& str)
{
	os << str.symbols;
	return os;
}
