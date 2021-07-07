//https://www.acmicpc.net/problem/11558

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T, N, K;
	vector<int> game;
	vector<bool> visited;

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		game.push_back(N);
		visited.push_back(true);

		int i, curr;

		for (i = 0; i < N; i++) {
			scanf("%d", &K);
			game.push_back(K);
			visited.push_back(false);
		}

		K = 0;
		i = 1;
		curr = 1;
		visited[1] = true;

		while (!visited[N]) {
			curr = game[i];
			K++;
			if (visited[curr]) {
				K = 0; break;
			}
			visited[curr] = true;
			i = curr;
		}

		cout << K << endl;

		game.clear();
		visited.clear();
	}


	return 0;
}
