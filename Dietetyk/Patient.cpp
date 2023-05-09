#include "Patient.h"
#include <iostream>;
#include <string>

using namespace std;

int ID = 1;

Patient::Patient() {
	//cout << "DOMYSLNE" << endl;
	m_name = "Janusz";
	m_surname = "Kowalski";
	m_age = 45;
	m_weight = 95;
	m_height = 183;
	m_id = ID;
	ID++;
}

Patient::Patient(string name, string surname, int age, double weight, double height) {
	//cout << "KONSTR" << endl;
	m_name = name;
	m_surname = surname;
	m_age = age;
	m_weight = weight;
	m_height = height;
	m_id = ID;
	ID++;
}

Patient::~Patient() {}

// -------------------------------------------GETTERY-----------------------------------------------------------
string Patient::get_name() const{ return m_name; };
string Patient::get_surname() const { return m_surname; };
int Patient::get_age() const { return m_age; };
double Patient::get_weight()const {return m_weight; };
double Patient::get_height() const {return m_height;};
double Patient::get_bmi()const {return m_bmi;};
int Patient::get_id() const {return m_id;};
// -------------------------------------------SETTERY-----------------------------------------------------------
void Patient::set_name(string name) { m_name = name; };
void Patient::set_surname(string surname) { m_surname = surname; };
void Patient::set_age(short int age) { m_age = age; };
void Patient::set_weight(double weight) { m_weight = weight; };
void Patient::set_height(double height) { m_height = height; };
void Patient::set_bmi(double bmi) { m_bmi = bmi; };