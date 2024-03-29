//https://www.acmicpc.net/problem/1966

#include <iostream>
#include <queue>
using namespace std;
int main() {
    int cnt = 0;
    int t;
    cin >> t;
    int n, m, ipt;
    while(t--) {
        cnt = 0;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int j = 0; j < n; ++j) {
            cin >> ipt;
            q.push({ j, ipt });
            pq.push(ipt);
        }
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value) {
                pq.pop();
                ++cnt;
                if (index == m) {
                    cout << cnt << endl;
                    break;
                }
            }
            else q.push({ index,value });
        }
    }
}