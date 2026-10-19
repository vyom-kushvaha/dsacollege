
#include <iostream>
#include <queue>
using namespace std;

int graph[20][20], n;
bool visited[20];

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    queue<int> q;

    for (int i = 0; i < n; i++)
        visited[i] = false;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int edges, u, v, start;

    cout << "Enter vertices: ";
    cin >> n;

    cout << "Enter edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout << "DFS: ";
    DFS(start);

    cout << "\nBFS: ";
    BFS(start);

    return 0;
}
