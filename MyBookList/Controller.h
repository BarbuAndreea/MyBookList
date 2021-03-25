#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "RepoBook.h"
#include "Book.h"

class Controller
{
public:
	RepoBook* repo;
	RepoBook* list;
	Controller() {

	}
	Controller(RepoBook *r, RepoBook *l) {
		repo = r;
		list = l;
	}
	void loadCtrl();
	bool add_b(Book b);
	bool remove_b(std::string s_title);
	bool update_b(Book b, std::string s_title);
    Book* display_all_b();
    Book* display_genre_b(string s_genre);
    void add_to_listen_list(Book book);
    void r_to_listen_list(int i);
    Book* display_list();
    int getLength();
    int getLengthList();
};

#endif // CONTROLLER_H
