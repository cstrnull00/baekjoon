#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

int distance(int**, int, int);

int main() {
    int N, M;
    int** maze;

    cin >> N >> M;

    maze = new int* [N];
    for (int i = 0; i < N; i++)
        maze[i] = new int[M];

    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < M; j++)
            maze[i][j] = getchar() - '0';
    }

    cout << distance(maze, N, M);

    for (int i = 0; i < N; i++)
        delete[] maze[i];
    delete[] maze;

    return 0;
}

int distance(int** maze, int N, int M) {
    int direction[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
    pair<int, int> current;
    queue <pair<int, int>> bfs;
    int x, y;

    bfs.push(make_pair(0,0));

    while (!bfs.empty()) {
        current = bfs.front();
        bfs.pop();

        for (int i = 0; i < 4; i++) {
            x = current.second + direction[i][0];
            y = current.first + direction[i][1];
            if (x >= 0 && x < M && y >= 0 && y < N && maze[y][x] == 1) {
                bfs.push(make_pair(y,x));
                maze[y][x] = maze[current.first][current.second] + 1;
            }
        }
    }

    return maze[N - 1][M - 1];
}