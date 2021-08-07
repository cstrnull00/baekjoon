//https://www.acmicpc.net/problem/2869

#include <iostream>

using namespace std;

int main() {
	int a, b, v, i;
	cin >> a >> b >> v;
	
	if ((v - b) % (a - b) == 0) i = (v - b) / (a - b);
	else i = (v - b) / (a - b) + 1;

	cout << i;

	return 0;
}