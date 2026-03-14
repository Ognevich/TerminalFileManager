#ifndef _MY_STR_HPP_
#define _MY_STR_HPP_
#include <iostream>

class Mystr
{
public:

	Mystr	();
	Mystr	(const char * symbols);
	Mystr	(Mystr& other);

	~Mystr	();
	

	size_t	str_size();

	Mystr&  operator=(const Mystr& other);
	char	operator[](int index);
	Mystr	operator+(const Mystr& other) const;

	friend	std::ostream& operator<<(std::ostream& os, const Mystr& str);

private:

	int size;
	char* symbols;

};

#endif 