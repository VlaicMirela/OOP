//
// Created by vlaic on 5/4/2023.
//

#include "entitate.h"

Produse::Produse() {
    this->setCod(0);
    this->setPret(0);
    this->nume = nullptr;
}

Produse::Produse(int cod, int pret, char *nume) {
    this->setCod(cod);
    this->setPret(pret);
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
}

Produse::Produse(const Produse &entitate) {
    this->setCod(entitate.cod);
    this->setPret(entitate.pret);
    char in[] = "in", out[] = "out";
    if(entitate.nume != nullptr) {
        this->nume = new char[strlen(entitate.nume) + 1];
        strcpy(this->nume, entitate.nume);
    }
    else
        this->nume = nullptr;
}

Produse::~Produse() {
    delete[] this->nume;
    nume = nullptr;
}

Produse &Produse::operator=(const Produse &entitate) {
    this->setCod(entitate.cod);
    this->setPret(entitate.pret);
    if(entitate.nume != nullptr) {
        this->nume = new char[strlen(entitate.nume) + 1];
        strcpy(this->nume, entitate.nume);
    }
    else
        this->nume = nullptr;
    return *this;
}

bool Produse::operator==(const Produse &entitate) {
    return (this->cod == entitate.cod) && (this->pret == entitate.pret) && (strcmp(this->nume, entitate.nume) == 0);
}

void Produse::setCod(int s) {
    this->cod = s;
}

void Produse::setNume(char* descriere) {
    if(this->nume)
        delete[] this->nume;
    this->nume = new char[strlen(descriere) + 1];
    strcpy(this->nume, descriere);
}


void Produse::setPret(int zi) {
    this->pret = zi;
}

unsigned int Produse::getCod() {
    return this->cod;
}

unsigned int Produse::getPret() {
    return this->pret;
}

char* Produse::getNume() {
    return this->nume;
}

