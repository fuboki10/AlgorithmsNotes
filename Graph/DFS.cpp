//// DFS
bool visited[];
vector<vector<int>> adj;
void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    for (auto var : adj[v])
    {
        if (!visited[var])
        {
            DFS(var);
        }
    }
}



//// Topological Sort
vector<int> Topological;
bool vis[];
void Topological_sort(int student)
{
    vis[student] = 1;
    for (int i = 0; i < adj[student].size(); ++i)
    {
        int child = adj[student][i];
        if (!vis[child])
        {
            Topological_sort(child);
        }
    }
    Topological.pb(student);
}
