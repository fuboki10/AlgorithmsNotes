/*** Dijkstra - Single source Multiple Destination ***/

const int N = 1e5 + 5; // maximum number of nodes

int SP[N];
vector<pair<int,int> >adj[N];
struct node
{
	int id,cost;
	node(int ii , int cc)
	{
		id = ii , cost = cc;
	}
	bool operator < (const node & nn) const
	{
		return cost > nn.cost;
	}
}
void dijkstra(int src)
{
	priority_queue<node>q;
	q.push(node(src , 0));
	memset(SP , -1 , sizeof SP);
	while(!q.empty())
	{
		node cur = q.top();
		q.pop();
		if(SP[cur.id] != -1) continue;
		SP[cur.id] = cur.cost;
		for(auto nxt : adj[cur.id]])
			if(SP[nxt.first] == -1) q.push(node(nxt.first , cur.cost + nxt.second));
	}
}
