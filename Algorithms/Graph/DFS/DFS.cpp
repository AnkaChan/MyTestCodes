#include "../GraphStructure/GraphTable.h"
#include <iostream>
#include <queue>
typedef GraphTable<VertexGraphTable, EdgeGraphTable> CGraph;

class GraphDFS : public CGraph{
public:
	GraphDFS() {};
	GraphDFS(std::vector<VertexGraphTable> v, std::vector<EdgeGraphTable> e) : CGraph(v, e) {};

	void DFS(){
		VertexGraphTable & v = vertices.front();
		vertexVisited = std::vector<bool>(vertices.size(), false);
		nodeDFS(v);
	}
	
	void nodeDFS(VertexGraphTable & v){
		printf("%d\n", v.id);
		vertexVisited[v.id] = true;
		for (int i = 0; i < edges[v.id].size(); ++i){
			int idTarget = edges[v.id][i].idTarget;
			if (!vertexVisited[idTarget]){
				nodeDFS(vertices[idTarget]);
				
			}
		}
	}
	
private:
	std::vector<bool> vertexVisited;
	
};

class GraphBFS : public CGraph {
public:
	GraphBFS() {};
	GraphBFS(std::vector<VertexGraphTable> v, std::vector<EdgeGraphTable> e) : CGraph(v, e) {};

	void BFS() {
		vertexVisited = std::vector<bool>(vertices.size(), false);
		nodesQ.push(vertices.front().id);
		vertexVisited[0] = true;
		while (!nodesQ.empty())
		{
			int vId = nodesQ.front();
			nodesQ.pop();
			printf("%d\n", vId);
			for (int i = 0; i < edges[vId].size(); i++)
			{
				if (!vertexVisited[edges[vId][i].idTarget])
				{
					nodesQ.push(edges[vId][i].idTarget);
					vertexVisited[edges[vId][i].idTarget] = true;
				}
			}
		}
	}
private:
	std::queue<int> nodesQ;
	std::vector<bool> vertexVisited;

};

int main(){
	std::vector<VertexGraphTable> v = {
		VertexGraphTable(0),
		VertexGraphTable(1),
		VertexGraphTable(2),
		VertexGraphTable(3),
		VertexGraphTable(4),
		VertexGraphTable(5),
		VertexGraphTable(6),
		VertexGraphTable(7),
		VertexGraphTable(8)
	};
	
	std::vector<EdgeGraphTable> e = {
		EdgeGraphTable(0,1),
		EdgeGraphTable(0,3),
		EdgeGraphTable(0,6),
		EdgeGraphTable(0,8),
		EdgeGraphTable(1,2),
		EdgeGraphTable(1,4),
		EdgeGraphTable(2,3),
		EdgeGraphTable(2,4),
		EdgeGraphTable(2,4),
		EdgeGraphTable(3,4),
		EdgeGraphTable(5,7),
		EdgeGraphTable(7,8)
	};
	
	GraphDFS g(v ,e);
	g.DFS();

	GraphBFS g2(v, e);
	g2.BFS();
	
}