//https://www.acmicpc.net/problem/2630

#include <iostream>

using namespace std;

int paper[128][128];
int w = 0, b = 0;

void divide(int y, int x, int n) {
	int color = paper[y][x];

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (color == 0 && paper[i][j] == 1) {
				color = 2;
			}
			else if (color == 1 && paper[i][j] == 0) {
				color = 2;
			}
			if (color == 2) {
				divide(y, x, n / 2);
				divide(y, x + n / 2, n / 2);
				divide(y + n / 2, x, n / 2);
				divide(y + n / 2, x + n / 2, n / 2);
				return;
			}
		}
	}
	if (color == 0) w++;
	else b++;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	divide(0, 0, n);
	cout << w << '\n' << b;

	return 0;
}
