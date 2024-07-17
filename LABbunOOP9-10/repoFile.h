//
// Created by vlaic on 5/11/2023.
//

#ifndef LABBUNOOP9_10_REPOFILE_H
#define LABBUNOOP9_10_REPOFILE_H

#include "repo.h"
#include <iostream>
#include <fstream>

using namespace std;

class RepoFile: private Repo {
public:
    /**
* constructorul unei liste de tranzactii
* @return o instanta a structurii de tip tranzactie
*/
    RepoFile():Repo(){}
    /**
* desconstructorul unei liste de tranzactii
* @return o instanta a structurii de tip tranzactie
*/
    ~RepoFile(){}
    /**
* creare operatorului  = unei liste de tranzactii
* @param repo - clasa repo
*/
    /**
* adauga o tranzactie in lista
* @param entitate- Tranzactie
*/
    void addElem(Produse entitate);


    int getIndex(Produse entitate);

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

    void save();

    void load();

    int inInt(char *v);
};


#endif//LABBUNOOP9_10_REPOFILE_H