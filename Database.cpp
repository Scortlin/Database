#include "functions.h"
int choice;

void menu() {
    cout << "Выберите действие: " << endl
        << "0 - выход из программы" << endl
        << "1 - ввод данных" << endl
        << "2 - вывод данных" << endl
        << "3 - изменение данных" << endl
        << "4 - добавление данных" << endl
        << "5 - удаление данных" << endl
        << "6 - сортировка данных" << endl
        << "7 - сохранение данных" << endl
        << "Ваш выбор: ";
    cin >> choice;
}
int main()
{
    setlocale(LC_ALL, "rus");
    menu();
    int actions;
    string filename;

    int size = 0;//количество данных
    Data* d = new Data[size];//массив данных

    while (choice != 0) {
        switch (choice) {
        case 1:
            system("cls");
            cout << "Ввести данные вручную или считать из файла";
            cin >> actions;
            system("cls");
            if (actions == 1) {
                DataEntry(d, size);
            }
            else {
                cout << "Введите название файла:  ";
                cin >> filename;
                DataReading(d, size, filename);
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 2:
            system("cls");
            if (size != 0) {
                Print(d, size);
            }
            else {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 3:
            system("cls");
            if (size != 0) {
                DataChange(d, size);
            }
            else {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 4:
            system("cls");
            if (size != 0) {
                AddData(d, size);
            }
            else {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 5:
            system("cls");
            if (size != 0) {
                DeleteData(d, size);
            }
            else {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 6:
            system("cls");
            if (size != 0) {
                SortingData(d, size);
            }
            else {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            menu();
            break;
        case 7:
            system("cls");
            if (size != 0) {
                SaveData(d, size,"out.txt");
            }
            else {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            menu();
            break;
        default:
            cout << "Пункт меню введен неврно!" << endl;
            system("cls");
            menu();
            break;
        }
    }
    system("cls");
    cout << "Работа завершена" << endl;
    system("pause");
    return 0;
}