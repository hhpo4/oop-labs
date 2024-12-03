#include "searchsite.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

SearchSite::SearchSite() : Site() {
    searchTechnology = "";
    hasAI = false;
}

SearchSite::SearchSite(const string& name, const string& type, const string& domain, int users, int linked, double time, const string technologies[], const string& searchTechnology, bool hasAI)
    : Site(name, type, domain, users, linked, time, technologies) {
    this->searchTechnology = searchTechnology;
    this->hasAI = hasAI;
}

const string& SearchSite::getSearchTechnology() const {
    return searchTechnology;
}

void SearchSite::setSearchTechnology(const string& searchTechnology) {
    this->searchTechnology = searchTechnology;
}

bool SearchSite::getHasAI() const {
    return hasAI;
}

void SearchSite::setHasAI(bool hasAI) {
    this->hasAI = hasAI;
}

ostream& operator<<(ostream &stream, const SearchSite &anotherSearchSite) {
    stream << static_cast<const Site&>(anotherSearchSite);
    stream << "Технология поиска: " << anotherSearchSite.searchTechnology << endl;
    stream << "ИИ: " << (anotherSearchSite.hasAI ? "Да" : "Нет") << endl;
}

ofstream& operator<<(ofstream& stream, const SearchSite& anotherSearchSite) {
    stream << static_cast<const Site&>(anotherSearchSite);
    stream << ",end," << anotherSearchSite.searchTechnology << "," << (anotherSearchSite.hasAI ? "true" : "false");
}

istream& operator>>(istream &stream, SearchSite &anotherSearchSite) {
    stream >> static_cast<Site&>(anotherSearchSite);
    cout << "Введите технологию поиска: ";
    getline(stream, anotherSearchSite.searchTechnology);
    cout << "Используется ли ИИ (true / false): ";
    string input;
    getline(stream, input);
    if (input == "true") {
        anotherSearchSite.hasAI = true;
    } else if (input == "false") {
        anotherSearchSite.hasAI = false;
    } else {
        cout << "Некорректное значение." << endl;
    }
}

ifstream& operator>>(ifstream& stream, SearchSite& anotherSearchSite) {
    stream >> anotherSearchSite;
    cout << "Введите технологию поиска: ";
    getline(stream, anotherSearchSite.searchTechnology);
    cout << "Используется ли ИИ (true / false): ";
    string input;
    getline(stream, input);
    if (input == "true") {
        anotherSearchSite.hasAI = true;
    } else if (input == "false") {
        anotherSearchSite.hasAI = false;
    } else {
        cout << "Некорректное значение." << endl;
    }
}