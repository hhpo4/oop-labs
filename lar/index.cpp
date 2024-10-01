#include <cstdio> 
#include <cstdlib> 
#include <string> 
#include <iostream>
#include <fstream>
#include <locale> 

using namespace std; 

struct rating { 
    string FIO; 
    int number; 
    string speciality; 
    int group; 
    string course; 
    int semester; 
    int mark; 
}; 

rating read_rating(ifstream &file) {
    rating rate;
    getline(file, rate.FIO); 
    file >> rate.number;
    file.ignore();
    getline(file, rate.speciality); 
    file >> rate.group;
    file.ignore();
    getline(file, rate.course);
    file >> rate.semester;
    file >> rate.mark;
    file.ignore();
    return rate;
}

void print_rating(rating rate)
{
cout << " фио:" << rate.FIO << endl;
cout << " Номер студака: " << rate.number << endl;
cout << " название специальности: " << rate.speciality << endl;
cout << " номер группы: " << rate.group << endl;
cout << " название дисцплины: " << rate.course << endl;
cout << " номер семестра: " << rate.semester << endl;
cout << " баллы: " << rate.mark << endl;
}

int main() { 
    
    int N;
    ifstream infile;
    infile.open("data.txt");
    if (!infile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1; 
    }
    infile >> N;
    infile.get(); 

    rating* student = new rating[N];

    for (int i = 0; i < N; i++) {
        student[i] = read_rating(infile); 
    }

    infile.close(); 

    for (int i = 0; i < N; i++)
        print_rating(student[i]);

    int found=0; 
    int semes; 

    cout << "введите номер семестра:"; 
    cin >> semes; 

    cout << "студенты получившие <60:"; 
    for(int i=0;i<N;i++){ 
        if(student[i].mark<60 && student[i].semester==semes){ 
            cout << student[i].FIO << endl; 
            found=1; 
        } 
    } 

    if(!found){ 
        cout << "таких нет" << endl;
    } 

    cout << "\n" << "студент с самой большой итоговой оценкой:"; 
    int max_ocenka = 0; 

    for(int i = 1; i < N; i++) { 
        if(student[i].mark > student[max_ocenka].mark) { 
            max_ocenka = i;  
        } 
    } 

    cout << student[max_ocenka].FIO << endl; 

    delete[] student;
    return 0; 
}