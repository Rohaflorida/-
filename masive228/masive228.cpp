
#include <iostream>

#include <cmath>

#include <Windows.h> // підключення заголовного файлу Windows.h

using namespace std;

int main() {

    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення

    const int n = 10; // розмір масиву
    double arr[n] = { 5.5, 10, 2.7, -4, 8.9, 12.3, 7.1, 1.8, 6.4, -3.2 }; // масив з даними
    int count = 0; // лічильник елементів менших за 10
    double sum = 0; // змінна для обчислення суми цілих частин
    int last_negative_index = -1; // індекс останнього від'ємного елемента
    double max_value = arr[0]; // максимальний елемент масиву
    int max_index = 0; // індекс максимального елемента масиву

    // обчислення кількості елементів менших за 10
    for (int i = 0; i < n; i++) {
        if (arr[i] < 10) {
            count++;
        }
    }

    // обчислення суми цілих частин елементів після останнього від'ємного елемента
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] < 0) {
            last_negative_index = i;
            break;
        }
    }
    if (last_negative_index == -1) {
        cout << "В масиві немає від'ємних елементів\n";
    }
    else {
        for (int i = last_negative_index + 1; i < n; i++) {
            sum += floor(arr[i]);
        }
        cout << "Сума цілих частин елементів після останнього від'ємного елемента: " << sum << endl;
    }

    // пошук максимального елемента
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
            max_index = i;
        }
    }

    // сортування масиву
    for (int i = 0; i < n; i++) {
        if (i != max_index && fabs(arr[i] - max_value) <= max_value * 0.2) {
            cout << arr[i] << " ";
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != max_index && fabs(arr[i] - max_value) > max_value * 0.2) {
            cout << arr[i] << " ";
        }
    }
    cout << max_value << endl;

    return 0;
}
