#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

int distinct(char**, int);
char** blindness(char**, int);

int main() {
    int N;
    char** region, **blind;

    cin >> N;

    region = new char* [N];
    blind = new char* [N];
    for (int i = 0; i < N; i++) {
        region[i] = new char[N];
        blind[i] = new char[N];
    }

    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < N; j++)
            region[i][j] = getchar();
    }
    
    blind = blindness(region, N);

    cout << distinct(region, N) << " " << distinct(blind, N) << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << region[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] region[i];
        delete[] blind[i];
    }
    delete[] region;
    delete[] blind;

    return 0;
}

int distinct(char** region, int N) {
    int x, y, numofregion = 0;
    char temp;
    int direction[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
    pair<int, int> current;
    queue<pair<int, int>> que;

    que.push(make_pair(0, 0));

    while (!que.empty()) {
        current = que.front();
        que.pop();
        temp = region[current.second][current.first];
        for (int i = 0; i < 4; i++) {
            x = current.second + direction[i][0];
            y = current.first + direction[i][1];
            if (x >= 0 && x < N && y >= 0 && y < N) {
                region[current.second][current.first] = numofregion;
                if (temp != region[y][x]) {
                    temp = region[y][x];
                    region[y][x] = ++numofregion;
                }
                que.push(make_pair(y, x));
            }
        }
    }

    return numofregion;
}

char** blindness(char** region, int N) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (region[i][j] == 'R')
                region[i][j] = 'G';
    return region;
}