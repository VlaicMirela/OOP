//
// Created by vlaic on 5/11/2023.
//

#ifndef LABBUNOOP9_10_SERVICE_H
#define LABBUNOOP9_10_SERVICE_H


#include "repoFile.h"
#include "monede.h"
#include "entitate.h"
#include <iostream>
#include <stack>
#include <vector>

class Service {
private:
    RepoFile repo;
    Monede monede;
public:
    /**
* constructorul service ului
* @param repo - Repo
* @return o instanta a structurii de tip tranzactie
*/
    Service(RepoFile repo);
    /**
* destructorul service ului
 */
    ~Service();
    /**
* adauga o tranzactie in lista
* @param entitate- Tranzactie
*/
    void adauga(char *nume, int cod, int pret);

    /**
* sterge o tranzactie
* @param ziua- int
*/


/**
* afiseaza o tranzactie in lista dupa suma
* @param suma - int
* @return lista - std::vector<Tranzactie>
*/
    Produse *getAll();

/**
* salveaza produsele
* @param suma - int
* @return lista - std::vector<Tranzactie>
*/
    void sterge(char *nume, int cod, int pret);

    void modifica(char *nume, int cod, int pret);

    int getSize();
    void save();

    void load();

    Produse getElem(int i);

    bool Tranzactie(int sum);

    void adaugaMonezi(int tip, int numar);

    bool Tranzactie(vector<pair<int, int>> bani, int sum);

    Monede getMonede();
};


#endif //LABBUNOOP9_10_SERVICE_H
