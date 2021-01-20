#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

int distance(int**, int, int);

int main() {
    int N, M;
    int** maze;

    cin >> N;
    cin >> M;

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
    int d = 0;
    pair<int, int> coordi(0,0);

    return d;
}