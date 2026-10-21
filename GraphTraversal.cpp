#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[10];
bool visited[10];

void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node]) {
        if (!visited[next]) {
            DFS(next);
        }
    }
}

void BFS(int start) {
    bool seen[10] = {false};
    queue<int> q;

    q.push(start);
    seen[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : graph[node]) {
            if (!seen[next]) {
                q.push(next);
                seen[next] = true;
            }
        }
    }
}

int main() {
    int edges, u, v, start;

    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "Enter roads (two buildings):\n";

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Enter starting building: ";
    cin >> start;

    cout << "DFS: ";
    DFS(start);

    cout << "\nBFS: ";
    BFS(start);

    return 0;
}