#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include "clk.h"

using namespace std;

#define N 1000000

int main() {
	//ofstream out("data.txt");
	//for (int i = 0; i < N; i++)
	//	out << i << "\n";
	//out.close();

	freopen("data.txt", "r", stdin);
	my_clock clk;
	clk.start();
	ios::sync_with_stdio(false);
	int c;
	for (int i = 0; i < N; i++)
		cin >> c;
	cout << clk.stop() << endl;

	return 0;
}
