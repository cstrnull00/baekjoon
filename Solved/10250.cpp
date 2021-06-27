//https://www.acmicpc.net/problem/10250

#include <iostream>

using namespace std;

int main() {
	int T, H, W, N, R, _H, _W;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &H, &W, &N);
		_H = N % H;
		_W = N / H;
		if (_H > 0) _W++;
		else _H = H;
		cout << _H * 100 + _W << endl;
	}

	return 0;
}