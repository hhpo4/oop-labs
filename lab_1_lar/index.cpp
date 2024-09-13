#include <cstdio> 
#include <cstdlib> 
#include <cstring> 

#define N 2  

struct rating { 
    char FIO[100]; 
    int number; 
    char speciality[100]; 
    int group; 
    char course[100]; 
    int semester; 
    int mark; 
}; 

int main() { 
    rating student[N] = { 
        {"Ларионов Владимир Алексеевич", 141451, "Програмная инженерия", 236, "Обьектно ориентированное програмирование", 2, 88}, 
        {"Колымажнов Никита Витальевич", 256377, "Програмная инженерия", 236, "Обьектно ориентированное програмирование", 2, 95} 
    }; 
    int found=0; 
    int semes; 
    printf("введите номер семестра:"); 
    scanf("%d", &semes); 

    printf("студенты получившие <60:"); 
    for(int i=0;i<N;i++){ 
    if(student[i].mark<60 && student[i].semester==semes){ 
        printf("\n%s",student[i].FIO); 
        found=1; 
        } 
    } 

    if(!found){ 
        printf("таких нет"); 
    } 

    printf("\n\nстудент с самой большой итоговой оценкой:"); 
    int max_ocenka = 0; 

    for(int i = 1; i < N; i++) { 
        if(student[i].mark > student[max_ocenka].mark) { 
            max_ocenka = i;  
        } 
    } 

    printf("\n%s", student[max_ocenka].FIO); 

    for(int i=0;i<N;i++){ 
    printf("\n\nфио: %s\n", student[i].FIO); 
    printf("Номер студака: %d\n", student[i].number); 
    printf("название специальности: %s\n", student[i].speciality); 
    printf("номер группы: %d\n", student[i].group); 
    printf("название дисцплины: %s\n", student[i].course); 
    printf("семестр: %d\n", student[i].semester);    
    printf("баллы: %d\n", student[i].mark); 
} 
    return 0; 
}