#pragma once
#include <iostream>
using namespace std;

class First {
public:
    struct Car {
        char* color = new char[25];
        char* model = new char[25];
        char* number = new char[9];
    }aa;
    Car* UpdateArr(Car* arr, int& size) {
        size++;
        Car* newArr = new Car[size];
        for (int i = 0; i < size - 1; i++) {
            newArr[i] = arr[i];

        }
        delete[] arr;
        return newArr;
    }
    void FillCar(Car* arr, int size) {

        cout << "Enter the color of car " << size << " :" << endl;
        gets_s(arr[size - 1].color, 25);
        cout << "Enter the model of car " << size << " :" << endl;
        gets_s(arr[size - 1].model, 25);
        cout << "Enter the nubmer of car " << size << " :" << endl;
        gets_s(arr[size - 1].number, 9);
    }
    void PrintCars(Car* arr, int size) {
        for (int i = 0; i < size; i++) {
            cout << "||Car number|| " << i + 1 << " :" << endl;
            cout << "Car's color - " << arr[i].color << endl;
            cout << "Car's model - " << arr[i].model << endl;
            cout << "Car's number - " << arr[i].number << endl << endl;
        }
    }
    void SearchCarOnNumber(Car* arr, int size) {
        char* buff = new char[9]; //Буфер для пользователя
        cout << "Enter the searching car's number\n";
        gets_s(buff, 9);
        for (int i = 0; i < size; i++) {
            if (strcmp(buff, arr[i].number) == 0) {
                cout << "||Car number|| " << i + 1 << " :" << endl;
                cout << "Car's color - " << arr[i].color << endl;
                cout << "Car's model - " << arr[i].model << endl;
                cout << "Car's number - ";
                cout << arr[i].number << endl << endl;
            }
        }
        delete[] buff; //Ликвидируем праздную память
    }
    void RedactCar(Car* arr, int size) {
        int carNumb;
        cout << "||All cars' numbers||\n";
        for (int i = 0; i < size; i++) {
            cout << "--| " << i + 1 << endl;
        }
        cout << "Enter the number of the machine being edited:\n";
        cin >> carNumb;
        cin.ignore(256, '\n'); // очищаем поток ввода
        system("cls");
        FillCar(arr, carNumb);
    }
};