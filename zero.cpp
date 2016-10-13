#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

enum spectrum { red, orange, yellow };

template <typename anytype> inline anytype Max(const anytype a, const anytype b) { return (a > b ? a : b); }
template <typename anytype> inline void Swap(anytype& a, anytype& b) { anytype tmp = b; b = a; a = tmp; return; }

struct job {
	string name;
	double salary;
	int floor;
	struct job(string a, double b, int c) : name(a), salary(b), floor(c){}
	job operator=(const job& a) {
		name = a.name;
		salary = a.salary;
		floor = a.floor;
		return job(name, salary, floor);
	}
};

ostream & operator<<(ostream & os, const job& a) {
	os << a.name << " " << a.salary << " " << a.floor;
	return os;
}

void show(int a) { cout << "INT: " << a << endl; }
void show(double a) { cout << "Doulbe: " << a << endl; }
void show(string a) { cout << "String: " << a << endl; }
void show(job a) { cout << "Job: " << a << endl; }
int main() {
	job a("ABC", 200, 1), b("abc", 1, 200);
	show(a);
	show(b);
	swap(a, b);
	show(a);
	show(b);
	return 0;
}