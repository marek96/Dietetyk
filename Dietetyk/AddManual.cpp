#ifndef Add_Manual
#define Add_Manual
#include "Patient.h"
#include <fstream>

extern vector<Patient> patients;

inline void add_manual() {

    string name, surname;
    int age;
    double weight, height;
    cout << "Podaj imie: ";
    cin >> name;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    //--------------------------------AGE-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    bool good_age = false;
    do {
        cout << "Podaj wiek: ";
        string s_age;
        cin >> s_age;
        bool is_number = true;
        for (char c : s_age) {
            if (!isdigit(c)) {
                is_number = false;
                break;
            }
        }
        if (!is_number) {
            cout << "To nie jest liczba, Dodaj wiek ponownie !!" << endl;
            good_age = false;
        }
        else {
            age = stoi(s_age);
            good_age = true;
        }
    } while (!good_age);

    //--------------------------------WEIGHT------------------------------------------------------------------------------------------------------------------------------------------------------
    bool good_weight = false;
   
    do {
        cout << "Podaj wage: ";
        string s_weight;
        cin >> s_weight;
        try {
            weight = stod(s_weight);
            if (weight <= 0) {
                cout << "Waga nie moze byc ujemna, Dodaj wage ponownie !!" << endl;
                good_weight = false;
            }
            else {
                good_weight = true;
            }
        }
        catch (const invalid_argument& e) {
            cout << "To nie jest liczba, Dodaj wage ponownie !!" << endl;
            good_weight = false;
        }
    } while (!good_weight);

    //--------------------------------HEIGHT------------------------------------------------------------------------------------------------------------------------------------------------------
    bool good_height = false;

    do {
        cout << "Podaj wzrost: ";
        string s_height;
        cin >> s_height;
        try {
            height = stod(s_height);
            if (height <= 0) {
                cout << "Wzrost nie moze byc ujemna, Dodaj wzrost ponownie !!" << endl;
                good_height = false;
            }
            else {
                good_height = true;
            }
        }
        catch (const invalid_argument& e) {
            cout << "To nie jest liczba, Dodaj wzrost ponownie !!" << endl;
            good_height = false;
        }
    } while (!good_height);
    
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    Patient p(name, surname, age, weight, height);
    patients.push_back(p);
    
    /*
    ofstream file;
    file.open("Patients.txt", ios::app);
    file << endl;
    file << p.get_id() << " " << name << " " << surname << " " << age << " " << weight << " " << height << " ";
    file.close();
    */

}


#endif