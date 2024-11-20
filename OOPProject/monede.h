//
// Created by vlaic on 5/11/2023.
//

#ifndef LABBUNOOP9_10_MONEDE_H
#define LABBUNOOP9_10_MONEDE_H
#include <string>
#include <vector>

class Monede {
private:
    std::vector<std::pair<int, int>> bancnote;
public:
    Monede();
    ~Monede();
    Monede(const Monede &collection);
    Monede& operator=(const Monede &collection);
    void remove(unsigned int index);
    std::vector<std::pair<int, int>> getList();
    std::pair<int, int> index(unsigned int index);
    void eliminare(unsigned int index, int value);

    void adauga(std::pair<int, int> bac);
};


#endif //LABBUNOOP9_10_MONEDE_H
