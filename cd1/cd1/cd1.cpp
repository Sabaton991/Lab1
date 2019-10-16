// cd1.cpp: определ€ет точку входа дл€ консольного приложени€.
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

// ѕредставление длинный целых чисел со знаком (тип long)

long n;

cout << "¬ведите число типа long: ";

cin >> n;

cout << "Ёто его двоичное представление:" << endl;

BinOut((unsigned char*)& n, sizeof(n));

cout << "¬ведите двоичное представление числа типа long :" << endl;

BinIn((unsigned char*)& n, sizeof(n));

cout << "Ёто его значение: " << n << endl;
// ѕредставление вещественных чисел

//двойной точности (тип double)

double x;

cout << "¬ведите число типа double: ";

cin >> x;

cout << "Ёто его двоичное представление:" << endl;

BinOut((unsigned char*)& x, sizeof(x));

cout << "¬ведите двоичное представление числа типа double:" << endl;

BinIn((unsigned char*)& x, sizeof(x));

cout << "Ёто его значение: " << x << endl;

_getch();
//ѕредставление массива char[2][10]
cout << "¬ведите массив строк " << endl;
char mass[2][10];
for (int i=0;i<2;i++) {
	for(int j=0;j<10;j++) {
cout <<  ("[") << (i+1) << ("]") << ("[") << (j+1) << ("]") << endl; 
		cin >> mass[i][j];
	}
}
BinOut((unsigned char*)& mass, sizeof(mass));

cout << "¬ведите двоичное представление массива типа char[2][10] \n";
BinIn((unsigned char*)& mass, sizeof(mass));
cout << "Ёто его значение: " << mass << endl;


system("pause");
return 0;

}
