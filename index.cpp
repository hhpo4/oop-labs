#include <iostream>
#include <vector>

using namespace std; 


struct Site {
    char name[50];      
    char type[50];        
    char domain[50];    
    int users;            
    int linked;             
    double time;             
    vector<> technologies; 
};

int main() {
    std::vector<Site> sites = {
        {"Google", "Поисковый", "google.com", 2000000000, 1000, 0.5, {"HTML", "JavaScript", "CSS"}},
        {"Wikipedia", "Информационный", "wikipedia.org", 500000000, 2500, 0.7, {"HTML", "PHP"}},
        {"Bing", "Поисковый", "bing.com", 100000000, 800, 0.6, {"HTML", "JavaScript"}},
        {"Yandex", "Поисковый", "yandex.ru", 150000000, 600, 0.4, {"HTML", "Python"}}
    };

    // 1) Найдем доменное имя самого быстрого поискового интернет-сервиса
    std::string fastestSearchDomain;
    double fastestSearchTime = std::numeric_limits<double>::max(); // Начальное значение

    for (const auto& site : sites) {
        if (site.type == "Поисковый" && site.time < fastestSearchTime) {
            fastestSearchTime = site.time;
            fastestSearchDomain = site.domain;
        }
    }

    if (!fastestSearchDomain.empty()) {
        std::cout << "Доменное имя самого быстрого поискового интернет-сервиса: " << fastestSearchDomain << std::endl;
    }

    // 2) Вывод информации о интернет-ресурсах с количеством пользователей больше заданного
    int minUsers;
    std::cout << "Введите минимальное количество пользователей в день: ";
    std::cin >> minUsers;

    std::cout << "Интернет-ресурсы с более чем " << minUsers << " пользователями в день:" << std::endl;

    for (const auto& site : sites) {
        if (site.users > minUsers) {
            std::cout << "Название: " << site.name << ", Тип: " << site.type 
                      << ", Домен: " << site.domain << ", Пользователи: " << site.users 
                      << ", Ссылки: " << site.linked << ", Время загрузки: " 
                      << site.time << " сек, Технологии: ";

            for (const auto& tech : site.technologies) {
                std::cout << tech << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
