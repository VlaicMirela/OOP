//
// Created by vlaic on 5/11/2023.
//

#include "monede.h"
#include <string>
#include <bits/stdc++.h>
using namespace std;

Monede::Monede()
{

}


Monede::~Monede()
{
}


Monede::Monede(const Monede &collection)
{
    this -> bancnote = collection.bancnote;
}


Monede& Monede::operator=(const Monede &collection)
{
    this -> bancnote = collection.bancnote;
    return *this;
}

void Monede::adauga(std::pair<int, int> bac)
{
    int gasit=0;
    for (int i = 0; i < this->bancnote.size(); i++)
    {
        if(this->bancnote[i].first == bac.first)
        {
            gasit=1;
            this->bancnote[i].second = this->bancnote[i].second + bac.second;
        }
    }
    if(!gasit)
        this -> bancnote.push_back(bac);


    sort(this -> bancnote.begin(), this -> bancnote.end(),[](std::pair<int, int> &a, std::pair<int, int> &b){ return (a.first > b.first);});
}

void Monede::remove(unsigned int index)
{
    if(index < this -> bancnote.size())
    {
        this -> bancnote.erase(this->bancnote.begin()+index);
    }
}

std::vector<std::pair<int, int>> Monede::getList()
{
    return this -> bancnote;
}


void Monede::eliminare(unsigned int index, int value) {
    this -> bancnote[index].second = this -> bancnote[index].second-value;
    if(this -> bancnote[index].first == 0)
        remove(index);
}
