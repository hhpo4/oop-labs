#include <iostream>
#include <fstream>
#include "Rating.h"

void addRatingToFile(const std::string& filename, const Rating& rate) {
    std::ofstream outfile(filename, std::ios::app);
    if (outfile.is_open()) {
        rate.writeToFile(outfile);
        outfile.close();
        std::cout << "Запись успешно добавлена." << std::endl;
    } else {
        std::cout << "Ошибка открытия файла для записи!" << std::endl;
    }
}

void removeRatingFromFile(const std::string& filename, int index, int& N) {
    std::ifstream infile(filename);
    std::ofstream outfile("temp.txt");
    std::string line;
    bool found = false;
    int currentIndex = 0;

    while (getline(infile, line)) {
        if (currentIndex == index) {
            found = true;
            for (int i = 0; i < 6; ++i) {
                getline(infile, line); // Пропускаем записи
            }
        } else {
            outfile << line << std::endl;
        }
        currentIndex++;
    }

    infile.close();
    outfile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    if (found) {
        std::cout << "Запись с номером " << index + 1 << " успешно удалена." << std::endl;
        N--;
    } else {
        std::cout << "Запись с номером " << index + 1 << " не найдена." << std::endl;
    }
}

int main() {
    int N;
    std::ifstream infile("lar.txt");
    if (!infile.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    infile >> N;
    infile.get();

    Rating* student = new Rating[N];

    for (int i = 0; i < N; i++) {
        student[i].readFromFile(infile);
    }

    infile.close();

    while (true) {
        std::cout << "\nВыберите одно из действий:\n1) Вывести структуру\n2) Вывести студентов, набравших <60\n3) Вывести студента с самым большим количеством баллов\n4) Добавить запись\n5) Удалить запись\n0) Выход" << std::endl;

        int mode;
        std::cin >> mode;

        switch (mode) {
            case 1:
                for (int i = 0; i < N; i++) {
                    student[i].print();
                }
                break;

            case 2: {
                std::cout << "Студенты, получившие <60:" << std::endl;
                int found = 0;
                int semes;
                std::cout << "Введите номер семестра: ";
                std::cin >> semes;
                for (int i = 0; i < N; i++) {
                    if (student[i].getMark() < 60 && student[i].getSemester() == semes) {
                        std::cout << student[i].getFIO() << std::endl;
                        found = 1;
                    }
                }

                if (!found) {
                    std::cout << "Таких нет" << std::endl;
                }
                break;
            }

            case 3: {
                std::cout << "\nСтудент с самой большой итоговой оценкой:" << std::endl;
                int max_index = 0;

                for (int i = 1; i < N; i++) {
                    if (student[i].getMark() > student[max_index].getMark()) {
                        max_index = i;
                    }
                }

                std::cout << student[max_index].getFIO() << std::endl;
                break;
            }

            case 4: {
                Rating newRating;
                newRating.inputFromKeyboard();
                addRatingToFile("lar.txt", newRating);
                Rating* newStudentList = new Rating[N + 1];
                for (int i = 0; i < N; i++) {
                    newStudentList[i] = student[i];
                }
                newStudentList[N] = newRating;
                delete[] student;
                student = newStudentList;
                N++;
                break;
            }

            case 5: {
std::cout << "Введите номер записи для удаления (1 - " << N << "): ";
                int index;
                std::cin >> index;
                if (index < 1 || index > N) {
                    std::cout << "Некорректный номер записи." << std::endl;
                } else {
                    removeRatingFromFile("lar.txt", index - 1, N);
                    Rating* newStudentList = new Rating[N];
                    for (int i = 0, j = 0; i < N + 1; i++) {
                        if (i != index - 1) {
                            newStudentList[j++] = student[i];
                        }
                    }
                    delete[] student;
                    student = newStudentList;
                }
                break;
            }

            case 0:
                std::cout << "Выход из программы." << std::endl;
                delete[] student;
                return 0;

            default:
                std::cout << "Введено недопустимое значение" << std::endl;
                break;
        }
    }

    delete[] student;
    return 0;
}