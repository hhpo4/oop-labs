#ifndef RATING_H
#define RATING_H

#include <iostream>
#include <fstream>
#include <string>

class Rating {
private:
    std::string FIO;
    int number;
    std::string speciality;
    int group;
    std::string course;
    int semester;
    int mark;

public:
    Rating();
    
    void inputFromKeyboard();
    void readFromFile(std::ifstream& file);
    void print() const;
    void writeToFile(std::ofstream& file) const;

    // Геттеры и сеттеры
    std::string getFIO() const;
    void setFIO(const std::string& fio);
    int getNumber() const;
    void setNumber(int num);
    std::string getSpeciality() const;
    void setSpeciality(const std::string& spec);
    int getGroup() const;
    void setGroup(int grp);
    std::string getCourse() const;
    void setCourse(const std::string& crs);
    int getSemester() const;
    void setSemester(int sem);
    int getMark() const;
    void setMark(int mk);
};

#endif // RATING_H