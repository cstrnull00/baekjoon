//https://www.acmicpc.net/problem/1753

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>

#define INF 2147483647

using namespace std;

typedef struct NODE {
    int to;
    int val;
};

void dijkstra(int* dist, vector<NODE>* edge, int start_node) {
    int now, cost;
    int new_val, before_val;

    priority_queue<pair<int, int>> dijk;
    dijk.push({0, start_node});

    while(!dijk.empty()) {
        now = dijk.top().second;
        cost = -1*dijk.top().first;
        dijk.pop();

        for(int i = 0; i < edge[now].size(); i++) {
            new_val = dist[now] + edge[now][i].val;
            before_val = dist[edge[now][i].to];

            if(new_val < before_val) {
                dist[edge[now][i].to] = new_val;
                dijk.push({-1*new_val, edge[now][i].to});
            }
        }

    }
}

int main() {
    int v, e, start_node;
    int from, to, val;
    int dist[20001];
    vector<NODE> edge[300001];
    
    cin >> v >> e >> start_node;

    for(int i = 0; i < e; i++) {
        cin >> from >> to >> val;
        edge[from].push_back(NODE{to,val});
    }

    for(int i = 1; i <= v; i++)
        dist[i] = INF;
    dist[start_node] = 0;

    dijkstra(dist, edge, start_node);

    for(int i = 1; i <= v; i++) {
        if (dist[i] != INF) printf("%d\n", dist[i]);
        else printf("INF\n");
    }

    return 0;
}