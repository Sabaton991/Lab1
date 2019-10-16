// cd1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>

#include <conio.h>

using namespace std;

void BinOut(unsigned char* Buf, int len) {

int i, j;

unsigned char byte;

for (i = len - 1; i >= 0; i--)

for (j = 1, byte = Buf[i]; j <= 8; byte <<= 1, j++)

_putch(byte & 0x80 ? '1' : '0');

printf("\n");

}

void BinIn(unsigned char* Buf, int len) {

int i, j;

char ch;

for (i = len - 1; i >= 0; i--)

for (j = 1, Buf[i] = 0; j <= 8; Buf[i] = (Buf[i] << 1) + (ch - '0'), j++) {

while ((ch = _getch()) != '0' && ch != '1');

_putch(ch);

}

printf("\n");

}

int main() {

setlocale(LC_ALL, "Russian");

// Представление длинный целых чисел со знаком (тип long)

long n;

cout << "Введите число типа long: ";

cin >> n;

cout << "Это его двоичное представление:" << endl;

BinOut((unsigned char*)& n, sizeof(n));

cout << "Введите двоичное представление числа типа long :" << endl;

BinIn((unsigned char*)& n, sizeof(n));

cout << "Это его значение: " << n << endl;
// Представление вещественных чисел

//двойной точности (тип double)

double x;

cout << "Введите число типа double: ";

cin >> x;

cout << "Это его двоичное представление:" << endl;

BinOut((unsigned char*)& x, sizeof(x));

cout << "Введите двоичное представление числа типа double:" << endl;

BinIn((unsigned char*)& x, sizeof(x));

cout << "Это его значение: " << x << endl;

_getch();



system("pause");
return 0;

}
