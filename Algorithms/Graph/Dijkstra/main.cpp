#include "../GraphStructure/GraphTable.h"
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <limits>
#include <stack>

struct VGT_Dijkstra : public VertexGraphTable {
	VGT_Dijkstra(int i) : VertexGraphTable(i) , dis(std::numeric_limits<double>::max()){};
	int lastVertexId = -1;
	bool inSet = false;
	double dis;
};

struct EGT_Dijkstra : public EdgeGraphTable {
	EGT_Dijkstra(int s, int t) : EdgeGraphTable(s, t) , weight(1){};
	EGT_Dijkstra(int s, int t, double w) : EdgeGraphTable(s, t), weight(w) {};

	double weight;
};


typedef GraphTable<VGT_Dijkstra, EGT_Dijkstra> CGraph;

class GraphDijkstra : public CGraph{
public:
	GraphDijkstra() {};
	GraphDijkstra(std::vector<VGT_Dijkstra> v, std::vector<EGT_Dijkstra> e) : CGraph(v, e) {};

	std::stack<int> dijkstra(int  v1, int  v2) {
		vertices[v1].dis = 0;
		for (int i = 0; i < vertices.size(); ++i)
		{
			double shortestPathW = std::numeric_limits<double>::max();
			int currentVid = -1;
			for (int j = 0; j < vertices.size(); ++j)
			{
				if ((!vertices[j].inSet) && vertices[j].dis < shortestPathW) {
					shortestPathW = vertices[j].dis;
					currentVid = j;
				}
			}
			if (currentVid == v2) {
				break;
			}
			if (currentVid == -1)
			{
				//v1 and v2 is in different connected component
				return std::stack<int>();
			}

			vertices[currentVid].inSet = true;
			for (int j = 0; j < edges[currentVid].size(); j++)
			{
				int idTaeget = edges[currentVid][j].idTarget;
				if (vertices[idTaeget].dis > vertices[currentVid].dis + edges[currentVid][j].weight) {
					vertices[idTaeget].dis = vertices[currentVid].dis + edges[currentVid][j].weight;
					vertices[idTaeget].lastVertexId = currentVid;
				}
			}
		}

		std::stack<int> shortestPath;
		int vId = v2;
		while (vId != -1)
		{
			shortestPath.push(vId);
			vId = vertices[vId].lastVertexId;
		}
		return shortestPath;
	}
	
private:
	
};


int main(){
	std::vector<VGT_Dijkstra> v = {
		VGT_Dijkstra(0),
		VGT_Dijkstra(1),
		VGT_Dijkstra(2),
		VGT_Dijkstra(3),
		VGT_Dijkstra(4),
		VGT_Dijkstra(5),
		VGT_Dijkstra(6),
		VGT_Dijkstra(7),
		VGT_Dijkstra(8)
	};
	
	std::vector<EGT_Dijkstra> e = {
		EGT_Dijkstra(0,1),
		EGT_Dijkstra(0,3),
		EGT_Dijkstra(0,6),
		EGT_Dijkstra(0,8),
		EGT_Dijkstra(1,2),
		EGT_Dijkstra(1,4),
		EGT_Dijkstra(2,3),
		EGT_Dijkstra(2,4),
		EGT_Dijkstra(2,4),
		EGT_Dijkstra(3,4),
		EGT_Dijkstra(5,7),
		EGT_Dijkstra(7,8)
	};
	
	GraphDijkstra g(v ,e);
	std::stack<int> path = g.dijkstra(2, 7);
	
	while(!path.empty())
	{
		int i = path.top();
		path.pop();
		printf("%d\n", i);
	}
	
}