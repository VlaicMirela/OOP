//
// Created by vlaic on 5/4/2023.
//

#ifndef LABBUNOOP9_10_REPO_H
#define LABBUNOOP9_10_REPO_H

#include "entitate.h"
#include <stack>

class Repo {
private:
    Produse* entitati;
    int nrElem = 0;
public:
    /**
* constructorul unei liste de tranzactii
* @return o instanta a structurii de tip tranzactie
*/
    Repo();
    /**
* desconstructorul unei liste de tranzactii
* @return o instanta a structurii de tip tranzactie
*/
    ~Repo();
    /**
* creare operatorului  = unei liste de tranzactii
* @param repo - clasa repo
*/
    Repo& operator=(const Repo repo);

    virtual /**
* adauga o tranzactie in lista
* @param entitate- Tranzactie
*/
    void addElem(Produse entitate);


    virtual int getIndex(Produse entitate);

    /**
* modifica o tranzactie in lista
* @param nou- Tranzactie
*/
    void modify(Produse nou);
    /**
* sterge o tranzactie in lista
* @param j- int
*/
    void delElem(int j);

    /**
* desconstructorul unei liste de tranzactii
* @return o instanta a structurii de tip tranzactie
*/
    void destroy();

    /**
* sterge o tranzactie in lista
* @param nou- Tranzactie
*/
    void del(Produse entitate);

    Produse *getAll();

    int getSize();

    Produse getElem(int i);
};


#endif  //LABBUNOOP9_10_REPO_H
