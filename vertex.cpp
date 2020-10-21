#include "vertex.hpp"
#include <algorithm>

namespace DynamicPlatformD {

template <typename T>
void Vertex<T>::AddEdge(int end_id, double cost){
    this->edges.push_back(Edge(end_id, cost));
}

template <typename T>
const std::vector<Edge> & Vertex<T>::GetEdges() const{
    return this->edges;
}

template <typename T>
void Vertex<T>::RemoveEdge(int end_id){
    auto p = this->edges.begin();
    for (auto p = this->edges.begin(); p != this->edges.end(); ++p)
        if((*p).GetDestID() == end_id) break;  

    edges.erase(p); //You can't erase while looping
      
    //Another way won't work
    //std::remove(edges.begin(), edges.end(),*p);//Overload the == operator
    //TODO: Remove dosen't change the size
}

}