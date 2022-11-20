#include <iostream>
#include <math.h>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;


//------------------------------------------------------------1------------------------------------------------------//


class Time {
	short hours;                  //hours
	short minute;				 //minute
	short second;				 //second

public:
	Time() : hours(20), minute(55), second(20) {
		if (hours < 0 || hours>23)
		{
			cout << "Error!!!!!\n";
			exit(0);
		}
		if (minute < 0 || minute>59)
		{
			cout << "Error!!!!!\n";
			exit(0);
		}
		if (second < 0 || second>59)
		{
			cout << "Error!!!!!\n";
			exit(0);
		}
	}
	Time(short a, short b, short c) : hours(a), minute(b), second(c) {
		if (hours < 0 || hours>23)
		{
			cout << "Error!!!!!\n";
			return;
		}
		if (minute < 0 || minute>59)
		{
			cout << "Error!!!!!\n";
			return;
		}
		if (second < 0 || second>59)
		{
			cout << "Error!!!!!\n";
			return;
		}

	}

	short getHours()  { return hours;  }
	short getMinute() { return minute; }
	short getSecond() { return second; }

	void setHours(short hours)
	{
		if (hours < 0 || hours>23)
		{
			cout << "Error!!!!!\n";
			return;
		}
		this->hours = hours;
	}

	void setMinute(short minute)
	{
		if (minute < 0 || minute>59)
		{
			cout << "Error!!!!!\n";
			return;
		}
		this->minute = minute;
	}
	
	void setSecond(short second)
	{
		if (second < 0 || second>59)
		{
			cout << "Error!!!!!\n";;
			return;
		}
		this->second = second;
	}
	

	void printInf24() {

		
		cout << hours << " hour " << minute << " minute " <<second<<" second"<<endl;
	}
	void printInf12()
	{
		
	    char type;
		if (hours < 12) {
			type = 'A';
		}
		else {
			hours = hours - 12;
			if (hours == 0)
			{
				hours = 12;
			}
			type = 'P';
		}
	
		if (type == 'A')
		{
			cout << hours << " A.M " << minute << " minute " << second << " second"<<endl;
		}
		else {
			cout << hours << " P.M " << minute << " minute " << second << " second"<<endl;
		}

		
	}

};



void task1()
{
	Time obj;
	obj.printInf24();
	obj.printInf12();
	cout << "--------------------------------------------------------------------------\n";
	short a, b, c;
	cout << "Input hours,minute,second:";
	cin  >> a >> b >> c;
	Time obj1(a, b, c);
	cout << "Output : \n";
	obj1.printInf24();
	obj1.printInf12();
	cout << "--------------------------------------------------------------------------\n";
	obj.setHours(23);
	obj.setMinute(59);
	obj.setSecond(59);
	obj.printInf24();
	obj.printInf12();
	cout << "--------------------------------------------------------------------------\n";
	obj.setHours(24);
	obj.setMinute(59);
	obj.setSecond(10);
	obj.printInf24();
	obj.printInf12();
	cout << "--------------------------------------------------------------------------\n";
	obj.setHours(23);
	obj.setMinute(-10);
	obj.setSecond(2);
	obj.printInf24();
	obj.printInf12();
	cout << "--------------------------------------------------------------------------\n";
	obj.setHours(23);
	obj.setMinute(22);
	obj.setSecond(-30);
	obj.printInf24();
	obj.printInf12();
	cout << "--------------------------------------------------------------------------\n";
	obj.getHours();
	obj.getMinute();
	obj.getSecond();
}
//-------------------------------------------------------------------------------------------------------------------//


//------------------------------------------------------------2------------------------------------------------------//

enum STATE {
	OK, BAD_INIT, BAD_DIV
};

class Vector {
private:
	double arr[3];
	int state;
	const int param;
	static int count;
public:

	Vector() : param(0) {
		state = OK;  for (short i = 0; i < 3; i++) arr[i] = 0; count++;
	}
	Vector(double p) :param(0), state(OK) {
		for (short i = 0; i < 3; i++) arr[i] = p; count++; 
	}
	//copy
	Vector(const Vector& s) : state(OK), param(0) {
		for (int i = 0; i < 3; i++) arr[i] = s.arr[i];
		count++;
	}
	Vector& operator=(const Vector& s) {
		if (this == &s) return *this;
		for (int i = 0; i < 3; i++) {
			arr[i] = s.arr[i];
		}
		return *this;
	}


	Vector(double* value);
	// destructor : 
	~Vector() {
		count--;
		cout << "state Vector " << state <<endl;
		cout << "Vector delete" << endl;
	}
	Vector Add(Vector& d);
	Vector Minus(Vector& d);
	Vector Multiply(double d);
	Vector DivideShort(short d);
	void Input();
	void Output();
	void addElement(const int p);
	void getElement();
	bool CompLessAll(Vector& s);
	bool CompMoreAll(Vector& s);
	bool CompExactlyAll(Vector& s);
	static int getCount() {
		if (count <= 0) cout << " No objects Vector ";
		return count;
	}
	int getState() {
		return state;
	}
};

int Vector::count = 0;

Vector::Vector(double* value) :param(0) {
	if (value == nullptr) {
		state = BAD_INIT;
		arr[0] = 0;
		arr[1] = 0;
		arr[2] = 0;
	}
	else {
		arr[0] = value[0];
		arr[1] = value[1];
		arr[2] = value[2];
		state = OK;
	}
	count++;
}

Vector Vector::Add(Vector& s){
	Vector tmp;
	for (int i = 0; i < 3; i++) {
		tmp.arr[i] = arr[i] + s.arr[i];
	}
	return tmp;
}

Vector Vector::Minus(Vector& s) {
	Vector tmp;
	for (int i = 0; i < 3; i++) {
		tmp.arr[i] = arr[i] - s.arr[i];
	}
	return tmp;
}

Vector Vector::Multiply(double d) {
	Vector tmp;
	if (d == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	for (int i = 0; i < 3; i++) {
		tmp.arr[i] = arr[i] * d;
	}
	return tmp;
}

Vector Vector::DivideShort(short d) {
	Vector tmp;
	if (d == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	for (int i = 0; i < 3; i++) {
		tmp.arr[i] = arr[i] / d;
	}
	return tmp;
}

void Vector::Input() {
	cout << "Input element array: ";
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
}

void Vector::Output() {
	cout << "Output element array:" << endl;
	for (int i = 0; i < 3; i++) {
		cout <<" "<< arr[i];
	}
	cout << endl;
}


void Vector::addElement(const int p) {
	srand(time(nullptr));
	int randomElement = rand() % 3;
	arr[randomElement] = p;
}

void Vector::getElement() {
	srand(time(nullptr));
	int randomElement = rand() % 3;
	cout << "Output random element in arry : " << arr[randomElement]<<endl;
}

bool Vector::CompLessAll(Vector& s) {
	for (int i = 0; i < 3; i++) {
		if (arr[i] < s.arr[i])
			return true;
	}
	return false;
}
bool Vector::CompMoreAll(Vector& s) {
	for (int i = 0; i < 3; i++) {
		if (arr[i] > s.arr[i])
			return true;
	}
	return false;
}
bool Vector::CompExactlyAll(Vector& s) {
	for (int i = 0; i < 3; i++) {
		if (arr[i] == s.arr[i])
			return true;
	}
	return false;
}

void task2() {
	double* v = nullptr, v2[] = { 1.1, 2.2, 10 };
	Vector objdef;
	Vector obj1(10.1);
	Vector objcopy(obj1);
	Vector obj2(v2);
	Vector obj3(v2);
	cout << "Test class Vector : " << endl;
	cout << "------------------------------------------------------------------" << endl;
	objdef.Output();
	cout << "------------------------------------------------------------------" << endl;
	obj1.Output();
	cout << "------------------------------------------------------------------" << endl;
	objdef.addElement(10);
	objdef.getElement();
	cout << "------------------------------------------------------------------" << endl;
	if (obj2.getState() != OK) cout << "Obj2 arr[i] = 0"<<endl;
	obj2.Output();
	if (obj3.getState() != OK) cout << "Obj2 arr[i] = 0" << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "Number of created objects Vector :" << Vector::getCount() << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "Test Input: "<<endl;
	objdef.Input();
	cout << "------------------------------------------------------------------" << endl;
	cout << "Test functions:" << endl;	
	cout << "------------------------------------------------------------------" << endl;
	objdef = objdef.Add(obj1);
	cout << "//////" << endl;
	objdef.Output();
	cout << "------------------------------------------------------------------" << endl;
	cout << "The number of created Vector objects before Munis" <<Vector::getCount() << endl;
	objdef = objdef.Minus(obj1);
	cout << "The number of created Vector objects after Munis" << Vector::getCount() << endl;
	objdef.Output();
	cout << "------------------------------------------------------------------" << endl;
	cout << "Multiply function : " << endl;
	objdef = objdef.Multiply(5);
	objdef.Output();
	cout << "------------------------------------------------------------------" << endl;
	cout << "DevideShort function : " << endl;
	objdef = objdef.DivideShort(5);
	objdef.Output();
	cout << "------------------------------------------------------------------" << endl;
	if (objdef.getState() == STATE::BAD_DIV) cout << "BAD_DIV" << endl;
	objdef.Output();
	cout << "------------------------------------------------------------------" << endl;
	objdef = objdef.DivideShort(0);
	if (objdef.getState() == STATE::BAD_DIV) cout << "BAD_DIV" << endl;
	objdef.Output();
	cout << "------------------------------------------------------------------" << endl;

	cout << "Object state " << objcopy.getState() << endl;
	if (objcopy.CompLessAll(objdef)) cout << "ObjectCopy less ObjectDef" << endl;
	if (objcopy.CompMoreAll(objdef)) cout << "ObjectCopy More ObjectDef" << endl;
	if (objcopy.CompLessAll(objdef)) cout << "ObjectCopy Exactly ObjectDef" << endl;
	cout << "End testing";
}

//-------------------------------------------------------------------------------------------------------------------//


//------------------------------------------------------------3------------------------------------------------------//


class Vect {

	double* vector;
	short sizeVector;
public:
	Vect();
	Vect(short n);


};

Vect::Vect() {
	sizeVector = 5;
	vector = new double[sizeVector];
	for (int i = 0; i < sizeVector; i++) {
		vector[i] = 0;
	}
}
Vect::Vect(short n) {
	sizeVector = n;
	vector = new double[n];
	for (int i = 0; i < n; i++) {
		vector[i] = 0;
	}
}

//-------------------------------------------------------------------------------------------------------------------//
class Matrix {
	Vect* matrix;
	short row;
	short column;
	int state;
	static int count;
public:
	Matrix();
	Matrix(short n);
	Matrix(short row, short column, double value);
	Matrix Add(Matrix& d);
	Matrix Minus(Matrix& d);
	Matrix Multiply(double d);
	Matrix DivideShort(int d);

	Matrix(Matrix& s) {
		matrix = s.matrix;
		row = s.row;
		column = s.column;
	}

	Matrix& operator=(Matrix& s) {
		matrix = s.matrix;
		row = s.row;
		column = s.column;
		return *this;
	}

	int getRow();
	int getColumn();
	void Output();

	static int getCount() {
		if (count <= 0) cout << " No objects Vector ";
		return count;
	}
	int getState() {
		return state;
	}
	bool CompLessAll(Matrix& s);
	bool CompMoreAll(Matrix& s);
	bool CompEqualsAll(Matrix& s);
};

int Matrix::count = 0;
Matrix::Matrix() {
	
}


void task3() {

	

}

/*example  4
Створити тип даних - клас вектор, який має вказівник на ComplexDouble, число елементів і змінну стану. У класі визначити
o	 конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль);
o	конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль);
o	конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу).
o	конструктор копій та операцію присвоєння; // !!!
o	деструктор звільняє пам'ять;
o	визначити функції друку, додавання;
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву. Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу.
*/

#include<complex>
using namespace std;
typedef complex<double> ComplexDouble;
#define _RE 0
#define _IM 1

class ComplexVector
{
	ComplexDouble* v;
	int num;
	int state = 0;
public:
	ComplexVector() : v(NULL), num(0), state(0) {}
	ComplexVector(int n);
	ComplexVector(int n, ComplexDouble&);
	ComplexVector(int n, ComplexDouble*);
	ComplexVector(const ComplexVector& s);
	ComplexVector& operator=(const ComplexVector& s);
	~ComplexVector() {
		cout << " del vec";
		if (v) delete[] v;
	}
	void Output();
	void Input();
	ComplexVector Add(ComplexVector& b);

};

ComplexVector::ComplexVector(int n) {
	if (n <= 0) { v = NULL;  num = 0;   state = -1; cout << " Vec --> 0  "; }
	num = n;
	v = new ComplexDouble[n];
	for (int i = 0; i < n; i++) {
		v[i] = 0.0;
		//v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0;  
	}
}
ComplexVector::ComplexVector(int n, ComplexDouble& b) {
	if (n <= 0) { v = NULL;  num = 0;   state = -1; cout << " Vec --> 0  "; }
	num = n;
	v = new ComplexDouble[n];
	for (int i = 0; i < n; i++) {
		v[i] = b;
		//v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0;  
	}
}

ComplexVector::ComplexVector(int n, ComplexDouble* p) {
	if (n <= 0 || p == NULL) { v = NULL;  num = 0;   state = -1; cout << " Vec --> 0  "; }
	num = n;
	v = new ComplexDouble[n];
	for (int i = 0; i < n; i++) {
		v[i] = p[i];
	}
}

ComplexVector::ComplexVector(const ComplexVector& s) {

	num = s.num;
	v = new ComplexDouble[num];
	state = 0;
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
}

ComplexVector& ComplexVector::operator=(const ComplexVector& s) {

	if (num != s.num)
	{
		if (v) delete[] v;
		num = s.num;
		v = new ComplexDouble[num];
		state = 0;
	}
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
	return *this;
}
void ComplexVector::Input() {
	if (num == 0) {
		if (v) delete[] v;
		do {
			cout << "Input size Vec\n";
			cin >> num;
		} while (num <= 0);
		v = new ComplexDouble[num];
	}
	for (int i = 0; i < num; i++) {

#if defined(_MSC_VER)
cout << " v [ " << i << " ] real img  "; cin >> v[i] >> v[i]._Val[_IM];
#else 
double re,im;
cout << " v [ " << i << " ] real img  "; cin >> re>>im;
v[i].real(re); 
v[i].imag(im);
#endif		
		
		
	}
}

void ComplexVector::Output() {
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << " v [ " << i << " ]   " << v[i] << '\t';
			cout << endl;
		}
	}
}

ComplexVector ComplexVector::Add(ComplexVector& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	if (tnum >= 0) {
		ComplexVector tmp(tnum);
		for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] + b.v[i];
		return tmp;
	}
	return ComplexVector(0);
}


int mainExample4()
{
	ComplexDouble a(1.0, 2), b, c;
	cout << a << endl;
#if defined(_MSC_VER)
    b._Val[_RE] = 21.3;
	b._Val[_IM] = 22.3;
#else 
    b.real( 21.3);
	b.imag (22.3);
#endif	
	
	cout << b << endl;
	c = a + b;
	cout << c << endl;
	cout << " Test  " << endl;
	ComplexVector VecObj, VecObj1(10);
	cout << "VecObj \n";
	VecObj.Output();
	cout << "VecObj1 \n";
	VecObj1.Output();
	cout << " Input a " << endl;

#if defined(_MSC_VER)
 cin >> a >> a._Val[_IM];
#else 
double re,im;
cin >> re>>im;
a.real(re); 
a.imag(im);
#endif		
	cout << a << endl;
	ComplexVector VecObj2(10, a);
	VecObj2.Output();

	VecObj.Input();
	cout << endl;
	VecObj.Output();
	VecObj1 = VecObj.Add(VecObj2);
	VecObj1.Output();

	return 1;
}

/// 

