#include <iostream>
#include <cstring>
using namespace std;

int Graph[1001][1001] = { {0, }, };
bool Visited[1001] = { false, };

int Child[1001] = { 0, };
int Parent[1001] = { 0, };

void DFS(int d)
{
    if (Visited[d])
        return;

    Visited[d] = true;

    for (int i = 0; i < Parent[d]; i++)
        DFS(Graph[d][i]);

    cout << d << " ";;
}

int main(void)
{
    int V, E;
    for (int tc = 1; tc <= 10; tc++)
    {
        memset(Visited, false, sizeof(Visited));
        memset(Child, 0, sizeof(Child));
        memset(Graph, 0, sizeof(Graph));
        memset(Parent, 0, sizeof(Parent));

        cin >> V >> E;

        for (int i = 0; i < E; i++)
        {
            int a, b;
            cin >> a >> b;

            Child[a]++;
            Graph[b][Parent[b]++] = a;
        }
        cout << "#" << tc << " ";

        for (int i = 1; i <= V; i++) {
            if (Child[i] == 0 && !Visited[i])
                DFS(i);
        }
        cout << "\n";
    }

    return 0;
}
