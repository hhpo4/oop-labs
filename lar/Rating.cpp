#include "Rating.h"

Rating::Rating() : number(0), group(0), semester(0), mark(0) {}

void Rating::inputFromKeyboard() {
    std::cout << "Введите ФИО: ";
    std::cin.ignore();
    std::getline(std::cin, FIO);
    std::cout << "Введите номер студента: ";
    std::cin >> number;
    std::cout << "Введите название специальности: ";
    std::cin.ignore();
    std::getline(std::cin, speciality);
    std::cout << "Введите номер группы: ";
    std::cin >> group;
    std::cout << "Введите название дисциплины: ";
    std::cin.ignore();
    std::getline(std::cin, course);
    std::cout << "Введите номер семестра: ";
    std::cin >> semester;
    std::cout << "Введите баллы: ";
    std::cin >> mark;
}

void Rating::readFromFile(std::ifstream& file) {
    std::getline(file, FIO);
    file >> number;
    file.ignore();
    std::getline(file, speciality);
    file >> group;
    file.ignore();
    std::getline(file, course);
    file >> semester;
    file >> mark;
    file.ignore();
}

void Rating::print() const {
    std::cout << "ФИО: " << FIO << std::endl;
    std::cout << "Номер студента: " << number << std::endl;
    std::cout << "Название специальности: " << speciality << std::endl;
    std::cout << "Номер группы: " << group << std::endl;
    std::cout << "Название дисциплины: " << course << std::endl;
    std::cout << "Номер семестра: " << semester << std::endl;
    std::cout << "Баллы: " << mark << std::endl;
}

void Rating::writeToFile(std::ofstream& file) const {
    file << FIO << std::endl;
    file << number << std::endl;
    file << speciality << std::endl;
    file << group << std::endl;
    file << course << std::endl;
    file << semester << std::endl;
    file << mark << std::endl;
}

// Геттеры и сеттеры
std::string Rating::getFIO() const { return FIO; }
void Rating::setFIO(const std::string& fio) { FIO = fio; }
int Rating::getNumber() const { return number; }
void Rating::setNumber(int num) { number = num; }
std::string Rating::getSpeciality() const { return speciality; }
void Rating::setSpeciality(const std::string& spec) { speciality = spec; }
int Rating::getGroup() const { return group; }
void Rating::setGroup(int grp) { group = grp; }
std::string Rating::getCourse() const { return course; }
void Rating::setCourse(const std::string& crs) { course = crs; }
int Rating::getSemester() const { return semester; }
void Rating::setSemester(int sem) { semester = sem; }
int Rating::getMark() const { return mark; }
void Rating::setMark(int mk) { mark = mk; }