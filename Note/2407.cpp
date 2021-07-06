//https://www.acmicpc.net/problem/2407

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string memo[101][101];

string numAdd(string n1, string n2) {
	int sum = 0;
	string result;

	while (!n1.empty() || !n2.empty() || sum) {
		if (!n1.empty()) {
			sum += n1.back() - '0';
			n1.pop_back();
		}
		if (!n2.empty()) {
			sum += n2.back() - '0';
			n2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

string combination(int n, int r) {
	if (r == 0 || r == n) return "1";

	string& result = memo[n][r];
	
	if (result != "") return result;

	result = numAdd(combination(n - 1, r - 1), combination(n - 1, r));
	return result;
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	cout << combination(n, m) << endl;

	return 0;
}