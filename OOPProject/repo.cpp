//
// Created by vlaic on 5/4/2023.
//

#include "repo.h"
#include <iostream>
using namespace std;

Repo::Repo() {
    this->nrElem = 0;
    this->entitati = new Produse[0];
}

Repo::~Repo() {

}

void Repo::destroy() {
    this->entitati = new Produse[0];
    this->nrElem = 0;
}

Repo& Repo::operator=(const Repo repo) {
    for(int i = 0;i< repo.nrElem;i++)
        this->entitati[i] = repo.entitati[i];
    return *this;
}

void Repo::addElem(Produse entitate) {

    Produse* copie = new Produse[this->nrElem];
    for(int i = 0;i< this->nrElem;i++)
        copie[i] = this->entitati[i];
    this->entitati = new Produse[++this->nrElem];
    for(int i = 0;i< this->nrElem-1;i++)
        this->entitati[i] = copie[i];
    this->entitati[this->nrElem-1] = entitate;
}

int Repo::getIndex(Produse entitate) {
    for(int i = 0;i<this->nrElem;i++)
        if(this->entitati[i] == entitate)
            return i;
    return -1;
}

void Repo::delElem(int j) {
    Produse* copie = new Produse[this->nrElem];
    for(int i = j;i< this->nrElem-1;i++)
        this->entitati[i] = this->entitati[i+1];
    for(int i = 0;i< this->nrElem-1;i++)
        copie[i] = this->entitati[i];
    this->entitati = new Produse[--this->nrElem];
    for(int i = 0;i< this->nrElem;i++)
        this->entitati[i] = copie[i];
}

void Repo::del(Produse entitate) {
    for(int i = 0;i < this->nrElem;i++)
        if(this->entitati[i] == entitate) {
            delElem(i);
            i = this->nrElem;
        }
}
void Repo::modify(Produse nou) {
    for(int i = 0;i < this->nrElem; i++)
        if(this->entitati[i].getCod() == nou.getCod() and strcmp(this->entitati[i].getNume(),nou.getNume()) == 0)
            this->entitati[i] = nou;
}

Produse* Repo::getAll() {
    return this->entitati;
}

int Repo::getSize() {
    return this->nrElem;
}

Produse Repo::getElem(int i) {
    return this->entitati[i];
}

