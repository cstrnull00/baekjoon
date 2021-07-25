//https://www.acmicpc.net/problem/1929

#include <iostream>
using namespace std;

bool isprime[1000001];
int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 2; i <= n; i++) isprime[i] = true;

	for (int i = 2; i * i <= n; i++)
		if (isprime[i])
			for (int j = i * i; j <= n; j += i)
				isprime[j] = false;
	
	for (int i = m; i <= n; i++)
		if (isprime[i]) printf("%d\n", i);

	return 0;
}