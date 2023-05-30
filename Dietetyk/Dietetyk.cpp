#include <iostream>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <time.h>
#include "Patient.h"
#include "AddManual.cpp"
#include <fstream>
#include <cstdio>
#include <fstream>

vector<Patient> patients;
int lines = 0;

void show() {
    for (const auto& patient : patients) {
        cout << patient.get_id() << ". " << patient.get_name() << " " << patient.get_surname() << endl;
    }
}
void show_patient(const Patient *patientPTR) {
    cout << "Imie: " << patientPTR->get_name() << endl;
    cout << "Nazwisko: " << patientPTR->get_surname() << endl;
    cout << "Wiek: " << patientPTR->get_age() << endl;
    cout << "Wzrost: " << patientPTR->get_weight() << endl;
    cout << "Waga: " << patientPTR->get_height() << endl;
    
}
bool check_int(string znak) {
    bool is_number = true;
    for (char c : znak) {
        if (!isdigit(c)) {
            is_number = false;
        }
    }
    if (!is_number) {return false;}
    else {return true;}
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
    while (!file.eof()) {
        string linia;
        getline(file, linia);
        if (!linia.empty()) {
            lines++;
        }
        else {
            break;
        }
    }
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


void save(const Patient* patientPTR) {
    //sprawdzamy czy plik jest pusty
    int empty_file;
    ifstream file;
    file.open("Patients.txt", ios::app);
    if (file.tellg() == 0) {
        cout << file.tellg();
        cout << "Pusty" << endl;
        empty_file = 1;
    }
    else {
        empty_file = 0;
    }
    file.close();
    // Przechodzimy do zapisu
    ofstream fileo;
    if (empty_file == 1) {
        
        fileo.open("Patients.txt", ios::app);
        fileo << patientPTR->get_id() << " " << patientPTR->get_name() << " " << patientPTR->get_surname() << " " << patientPTR->get_age() << " " << patientPTR->get_weight() << " " << patientPTR->get_height() << " ";
        
    }
    else {
        
        fileo.open("Patients.txt", ios::app);
        fileo << endl;
        fileo << patientPTR->get_id() << " " << patientPTR->get_name() << " " << patientPTR->get_surname() << " " << patientPTR->get_age() << " " << patientPTR->get_weight() << " " << patientPTR->get_height() << " ";
       
    }
    file.close();
    // Do poprawy inaczej nie umiem pozbyc sie tego 'endl'
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
    cout << "4 - NIC" << endl;
    cout << "5 - Aktualizuj plik z danymi" << endl;
    cout << "************************************************************" << endl;
}

int main()
{   
    
    int on = 1;
    reading(); //Wczytanie od razu po uruchomieniu bazy osob
    do {
        system("cls");
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
            system("cls");
            show();
            int mod;
            do {
                cout << "Ktorego pacjenta chcesz usunac ? (Wprowadz jego ID): ";
                cin >> mod;
            } while (mod > patients.size() || mod < 1);
            for (auto& patient : patients) {
                if (mod == patient.get_id()) {
                    system("cls");
                    string smod_nr;
                    int mod_nr;
                    show_patient(&patient);
                    cout << "*********************************" << endl;
                    cout << "1 - Imie" << endl;
                    cout << "2 - Nazwisko" << endl;
                    cout << "3 - Wiek" << endl;
                    cout << "4 - Waga" << endl;
                    cout << "5 - Wzrost" << endl;
                    cout << "*********************************" << endl;
                    do {   
                        do {
                            cout << "Ktora z informacji chcesz zmienic ? " << endl;
                            cout << "Wybor: ";
                            cin >> smod_nr;
                        } while (check_int(smod_nr) == 0);
                        
                        mod_nr = stoi(smod_nr);
                        
                    }while(mod_nr > 5 || mod_nr < 1);
                    switch (mod_nr) {
                    case 1: {
                        system("cls");
                        cout << "Aktualne imie: " << patient.get_name() << endl;
                        cout << "------------------------------------------------" << endl;
                        cout << "Wprowadz nowe imie: ";
                        string new_name;
                        cin >> new_name;
                        patient.set_name(new_name);
                        system("cls");

                        cout << "Wprowadzono zmiany" << endl;
                        cout << "------------------------------------------------" << endl;
                        show_patient(&patient);
                        couting();
                        break;
                    }
                    case 2: {
                        system("cls");
                        cout << "Aktualne nazwisko: " << patient.get_surname() << endl;
                        couting();
                        break;
                    }
                    case 3: {
                        system("cls");
                        cout << "Aktualny wiek: " << patient.get_age() << endl;
                        couting();
                        break;
                    }
                    case 4: {
                        system("cls");
                        cout << "Aktualna waga: " << patient.get_weight() << endl;
                        couting();
                        break;
                    }
                    case 5: {
                        system("cls");
                        cout << "Aktualna wzrost: " << patient.get_height() << endl;
                        couting();
                        break;
                    }
                        
                    }
                } 
            }
            system("cls");
            couting();
            break;
        }

        case 4: {
            system("cls");
            if (remove("Patients.txt") == 0) {
                
                for (auto& patient : patients) {
                    save(&patient);
                }
                
                cout << "Dane Zaktualizowane" << endl;
            }
            else {
                cout << "ERROR" << endl;
            }
           
            couting();
            break;
        
        }
        case 5: {   
            for (auto& patient : patients) {
                save(&patient);
            }
        }
        }

    } while (on == 1);

}

