#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int virus(vector<pair<int,int>> network, int num, int pairs) {
    int viru = 1;
    vector<pair<int,int>> infection;

    for(int i = 0; i < pairs ; i++)
        if (network[i].first == 1) {
            infection.push_back(network[i]);
            network.erase(network.begin() + i);
            viru++;
            break;
        }

    while(!network.empty()){
        for(int i = 0;i < pairs;i++)
            if (infection[0].second == network[i].first) {
                infection.push_back(network[i]);
                network.erase(network.begin() + i);
                viru++;
                break;
            }
    }

    return viru;
}

int main(){
    int num, pairs, a, b;
    vector <pair<int,int>> network;

    cin >> num;
    cin >> pairs;

    for(int i = 0;i<pairs;i++){
        scanf("%d %d",&a,&b);
        network.push_back(make_pair(a, b));
    }

    cout << virus(network, num, pairs) << endl;

    return 0;
}