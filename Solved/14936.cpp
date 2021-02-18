//https://www.acmicpc.net/problem/14936

#include<iostream>
#include<vector>

#define _MAX 100001

int button_state(int n, int m) {
    int cnt = 1;

    if(n <= m) cnt++; //all buttons lighted
    if(n > 1 && n/2 <= m) cnt++; //even buttons lighted
    if(n > 1 && (n+1)/2 <= m) cnt++; //odd buttons lighted
    if(n > 2 && (n-1)/3+1 <= m) cnt++; //3k+1 buttons lighted
    if(n >= 3 && n/2 + (n-1)/3+1 <= m) cnt++; //even AND 3k+1 buttons lighted
    if(n >= 3 && (n+1)/2 + (n-1)/3+1 <= m) cnt++; //odd AND 3k+1 buttons lighted
    if(n >= 3 && n + (n-1)/3+1 <= m) cnt++; //all AND 3k+1 buttons lighted

    return cnt;
}

int main() { 
    int n, m;

    std::cin >> n >> m;

    std::cout << button_state(n, m);

    return 0;
}