// cd1.cpp: ���������� ����� ����� ��� ����������� ����������.
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

// ������������� ������� ����� ����� �� ������ (��� long)

long n;

cout << "������� ����� ���� long: ";

cin >> n;

cout << "��� ��� �������� �������������:" << endl;

BinOut((unsigned char*)& n, sizeof(n));

cout << "������� �������� ������������� ����� ���� long :" << endl;

BinIn((unsigned char*)& n, sizeof(n));

cout << "��� ��� ��������: " << n << endl;
// ������������� ������������ �����

//������� �������� (��� double)

double x;

cout << "������� ����� ���� double: ";

cin >> x;

cout << "��� ��� �������� �������������:" << endl;

BinOut((unsigned char*)& x, sizeof(x));

cout << "������� �������� ������������� ����� ���� double:" << endl;

BinIn((unsigned char*)& x, sizeof(x));

cout << "��� ��� ��������: " << x << endl;

_getch();
//������������� ������� char[2][10]
cout << "������� ������ ����� " << endl;
char mass[2][10];
for (int i=0;i<2;i++) {
	for(int j=0;j<10;j++) {
cout <<  ("[") << (i+1) << ("]") << ("[") << (j+1) << ("]") << endl; 
		cin >> mass[i][j];
	}
}
BinOut((unsigned char*)& mass, sizeof(mass));

cout << "������� �������� ������������� ������� ���� char[2][10] \n";
BinIn((unsigned char*)& mass, sizeof(mass));
cout << "��� ��� ��������: " << mass << endl;


system("pause");
return 0;

}
