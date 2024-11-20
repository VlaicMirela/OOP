//
// Created by vlaic on 5/4/2023.
//

#ifndef LABBUNOOP9_10_TESTS_H
#define LABBUNOOP9_10_TESTS_H


#include "repo.h"
#include "entitate.h"
#include "service.h"
#include "repoFile.h"

class Tests {
private:
    Repo repo;
    RepoFile repoFile;
    Produse tranzactie;
    Service service = Service(repoFile);
public:
    /**
* constructorul Tests
*/
    Tests();
    /**
* destructorul Tests
*/
    ~Tests();
    /**
* testeaza clasa entitate
*/
    void testEntitate();
    /**
* testeaza clasa repo
*/
    void testRepo();
    /**
* testeaza
*/
    void tests();

    void testRepoFile();

    void testService();
};



#endif //LABBUNOOP9_10_TESTS_H
