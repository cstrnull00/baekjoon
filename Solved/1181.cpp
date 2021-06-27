//https://www.acmicpc.net/problem/1181

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
	if (a.length() != b.length()) return a.length() < b.length();
	else return a < b;
}

int main() {
	int n;
	string word;
	vector<string> dic;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> word;
		dic.push_back(word);
	}
	
	sort(dic.begin(), dic.end(), comp);

	for (int i = 0; i < n; i++) {
		if (i > 0 && dic[i] == dic[i - 1]) continue;
		else cout << dic[i] << endl;
	}

	return 0;
}