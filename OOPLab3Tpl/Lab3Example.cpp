#include <iostream>
#include <math.h>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;
void MenuTask()
{
	cout << "     Menu Task   \n";
	cout << "    1.  Class Time  \n";
	cout << "    2.  Class Vector \n";
	cout << "    3.  Class Vector and Matrix \n";
	cout << "    4.  Exit \n";
}
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
	else if (objcopy.CompMoreAll(objdef)) cout << "ObjectCopy More ObjectDef" << endl;
	else if (objcopy.CompLessAll(objdef)) cout << "ObjectCopy Exactly ObjectDef" << endl;
	cout << "End testing";
}

//-------------------------------------------------------------------------------------------------------------------//


//------------------------------------------------------------3------------------------------------------------------//

class Vector2{
	double* v;
	int num = 5;
	static double badIndexRef;
	static int numVec;
public:
	Vector2() : num(0), v(nullptr) {}
	Vector2(int n);
	Vector2(const Vector2& s);  // crot copy
	Vector2& operator=(const Vector2& s);
	void Init(int n);   //
	void Init(int n, double);   //
	double& operator[](int index);
	~Vector2() {
	  //  std::cout << " del vec";
		if (v) delete[] v;
	}
};
double Vector2::badIndexRef = 0;
int Vector2::numVec = 0;
Vector2::Vector2(int n) {
	if (n <= 0)    n = 5;  // default num =5;
	num = n;
	v = new double[n];
	for (int i = 0; i < n; i++) {
		v[i] = 0.0;  
	}
}
void Vector2::Init(int n) {
	if (num != n) {
		if (v != nullptr) delete[] v;
		num = n;
		v = new double[n];
	}
	for (int i = 0; i < num; i++) 	v[i] = 0;
}
void Vector2::Init(int n, double b) {
	if (num != n) {
		if (v != nullptr) delete[] v;
		num = n;
		v = new double[n];
	}
	for (int i = 0; i < num; i++) 	v[i] = b;
}


Vector2::Vector2(const Vector2& s) {
	if (this == &s) return;  
	num = s.num;
	v = new double[num];
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
}
Vector2& Vector2::operator=(const Vector2& s) {
	if (this == &s) return *this;
	if (num != s.num)
	{
		if (v) delete[] v;
		num = s.num;
		v = new double[num];
	}
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
	return *this;
}
double& Vector2::operator[](int index)
{
	if (index >= 0 && index < num) return v[index];
	cout << " Error : operator[] - index out of range \n";
	return badIndexRef;
}

//----------------------------------------------
class Matrix {
	Vector2* vec = nullptr;
	int n = 5, m = 5;
	int state = 0;
public:
	Matrix() : Matrix(5) {  }
	Matrix(int n) : Matrix(n, n) {  };
	Matrix(int n, int m) : Matrix(n, m, 0) {  };
	Matrix(int n, int m, double);
	Matrix(const Matrix& s);
	Matrix& operator=(const Matrix& s);
	Vector2& operator[](int index);
	~Matrix() {
	    std::cout << " del mat";
		if (vec) delete[] vec;
	}
	int getState() {
		return state;
	}
	void Output();
	Matrix Add(Matrix& d);
	Matrix Minus(Matrix& d);
	Matrix Multiply(double d);
	Matrix DivideInt(int d);
	bool CompLessAll(Matrix& s);
	bool CompMoreAll(Matrix& s);
	bool CompExactlyAll(Matrix& s);
	void addElement(const int p);
	void getElement();

};
Matrix::Matrix(int ni, int mi, double b)
{
	if (ni <= 0) n = 5; else n = ni;
	if (mi <= 0) m = 5; else m = mi;
	vec = new Vector2[n];
	for (int i = 0; i < n; i++) { vec[i].Init(m, b); }

	
}
Matrix::Matrix(const Matrix& s)
{
	n = s.n;
	m = s.m;
	int i;
	vec = new Vector2[n];
	for (i = 0; i < n; i++) vec[i].Init(m, 0);
	for (i = 0; i < n; i++)
		for (int j = 0; j < m; j++)  vec[i][j] = s.vec[i][j];
	
}
Matrix& Matrix::operator=(const Matrix& s)
{
	if (this != &s) {
		int i;
		if (n != s.n || m != s.m) {
			n = s.n; m = s.m;
			if (vec != nullptr) {
				delete[] vec;
			}
			vec = new Vector2[n];
			for (i = 0; i < n; i++) vec[i].Init(m, 0);
		}
		for (i = 0; i < n; i++)
			for (int j = 0; j < m; j++)  vec[i][j] = s.vec[i][j];

	}
	return *this;
}
Vector2& Matrix::operator[](int index)
{
	if (index >= 0 && index < n) return vec[index];
	cout << " Error : operator[] - index index out of range \n";
	return vec[0];
}
void Matrix::Output()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << vec[i][j]<<"\t";
		}
		cout << endl;
	}
}
Matrix Matrix::Add(Matrix& s) {
	Matrix tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp.vec[i][j] = vec[i][j] + s.vec[i][j];
		}
	}
	return tmp;
}

Matrix Matrix::Minus(Matrix& s) {
	Matrix tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp.vec[i][j] = vec[i][j] - s.vec[i][j];
		}
	}
	return tmp;
}

Matrix Matrix::Multiply(double d) {
	Matrix tmp;
	if (d == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp.vec[i][j] = vec[i][j] * d;
		}
	}
	return tmp;
}

Matrix Matrix::DivideInt(int d) {
	Matrix tmp;
	if (d == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp.vec[i][j] = vec[i][j] / d;
		}
	}
	return tmp;
}
void Matrix::addElement(const int p) {
	srand(time(nullptr));
	int randomN = rand() % 3;
	int randomM = rand() % 3;
	vec[randomN][randomM] = p;
}

void Matrix::getElement() {
	srand(time(nullptr));
	int randomN = rand() % 3;
	int randomM = rand() % 3;
	cout << "Output random element in arry : " << vec[randomN][randomM] << endl;
}
bool Matrix::CompLessAll(Matrix& s) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec[i][j] < s.vec[i][j])
			{
				return true;
			}
		}

	}
	return false;
}
bool Matrix::CompMoreAll(Matrix& s) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec[i][j] > s.vec[i][j])
			{
				return true;
			}
		}
	}
	return false;
}
bool Matrix::CompExactlyAll(Matrix& s) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec[i][j] == s.vec[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

void task3() {
	Matrix A;
	Matrix B(5);
	Matrix C(5, 5, 3);
	Matrix objcopy(C);
	Matrix D;
	Matrix E(5, 5, 10);
	cout << "Test class Matrix : " << endl;
	cout << "------------------------------------------------------------------" << endl;
	A.Output();
	cout << "------------------------------------------------------------------" << endl;
	B.Output();
	cout << "------------------------------------------------------------------" << endl;
	A.addElement(10);
	A.getElement();
	cout << "------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "Test functions:" << endl;
	cout << "------------------------------------------------------------------" << endl;
	C = C.Add(C);
	cout << "Add//////" << endl;
	C.Output();
	cout << "------------------------------------------------------------------" << endl;
	C = C.Minus(E);
	cout << endl;
	C.Output();
	cout << "------------------------------------------------------------------" << endl;
	cout << "Multiply function : " << endl;
	C = C.Multiply(4);
	cout << endl;
	C.Output();
	cout << "------------------------------------------------------------------" << endl;
	cout << "DevideInt function : " << endl;
	C = C.DivideInt(3);
	cout << endl;
	C.Output();
	cout << "------------------------------------------------------------------" << endl;
	C = C.DivideInt(0);
	if (C.getState() == STATE::BAD_DIV) cout << "BAD_DIV" << endl;
	cout << endl;
	C.Output();
	cout << "------------------------------------------------------------------" << endl;
	cout << "Object state " << objcopy.getState() << endl;
	if (objcopy.CompLessAll(C)) cout << "ObjectCopy less ObjectDef" << endl;
	else if (objcopy.CompMoreAll(C)) cout << "ObjectCopy More ObjectDef" << endl;
	else if (objcopy.CompLessAll(C)) cout << "ObjectCopy Exactly ObjectDef" << endl;
	cout << "End testing"<<endl;
}

//-------------------------------------------------------------------------------------------------------------------//
