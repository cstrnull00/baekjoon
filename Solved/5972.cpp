//https://www.acmicpc.net/problem/5972

#include <iostream>
#include <utility>
#include <queue>
#include <vector>

#define INF 2147482647

using namespace std;

int n, m;
vector<pair<int, int>> edge[100001];

int dijkstra(int, int);

int main() {
	scanf("%d %d", &n, &m);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(make_pair(b, c));
		edge[b].push_back(make_pair(a, c));
	}

	cout << dijkstra(1, n);

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

		for (auto i : edge[curr]) {
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