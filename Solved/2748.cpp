//https://www.acmicpc.net/problem/2748

#include <iostream>

using namespace std;

int main() {
	long long n, p, q, r;
	
	cin >> n;
	
	p = 0;
	q = 1;
	r = p + q;

	for (int i = 0; i < n - 2; i++) {
		p = q;
		q = r;
		r = p + q;
	}

	cout << r << endl;

	return 0;
}