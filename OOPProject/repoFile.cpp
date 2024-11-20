//
// Created by vlaic on 5/11/2023.
//

#include "repoFile.h"
ifstream f("..//date.txt");
ofstream g("..//date.txt");

int RepoFile::inInt(char v[100]) {
    int nr = 0;
    for(int i =  0; i < strlen(v); i++)
        nr = nr*10 + int(v[i] - '0');
    return nr;
}

void RepoFile::save() {
    ofstream g("..//date.txt");
    g << getSize() << endl;
    for (int i = 0; i < getSize(); i++)
    {
        Produse produse = this->getElem(i);
        g << this->getElem(i).getNume() << " " << this->getElem(i).getCod() << " " << this->getElem(i).getPret() << endl;
    }
    g.close();
}

void RepoFile::load() {
    ifstream f("..//date.txt");
    int n=getSize();
    char s[100], v[7][100];
    f>>n;
    f.get();
    Repo::destroy();
    for(int i = 0;i < n;i++) {
        f.getline(s, 100);
        int nr = 0;
        char* p = strtok(s, " ");
        while(p != NULL)
        {
            strcpy(v[nr++],p);
            p = strtok(NULL, " ");
        }
        Produse produse = Produse(inInt(v[1]), inInt(v[2]), v[0]);
        Repo::addElem(produse);
    }
    f.close();
}

void RepoFile::addElem(Produse entitate) {
    load();
    Repo::addElem(entitate);
    save();
}

Produse RepoFile::getElem(int i) {
    return Repo::getElem(i);
}

void RepoFile::modify(Produse nou) {
    load();
    Repo::modify(nou);
    save();
}

int RepoFile::getSize() {
    return Repo::getSize();
}

Produse* RepoFile::getAll() {
    return Repo::getAll();
}

int RepoFile::getIndex(Produse entitate) {
    load();
    return Repo::getIndex(entitate);
}

void RepoFile::delElem(int j) {
    load();
    Repo::delElem(j);
    save();
}

void RepoFile::del(Produse entitate) {
    load();
    Repo::del(entitate);
    save();
}

void RepoFile::destroy() {
    Repo::destroy();
    save();
}
