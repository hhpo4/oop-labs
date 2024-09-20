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
Site getSiteFromUser(void);
void addSiteToFile(string filename, Site site);
void deleteSiteFromFile(string filename, string siteName);



int main() {
    Site* sites = new Site[MAX_SITES];

    int mode;
    cout << "Выбирите одно из действий: \nВывести все сайты в консоль - 1\nНайти самый быстрый поисковой сайт - 2\nВывести информацию о сайтах, в которых среднее число пользователей в день превышает заданную величину - 3\nДобавить сайт в файл - 4\nУдалить файл из сайта по имени - 5" << endl;
    cin >> mode;

    Site fastestSearch;
    Site newSite;

    switch (mode) {
        case 1: 
            readSitesFromFile("websites.txt", sites);
            printSites(sites);
            break;
        case 2: 
            readSitesFromFile("websites.txt", sites);

            fastestSearch = findFastestSearch(sites);
            cout << "Доменное имя самого быстрого поискового сервиса: " << fastestSearch.domain << endl << endl;
            break;
        case 3: 
            readSitesFromFile("websites.txt", sites);

            int minUsers;
            cout << "Введите минимальное число пользователей в день: ";
            cin >> minUsers;

            printSitesWithMinUsers(sites, minUsers);
            break;
        case 4: 
            newSite = getSiteFromUser();
            addSiteToFile("websites.txt", newSite);
            break;
        default:
            cout << "Введенно недопустимое значение" << endl;
            break;
    }

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

Site getSiteFromUser(void) {
    Site site;

    cout << "Введите имя сайта: " << endl;
    cin.ignore();

    cout << "Введите тип сайта: ";
    getline(cin, site.type);
    cin.ignore();

    cout << "Введите доменное имя сайта: ";
    getline(cin, site.domain);
    cin.ignore();


    cout << "Введите количество пользователей: ";
    cin.ignore();
    cin >> site.users;


    cout << "Введите количество ссылок: ";
    cin.ignore();
    cin >> site.linked;

    cout << "Введите время загрузки (в секундах): \n";
    cin.ignore();
    cin >> site.time;

    cout << "Введите технологии (введите 'end' для завершения):" << endl;
    for (int i = 0; i < MAX_TECHNOLOGIES; ++i) {
        string tech;
        getline(cin, tech);
        if (tech == "end") {
            break;
        }
        site.technologies[i] = tech;
    }

    return site;
}


void addSiteToFile(string filename, Site site) {
    ofstream file(filename, ios_base::app); 

    if (file.is_open()) {
        file << site.name << "," << site.type << "," << site.domain << ","
            << site.users << "," << site.linked << "," << site.time;
        for (int i = 0; i < MAX_TECHNOLOGIES && !site.technologies[i].empty(); ++i) {
            file << "," << site.technologies[i];
        }
        file << endl;
        file.close();
        cout << "Сайт добавлен: " << site.name << endl;
    } else {
        cout << "Не удалось открыть файл для записи." << endl;
    }
}
