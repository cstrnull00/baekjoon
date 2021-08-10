//https://www.acmicpc.net/problem/18111

#include <iostream>

using namespace std;

int N, M, B;
int map[501][501];

int narashi(int h) {
	int higher = 0, lower = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > h) higher += map[i][j] - h;
			else if (map[i][j] < h) lower += h - map[i][j];
		}
	}

	if (higher == 0 && lower == 0) return 0;
	if (lower > higher + B) return -1;

	return higher * 2 + lower;
}

int main() {
	int max = 0, min = 256;

	scanf("%d %d %d", &N, &M, &B);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] > max) max = map[i][j];
			if (map[i][j] < min) min = map[i][j];
		}

	int ans = 0, sec = 2147483647;

	for (int i = min; i <= max; i++) {
		int time = narashi(i);

		if (time >= 0 && sec >= time) {
			sec = time;
			ans = i;
		}
	}


	cout << sec << " " << ans;

	return 0;
}