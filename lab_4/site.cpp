#include "site.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

void Site::readFromKeyboard() {
    std::string line;

    std::cout << "Введите имя сайта: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Введите тип сайта: ";
    std::getline(std::cin, type);
    std::cout << "Введите доменное имя сайта: ";
    std::getline(std::cin, domain);
    std::cout << "Введите количество пользователей: ";
    std::getline(std::cin, line);
    users = std::stoi(line);
    std::cout << "Введите количество ссылок: ";
    std::getline(std::cin, line);
    linked = std::stoi(line);
    std::cout << "Введите время загрузки (в секундах): ";
    std::getline(std::cin, line);
    time = std::stod(line);
    std::cout << "Введите технологии (введите 'end' для завершения):" << std::endl;
    for (int i = 0; i < 50; i++) {
        std::getline(std::cin, technologies[i]);
        if (technologies[i] == "end") {
            break;
        }
    }
}

void Site::readFromFile(std::ifstream& file) {
        std::string line;
        std::getline(file, line);
        std::stringstream ss(line);
        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, domain, ',');
        std::getline(ss, line, ',');
        users = std::stoi(line);
        std::getline(ss, line, ',');
        linked = std::stoi(line);
        std::getline(ss, line, ',');
        time = std::stod(line);
        for (int i = 0; i < 50; i++) {
            std::getline(ss, technologies[i], ',');
            if (technologies[i].empty()) {
                break;
            }
        }
}

void Site::printToScreen() const {
    std::cout << "Название: " << name << std::endl;
    std::cout << "Тип: " << type << std::endl;
    std::cout << "Домен: " << domain << std::endl;
    std::cout << "Пользователи: " << users << std::endl;
    std::cout << "Ссылки: " << linked << std::endl;
    std::cout << "Время загрузки: " << time << " сек." << std::endl;
    std::cout << "Технологии: ";
    for (int i = 0; i < 50; i++) {
        if (!technologies[i].empty()) {
            std::cout << technologies[i] << " ";
        } else {
            break;
        }
    }
    std::cout << std::endl;
}

void Site::writeToFile(const std::string& filename, bool binary) const {
    if (binary) {
        std::ofstream file(filename, std::ios::binary | std::ios::app);
        if (file.is_open()) {
            file.write(name.c_str(), name.length() + 1);
            file.write(type.c_str(), type.length() + 1);
            file.write(domain.c_str(), domain.length() + 1);
            file.write(reinterpret_cast<const char*>(&users), sizeof(int));
            file.write(reinterpret_cast<const char*>(&linked), sizeof(int));
            file.write(reinterpret_cast<const char*>(&time), sizeof(double));
            for (int i = 0; i < 50; i++) {
                if (!technologies[i].empty()) {
                    file.write(technologies[i].c_str(), technologies[i].length() + 1);
                } else {
                    break;
                }
            }
            file.close();
        } else {
            std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        }
    } else {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << name << "," << type << "," << domain << "," << users << "," << linked << "," << time;
            for (int i = 0; i < 50; i++) {
                if (!technologies[i].empty()) {
                    file << "," << technologies[i];
                } else {
                    break;
                }
            }
            file << std::endl;
            file.close();
        } else {
            std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        }
    }
    //обрезается первая буква второго записанного файла
}
