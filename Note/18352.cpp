//https://www.acmicpc.net/problem/18352

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> edge[300001];
int dist[300001] = { 0, };
int N, M, K, X;

void bfs(int s) {
	queue<int> que;
	int length = 0;

	que.push(s);

	while (!que.empty()) {
		int curr = que.front();
		que.pop();
		
		for (int i = 0; i < edge[curr].size(); i++) {
			int next = edge[curr][i];
			if (!dist[next] && next != s) {
				dist[next] = dist[curr] + 1;
				que.push(next);
			}
		}
	}
}

int main() {
	vector<int> result;
	int s, e;

	scanf("%d %d %d %d", &N, &M, &K, &X);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		edge[s].push_back(e);
	}

	bfs(X);

	for (int i = 1; i <= N; i++)
		if (dist[i] == K) result.push_back(i);

	if (result.empty()) cout << -1 << endl;
	else {
		sort(result.begin(), result.end());
		for (auto i : result) cout << i << endl;
	}


	return 0;
}