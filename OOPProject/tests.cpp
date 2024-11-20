//
// Created by vlaic on 5/4/2023.
//

#include "tests.h"
#include <assert.h>
#include <iostream>

Tests::Tests() {

}

Tests::~Tests() {

}

void Tests::testEntitate() {
    char nume[7] = "abcd";
    this->tranzactie.setNume(nume);
    this->tranzactie.setCod(12);
    this->tranzactie.setPret(10);
    assert(strcmp(this->tranzactie.getNume(), "abcd") == 0);
    assert(this->tranzactie.getCod() == 12);
    assert(this->tranzactie.getPret() == 10);
}

void Tests::testRepo() {
    char nume[7] = "abcd";
    Produse produse1(12, 8, nume);
    Produse produse2(10, 7, nume);
    repo.addElem(produse1);
    repo.addElem(produse2);
    assert(repo.getSize() == 2);
    assert(repo.getElem(1).getPret() == 7);
    assert(repo.getIndex(produse1) == 0);
    Produse produse3(11, 20, nume);
    repo.delElem(1);
    assert(repo.getSize() == 1);
}

void Tests::testRepoFile() {
    repoFile.save();
    repoFile.load();
    char nume[7] = "abcd";
    Produse produse1(12, 8, nume);
    Produse produse2(10, 7, nume);
    repoFile.addElem(produse1);
    repoFile.addElem(produse2);
    assert(repoFile.getSize() == 2);
    assert(repoFile.getElem(1).getPret() == 7);
    repoFile.delElem(1);
    assert(repoFile.getSize() == 1);
}

void Tests::testService() {
    service.save();
    service.load();
    char nume[7] = "rosii";
    Produse produse1(12, 8, nume);
    Produse produse2(10, 7, nume);
    service.adauga(nume, 12, 8);
    service.adauga(nume, 10, 7);
    assert(service.getSize() == 2);
    assert(service.getElem(1).getPret() == 7);
    Produse produse3(11, 20, nume);
    repoFile.delElem(1);
    service.adaugaMonezi(10, 10);
    service.adaugaMonezi(50, 4);
    assert(service.Tranzactie(11*10) == 1);
    assert(service.Tranzactie(20*10) == 0);

}

void Tests::tests() {
    testRepo();
    testEntitate();
    testRepoFile();
    testService();
    std::cout<<"testele au trecut cu succes!\n";
}

