//https://www.acmicpc.net/problem/11000

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> l[200001];
priority_queue<int, vector<int>, greater<int>> r;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> l[i].first >> l[i].second;

	sort(l, l + n);

	r.push(l[0].second);

	for (int i = 1; i < n; i++) {
		if (r.top() <= l[i].first) {
			r.pop();
			r.push(l[i].second);
		}
		else r.push(l[i].second);
	}
	
	cout << r.size();
	
	return 0;
}