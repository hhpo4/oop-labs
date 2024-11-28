#include <iostream>
#include <fstream>
#include <sstream>

#include "gameSite.h"

using namespace std;

GameSite::GameSite() : Site() {
    gameName = "";
    year = 0;
}

GameSite::GameSite(const string& name, const string& type, const string& domain, int users, int linked, double time, const string technologies[], const string& gameName, int year) : Site(name, type, domain, users, linked, time, technologies) {
    this->gameName = gameName;
    this->year = year;
}

void GameSite::display() {
    Site::display();
    cout << "Название игры: " << gameName << endl;
    cout << "Год выпуска: " << year << endl;
}

void GameSite::readFromFile(const string& filename) {
    Site::readFromFile(filename);
    ifstream file(filename);
    string line;
    getline(file, line);
    stringstream ss(line);
    ss >> gameName;
    ss >> year;
}

void GameSite::writeToFile(const string& filename) {
    Site::writeToFile(filename);
    ofstream file(filename, ios::app);
    file << ",end," << gameName << "," << year;
}

void GameSite::readFromKeyboard() {
    Site::readFromKeyboard();
    cout << "Введите название игры: ";
    cin >> gameName;
    cout << "Введите год выпуска: ";
    cin >> year;
}