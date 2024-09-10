#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#define MAX_TECHNOLOGIES 50

struct Site {
    string name;
    string type;
    string domain;
    int users;
    int linked;
    double time;
    string technologies[MAX_TECHNOLOGIES];
};

void readSitesFromFile(string filename, vector<Site>& sites) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        Site site;
        
        stringstream ss(line);
        getline(ss, site.name, ',');
        getline(ss, site.type, ',');
        getline(ss, site.domain, ',');
        getline(ss, line, ',');
        site.users = stoi(line);
        getline(ss, line, ',');
        site.linked = stoi(line);
        getline(ss, line, ',');
        site.time = stod(line);

        int techIndex = 0;
        while (getline(ss, line, ',')) {
            site.technologies[techIndex++] = line;
        }

        sites.push_back(site);
    }

    file.close();
}

void printSites(const vector<Site>& sites) {
    for (const Site& site : sites) {
        cout << "Название: " << site.name << endl;
        cout << "Тип: " << site.type << endl;
        cout << "Домен: " << site.domain << endl;
        cout << "Пользователи: " << site.users << endl;
        cout << "Ссылки: " << site.linked << endl;
        cout << "Время загрузки: " << site.time << " сек." << endl;
        cout << "Технологии: ";
        for (int i = 0; i < MAX_TECHNOLOGIES; i++) {
            if (site.technologies[i] != "") {
                cout << site.technologies[i] << " ";
            } else {
                break;
            }
        }
        cout << endl << endl;
    }
}

Site findFastestSearch(const vector<Site>& sites) {
    Site fastestSearch = sites[0]; 
    for (const Site& site : sites) {
        if (site.type == "Поисковый" && site.time < fastestSearch.time) {
            fastestSearch = site;
        }
    }
    return fastestSearch;
}

void printSitesWithMinUsers(const vector<Site>& sites, int minUsers) {
    cout << "Информация о ресурсах с числом пользователей больше " << minUsers << ":\n";
    for (const Site& site : sites) {
        if (site.users > minUsers) {
            cout << "Название: " << site.name << endl;
            cout << "Тип: " << site.type << endl;
            cout << "Домен: " << site.domain << endl;
            cout << "Пользователи: " << site.users << endl;
            cout << "Ссылки: " << site.linked << endl;
            cout << "Время загрузки: " << site.time << " сек." << endl;
            cout << "Технологии: ";
            for (int i = 0; i < MAX_TECHNOLOGIES; i++) {
                if (site.technologies[i] != "") {
                    cout << site.technologies[i] << " ";
                } else {
                    break;
                }
            }
            cout << endl << endl;
        }
    }
}

int main() {
    vector<Site> sites;

    readSitesFromFile("websites.txt", sites);

    Site fastestSearch = findFastestSearch(sites);
    cout << "Доменное имя самого быстрого поискового сервиса: " << fastestSearch.domain << endl << endl;

    int minUsers;
    cout << "Введите минимальное число пользователей в день: ";
    cin >> minUsers;

    printSitesWithMinUsers(sites, minUsers);

    printSites(sites);

    return 0;
}
