#include "site.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>

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

Site::Site(const std::string& name, const std::string& type, const std::string& domain, int users, int linked, double time, const std::string technologies[]) {
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

const std::string& Site::getName() const {
    return name;
}

void Site::setName(const std::string& name) {
    this->name = name;
}

const std::string& Site::getType() const {
    return type;
}

void Site::setType(const std::string& type) {
    this->type = type;
}

const std::string& Site::getDomain() const {
    return domain;
}

void Site::setDomain(const std::string& domain) {
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

const std::string* Site::getTechnologies() const {
    return technologies;
}

void Site::setTechnologies(const std::string technologies[]) {
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

std::istream&operator>>(std::istream &stream, Site &anotherSite) {
    std::string line;

    std::cout << "Введите имя сайта: ";
    std::cin.ignore();
    std::getline(stream, anotherSite.name);
    std::cout << "Введите тип сайта: ";
    std::getline(stream, anotherSite.type);
    std::cout << "Введите доменное имя сайта: ";
    std::getline(stream, anotherSite.domain);
    std::cout << "Введите количество пользователей: ";
    std::getline(stream, line);
    anotherSite.users = std::stoi(line);
    std::cout << "Введите количество ссылок: ";
    std::getline(stream, line);
    anotherSite.linked = std::stoi(line);
    std::cout << "Введите время загрузки (в секундах): ";
    std::getline(stream, line);
    anotherSite.time = std::stod(line);
    std::cout << "Введите технологии (введите 'end' для завершения):" << std::endl;
    for (int i = 0; i < 50; i++) {
        std::getline(stream, anotherSite.technologies[i]);
        if (anotherSite.technologies[i] == "end") {
            break;
        }
    }
}

std::ifstream& operator>>(std::ifstream& stream, Site& anotherSite) {
        std::string line;
        std::getline(stream, line);
        std::stringstream ss(line);
        std::getline(ss, anotherSite.name, ',');
        std::getline(ss, anotherSite.type, ',');
        std::getline(ss, anotherSite.domain, ',');
        std::getline(ss, line, ',');
        anotherSite.users = std::stoi(line);
        std::getline(ss, line, ',');
        anotherSite.linked = std::stoi(line);
        std::getline(ss, line, ',');
        anotherSite.time = std::stod(line);
        for (int i = 0; i < 50; i++) {
            std::getline(ss, anotherSite.technologies[i], ',');
            if (anotherSite.technologies[i].empty()) {
                break;
            }
        }
}

std::ostream& operator<<(std::ostream& stream, const Site& anotherSite) {
    stream << "Название: " << anotherSite.name << std::endl;
    stream << "Тип: " << anotherSite.type << std::endl;
    stream << "Домен: " << anotherSite.domain << std::endl;
    stream << "Пользователи: " << anotherSite.users << std::endl;
    stream << "Ссылки: " << anotherSite.linked << std::endl;
    stream << "Время загрузки: " << anotherSite.time << " сек." << std::endl;
    stream << "Технологии: ";
    for (int i = 0; i < 50; i++) {
        if (!anotherSite.technologies[i].empty()) {
            stream << anotherSite.technologies[i] << " ";
        } else {
            break;
        }
    }
    stream << std::endl;
}

std::ofstream& operator<<(std::ofstream& stream, const Site& anotherSite) {
    stream << anotherSite.getName() << "," << anotherSite.getType() << "," << anotherSite.getDomain() << "," << anotherSite.getUsers() << "," << anotherSite.getLinked() << "," << anotherSite.getTime();
    for (int i = 0; i < 50; i++) {
        if (!anotherSite.getTechnologies()[i].empty()) {
            stream << "," << anotherSite.getTechnologies()[i];
        } else {
            stream << std::endl;
            break;
        }
    } 
}
