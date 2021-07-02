//https://www.acmicpc.net/problem/10826

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sum(string& s1, string& s2) {
	string result(max(s1.size(), s2.size()), '0');
	bool carry = false;

	for (int i = 0; i < result.size(); i++) {
		int temp = carry;
		carry = false;

		if (i < s1.size())
			temp += s1[s1.size() - i - 1] - '0';
		if (i < s2.size())
			temp += s2[s2.size() - i - 1] - '0';
		if (temp >= 10) {
			carry = true;
			temp -= 10;
		}

		result[result.size() - i - 1] = temp + '0';
	}

	if (carry) result.insert(result.begin(), '1');

	return result;

}

int main() {

	int n;
	scanf("%d", &n);

	string fibo[10001];
	fibo[0] = '0';
	fibo[1] = '1';

	for (int i = 2; i <= n; i++) {
		fibo[i] = sum(fibo[i - 1], fibo[i - 2]);
	}

	cout << fibo[n] << endl;

	return 0;
}