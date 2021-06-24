//https://www.acmicpc.net/problem/2776

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int* original, int search, int n);

int main() {
    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n, m, input, original[1000001];

        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            scanf("%d", &original[j]);
        }

        sort(original, original + n);

        cin >> m;
        for (int j = 0; j < m; j++) {
            scanf("%d", &input);
            printf("%d\n", binarySearch(original, input, n));
        }
    }

    return 0;
}

int binarySearch(int* original, int search, int n) {
    int left, mid, right;
    left = 0;
    right = n - 1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (original[mid] > search) right = mid - 1;
        else if (original[mid] < search) left = mid + 1;
        else return 1;
    }

    return 0;
}