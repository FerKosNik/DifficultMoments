#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <optional>
using namespace std;

struct Person {
    string SurName;
    string Name;
    string MidleName;

    friend ostream& operator<< (ostream& out, Person& p) {
        out << p.SurName << " " << p.Name << " ";
        if (p.MidleName!="") out << p.MidleName << " ";
        return out;
    };

    friend bool operator< (const Person& p1, const Person& p2) {
        return tie(p1.SurName, p1.Name, p1.MidleName) < tie(p2.SurName, p2.Name, p2.MidleName);
    };

    friend bool operator== (const Person& p1, const Person& p2) {
        return tie(p1.SurName, p1.Name, p1.MidleName) == tie(p2.SurName, p2.Name, p2.MidleName);
    };
};

struct PhoneNumber {
    int Contry;
    int City;
    string Number;
    int Extra;

    friend bool operator< (const PhoneNumber& pn1, const PhoneNumber& pn2) {
        return tie(pn1.Contry, pn1.City, pn1.Number, pn1.Extra) < tie(pn2.Contry, pn2.City, pn2.Number, pn2.Extra);
    };

    friend ostream& operator<< (ostream& out, PhoneNumber& pn) {
        out << " " << "+" << pn.Contry << "(" << pn.City << ")" << pn.Number << "  ";
        if (pn.Extra > 0) out << pn.Extra;

        return out;
    }
};

class PhoneBook {
public:
    PhoneBook(ifstream& ifIn);
    ~PhoneBook() {};

    void SortByName();
    void SortByPhone();
    void ChangePhoneNumber(Person, PhoneNumber);
    tuple <string, PhoneNumber> GetPhoneNumber(string);

    friend ostream& operator<< (ostream& out, const PhoneBook pb) {
        for (auto it : pb.Book)
            out << it.first << it.second << endl;

        return out;
    }
PhoneBook() {};
vector<pair<Person, PhoneNumber>> Book;
};