#ifndef BOOK_H
#define BOOK_H
#include<string>
#include <ostream>
using namespace std;

class Book
{
private:
	std::string b_title, b_author, b_genre, b_description, b_cover;
	int b_year;

public:
	Book(){

	}
	Book(std::string title, std::string author, std::string genre, std::string description, std::string cover, int year);
	std::string get_title();
	std::string get_author();
	std::string get_genre();
	std::string get_description();
	std::string get_cover();
	int get_year();
	void set_title(std::string new_title);
	void set_author(std::string new_author);
	void set_genre(std::string new_genre);
	void set_description(std::string new_description);
	void set_cover(std::string new_cover);
	void set_year(int new_year);
	std::string get_string();
friend ostream& operator<<(ostream& stream, Book& book);

};

#endif //BOOK_H
