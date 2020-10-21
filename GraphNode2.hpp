#ifndef GraphNode2_FILE_H
#define GraphNode2_FILE_H

#include "graph.hpp"

namespace DynamicPlatformD{

// template <template<class> class H, class GraphNode = GraphNode>

template <typename T> class Graph; 
template <typename T>
using GraphPtr = std::shared_ptr< Graph<T> >; //C++ equivlant typedef, template aliasing

template <typename T> class Node;
template <typename T>
using NodePtr = std::shared_ptr< Node<T> >;

template<typename T>
class Node {
public:
    Node() {}
 
    GraphPtr<T> getGraph(){ return this->current; }
    void setGraph(GraphPtr<T> _graph) { this->current = _graph; }

    NodePtr<T> getNext(){ return this->next; }
    void setNext(NodePtr<T> _next) { this->next = _next; }

    NodePtr<T> getPrevious(){ return this->prev; }
    void setPrevious(NodePtr<T> _prev) { this->prev = _prev; }

    ~Node() {}
private:
    GraphPtr<T> current = nullptr;

    NodePtr<T> next = nullptr; // Pointer to next node in DLL 
    NodePtr<T> prev = nullptr; // Pointer to previous node in DLL

    //TODO: static Counter for uid used to increament in copy, keep in move
    //and decrement in destructtor
    static size_t gidCounter;
};

template<typename T>
GraphPtr<T> Find(GraphPtr<T> first, unsigned int gid){
    auto temp = first;
    while(temp->getNext() != nullptr ){
        if(temp->g.getId() == gid){
            break;
        }
    }

    return temp;
}

template<typename T>
void PushAfter(GraphPtr<T> first, unsigned int after){

}

}

#include "GraphNode.cpp"

#endif