//// DFS
bool visited[];
vector<vector<int>> adj;
void DFS(int v)
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


//// Stable Topological sort (Kahn's algorithm)

void Graph::topologicalSort() 
{ 
    vector<int> in_degree(V, 0); 
  
    for (int u=0; u<V; u++) 
    { 
        for (auto it : adj[u])
             in_degree[it]++; 
    } 
 
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    int cnt = 0; 
    vector <int> top_order; 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
        top_order.push_back(u); 
  
        for (auto it : adj[u])
            if (--in_degree[it] == 0) 
                q.push(it); 

        cnt++; 
    } 
  
    // Check if there was a cycle 
    if (cnt != V) 
    { 
        cout << "There exists a cycle in the graph\n"; 
        return; 
    } 
  
    for (int i=0; i<top_order.size(); i++) 
        cout << top_order[i] << " "; 
    cout << endl; 
} 

//// Iterative DFS
void DFS(int s) 
{ 

    vector<bool> visited(V, false); 
  
    stack<int> stack; 
  
    stack.push(s); 
  
    while (!stack.empty()) 
    { 

        s = stack.top(); 
        stack.pop(); 
        if (!visited[s]) 
        { 
            cout << s << " "; 
            visited[s] = true; 
        }  
        for (auto i : adj[s])
            if (!visited[i]) 
                stack.push(i); 
    } 
} 


//// Detect Cycle
bool isCycle(int v, int parent)
{
	vis[v] = 1;
	for (auto child : adj[v])
	{
		if (!vis[child])
		{
			if (isCycle(child, v))
			{
				return true;
			}
		}
		else if (child != parent)
		{
			return true;
		}
	}
	return false;
}

