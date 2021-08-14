//https://www.acmicpc.net/problem/17219

#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, string> hash;

	int n, m;
	cin >> n >> m;

	string url;
	string pwd;
	
	while (n--) {
		cin >> url >> pwd;
		hash.insert({ url, pwd });
	}
	while (m--) {
		cin >> url;
		cout << hash[url] << '\n';
	}

	return 0;
}