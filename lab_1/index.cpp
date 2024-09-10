#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SITES 4
#define MAX_NAME_LENGTH 50
#define MAX_TYPE_LENGTH 50
#define MAX_DOMAIN_LENGTH 50
#define MAX_TECHNOLOGIES 50

struct Site {
    char name[MAX_NAME_LENGTH];
    char type[MAX_TYPE_LENGTH];
    char domain[MAX_DOMAIN_LENGTH];
    int users;
    int linked;
    double time;
    char technologies[MAX_TECHNOLOGIES][MAX_TYPE_LENGTH];
};

int main() {
    struct Site sites[MAX_SITES] = {
        {
            "Google", "Поисковый", "google.com", 1000000000, 100000, 0.1, 
            {"HTML", "CSS", "JavaScript"}
        },
        {
            "Bing", "Поисковый", "bing.com", 500000000, 50000, 0.2,
            {"HTML", "CSS", "JavaScript"}
        },
        {
            "Wikipedia", "Информационный", "wikipedia.org", 200000000, 1000000, 0.3,
            {"HTML", "CSS", "JavaScript"}
        },
        {
            "Amazon", "Торговый", "amazon.com", 300000000, 500000, 0.4,
            {"HTML", "CSS", "JavaScript"}
        },
    };

    struct Site fastestSearch = sites[0];
    for (int i = 0; i < MAX_SITES; i++) {
        if (strcmp(sites[i].type, "Поисковый") == 0 && sites[i].time < fastestSearch.time) {
            fastestSearch = sites[i];
        }
    }
    printf("Доменное имя самого быстрого поискового сервиса: %s\n", fastestSearch.domain);

    int minUsers;
    printf("Введите минимальное число пользователей в день: ");
    scanf("%d", &minUsers);

    printf("Информация о ресурсах с числом пользователей больше %d:\n", minUsers);
    for (int i = 0; i < MAX_SITES; i++) {
        if (sites[i].users > minUsers) {
            printf("Название: %s\n", sites[i].name);
            printf("Тип: %s\n", sites[i].type);
            printf("Домен: %s\n", sites[i].domain);
            printf("Пользователи: %d\n", sites[i].users);
            printf("Ссылки: %d\n", sites[i].linked);
            printf("Время загрузки: %.1f сек.\n", sites[i].time);
            printf("Технологии: ");
            for (int j = 0; j < MAX_TECHNOLOGIES; j++) {
                if (strlen(sites[i].technologies[j]) > 0) {
                    printf("%s ", sites[i].technologies[j]);
                } else {
                    break;
                }
            }
            printf("\n\n");
        }
    }

    return 0;
}
