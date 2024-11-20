//
// Created by vlaic on 5/4/2023.
//

#ifndef LABBUNOOP9_10_ENTITATE_H
#define LABBUNOOP9_10_ENTITATE_H
#include <iostream>
#include <map>
#include <string.h>

class Produse {
private:
    unsigned int cod, pret;
    char* nume;
public:
    /**
 * constructorul unei tranzactii
 * @return o instanta a structurii de tip tranzactie
 */
    Produse();
    /**
* constructorul unei tranzactii
* @param id - int pozitiv
* @param nume - un pointer catre un sir de caractere alocat dinamic
* @param cantitate - int pozitiv
* @param concentratie - int pozitiv
* @return o instanta a structurii de tip tranzactie
*/
    Produse(int cod, int pret, char *nume);

/**
* constructorul unei tranzactii
* @param tranzactie - clasa tranzactie
*/
    Produse(const Produse& entitate);
    /**
* desconstructorul unei tranzactii
* @param tranzactie - clasa tranzactie
*/
    ~Produse();
    /**
* creare operatorului unei tranzactii
* @param tranzactie - clasa tranzactie
*/
    Produse& operator=(const Produse& entitate);
    /**
* creare operatorului  == unei tranzactii
* @param tranzactie - clasa tranzactie
*/
    bool operator==(const Produse &entitate);
    /**
* seteaza cod tranzactiei
* @param suma- int
*/
    void setCod(int s);
    /**
* constructorul unei tranzactii
* @return o instanta a structurii de tip cod
*/
    unsigned int getCod();
    /**
* seteaza descrierea tranzactiei
* @param descriere - char
*/
    void setNume(char *descriere);

    /**
* seteaza tipul tranzactiei
* @param ziua - int
*/
    void setPret(int zi);
    /**
* constructorul unei tranzactii
* @return o instanta a structurii de tip nume
*/
    char *getNume();
    /**
* constructorul unei tranzactii
* @return o instanta a structurii de tip tip
*/

    /**
* constructorul unei tranzactii
* @return o instanta a structurii de tip pret
*/
    unsigned int getPret();
};

#endif //LABBUNOOP9_10_ENTITATE_H
