// lab10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class calculate {
double r;  //радиус
double l;  //угол
public:

calculate(double, double);//конструктор
double S_sector();
double S_krug();
void output_sector();
void output_krug();
};

calculate::calculate(double x, double y){
r=x;
l=y;
};
double calculate::S_sector() {
return (l * 3.14*pow(r,2))/360 ;
};
double calculate::S_krug() {
return 3.14*pow(r,2);
};
void output_kr(calculate ob1, string kr) {
	cout <<"S " << kr << " = " << ob1.S_krug() << " cm^2 " << endl; 
};
void output_sector(calculate ob2, string sec) {
	cout <<"S " << sec << " = " << ob2.S_sector() << " cm^2 " << endl; 
};
int main(){
	setlocale(LC_ALL, "Russian");
double r;
double l=0;
string sec = "sector";
string kr = "krug";
string a;

cout<<"Введите название фигуры"<<endl;
cin >> a;

while (a != kr && a != sec) {
cout<<"Название неверно, пожалуйста введите заново"<<endl;
cin >> a; }
if(a == kr) {
cout<<"Введите радиус"<<endl;
cin >> r;

calculate ob1(r,l);  //конструктор с параметром
ob1.S_krug();
output_kr(ob1, kr);
}
else if (a == sec) {
 
cout<<"Введите радиус" << endl;
cin >> r;
cout<<"Введите значение угла" << endl;
cin >> l;
calculate ob2(r,l);
ob2.S_sector();
output_sector(ob2, sec);

}

system("pause");
return 0;
}

