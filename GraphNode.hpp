#ifndef GraphNode_FILE_H
#define GraphNode_FILE_H

#include "graph.hpp"

namespace DynamicPlatformD{

// template <template<class> class H, class GraphNode = GraphNode>

template <typename T> class GraphNode; 
template <typename T>
using GraphNodePtr = std::shared_ptr< GraphNode<T> >; //C++ equivlant typedef, template aliasing


template<typename T>
class GraphNode : public Graph<T> { //A node is a graph.
public:
    GraphNode() : Graph<T>(){ }
 
    GraphNodePtr<T> getNext(){ return this->next; }
    void setNext(GraphNodePtr<T> _next) { this->next = _next; }

    GraphNodePtr<T> getPrevious(){ return this->prev; }
    void setPrevious(GraphNodePtr<T> _prev) { this->prev = _prev; }

    ~GraphNode() {}
private:
    
    GraphNodePtr<T> next = nullptr; // Pointer to next node in DLL 
    GraphNodePtr<T> prev = nullptr; // Pointer to previous node in DLL

    //TODO: static Counter for uid used to increament in copy, keep in move
    //and decrement in destructtor
    static size_t gidCounter;
};

template<typename T>
GraphNodePtr<T> Find(GraphNodePtr<T> first, unsigned int gid){
    auto temp = first;
    while(temp->getNext() != nullptr ){
        if(temp->g.getId() == gid){
            break;
        }
    }

    return temp;
}

template<typename T>
void PushAfter(GraphNodePtr<T> first, unsigned int after){

}

}

#include "GraphNode.cpp"

#endif