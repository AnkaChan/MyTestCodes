#include <vector>
struct VertexGraphTable{
	VertexGraphTable(int i) : id(i) {};
	int id;
};

struct EdgeGraphTable{
	EdgeGraphTable(int s, int t) : idSource(s), idTarget(t) {};
	int idSource;
	int idTarget;
};

template<typename V, typename E> 
class GraphTable{
public:
	GraphTable() {};
	GraphTable(std::vector<V> & inVertices, std::vector<E> inEdges, bool inIsDirected = false){
		vertices = inVertices;
		edges.resize(vertices.size());
		
		isDirected = inIsDirected;
		
		for (int i = 0; i < inEdges.size(); ++i){
			edges[inEdges[i].idSource].push_back(inEdges[i]);
			if (!isDirected){
				E eDual = inEdges[i];
				eDual.idSource = inEdges[i].idTarget;
				eDual.idTarget = inEdges[i].idSource;
				edges[eDual.idSource].push_back(eDual);
			}
		}
	}
	

	
protected:
	std::vector<V> vertices;
	std::vector<std::vector<E>> edges;
	
	bool isDirected = false;
};
