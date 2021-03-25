#ifndef REPOBOOK_H
#define REPOBOOK_H
#include"Book.h"
#include <iostream>

class RepoBook
{
private:
	int capacity_r;
	int length_r;
public:
	Book* elems;
	RepoBook() {

	}
	RepoBook(int capacity) {
		capacity_r = capacity;
		elems = new Book[capacity_r];
		length_r = 0;
	}
	void destroy();
	int get_length();
	void set_length(int new_length);
	bool add(Book b);
	bool remove(std::string s_title);
	bool update(Book b, string s_title);
    Book* display_all();
    Book* display_genre(string s_genre);
	void add_to_listen_list(Book books[100]);
};

#endif

