//https://www.acmicpc.net/problem/1927

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	priority_queue<int, vector<int>, greater<int>> heap;

	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (heap.empty()) cout << 0 << '\n';
			else {
				cout << heap.top() << '\n';
				heap.pop();
			}
		}
		else {
			heap.push(x);
		}
	}

	return 0;
}