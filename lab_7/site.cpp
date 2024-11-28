#include "site.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <limits>

using namespace std;

Site::Site() {
    name = "";
    type = "";
    domain = "";
    users = 0;
    linked = 0;
    time = 0.0;
    for (int i = 0; i < 50; i++) {
        technologies[i] = "";
    }
}

Site::Site(const string& name, const string& type, const  string& domain, int users, int linked, double time, const  string technologies[]) {
    this->name = name;
    this->type = type;
    this->domain = domain;
    this->users = users;
    this->linked = linked;
    this->time = time;
    for (int i = 0; i < 50; i++) {
        this->technologies[i] = technologies[i];
    }
}

const  string& Site::getName() const {
    return name;
}

void Site::setName(const  string& name) {
    this->name = name;
}

const  string& Site::getType() const {
    return type;
}

void Site::setType(const  string& type) {
    this->type = type;
}

const  string& Site::getDomain() const {
    return domain;
}

void Site::setDomain(const  string& domain) {
    this->domain = domain;
}

int Site::getUsers() const {
    return users;
}

void Site::setUsers(int users) {
    this->users = users;
}

int Site::getLinked() const {
    return linked;
}

void Site::setLinked(int linked) {
    this->linked = linked;
}

double Site::getTime() const {
    return time;
}

void Site::setTime(double time) {
    this->time = time;
}

const  string* Site::getTechnologies() const {
    return technologies;
}

void Site::setTechnologies(const  string technologies[]) {
    for (int i = 0; i < 50; i++) {
        this->technologies[i] = technologies[i];
    }
}

bool Site::operator==(const Site& anotherSite) {
    bool isTechnologiesEqual;

    for (int i = 0; i < 50; i++) {
        if (technologies[i] != anotherSite.getTechnologies()[i]) {
            isTechnologiesEqual = false;
            break;
        }
    }

    return name == anotherSite.getName() &&
            type == anotherSite.getType() &&
            domain == anotherSite.getDomain() &&
            users == anotherSite.getUsers() &&
            linked == anotherSite.getLinked() &&
            time == anotherSite.getTime() && 
            isTechnologiesEqual;
}

void Site::readFromKeyboard() {
    string line;

    cout << "Введите имя сайта: ";
    cin.ignore();
    getline(cin, name);
    cout << "Введите тип сайта: ";
    getline(cin, type);
    cout << "Введите доменное имя сайта: ";
    getline(cin, domain);
    cout << "Введите количество пользователей: ";
    getline(cin, line);
    users =  stoi(line);
    cout << "Введите количество ссылок: ";
    getline(cin, line);
    linked =  stoi(line);
    cout << "Введите время загрузки (в секундах): ";
    getline(cin, line);
    time =  stod(line);
    cout << "Введите технологии (введите 'end' для завершения):" <<  endl;

    string tmpLine;
    for (int i = 0; i < 50; i++) {
        getline(cin, tmpLine);
        if (tmpLine == "end") {
            break;
        } else {
            technologies[i] = tmpLine;
        }
    }
}

void Site::readFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        getline(file, line);
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, type, ',');
        getline(ss, domain, ',');
        getline(ss, line, ',');
        users =  stoi(line);
        getline(ss, line, ',');
        linked =  stoi(line);
        getline(ss, line, ',');
        time =  stod(line);
        
        string tmpLine;
        for (int i = 0; i < 50; i++) {
            getline(ss, tmpLine, ',');
            if (tmpLine == "end") {
                break;
            } else {
                technologies[i] = tmpLine;
            }
        }
    }
}

void Site::display() {
    cout << "Название: " << name <<  endl;
    cout << "Тип: " << type <<  endl;
    cout << "Домен: " << domain <<  endl;
    cout << "Пользователи: " << users <<  endl;
    cout << "Ссылки: " << linked <<  endl;
    cout << "Время загрузки: " << time << " сек." <<  endl;
    cout << "Технологии: ";
    for (int i = 0; i < 50; i++) {
        if (!technologies[i].empty()) {
            cout << technologies[i] << " ";
        } else {
            break;
        }
    }
    cout <<  endl;
}

void Site::writeToFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << name << "," << type << "," << domain << "," << users << "," << linked << "," << time;
        for (int i = 0; i < 50; i++) {
            if (!technologies[i].empty()) {
                file << "," << technologies[i];
            } else {
                break;
            }
        }
        file << endl;
        file.close();
        cout << "Запись успешно добавлена." << endl;
    } else {
        cout << "Ошибка открытия файла для записи!" << endl;
    }


}
