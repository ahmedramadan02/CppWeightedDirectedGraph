#ifndef VERTEX_FILE_H
#define VERTEX_FILE_H

#include <vector>
#include "edge.hpp"

namespace DynamicPlatformD {

template <typename T>
class Vertex
{
public:
    Vertex(){}
    Vertex(int id, T value): id(id), data(value) {}
    void AddEdge(int end_id, double cost);
    unsigned int GetId() const { return this->id; }
    const T & GetData() const { return this->data; }
    void SetData(T _newdata) { data = _newdata; }
    const std::vector<Edge> & GetEdges() const;
    void RemoveEdge(int end_id);
    void SetVisited(bool visited) { this->isVisited = visited; }
    bool GetVisited(){ return this->isVisited; }

    //Overriding the < and > and = operators, for the priority queue
    //bool operator <(const Vertex& v) { return this->id < v.id; }

private:
    unsigned int id;
    T data;
    std::vector<Edge> edges;
    bool isVisited = false;
    bool isActive = true;
};

}

#include "vertex.cpp"
#endif