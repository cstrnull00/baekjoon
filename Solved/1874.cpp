//https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, max = 0, index = 0;

	cin >> n;
	stack<int> dest;
	char ans[200001];

	while (n--) {
		cin >> x;

		if (x > max) {
			for (int i = max + 1; i <= x; i++) {
				dest.push(i);
				ans[index++] = '+';
			}
		}
		else
			if (dest.top() != x) {
				cout << "NO";
				return 0;
			}
		dest.pop();
		ans[index++] = '-';
		max = max > x ? max : x;
	}

	for (int i = 0; i < index; i++) cout << ans[i] << '\n';

	return 0;
}