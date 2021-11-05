#include "PhoneBook.h"


PhoneBook::PhoneBook(ifstream& ifIn) {
    if (ifIn.is_open()) {
        while (!ifIn.eof()) {
            string tmpName, tmpSureName, tmpPhone, tmpGarb;
            string tmpMidleName;
            int tmpExtra;
            int tmpContry, tmpCity, tmpEx;
            char Check;

            getline(ifIn, tmpSureName, ' ');
            getline(ifIn, tmpName, ' ');

            Check = ifIn.peek();

            if (Check != '-') {
                getline(ifIn, tmpGarb, ' ');
                tmpMidleName = tmpGarb;
            }
            else
                ifIn.ignore(2);
            ifIn >> tmpContry;
            ifIn >> tmpCity;

            getline(ifIn, tmpPhone, ' ');
            Check = ifIn.peek();

            if (Check != '-') {
                ifIn >> tmpEx;
                tmpExtra = tmpEx;
            }

            getline(ifIn, tmpGarb, '\n');
            pair<Person, PhoneNumber> NewPhone;

            NewPhone.first = Person{ tmpSureName, tmpName, tmpMidleName };
            NewPhone.second = PhoneNumber{ tmpContry, tmpCity, tmpPhone, tmpExtra };

            Book.insert(Book.end(), NewPhone);
        }
    }
    else
        cout << "File is not open!" << endl;
    
}

void PhoneBook::SortByName() {
    sort(Book.begin(), Book.end(), [](auto& lhs, auto& rhs) {
        return lhs.first < rhs.first; });
}

void PhoneBook::SortByPhone() {
    sort(Book.begin(), Book.end(), [](auto& lhs, auto& rhs) {
        return lhs.second < rhs.second; });
}

void PhoneBook::ChangePhoneNumber(Person person, PhoneNumber phone) {
    for (auto it : Book) {
        if (it.first == person)
            it.second = phone;
    }
}

tuple <string, PhoneNumber> PhoneBook::GetPhoneNumber(string SurName) {
    tuple<string, PhoneNumber> RutPhone;
    for (auto it : Book) {
        if ((it.first.SurName == SurName) && (get<0>(RutPhone).empty())) {
            if (get<1>(RutPhone).Number.empty()) {
                get<1>(RutPhone) = it.second;
                
            }
            else get<0>(RutPhone) = "Found more that one \n";
        }
    }

    if (get<0>(RutPhone).empty() && get<1>(RutPhone).Extra == NULL) get<0>(RutPhone) = "not found person \n";
    return RutPhone;
};