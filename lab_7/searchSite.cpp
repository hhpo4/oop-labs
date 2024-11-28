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

bool SearchSite::operator==(const SearchSite& anotherSearchSite) {

}

void SearchSite::display() {    
    Site::display();
    cout << "Технология поиска: " << searchTechnology << endl;
    cout << "ИИ: " << (hasAI ? "Да" : "Нет") << endl;
}

void SearchSite::writeToFile(const string& filename) {
    Site::writeToFile(filename);
    ofstream file(filename, ios::app);
    file << ",end," << searchTechnology << "," << (hasAI ? "true" : "false");
}

void SearchSite::readFromKeyboard() {
    Site::readFromKeyboard();
    cout << "Введите технологию поиска: ";
    getline(cin, searchTechnology);
    cout << "Используется ли ИИ (true / false): ";
    string input;
    getline(cin, input);
    if (input == "true") {
        hasAI = true;
    } else if (input == "false") {
        hasAI = false;
    } else {
        cout << "Некорректное значение." << endl;
    }
}

void SearchSite::readFromFile(const string& filename) {
    Site::readFromFile(filename);
    ifstream file(filename);
    string line;
    getline(file, line);
    stringstream ss(line);
    ss >> searchTechnology;
    ss >> hasAI;
}