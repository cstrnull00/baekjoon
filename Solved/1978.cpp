//https://www.acmicpc.net/problem/1978

#include <iostream>
using namespace std;

bool isprime[1001];
int main() {
    int n, max = 0;
    scanf("%d", &n);

    int num[101];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        if (num[i] > max) max = num[i];
    }

    for (int i = 2; i <= max; i++) isprime[i] = true;

    for (int i = 2; i * i <= max; i++)
        if (isprime[i])
            for (int j = i * i; j <= max; j += i)
                isprime[j] = false;

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (isprime[num[i]]) cnt++;

    printf("%d", cnt);

    return 0;
}