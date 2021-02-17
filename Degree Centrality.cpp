#include<iostream>
#include <vector>
#include<string>
using namespace std;
class edge {
 
	private:
		int value;
		int first;
		int second;
	public:
		void set_value(int d) { value = d; }
		int get_value() { return value; }
		int get_first() { return first; }
		void set_first(int f) { first = f; }
		int get_second() { return second; }
		void set_second(int s) { second = s; }
};
 
class node {
private:
	int name;
	int degree_center;
public:
	void set_degree(int degree) { degree_center = degree; }
	int get_name() { return name; }
	int get_degree() { return degree_center; }
	void set_name(int n) { name = n; }
};
vector<node> get_center(vector<node>nodes,vector<edge>a,int number_edges) {
	int degree = 0;
	/*for (int i = 0; i < number_edges;i++) {
		for (int j = i; j < number_edges;j++) {
			if (a[i].get_first()==a[j].get_second()||a[i].get_second()==a[j].get_first()) {
				degree++;
			}
		}
	}*/
	for (int j = 0; j < nodes.size(); j++) {
		for (int i = 0; i < number_edges; i++) {
			if (nodes[j].get_name() == a[i].get_first() || nodes[j].get_name() == a[i].get_second())degree++;
		}
		nodes[j].set_degree(degree);
		degree = 0;
	}
	return nodes;
}
int main() {
	int number_nodes, number_edges;
	int first,second,edge_value;
	vector<edge> edges;
	vector<node>nodes;
	//vector<pair<int,int>>edges;
	cin >> number_nodes >> number_edges;
 
	for (int i = 0; i < number_edges; i++) {
		cin >> first>>second>>edge_value;
		//edges.push_back(make_pair(first,second));
		edge a;
		a.set_first(first);
		a.set_second(second);
		a.set_value(edge_value);
		edges.push_back(a);
	}
	for (int it = 0; it < number_nodes;it++) {
		node as;
		as.set_name(it);
		nodes.push_back(as);
	}
	nodes=get_center(nodes, edges, number_edges);
	for (int itt = 0; itt < nodes.size(); itt++)
	{
		cout << nodes[itt].get_degree()<<"\n";
	}
	/*for (int i = 0; i < number_edges; i++)
		cout << edges[i].get_value() << endl;*/
	//system("pause");
	return 0;
}