#include <iostream>

using namespace std;

int distinct(char**, int);
char** blindness(char**, int);

int main() {
    int N, char** region;

    cin >> N;

    region = new char*[N];
    for(int i = 0; i < N; i++)
        region[i] = new char[N];

    for(int i = 0; i < N; i++){
        getchar();
        for(int j = 0; j < N; j++)
            region[i][j] = getchar();
    }

    cout << distinct(region, N) << " " << distinct(blindness(region, N), N);

    for(int i = 0; i < N; i++)
        delete[] region[i];
    delete[] region;

    return 0;
}

int distinct(char** region, int N) {
    int numofregion = 0;

    return numofregion;
}

char** blindness(char** region, int N) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(region[i][j] == 'R')
                region[i][j] = 'G';
    return region;
}