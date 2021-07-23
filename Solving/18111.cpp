//https://www.acmicpc.net/problem/18111

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, B;
	int map[501][501];
	int height[256] = { 0, };
	int max = 0, min = 256;

	scanf("%d %d %d", &N, &M, &B);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] > max) max = map[i][j];
			if (map[i][j] < min) min = map[i][j];
			height[map[i][j]]++;
		}

	int sec = 0;


	cout << sec << " " << map[0][0];

	return 0;
}