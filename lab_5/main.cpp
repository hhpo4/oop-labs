#include "Site.h"
#include "SiteCollection.h"
#include <iostream>

#define FILE_NAME "sites.txt"


int main() {
    SiteCollection sites(11, 10);

    sites.loadFromFile(FILE_NAME);
    sites.displayAll();

    std::string command;

    while (true) {
        std::cout << "Выберите одно из действий: \n"
            << "Добавить новый элемент - 1\n"
            << "Удалить элемент по индексу - 2\n"
            << "Найти самый быстрый сайт - 3\n"
            << "Сохранить данные в файл - 4\n"
            << "Прочитать данные из файла - 5\n"
            << "Вывести данные на экран - 6\n"
            << "Введите 'end' для выхода." << std::endl;

        std::cin >> command;

        if (command == "end") {
            break;
        }

        int mode = std::stoi(command);

        switch (mode) {
            case 1: {
                Site newSite;
                std::cin >> newSite;
                sites += newSite;
                std::cout << "Элемент добавлен: " << std::endl << newSite << std::endl;
                break;
            }
            case 2: {
                int index;
                std::cout << "Введите индекс элемента для удаления: ";
                std::cin >> index;
                sites.removeSite(index);
                break;
            }
            case 3: {
                Site* fastestSite = sites.findFastestSite();
                std::cout << "Самый быстрый сайт: " << fastestSite->getName() << std::endl;
                std::cout << "Скорость: " << fastestSite->getTime() << std::endl << std::endl;
                break;
            }
            case 4: {
                sites.saveToFile(FILE_NAME);
                break;
            }
            case 5: {
                sites.loadFromFile(FILE_NAME);
                break;
            }
            case 6: {
                sites.displayAll();
                break;
            }
            default:
                std::cout << "Неверный ввод." << std::endl;
                break;
        }
    }

    return 0;
}
