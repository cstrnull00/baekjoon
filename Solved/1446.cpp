//https://www.acmicpc.net/problem/1446

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct shortcut {
	int end;
	int length;
};

int main() {
	int N, D;
	int dist[10001];
	vector<shortcut> sc[10001];

	scanf("%d %d", &N, &D);

	for (int i = 0; i < N; i++) {
		shortcut tmp;
		int s;
		scanf("%d %d %d", &s, &tmp.end, &tmp.length);
		if (tmp.end - s > tmp.length && tmp.end <= D)
			sc[s].push_back(tmp);
	}

	for (int i = 0; i <= D; i++) dist[i] = i;

	int prev = -1;
	for (int i = 0; i <= D; i++) {
		dist[i] = min(dist[i], prev + 1);
		if (!sc[i].empty()) {
			for (auto j : sc[i]) {
				if (dist[i] + j.length < dist[j.end])
					dist[j.end] = dist[i] + j.length;
			}
		}
		prev = dist[i];
	}

	cout << dist[D] << endl;

	return 0;
}