//https://www.acmicpc.net/problem/9461

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<unsigned long long> num;

		for (int i = 0; i < 3; i++) num.push_back(1);
		for (int i = 3; i < 5; i++) num.push_back(2);

		for (int i = 5; i < n; i++) {
			num.push_back(num[i - 1] + num[i - 5]);
		}

		cout << num[n - 1] << endl;
	}

	return 0;
}