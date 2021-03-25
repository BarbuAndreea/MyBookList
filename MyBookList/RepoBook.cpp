#include "RepoBook.h"
#include <stdlib.h>

void RepoBook::destroy() {
    free(elems);
}

int RepoBook::get_length()
{
    return length_r;
}

void RepoBook::set_length(int new_length)
{
    length_r = new_length;
}

bool RepoBook::add(Book b)
{
    for (int i = 0; i < length_r; i++)
    {
        if (elems[i].get_title() == b.get_title())
            return false;
    }
    if (capacity_r <= length_r)
    {
        capacity_r *= 2;
        elems = new Book[capacity_r];
        if (elems == nullptr)
        {
            length_r = capacity_r = 0;
            return false;
        }
    }
    elems[length_r] = b;
    length_r++;
    return true;
}

bool RepoBook::remove(std::string s_title)
{
    for (int i = 0; i < length_r; i++)
    {
        if (elems[i].get_title() == s_title)
        {
            for (int j = i; j < length_r; j++)
            {
                elems[j] = elems[j + 1];
            }
            length_r = length_r - 1;
            return true;
        }

    }
    return false;
}

bool RepoBook::update(Book b, string s_title)
{
    for (int i = 0; i < length_r; i++)
    {
        if (elems[i].get_title() == s_title)
        {
            elems[i] = b;
            return true;
        }
    }
    return false;
}

Book* RepoBook::display_all()
{
    return elems;
}

Book* RepoBook::display_genre(string s_genre)
{
    Book* books =new Book[length_r];
    int index =0 ;
    if (s_genre == "")
        return elems;
    else {
        for (int i = 0; i < length_r; i++)
        {
            if (elems[i].get_genre() == s_genre)
            {
                books[index]= elems[i];
                index=index+1;
            }
        }
    }
    return books;
}

