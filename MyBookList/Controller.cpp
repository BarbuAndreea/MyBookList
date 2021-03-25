#include "Controller.h"

void Controller::loadCtrl()
{
    *repo = RepoBook(100);
    Book* b1 = new Book("O scrisoare pierdută", "I.L. Caragiale", "dramatic", "comedie", "https://a.wattpad.com/cover/42526929-352-k637879.jpg", 1980);
    add_b(*b1);
    Book* b2 = new Book("Moara cu noroc ", "Ioan Slavici", "epic", "nuvelă psihologică, realistă", "https://s12emagst.akamaized.net/products/93/92070/images/res_e38c85c8603b4c581adfa2dbc171c13f_full.jpg", 1970);
    add_b(*b2);
    Book* b3 = new Book("Morometii", "Marin Preda", "epic", "roman tradițional, obiectiv, realist", "https://upload.wikimedia.org/wikipedia/ro/1/19/365778.jpg", 1982);
    add_b(*b3);
    Book* b4 = new Book("Baltagul", "Mihail Sadoveanu", "epic", "roman tradițional și obiectiv", "https://s12emagst.akamaized.net/products/9407/9406045/images/res_ec1f372ed0b1b854848021b1c4a722bb_full.jpg", 1893);
    add_b(*b4);
    Book* b5 = new Book("Ion", "Liviu Rebreanu", "epic", "roman realist-obiectiv, tradițional", "https://cdn.dc5.ro/img-prod/9786066867122-2676158.jpg", 1985);
    add_b(*b5);
    Book* b6 = new Book("Patul lui Procust", "Camil Petrescu", "epic", "roman modern, citadin", "https://www.libris.ro/img/pozeprod/59/1012/2F/602101.jpg", 1976);
    add_b(*b6);
    Book* b7 = new Book("Enigma Otiliei", "George Călinescua", "epic", "roman de tip balzacian, bildungsroman", "https://s12emagst.akamaized.net/products/100/99015/images/res_6f0c7021147059bb80c76c57907c80ea_full.jpg", 1987);
    add_b(*b7);
    Book* b8 = new Book("Iona", "Marin Sorescu", "dramatic", "parabolă dramatică, teatru modern postbelic", "https://s12emagst.akamaized.net/products/19370/19369799/images/res_4780440d9e9dc128cca38207b6565d95_full.jpg", 1899);
    add_b(*b8);
    Book* b9 = new Book("Povestea lui Harap-Alb", "Ion Creangă", "epic", "basm", "https://s12emagst.akamaized.net/products/987/986834/images/res_def052f0eff0e5caa11dab737810611e_full.jpg", 1987);
    add_b(*b9);
    Book* b10 = new Book("Alexandru Lăpușneanu", "Costache Negruzzi", "epic", "nuvelă istorică", "https://s12emagst.akamaized.net/products/87/86130/images/res_7c467b5bf411b05ed70fb00ca6216a40_full.jpg", 1898);
    add_b(*b10);
    Book* b11 = new Book("Floare albastră", "Mihai Eminescu", "liric", "poezie romantică", "https://i.pinimg.com/originals/76/7a/79/767a79d404659a5df931dc8cb51c7109.jpg", 1998);
    add_b(*b11);
}

bool Controller::add_b(Book b)
{
    return repo->add(b);
}

bool Controller::remove_b(std::string s_title)
{
    return repo->remove(s_title);
}

bool Controller::update_b(Book b, std::string s_title)
{
    return repo->update(b, s_title);
}

Book* Controller::display_all_b()
{
    return  repo->display_all();
}

Book* Controller::display_genre_b(string s_genre)
{
    return  repo->display_genre(s_genre);
}

void Controller::add_to_listen_list(Book book)
{
    list->add(book);
}

void Controller::r_to_listen_list(int i)
{

    list->remove(list->elems[i].get_title());
}

Book* Controller::display_list()
{
    return list->display_all();
}

int Controller::getLength(){
    return repo->get_length();
}
int Controller::getLengthList(){
    return list->get_length();
}
