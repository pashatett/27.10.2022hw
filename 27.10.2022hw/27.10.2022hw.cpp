#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

//1
#include "First.h"
int main(){
    First f;
    int size = 0;
    Car* arr = new Car[size];//не понял как расширить область видимости

    while (true) {
        system("cls");
        int us; //Выбор пользователя
        cout << "Select the option:\n";
        cout << "1 - Add new car\n";
        cout << "2 - Print all cars\n";
        cout << "3 - Redact car\n";
        cout << "4 - Search car on number\n";
        us = _getch();

        switch (us) {
        case 49:
            //Если пользователь ввёл уже 10 машин
            if (size == 10) {
                cout << "\tYou can't add more than 10 cars\n";
                Sleep(2000);
                break;
            }
            system("cls");
            arr = f.UpdateArr(arr, size);
            f.FillCar(arr, size);
            break;
        case 50:
            system("cls");
            f.PrintCars(arr, size);
            cout << "\n\tPress any key to return\n";
            us = _getch();
            break;
        case 51:
            system("cls");
            f.RedactCar(arr, size);
            break;
        case 52:
            system("cls");
            f.SearchCarOnNumber(arr, size);
            cout << "\n\tPress any key to return\n";
            us = _getch();
            break;
        default:
            system("cls");
            cout << "\n\n\t\tERROR\n";
            Sleep(1500);
        }
    }
}


//2
#include "Second.h"
int main() {
    Second f;
    int size = 0;
    Creature* arr = new Creature[size];
    int us; //Выбор пользователя
    while (true) {
        system("cls");
        cout << "Select the option:\n";
        cout << "1. - Add new creature\n";
        cout << "2. - Print all creatures\n";
        cout << "3. - Redact creature\n";
        cout << "4. - Search creature on Characteristic\n";
        us = _getch();

        switch (us) {
        case 49:
            if (size == 10) {
                cout << "\tYou can't add more than 10 creatures\n";
                Sleep(2000);
                break;
            }
            system("cls");
            arr = f.UpdateArr(arr, size);
            f.FillCreature(arr, size);
            break;
        case 50:
            system("cls");
            f.PrintCreature(arr, size);
            cout << "\n\tPress any key to return\n";
            us = _getch();
            break;
        case 51:
            system("cls");
            f.RedactCreature(arr, size);
            break;
        case 52:
            system("cls");
            f.SearchCreatureOnCharacteristic(arr, size);
            cout << "\n\tPress any key to return\n";
            us = _getch();
            break;
        default:
            system("cls");
            cout << "\n\n\t\tERROR\n";
            Sleep(1500);
        }
    }
}