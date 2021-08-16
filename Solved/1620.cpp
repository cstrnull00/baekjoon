//https://www.acmicpc.net/problem/1620

#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

map<string, int> book;
string index[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string pokemon; cin >> pokemon;
		book.insert({ pokemon, i + 1 });
		index[i + 1] = pokemon;
	}

	for (int i = 0; i < m; i++) {
		string order; cin >> order;
		if ('0' <= order[0] && order[0] <= '9') {
			stringstream ssInt(order);
			ssInt >> n;
			cout << index[n] << '\n';
		}
		else cout << book[order] << '\n';
	}

	return 0;
}