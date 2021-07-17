//https://www.acmicpc.net/problem/14221

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define MAX 2147483647

using namespace std;

vector<pair<int, int>> edge[100001];
vector<int> store;
int n, m;

int dijkstra(int);

int main() {
	int a, b, c, p, q;
	vector<int> home;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(make_pair(b, c));
		edge[b].push_back(make_pair(a, c));
	}

	scanf("%d %d", &p, &q);
	for (int i = 0; i < p; i++) {
		scanf("%d", &a);
		home.push_back(a);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &a);
		store.push_back(a);
	}

	int dist = MAX;
	int temp;
	int ans = 0;

	for (auto i : home) {
		temp = dijkstra(i);
		if (dist > temp) {
			ans = i;
			dist = temp;
		}
	}

	cout << ans;

	return 0;
}

int dijkstra(int home) {
	int dist = MAX;
	int distance[5001];
	priority_queue<pair<int, int>> que;

	fill(distance, distance + 5001, MAX);

	que.push(make_pair(0, home));
	distance[home] = 0;

	while (!que.empty()) {
		int cost = -que.top().first;
		int curr = que.top().second;

		que.pop();

		for (auto i : edge[curr]) {
			int next = i.first;
			int nextcost = i.second;

			if (distance[next] > distance[curr] + nextcost) {
				distance[next] = distance[curr] + nextcost;
				que.push(make_pair(-distance[next], next));
			}
		}
	}

	for (auto i : store)
		dist = min(distance[i], dist);

	return dist;
}