//https://www.acmicpc.net/problem/1018

#include <iostream>

using namespace std;

char** candi;

char WB[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};

char BW[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};

int WB_cnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) 
			if (candi[x + i][y + j] != WB[i][j]) cnt++;
	return cnt;
}

int BW_cnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (candi[x + i][y + j] != BW[i][j]) cnt++;
	return cnt;
}

int main() {
	int n, m, min = 2500;

	scanf("%d %d", &n, &m);

	candi = new char* [n];
	for (int i = 0; i < n; i++)
		candi[i] = new char[m];

	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			candi[i][j] = getchar();
		}
		getchar();
	}

	for (int i = 0; i + 8 <= n; i++) {
		for (int j = 0; j + 8 <= m; j++) {
			int _WB = WB_cnt(i, j);
			int _BW = BW_cnt(i, j);
			int tmp = _WB > _BW ? _BW : _WB;
			min = min > tmp ? tmp : min;
		}
	}

	cout << min;

	for (int i = 0; i < n; i++)
		delete[] candi[i];
	delete[] candi;

	return 0;
}