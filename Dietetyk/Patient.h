#include <iostream>	
#include <string>
#include <vector>
#pragma once

using namespace std;


class Patient
{
private:
	string m_name, m_surname;
	int m_age,m_id;
	double m_weight, m_height;
	double m_bmi;
public:
	Patient();
	Patient(string name, string surname, int age, double weight, double height);
	~Patient();
	// -------------------------------------------GETTERY-----------------------------------------------------------
	string get_name() const;
	string get_surname() const;
	int get_age() const;
	double get_weight() const;
	double get_height() const;
	double get_bmi() const;
	int get_id() const;
	// -------------------------------------------SETTERY-----------------------------------------------------------
	void set_name(string name);
	void set_surname(string surname);
	void set_age(short int age);
	void set_weight(double weight);
	void set_height(double height);
	void set_bmi(double bmi);
};

