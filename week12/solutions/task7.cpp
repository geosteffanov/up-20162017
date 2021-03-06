#include <iostream>
using namespace std;
/* на тази функция трудната част не е свързана с указателите,
   така че не се притеснявайте ако изглежда тромава и неразбираема */

void incrementDuplicates(int** arr, int size) {
        bool toCheck[20];  /* за да избегнем случая в който
                              увеличаваме два пъти една и съща променлива 
                              (ако два или повече от указателите в масива сочат към нея)
                              си създаваме един масив от true, false,
                              който казва - ако toCheck[i] == true, значи трябва 
                              да правим проверка за този елемент, ако е false,
                              значи сме го срещнали по-рано и не трябва да правим проверка */
        for (int i = 0; i < size; i++) {
            *(toCheck + i) = true; // в началото знаем , че за всички трябва да направим проверка (защото не знаем за кои не трябва)
        }

        for (int i = 0; i < size; i++) {
            if (*(toCheck + i) == true) {
                bool duplicate = false;
                for (int j = i + 1; j < size; j++) {
                    if (*(arr + i) == *(arr + j)) {  /* указателите имат оператор за сравнение
                                                        той връща true ако двата указателя сочат
                                                        един и същ адрес, т.е. стойностите им са равни.
                                                        В противен случай връща false.
                                                        Два указателя могат да се вадят естествено, при което
                                                        се образува и разликата на адресите, към които те сочат.
                                                        Ако тя е 0, то адресите-стойности на указателите са
                                                        еднакви */
                           duplicate = true;
                         *(toCheck + j) = false; /* arr[i] == arr[j] => сега като увеличим стойността сочена от
                                                    arr[i], не трябва да увеличаваме стойността сочена от arr[j]
                                                    (иначе ще я увеличим 2 пъти) => казваме, че 
                                                    arr[j] не трябва да се проверява.
                                                  */
                    }
                }
                if (duplicate == true)
                    **(arr + i)+= 1; /* е, ако се окаже че има дупликиране на адреси => значи нека стойността на променливата
                                        сочена от arr[i] се увеличи с 1. Това е равносилно на *arr[i] += 1, което пък е равно-
                                        силно на **(arr + i) += 1;
            }                         */
        }
}
int main() {

    int arr[] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* arrOfPointers[10];
    for (int i = 0; i < 10; i++) {
        arrOfPointers[i] = &arr[i];
    }

    arrOfPointers[0] = arrOfPointers[2] = arrOfPointers[4];
    arrOfPointers[3] = arrOfPointers[6];
    arrOfPointers[8] = arrOfPointers[9];


    incrementDuplicates(arrOfPointers, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
