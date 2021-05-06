#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class abstractGraph
{
protected:
	typedef int32_t vertex_t;
	int vertexes_number, edges_number;
public:
	abstractGraph() : vertexes_number(0), edges_number(0) {}
	virtual void input() = 0;
	virtual void print() const = 0;
};

//превый тип хранения графи ввиде спика ребер
class Graph_type1 : public abstractGraph
{
private:
	set<pair<vertex_t, vertex_t>> set_of_edges;
public:
	Graph_type1() : abstractGraph() {}
	void input() override
	{
		cin >> vertexes_number;
		cin >> edges_number;
		set_of_edges.clear();
		for (vertex_t i = 0; i < edges_number; i++)
		{
			vertex_t a, b;
			cin >> a >> b;
			set_of_edges.insert(make_pair(a, b));
		}
	}
	void print() const override
	{
		cout << "Vertexes number = " << vertexes_number << endl;
		for (auto edge : set_of_edges)
		{
			cout << "(" << edge.first << ", " << edge.second << ") ";
		}
		cout << endl;
	}
};

//второй тип хранения графа ввиде матрицы смежности
class Graph_type2 : public abstractGraph
{
private:
	vector<vector<bool>> matrix; //matrix of adjacency
public:
	Graph_type2() : abstractGraph() {}
	void input() override
	{
		cin >> vertexes_number;
		cin >> edges_number;
		matrix.assign(vertexes_number, vector<bool>(vertexes_number));
		for (vertex_t i = 0; i < edges_number; i++)
		{
			vertex_t a, b;
			cin >> a >> b;
			matrix[a][b] = 1;
			matrix[b][a] = 1;
		}
	}
	void print() const override
	{
		cout << "Vertexes number = " << vertexes_number << endl;
		for (vertex_t a = 0; a < vertexes_number; a++)
		{
			for (vertex_t b = 0; b < vertexes_number; b++)
			{
				cout << matrix[a][b] << " ";
			}
			cout << endl;
		}
	}
};

//третий тип хранения графа ввиде списка смежности
class Graph_type3 : public abstractGraph
{
private:
	map <int, set<vertex_t>> list; //list of adjecency
public:
	Graph_type3() : abstractGraph() {}
	void input() override
	{
		cin >> vertexes_number;
		cin >> edges_number;
		list.clear();
		for (vertex_t i = 0; i < edges_number; i++)
		{
			vertex_t a, b;
			cin >> a >> b;
			list[a].insert(b);
			list[b].insert(a);
		}
	}
	void print() const override
	{
		cout << "Vertexes number = " << vertexes_number << endl;
		for (auto vertex : list)
		{
			cout << vertex.first << ": { ";
			for (auto adjacent_vertex : vertex.second)
			{
				cout << adjacent_vertex << " ";
			}
			cout << "}" << endl;
		}
	}
};

int main()
{
	Graph_type1 g1;
	g1.input();
	g1.print();
	Graph_type2 g2;
	g2.input();
	g2.print();
	Graph_type3 g3;
	g3.input();
	g3.print();
	return 0;
}