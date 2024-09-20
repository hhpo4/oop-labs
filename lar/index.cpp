#include <cstdio> 
#include <cstdlib> 
#include <string> 
#include <iostream>
#include <fstream> 

using namespace std; 

struct rating { 
    string FIO; 
    int number; 
    string speciality; 
    int group; 
    string course; 
    int semester; 
    int mark; 
}; 

int main() {
    ifstream inputFile("input.txt"); 
    int N;
    inputFile >> N;
    inputFile.close();

    rating* student = new rating[N];

    ifstream dataFile("data.txt");
    for (int i = 0; i < N; i++) {
        dataFile >> student[i].FIO >> student[i].number >> student[i].speciality >> student[i].group >> student[i].course >> student[i].semester >> student[i].mark;
    }
    dataFile.close();

    int found = 0;
    int semes;

    cout << "Введите номер семестра: ";
    cin >> semes;

    cout << "Студенты, получившие <60: ";
    for (int i = 0; i < N; i++) {
        if (student[i].mark < 60 && student[i].semester == semes) {
            cout << student[i].FIO << " ";
            found = 1;
        }
    }

    if (!found) {
        cout << "Таких нет";
    }

    cout << "\nСтудент с самой большой итоговой оценкой: ";
    int max_ocenka = 0;

    for (int i = 1; i < N; i++) {
        if (student[i].mark > student[max_ocenka].mark) {
            max_ocenka = i; 
        }
    }

    cout << student[max_ocenka].FIO << endl;

    ofstream outputFile("output.txt");
    for (int i = 0; i < N; i++) {
        outputFile << "\n\nФИО: " << student[i].FIO << "\n";
        outputFile << "Номер студака: " << student[i].number << "\n";
        outputFile << "Название специальности: " << student[i].speciality << "\n";
        outputFile << "Номер группы: " << student[i].group << "\n";
        outputFile << "Название дисциплины: " << student[i].course << "\n";
        outputFile << "Семестр: " << student[i].semester << "\n";
        outputFile << "Баллы: " << student[i].mark << "\n";
    }
    outputFile.close();

    delete[] student;

    return 0;
}