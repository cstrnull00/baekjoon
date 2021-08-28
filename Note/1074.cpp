//https://www.acmicpc.net/problem/1074

#include <iostream>

using namespace std;

int n, r, c, ans = 0;

void visit(int y, int x, int l) {
	if (y == r && x == c) {
		cout << ans;
		return;
	}

	if (r < y + l && r >= y && c < x + l && c >= x) {
		visit(y, x, l / 2);
		visit(y, x + l / 2, l / 2);
		visit(y + l / 2, x, l / 2);
		visit(y + l / 2, x + l / 2, l / 2);
	}
	else ans += l * l;
}

int main() {
	cin >> n >> r >> c;
	visit(0, 0, (1 << n));
	return 0;
}