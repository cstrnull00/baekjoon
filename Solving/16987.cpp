#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int broke_max(vector<pair<int,int>> egg, int N) {
    int max = 0, index = 0;
    vector<bool> broken;
    pair<int, int> inhand;

    for(int i = 0;i < N; i++)
        broken.push_back(false);

    inhand = egg[index];

    return max;
}

int main() {
    int N, durability, weight;
    vector<pair<int,int>> egg;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> durability >> weight;
        egg.push_back(make_pair(durability, weight));
    }

    cout << broke_max(egg, N);

    return 0;
}