#include "Book.h"

Book::Book(int id, string author, string title, string section, string inStock, string value) //определение конструктоар 
{
	_id = id;
	_author = author;
	_title = title;
	_section = section;
	_inStock = inStock;
	_value = value;
}

int Book::id() const 
{
	return _id;
}

string Book::author() const
{
	return _author;
}

string Book::title() const
{
	return _title;
}

string Book::section() const
{
	return _section;
}

string Book::inStock() const
{
	return _inStock;
}

string Book::value() const
{
	return _value;
}

void Book::author(string s)
{
	_author = s;
}

void Book::title(string s)
{
	_title = s;
}

void Book::section(string s)
{
	_section = s;
}

void Book::inStock(string s)
{
	_inStock = s;
}

void Book::value(string s)
{
	_value = s;
}

Book::~Book() //деструктор 
{
}

ostream& operator<< (ostream& op, const Book& b)  //для вывода элементов класса
{
	op << b.author() << ' ' << b.title() << ' ' << b.section() << ' '
		<< b.inStock() << ' ' << b.value() << endl;
	return op;
}
