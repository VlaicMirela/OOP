//
// Created by vlaic on 5/11/2023.
//

#ifndef LABBUNOOP9_10_UI_H
#define LABBUNOOP9_10_UI_H


#include "iostream"
#include "repoFile.h"
#include "service.h"
#include <cstring>
class UI {
private:
    RepoFile repo;
    Service service = Service(repo);
public:
    UI();
    void meniu();

    void Tranzactie();
};


#endif //LABBUNOOP9_10_UI_H
