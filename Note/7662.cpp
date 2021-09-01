//https://www.acmicpc.net/problem/7662

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		multiset<int> ms;
		char order;
		int inst, num;
		cin >> inst;

		while (inst--) {
			cin >> order >> num;
			if (order == 'I') ms.insert(num);
			else {
				if (ms.empty()) continue;
				else if (num == 1) {
					auto iter = ms.end();
					ms.erase(--iter);
				}
				else if (num == -1) ms.erase(ms.begin());
			}
		}

		auto end = ms.end();

		if (ms.empty()) cout << "EMPTY" << '\n';
		else cout << *(--end) << " " << *ms.begin() << '\n';
	}

	return 0;
}