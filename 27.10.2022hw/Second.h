#pragma once
#include <iostream>
using namespace std;

class Second {
public:
    struct Creature {
        int speed;
        char* type = new char[9];
        char* color = new char[15];
        struct {
            float speed_fly;
            bool hooves;
            int IQ;
        } Type;
    };
    Creature* UpdateArr(Creature* arr, int& size) {
        size++;
        Creature* newArr = new Creature[size];
        for (int i = 0; i < size - 1; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        return newArr;
    }
    void FillCreature(Creature* arr, int size) {
        cout << "Enter the speed of creature " << size << " :" << endl;
        cin >> arr[size - 1].speed;
        cin.ignore(256, '\n'); //очиска потока ввода
        cout << "Enter the type of creature " << size << " (bird,human,beasts):" << endl;
        gets_s(arr[size - 1].type, 10);
        cout << "Enter the color of creature " << size << " :" << endl;
        gets_s(arr[size - 1].color, 16);
        //Если сущность птичка
        if (strcmp(arr[size - 1].type, "bird") == 0) {
            cout << "Enter the fly speed of creature " << size << " :" << endl;
            cin >> arr[size - 1].Type.speed_fly;
            arr[size - 1].Type.hooves = false;
            arr[size - 1].Type.IQ = 0;
        }
        //Если сущность скот
        else if (strcmp(arr[size - 1].type, "beasts") == 0) {
            cout << "Enter the type hooves of creature " << size << " (true/false):" << endl;
            cin >> arr[size - 1].Type.hooves;
            arr[size - 1].Type.speed_fly = 0;
            arr[size - 1].Type.IQ = 0;
        }
        //Если сущность человек
        else if (strcmp(arr[size - 1].type, "human") == 0) {
            cout << "Enter the level IQ of creature " << size << " :" << endl;
            cin >> arr[size - 1].Type.IQ;
            arr[size - 1].Type.hooves = false;
            arr[size - 1].Type.speed_fly = 0;
        }
        //Если пользователь ошибся
        else{
            system("cls");
            cout << "\tWRONG!!\n";
            system("cls");
            FillCreature(arr, size);
        }
        cin.ignore(256, '\n'); //Очищаем поток ввода, чтобы не было препоной при выполнении следующих функций
    }
    void PrintCreature(Creature* arr, int size) {
        for (int i = 0; i < size; i++) {
            cout << "||Creature number|| " << i + 1 << " :" << endl;
            cout << "Creature'speed - " << arr[i].speed << endl;
            cout << "Creature's type - " << arr[i].type << endl;
            cout << "Creature's color - " << arr[i].color << endl;
            //Птичка
            if (strcmp(arr[i].type, "bird") == 0) {
                cout << "Fly speed of creature - " << arr[i].Type.speed_fly << endl << endl;
            }
            //Скот
            else if (strcmp(arr[i].type, "beasts") == 0) {
                cout << "Type hooves of creature - " << arr[i].Type.hooves << endl << endl;
            }
            //Человек
            else if (strcmp(arr[i].type, "human") == 0) {
                cout << "Level IQ of creature " << arr[i].Type.IQ << endl << endl;
            }
        }
    }
    void SearchCreatureOnCharacteristic(Creature* arr, int size) {
        char* buff = new char[20]; //Буфер для ввода типа
        float usNb; //Переменная пользователя для птичка
        bool usNbe; //Для скота
        int usNh; //Для человека
        cout << "Enter the searching creature's type\n"; //Не придумал иную реализацию фукнции поиска
        gets_s(buff, 20);
        //Человек
        if (strcmp(buff, "human") == 0) {
            cout << "Enter the searching creature's Characteristic\n";
            cin >> usNh;
            cout << endl;
            for (int i = 0; i < size; i++) {
                if (usNh == arr[i].Type.IQ) {
                    cout << "||Creature number|| " << i + 1 << " :" << endl;
                    cout << "Creature'speed - " << arr[i].speed << endl;
                    cout << "Creature's type - " << arr[i].type << endl;
                    cout << "Creature's color - " << arr[i].color << endl;
                    cout << "IQ - ";
                    cout << arr[size - 1].Type.IQ << endl << endl;
                }
            }
        } //Если создание человек
        //Птичка
        else if (strcmp(buff, "bird") == 0) {
            cout << "Enter the searching creature's Characteristic\n";
            cin >> usNb;
            cout << endl;
            for (int i = 0; i < size; i++) {
                if (usNb == arr[i].Type.speed_fly) {
                    cout << "||Creature number|| " << i + 1 << " :" << endl;
                    cout << "Creature'speed - " << arr[i].speed << endl;
                    cout << "Creature's type - " << arr[i].type << endl;
                    cout << "Creature's color - " << arr[i].color << endl;
                    cout << "Fly speed of creature - ";
                    cout << arr[size - 1].Type.speed_fly << endl << endl;
                }
            }
        } //Если создание птичка
        //Скот
        else if (strcmp(buff, "beasts") == 0) {
            cout << endl;
            cout << "Enter the searching creature's Characteristic(true/false)\n";
            cin >> usNbe;
            for (int i = 0; i < size; i++) {
                if (usNbe == arr[i].Type.hooves) {
                    cout << "||Creature number|| " << i + 1 << " :" << endl;
                    cout << "Creature'speed - " << arr[i].speed << endl;
                    cout << "Creature's type - " << arr[i].type << endl;
                    cout << "Creature's color - " << arr[i].color << endl;
                    cout << "Type hooves - ";

                    cout << arr[size - 1].Type.hooves << endl << endl;

                }
            }
        } //Если создание скот
    }
    void RedactCreature(Creature* arr, int size) {
        int creatureNumb;
        cout << "||All creatures' numbers||\n";
        for (int i = 0; i < size; i++) {
            cout << "--| " << i + 1 << endl;
        }
        cout << "Enter the number of the creature being edited:\n";
        cin >> creatureNumb;
        system("cls");
        FillCreature(arr, creatureNumb); 

    }
};