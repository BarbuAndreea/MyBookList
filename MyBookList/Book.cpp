#include "Book.h"
using namespace std;

Book::Book(string title, string author, string genre, string description, string cover, int year)
{
	b_title = title;
	b_author = author;
	b_genre = genre;
	b_description = description;
	b_cover = cover;
	b_year = year;
}

string Book::get_title()
{
	return b_title;
}

string Book::get_author()
{
	return b_author;
}
string Book::get_genre()
{
	return b_genre;
}

string Book::get_description()
{
	return b_description;
}

string Book::get_cover()
{
	return b_cover;
}

int Book::get_year()
{
	return b_year;
}

void Book::set_title(std::string new_title)
{
	b_title = new_title;
}

void Book::set_author(std::string new_author)
{
	b_author = new_author;
}

void Book::set_genre(std::string new_genre)
{
	b_genre = new_genre;
}

void Book::set_description(std::string new_description)
{
	b_description = new_description;
}

void Book::set_cover(std::string new_cover)
{
	b_cover = new_cover;
}

void Book::set_year(int new_year)
{
	b_year = new_year;
}

string Book::get_string()
{
	return "Title: "+ b_title+ "; Author: "+ b_author+ "; Genre: "+ b_genre+ "; Descrition: "+ b_description+ "; Cover: "+ b_cover+ "; Year: "+ to_string(b_year)+".\n";
}

ostream& operator<<(ostream& stream, Book& book)
{
	stream << book.get_string();
	return stream;
}