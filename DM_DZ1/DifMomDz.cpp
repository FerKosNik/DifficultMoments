#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

struct Person {
public:
	Person(string SurName, string Name, string MidleName = "") {
		this->SurName = SurName;
		this->Name = Name;
		this->MidleName = MidleName;
	};
	string SurName;
	string Name;
	string MidleName;
	void operator<< (Person& p) {
		if (p.MidleName != "")
		{
			cout << p.SurName << "\t" << p.Name << "\t" << p.MidleName;
		}
		else cout << p.SurName << "\t" << p.Name << "\t\t";
	};
	
	friend bool operator< (const Person& p1, const Person& p2);
	friend bool operator== (const Person& p1, const Person& p2);
};

bool operator< (const Person& p1, const Person& p2)
{
	return tie(p1.SurName, p1.Name, p1.MidleName) < tie(p2.SurName, p2.Name, p2.MidleName);
}
bool operator== (const Person& p1, const Person& p2)
{
	return tie(p1.SurName, p1.Name, p1.MidleName) == tie(p2.SurName, p2.Name, p2.MidleName);
}

struct PhoneNumber
{
public:
	PhoneNumber(int Contry, int City, string Number, int Extra = NULL) {
		this->Contry = Contry;
		this->City = City;
		this->Number = Number;
		this->Extra = Extra;
	}
		
	int Contry;
	int City;
	string Number;
	int Extra;

	void operator<< (PhoneNumber& pn) {
		if (pn.Extra > 0)
		{
			cout << "\t+" << pn.Contry << "(" << pn.City << ")" << pn.Number << "  " << pn.Extra;
		}
		else cout << "\t+" << pn.Contry << "(" << pn.City << ")" << pn.Number;
	};
};

int main()
{
	Person P1("Ivanov", "Ivan");
	Person P2("Sidorov", "Sidor", "Petrovich");

	PhoneNumber PN1(7, 812, "8177167633", 12);
	PhoneNumber PN2(7, 982, "7167633");
	P1.operator<<(P1);
	PN1.operator<<(PN1);
	cout << endl;
	P2.operator<<(P2);
	PN2.operator<<(PN2);
	return 0;
}
