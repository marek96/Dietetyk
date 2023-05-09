#include <iostream>
#include <vector>
#include <Windows.h>
#include <time.h>
#include "Patient.h"
#include "AddManual.cpp"
#include <fstream>

vector<Patient> patients;

void show() {
    for (const auto& patient : patients) {
        cout << patient.get_id() << ". " << patient.get_name() << " " << patient.get_surname() << endl;
    }
}
void add(string name, string surname, int age, double weight, double height) {

    if (patients.empty()) {
        Patient p(name, surname, age, weight, height);
        patients.push_back(p);
    }
    for (const auto& patient : patients) {
        if (surname == patient.get_surname() && name == patient.get_name()) {
            //if (name == patient.get_name()) {
            return;
        }
    }
    Patient p(name, surname, age, weight, height);
    patients.push_back(p);
 }


void reading() {
    ifstream file("Patients.txt");
    int lines = 0;
    while (!file.eof()) {
        string linia;
        getline(file, linia);
        lines++;
    }

    /*cout << endl;
    cout << "Liczba linijek: " << lines << endl;
    cout << endl;*/

    file.seekg(0);
    for (int j = 0; j < lines; j++) {
        string tab[6];
        for (int i = 0; i < 6; i++) {
            string slowo;
            getline(file, slowo, ' ');
            tab[i] = slowo;
            //cout << slowo << " ";
        };
        string n = tab[1];
        string s = tab[2];
        int a = stoi(tab[3]);
        double w = stod(tab[4]);
        double h = stod(tab[5]);
        add(n,s, a, w, h);
       
    }
}

void couting() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Powrot do menu glownego" << endl;
    for (int i = 5; i > 0; i--) {
        cout << i << " ";
        Sleep(500);
    }
}
void main_menu() {
    cout << "************************************************************" << endl;
    cout << "Panel startowy programu Dietetyk" << endl;
    cout << "1 - Dodaj pacjenta" << endl;
    cout << "2 - Wyswietl baze pacjentow" << endl;
    cout << "3 - Modyfikuj pacjentow" << endl;
    cout << "4 - Uusn pacjenta" << endl;
    cout << "************************************************************" << endl;
}

int main()
{   
    
    int on = 1;
    do {
        system("cls");
        reading(); //Wczytanie od razu po uruchomieniu bazy osob
        main_menu();
        int choice;
        cout << endl;
        cout << "Wprowadz wybor: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int decision_adding = 0;
            do {
                system("cls");
                add_manual();
                int c_patientadd;
                do {
                    cout << "Czy chcesz dodac kolejnego pacjenta ? (1-Tak / 0-Nie) ";
                    cin >> c_patientadd;
                    if (c_patientadd == 1 || c_patientadd == 0) {
                        if (c_patientadd == 1) {
                            decision_adding = 0;
                        }
                        if (c_patientadd == 0) {
                            decision_adding = 1;
                        }
                    }
                    else {
                        cout << "Wprowadz wartosc '1' lub '0' " << endl;
                    }
                } while (c_patientadd > 1); //Tu to nie dokonca dobrze dziala zakladamy ze nikt nie wklepie minusowej - mozna to potem poprawic

            } while (decision_adding == 0);

            couting();
            break;
        }
        case 2: {
            system("cls");
            show();
            couting();
            break; }
        case 3: {
            
        }

        case 4: {
            system("cls");
            show();
            cout << endl;
            int del;
            cout << "Ktorego pacjenta chcesz usunac ? (Wprowadz jego ID): ";
            cin >> del;
            for (const auto& patient : patients) {
                if (del == patient.get_id()) {
                    patients.erase(patient);
                }
            }

            break;
        
        }
        }

    } while (on == 1);

}

