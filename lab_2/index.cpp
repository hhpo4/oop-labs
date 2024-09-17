#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#define MAX_TECHNOLOGIES 50
#define MAX_SITES 10

struct Site {
    string name;
    string type;
    string domain;
    int users;
    int linked;
    double time;
    string technologies[MAX_TECHNOLOGIES];
};

void readSitesFromFile(string filename, Site sites[]);
void printSites(Site sites[]); 
Site findFastestSearch(Site sites[]);
void printSitesWithMinUsers(Site sites[], int minUsers);

int main() {
    Site* sites = new Site[MAX_SITES];

    readSitesFromFile("websites.txt", sites);
    
    printSites(sites);

    Site fastestSearch = findFastestSearch(sites);
    cout << "Доменное имя самого быстрого поискового сервиса: " << fastestSearch.domain << endl << endl;

    int minUsers;
    cout << "Введите минимальное число пользователей в день: ";
    cin >> minUsers;

    printSitesWithMinUsers(sites, minUsers);

    delete[] sites;

    return 0;
}

void readSitesFromFile(string filename, Site sites[]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    int index = 0;
    while (index < MAX_SITES && getline(file, line)) {
        stringstream ss(line);
        getline(ss, sites[index].name, ',');
        getline(ss, sites[index].type, ',');
        getline(ss, sites[index].domain, ',');
        getline(ss, line, ',');
        sites[index].users = stoi(line);
        getline(ss, line, ',');
        sites[index].linked = stoi(line);
        getline(ss, line, ',');
        sites[index].time = stod(line);

        int techIndex = 0;
        while (techIndex < MAX_TECHNOLOGIES && getline(ss, line, ',')) {
            sites[index].technologies[techIndex++] = line;
        }

        index++;
    }

    file.close();
}

void printSites(Site sites[]) {
    for (int i = 0; i < MAX_SITES; i++) {
        if (sites[i].name != "") {
            cout << "Название: " << sites[i].name << endl;
            cout << "Тип: " << sites[i].type << endl;
            cout << "Домен: " << sites[i].domain << endl;
            cout << "Пользователи: " << sites[i].users << endl;
            cout << "Ссылки: " << sites[i].linked << endl;
            cout << "Время загрузки: " << sites[i].time << " сек." << endl;
            cout << "Технологии: ";
            for (int j = 0; j < MAX_TECHNOLOGIES; j++) {
                if (sites[i].technologies[j] != "") {
                    cout << sites[i].technologies[j] << " ";
                } else {
                    break;
                }
            }
            cout << endl << endl;
        }
    }
}

Site findFastestSearch(Site sites[]) {
    Site fastestSearch = sites[0];
    for (int i = 0; i < MAX_SITES; i++) {
        if (sites[i].name != "" && sites[i].type == "Поисковый" && sites[i].time < fastestSearch.time) {
            fastestSearch = sites[i];
        }
    }
    return fastestSearch;
}

void printSitesWithMinUsers(Site sites[], int minUsers) {
    cout << "Информация о ресурсах с числом пользователей больше " << minUsers << ":\n";
    for (int i = 0; i < MAX_SITES; i++) {
        if (sites[i].name != "" && sites[i].users > minUsers) {
            cout << "Название: " << sites[i].name << endl;
            cout << "Тип: " << sites[i].type << endl;
            cout << "Домен: " << sites[i].domain << endl;
            cout << "Пользователи: " << sites[i].users << endl;
            cout << "Ссылки: " << sites[i].linked << endl;
            cout << "Время загрузки: " << sites[i].time << " сек." << endl;
            cout << "Технологии: ";
            for (int j = 0; j < MAX_TECHNOLOGIES; j++) {
                if (sites[i].technologies[j] != "") {
                    cout << sites[i].technologies[j] << " ";
                } else {
                    break;
                }
            }
            cout << endl;
        }
    }
}
