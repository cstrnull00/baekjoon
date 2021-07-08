//https://www.acmicpc.net/problem/1388

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, cnt = 0;
	vector<vector<char>> floor;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<char> tmp;
		char temp;
		for (int j = 0; j < M; j++) {
			cin >> temp;
			tmp.push_back(temp);
		}
		floor.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cnt++;
			if (floor[i][j] == '-' && j > 0) {
				if (floor[i][j - 1] == '-') cnt--;
			}
			else if (floor[i][j] == '|' && i > 0) {
				if (floor[i - 1][j] == '|') cnt--;
			}
		}
	}
	
	cout << cnt << endl;

	return 0;
}