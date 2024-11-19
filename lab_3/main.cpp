#include "site.h"
#include <iostream>
#include <vector>

#define FILE_NAME "sites.txt"

int main() {
    int siteCount;
    std::cout << "Введите требуемое количество сайтов: ";
    std::cin >> siteCount;

    std::vector<Site> sites(siteCount);

    std::string command;

    while (true) {
        std::cout << "Выберите одно из действий: \n"
            << "Ввести данные с клавиатуры - 1\n"
            << "Вывести данные на экран - 2\n"
            << "Записать данные в текстовый файл - 3\n"
            << "Записать данные в бинарный файл - 4\n"
            << "Прочитать данные с файла - 5\n"
            << "Введите 'end' для выхода." << std::endl;
        std::cin >> command;

        if (command == "end") {
            break;
        }

        int mode = std::stoi(command);

        switch (mode) {
            case 1: 
                for (Site& site : sites) {
                    site.readFromKeyboard();
                }
                break;
            case 2:
                for (const Site& site : sites) {
                    site.printToScreen();
                    std::cout << std::endl;
                }
                break;
            case 3:
                for (const Site& site : sites) {
                    site.writeToFile(FILE_NAME); 
                }
                break;
            case 4:
                for (const Site& site : sites) {
                    site.writeToFile(FILE_NAME, true); 
                }
                break;
            case 5: {
                std::ifstream infile(FILE_NAME);

                if (!infile.is_open()) {
                    std::cout << "Файл данных не найден!" << std::endl;
                    system("pause");
                    return 1;
                }

                Site *sites = new Site[siteCount];

                for (int i = 0; i < siteCount; i++) {
                    sites[i].readFromFile(infile);
                }

                infile.close();
                std::cout << "Содержимое файла: " << std::endl;

                for (int i = 0; i < siteCount; i++) {
                    sites[i].printToScreen();
                    std::cout << std::endl;
                }

                delete [] sites;
                break;
            }

            default:
                std::cout << "Неверный ввод." << std::endl;
                break;
        }
    }
    return 0;
}
