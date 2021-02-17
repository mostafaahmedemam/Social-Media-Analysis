#include<iostream>
#include<vector>
#include<set>
#include<queue> 

using namespace std;

# define INF 0x3f3f3f3f 
 
// iPair ==> Integer Pair 
typedef pair<int, int> iPair;
 
// To add an edge 
void addEdge(vector <pair<int, int> > adj[], int u,
	int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}
 
 
// Prints shortest paths from src to all other vertices 
int shortestPath(vector<pair<int, int> > adj[], int V, int src)
{
	priority_queue< iPair, vector <iPair>, greater<iPair> > pq;
 
	// Create a vector for distances and initialize all 
	// distances as infinite (INF) 
	vector<int> dist(V, INF);
 
	// Insert source itself in priority queue and initialize 
	// its distance as 0. 
	pq.push(make_pair(0, src));
	dist[src] = 0;
 
	/* Looping till priority queue becomes empty (or all
	distances are not finalized) */
	while (!pq.empty())
	{
		// The first vertex in pair is the minimum distance 
		// vertex, extract it from priority queue. 
		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted distance (distance must be first item 
		// in pair) 
		int u = pq.top().second;
		pq.pop();
 
		// Get all adjacent of u.  
		for (auto x : adj[u])
		{
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = x.first;
			int weight = x.second;
 
			// If there is shorted path to v through u. 
			if (dist[v] > dist[u] + weight)
			{
				// Updating distance of v 
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	int sum_SP = 0;
	// Print shortest distances stored in dist[] 
	/*printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);*/
	for (int i = 0; i < V; i++) {
		sum_SP += dist[i];
	}
	return sum_SP;
}
 
// Driver program to test methods of graph class 
int main()
{
	int number_nodes, number_edges, weight, first, second;
	cin >> number_nodes >> number_edges;
	vector<iPair > adj[9];
 
	// making above shown graph 
	vector<int>SP;
	for (int i = 0; i < number_edges; i++) {
		cin >> first >> second >> weight;
		addEdge(adj, first, second, weight);
	}
 
	for (int i = 0; i < number_nodes; i++) {
		SP.push_back(shortestPath(adj, number_nodes, i));
		
	}
	for (int i = 0; i < number_nodes; i++) {
		cout<<(long double)(number_nodes-1)/(long double)SP[i]<<endl;
 
	}
	//system("pause");
	return 0;
}