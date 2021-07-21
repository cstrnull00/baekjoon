//https://www.acmicpc.net/problem/1157

#include <iostream>

using namespace std;

int main() {
	char word[1000001];
	int ch[26] = { 0, };
	int i = 0, before = 0, max = 0;

	scanf("%s", word);

	while (word[i]) {
		if (word[i] > 64 && word[i] < 91) {
			ch[word[i] - 65]++;
			if (ch[max] < ch[word[i] - 65])
				max = word[i] - 65;
		}
		else if (word[i] > 96 && word[i] < 123) {
			ch[word[i] - 97]++;
			if (ch[max] < ch[word[i] - 97])
				max = word[i] - 97;	
		}
		i++;
	}

	bool flag = false;
	int tmp = ch[max];
	for (int i = 0; i < 26; i++) {
		if (tmp == ch[i] && i != max) {
			flag = true;
			break;
		}
	}

	if (flag) cout << "?";
	else printf("%c", max + 65);

	return 0;
}