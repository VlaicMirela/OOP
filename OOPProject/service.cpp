//
// Created by vlaic on 5/11/2023.
//

#include "service.h"
Service::Service(RepoFile repo) {
    this->repo = repo;
}

Service::~Service() {
    this->repo.destroy();
}

void Service::adauga(char *nume, int cod, int pret) {
    Produse produse = Produse(cod, pret, nume);
    this->repo.addElem(produse);
}

void Service::sterge(char *nume, int cod, int pret) {
    Produse produse = Produse(cod, pret, nume);
    this->repo.del(produse);
}

void Service::modifica(char *nume, int cod, int pret) {
    Produse produse = Produse(cod, pret, nume);
    this->repo.modify(produse);
}

int Service::getSize() {
    return this->repo.getSize();
}

Produse Service::getElem(int i){
    return repo.getElem(i);
}

Produse* Service::getAll() {
    return this->repo.getAll();
}

void Service::load() {
    this->repo.load();
}

void Service::save() {
    this->repo.save();
}

bool Service::Tranzactie(std::vector<pair<int,int>> bani, int sum) {
    int total = 0;
    std::vector<std::pair<int, int>> lista = this->monede.getList();
    for (int it = 0; it < lista.size(); it++) {
        int currency = lista[it].first, value;
        if (lista[it].second * lista[it].first > sum)
            value = sum / lista[it].first;
        else
            value = lista[it].second;
        if (currency * value > 0) {
            std::pair<int, int> bac;
            bac.first = currency;
            bac.second = value;
            total += currency * value;
            bani.push_back(bac);
            this->monede.eliminare(it, value);
            sum = sum - currency * value;
        }
    }
    if (sum != 0) {
        return 0;
    }
    for(auto i:bani)
        cout<<"moneda: " <<i.first<<" in numar de: "<<i.second<<endl;
    return 1;
}

bool Service::Tranzactie(int sum) {
    int total = 0;
    std::vector<std::pair<int, int>> lista = this->monede.getList();
    for (int it = 0; it < lista.size(); it++) {
        int currency = lista[it].first, value;
        if (lista[it].second * lista[it].first > sum)
            value = sum / lista[it].first;
        else
            value = lista[it].second;
        if (currency * value > 0) {
            std::pair<int, int> bac;
            bac.first = currency;
            bac.second = value;
            total += currency * value;
            this->monede.eliminare(it, value);
            sum = sum - currency * value;
        }
    }
    if (sum != 0) {
        return 0;
    }
    return 1;
}
void Service::adaugaMonezi(int tip, int numar) {
    std::pair<int, int> monede;
    monede.first = tip;
    monede.second = numar;
    this->monede.adauga(monede);
}

Monede Service::getMonede() {
    return this->monede;
}