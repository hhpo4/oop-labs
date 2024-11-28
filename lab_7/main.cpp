#include "Site.h"
#include "searchSite.h"
#include "SiteCollection.h"
#include <iostream>
#include <fstream>
#include <string>

#define FILE_NAME "sites.txt"

using namespace std;


int main() {
    int commonSitesMax;
    int searchSitesMax;

    cout << "Введите максимальное количество обычных сайтов в коллекции: ";
    cin >> commonSitesMax;
    cout << "Введите максимальное количество поисковых сайтов в коллекции: ";
    cin >> searchSitesMax;

    SiteCollection sites(commonSitesMax, searchSitesMax, 0, 0);

    while (true) {
        cout << "Выберите одно из действий: \n"
            << "Добавить сайт в коллекцию - 1\n"
            << "Записать сайты в файл - 2\n"
            << "Прочитать сайты из файла - 3\n"
            << "Найти самый быстрый сайт - 4\n"
            << "Вывести коллекцию на экран - 5\n"
            << "Введите 6 для выхода." << endl;
            
        
        int command;
        cin >> command;

        if (command == 6) {
            break;
        }

        switch (command) {
            case 1: {
                cout << "Сначала введите все обычные сайта, затем - поисковые." << endl;

                while (true) {
                    int addSiteCommand;

                    cout << "Добавить обычный сайт - 1\n"
                        << "Добавить поисковый сайт - 2\n"
                        << "Введите 3 для выхода." << endl;

                    cin >> addSiteCommand;

                    if (addSiteCommand == 3) {
                        break;
                    }
                    
                    switch (addSiteCommand) {
                        case 1: {
                            Site newCommonSite;
                            cin >> newCommonSite;
                            sites += newCommonSite;
                            break;
                        }
                        case 2: {
                            SearchSite newSearchSite;
                            cin >> newSearchSite;
                            sites += newSearchSite;
                            break;
                        }
                        default:
                            break;
                    }
                }

                break;
            }
            case 2: {
                ofstream file(FILE_NAME);
                if (file.is_open()) {
                    file << sites;
                    file.close();
                }
                break;
            }
            case 3: {
                sites.loadFromFile(FILE_NAME);
                cout << sites;
                break;
            }
            case 4: {
                sites.findFastestSite();
                break;
            }
            case 5: {
                cout << sites;
                break;
            }
            default: {
                break;
            }
        }
    }

    return 0;
}
