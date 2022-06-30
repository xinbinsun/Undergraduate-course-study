#include<iostream>
using namespace std;
class A {
int i; public:
	virtual void set(int ii) { i = ii; } virtual int get() { return i; }
};
class B :public A {
int i; public:
	virtual void set(int ii) { i = ii; }

	virtual int get() { return i; }
};
int main() {
	B a;
	B b;
	a.set(10);
	cout << a.get()<<" ";
	cout << b.get()<<endl;
	b.set(20); 
	cout << a.get() << " ";
	cout << b.get() << endl;
	A& p = a;
	cout << a.get() << " ";
	cout << b.get() << endl;
	p.set(30); 
	cout << a.get() << " ";
	cout << b.get() << endl;
	p = b;
	cout << a.get() << " ";
	cout << b.get() << endl;
	p.set(40);
	cout << a.get() << " ";
	cout << b.get() << endl;
	p.set(50);
	cout << a.get() << " ";
	cout << b.get() << endl;
	return 0;
}