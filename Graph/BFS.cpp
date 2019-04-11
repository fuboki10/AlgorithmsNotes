/*** BFS - Single source Multiple Destination ***/

const int N = 1e5 + 5; // maximum number of nodes

int SP[N];
vector<int>adj[N];
void bfs(int src)
{
	queue<int>q;
	q.push(src);
	memset(SP , -1 , sizeof SP);
	int level = 0;
	while(!q.empty())
	{
		int sz = q.size();
		for(int i = 0; i < sz ; ++i)
		{
			int cur = q.front();
			q.pop();
			if(SP[cur] != -1) continue;
			SP[cur] = level;
			for(auto nxt : adj[cur]])
				if(SP[nxt] == -1) q.push(nxt);
		}
		level++;
	}
}
