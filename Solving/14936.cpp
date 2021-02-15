//https://www.acmicpc.net/problem/14936

#include<iostream>
#include<vector>

#define _MAX 100001

int button_state(int n, int m) {
    int cnt = 0;
    std::vector<bool> state;

    for(int i = 0; i < n; i++)
        state.push_back(false);

    return cnt;
}

int main() { 
    int n, m;

    std::cin >> n >> m;

    std::cout << button_state(n, m);

    return 0;
}