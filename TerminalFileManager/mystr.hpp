#ifndef _MY_STR_HPP_
#define _MY_STR_HPP_
#include <iostream>

class Mystr
{
public:

	Mystr	(const char * symbols);
	~Mystr	();
	// ADD copy constructor;

	size_t	str_size();

	Mystr&  operator=(const Mystr& other);
	char	operator[](int index);

	friend	std::ostream& operator<<(std::ostream& os, const Mystr& str);

private:

	int size;
	char* symbols;

};

#endif 