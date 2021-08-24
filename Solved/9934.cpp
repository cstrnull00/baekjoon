//https://www.acmicpc.net/problem/9934

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> bd;
vector<int> ans[11];

void search(int s, int e, int depth) {

    if (s == e) {
        ans[depth].push_back(bd[s]);
        return;
    }

    int mid = (e + s) / 2;
    ans[depth].push_back(bd[mid]);

    search(s, mid - 1, depth + 1);
    search(mid + 1, e, depth + 1);
}


int main() {
    int k;
    cin >> k;

    for (int i = 0; i < pow(2, k) - 1; i++) {
        int num;
        cin >> num;
        bd.push_back(num);
    }

    search(0, bd.size() - 1, 0);

    for (int i = 0; i < k; i++) {
        for (auto j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}