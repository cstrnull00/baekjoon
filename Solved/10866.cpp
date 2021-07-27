//https://www.acmicpc.net/problem/10866

#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int main() {
	deque<int> q;
	int n, input;
	char order[11];
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%s", order);

		if (!strcmp(order, "push_back")) {
			getchar();
			scanf("%d", &input);
			q.push_back(input);
		}
		else if (!strcmp(order, "push_front")) {
			getchar();
			scanf("%d", &input);
			q.push_front(input);
		}
		else if (!strcmp(order, "pop_back")) {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.back() << endl;
				q.pop_back();
			}
		}
		else if (!strcmp(order, "pop_front")) {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop_front();
			}
		}
		else if (!strcmp(order, "size")) {
			cout << q.size() << endl;
		}
		else if (!strcmp(order, "empty")) {
			if (q.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (!strcmp(order, "front")) {
			if (q.empty()) cout << -1 << endl;
			else cout << q.front() << endl;
		}
		else if (!strcmp(order, "back")) {
			if (q.empty()) cout << -1 << endl;
			else cout << q.back() << endl;
		}
	}

	return 0;
}