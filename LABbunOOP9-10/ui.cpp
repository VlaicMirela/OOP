//
// Created by vlaic on 5/11/2023.
//

#include "ui.h"
#include "entitate.h"

UI::UI() {
    service.adaugaMonezi(1,10);
    service.adaugaMonezi(5,20);
    service.adaugaMonezi(10, 100);
    service.adaugaMonezi(50, 40);
}

void UI::Tranzactie() {
    int index, bancnota;
    vector<pair<int, int>> bani;
    cout << "alege din urmatoarele produse: \n";
    Produse* elemente = service.getAll();
    for(int i = 0;i < service.getSize(); i++)
        cout<<i+1<<". nume: " << elemente[i].getNume() << " cod: "<< elemente[i].getCod()<<" pret: " <<elemente[i].getPret()<<endl;
    cout << "alege din produsele afisate mai sus sau din fisierul text:";
    cin>>index;
    cout << "introdu bancnota:";
    cin >> bancnota;
    bool tranz = service.Tranzactie(bani,(bancnota-elemente[index-1].getPret())*100);
    if(bancnota<elemente[index-1].getPret())
        cout << "nu ati introdus suma necesara tranzactionarii!!";
    else
    if (tranz)
    {
        cout << "tranzactie reusita!!!\n";
    }
    else
        cout << "nu dispun de restul necesar pentru a incheia tranzactia\n";

}
void UI::meniu() {
    bool ruleaza = true;
    while(ruleaza) {
        int caz = 0;
        cout<< "***admin:\n"
            << "1. adauga produs\n"
            << "2. modifica produs\n"
            << "3. sterge produs\n"
            << "4. load din fisier\n"
            << "5. save din fisier\n"
            << "6. afisare monezi din tonomat\n"
            << "***utilizator:\n"
            << "7. cumpara produs\n";
        cin >> caz;
        char nume[20];
        int cod, pret;
        switch (caz) {
            case 1: {
                cout << "nume: ";
                cin >> nume;
                cout << "cod: ";
                cin >> cod;
                cout << "pret: ";
                cin >> pret;
                Produse produse = Produse(cod, pret, nume);
                service.adauga(nume, cod, pret);
                break;
            }
            case 2: {
                cout << "tastati numele si codul produsului ce doriti sa fie schimbat pretul\n"
                     << "nume: ";
                cin >> nume;
                cout << "cod: ";
                cin >> cod;
                cout <<"noul pret: ";
                cin >> pret;
                Produse produse = Produse(cod, pret, nume);
                service.modifica(nume, cod, pret);
                break;
            }
            case 3: {cout<< "nume: ";
                cin >> nume;
                cout << "cod: ";
                cin >> cod;
                cout <<"pret: ";
                cin >> pret;
                Produse produse = Produse(cod, pret, nume);
                service.sterge(nume, cod, pret);
                break;
            }
            case 4: {
                service.load();
                break;
            }
            case 5: {
                service.save();
                break;
            }
            case 6: {
                std::vector<std::pair<int, int>> moned = service.getMonede().getList();
                for(auto i:moned)
                    cout<<"moneda: "<<i.first<<" in valoare de: "<<i.second<<endl;
                break;
            }
            case 7: {
                Tranzactie();
                break;
            }
            case 0: {
                ruleaza = 0;
                break;
            }
        }
    }
}

