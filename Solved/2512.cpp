//https://www.acmicpc.net/problem/2512

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> input(N);

    int maxBudget = 0;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
        maxBudget = max(maxBudget, input[i]);
    }

    int M;
    cin >> M;

    int low = 0, high = maxBudget;
    int result = maxBudget;

    while (low <= high) {
        int mid = (low + high) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++)
            sum += min(input[i], mid);
        if (sum <= M) {
            result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << result;

    return 0;
}