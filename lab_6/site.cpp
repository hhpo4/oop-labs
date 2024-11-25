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

istream&operator>>( istream &stream, Site &anotherSite) {
    string line;

    cout << "Введите имя сайта: ";
    cin.ignore();
    getline(stream, anotherSite.name);
    cout << "Введите тип сайта: ";
    getline(stream, anotherSite.type);
    cout << "Введите доменное имя сайта: ";
    getline(stream, anotherSite.domain);
    cout << "Введите количество пользователей: ";
    getline(stream, line);
    anotherSite.users =  stoi(line);
    cout << "Введите количество ссылок: ";
    getline(stream, line);
    anotherSite.linked =  stoi(line);
    cout << "Введите время загрузки (в секундах): ";
    getline(stream, line);
    anotherSite.time =  stod(line);
    cout << "Введите технологии (введите 'end' для завершения):" <<  endl;

    string tmpLine;
    for (int i = 0; i < 50; i++) {
        getline(stream, tmpLine);
        if (tmpLine == "end") {
            break;
        } else {
            anotherSite.technologies[i] = tmpLine;
        }
    }
}

ifstream& operator>>( ifstream& stream, Site& anotherSite) {
        string line;
        getline(stream, line);
        stringstream ss(line);
        getline(ss, anotherSite.name, ',');
        getline(ss, anotherSite.type, ',');
        getline(ss, anotherSite.domain, ',');
        getline(ss, line, ',');
        anotherSite.users =  stoi(line);
        getline(ss, line, ',');
        anotherSite.linked =  stoi(line);
        getline(ss, line, ',');
        anotherSite.time =  stod(line);
        
        string tmpLine;
        for (int i = 0; i < 50; i++) {
            getline(ss, tmpLine, ',');
            if (tmpLine == "end") {
                break;
            } else {
                anotherSite.technologies[i] = tmpLine;
            }
        }
}

ostream& operator<<( ostream& stream, const Site& anotherSite) {
    stream << "Название: " << anotherSite.name <<  endl;
    stream << "Тип: " << anotherSite.type <<  endl;
    stream << "Домен: " << anotherSite.domain <<  endl;
    stream << "Пользователи: " << anotherSite.users <<  endl;
    stream << "Ссылки: " << anotherSite.linked <<  endl;
    stream << "Время загрузки: " << anotherSite.time << " сек." <<  endl;
    stream << "Технологии: ";
    for (int i = 0; i < 50; i++) {
        if (!anotherSite.technologies[i].empty()) {
            stream << anotherSite.technologies[i] << " ";
        } else {
            break;
        }
    }
    stream <<  endl;
}

ofstream& operator<<( ofstream& stream, const Site& anotherSite) {
    stream << anotherSite.getName() << "," << anotherSite.getType() << "," << anotherSite.getDomain() << "," << anotherSite.getUsers() << "," << anotherSite.getLinked() << "," << anotherSite.getTime();
    for (int i = 0; i < 50; i++) {
        if (!anotherSite.getTechnologies()[i].empty()) {
            stream << "," << anotherSite.getTechnologies()[i];
        } else {
            break;
        }
    } 
}
