#ifndef GRAPH_FILE_H
#define GRAPH_FILE_H

#include <ostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include "vertex.hpp"

namespace DynamicPlatformD {

class GraphBase {
public:
    //virtual ~ParameterBase() {}
    GraphBase* get() const; 
    virtual int getId() { return this-> guid;}
    virtual void setId(int valId) { this-> guid = valId;}
protected:
int guid = 0;
};

//Forward Decleration to make the << operator works, 
//otherwise linking error
template <typename T> class Graph;
template <typename T>
std::ostream & operator<< (std::ostream &out, const Graph<T> &g);

template <typename T>
class Graph : GraphBase{
public:
    Graph(){}
    Graph(const Graph &_g);
    
    Graph& operator= (const Graph &t);
    int AddVertex(T value);
    void EditVertexData(int vertex_id, T value);
    void AddEdge(int start_id, int end_id, double cost = 0);
    void RemoveEdge(int start_id, int end_id);
    const T & GetVertexData(unsigned int vertex_id) const;
    std::vector<int> GetAllVertexIDs() const;
    const Vertex<T>& GetVertex(int verId) const;
    void Print() const;

    //Seaches for a vertex with a certian value with starting node
    std::vector<int> DijkstraSPF(int start_id, int target_node) const;
    
    //TODO: Separate the Alogs and add A*, Bellman–Ford, ...

    ~Graph();

    //Implemet a function in class base
    //GraphBase* get() {return dynamic_cast<Graph<T>*>(this); }
    GraphBase* get() {return this; }
    int getId() final { return this-> guid;}
    void setId(int valId) final { this-> guid = valId;}

    //TODO: Fix linking error
    friend std::ostream & operator<< <>(std::ostream &out, const Graph<T> &g); 
protected:
    //use vectors for fast access
    std::vector< Vertex<T> > vertices;

};

}

#include "graph.cpp"
#endif


