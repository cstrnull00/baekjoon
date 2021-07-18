//https://www.acmicpc.net/problem/1916

#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 2147482647

using namespace std;

int n, m;
vector<pair<int, int>> bus[100001];

int dijkstra(int, int);

int main() {
	scanf("%d %d", &n, &m);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		bus[a].push_back(make_pair(b, c));
	}

	int s, e;
	scanf("%d %d", &s, &e);

	cout << dijkstra(s, e);

	return 0;
}

int dijkstra(int s, int e) {
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> que;

	que.push(make_pair(0, s));
	dist[s] = 0;

	while (!que.empty()) {
		int currcost = -que.top().first;
		int curr = que.top().second;

		que.pop();

		if (dist[curr] < currcost) continue;

		for (auto i : bus[curr]) {
			int next = i.first;
			int nextcost = i.second;

			if (dist[next] > dist[curr] + nextcost) {
				dist[next] = dist[curr] + nextcost;
				que.push(make_pair(-dist[next], next));
			}
		}
	}

	return dist[e];
}