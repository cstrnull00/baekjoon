//https://www.acmicpc.net/problem/11399

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];

	sort(p.begin(), p.end());

	long long sum = 0, add = 0;
	for (int i = 0; i < n; i++) {
		add += p[i];
		sum += add;
	}

	cout << sum;

	return 0;
}