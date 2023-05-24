#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    string nazwisko;
    string imie;
    int nr_albumu;
    string grupa;
    int rok;

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "Nazwisko: " << student.nazwisko << endl;
        os << "Imie: " << student.imie << endl;
        os << "Nr albumu: " << student.nr_albumu << endl;
        os << "Grupa: " << student.grupa << endl;
        os << "Rok: " << student.rok << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student) {
        is >> student.nazwisko >> student.imie >> student.nr_albumu >> student.grupa >> student.rok;
        return is;
    }
};

int main() {
    vector<Student> studenci;
    ofstream zapis("studenci.txt");
    if (zapis.is_open()) {
        for (const auto& student : studenci) {
            zapis << student << endl;
        }
        zapis.close();
    }
    else {
        cout << "Nie mozna zapisac pliku" << endl;
    }

    ifstream odczyt("studenci.txt");
    if (odczyt.is_open()) {
        Student student;
        while (odczyt >> student) {
            studenci.push_back(student);
        }
        odczyt.close();
    }
    else {
        cout << "Nie mozna odczytac pliku" << endl;
    }

    cout << "Wszyscy studenci: " << endl;
    for_each(studenci.begin(), studenci.end(), [](const Student& student) {
        cout << student << endl;
        });

    int trzeci_rok = count_if(studenci.begin(), studenci.end(), [](const Student& student) {
        return student.rok == 3;
        });
    cout << "Ilosc studentow na trzecim roku: " << trzeci_rok << endl;

    return 0;
}
