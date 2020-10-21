#include "graph.hpp"
#include <queue>
#include <utility>
#include <limits>
#include <iostream> //to be removed

namespace DynamicPlatformD {

//The copy constructor
template <typename T>
Graph<T>::Graph(const Graph<T> &_g){

}

//TODO: Avoid shallow copying The equal operator
template <typename T>
Graph<T>& Graph<T>::operator= (const Graph &t) {


}

//TODO: Avoid shallow copying The move constructor

//TODO: Avoid shallow copying The move asignement operator

template <typename T>
int Graph<T>::AddVertex(T value){
    //TODO: GetUniqueId() function
    unsigned int currentIndex = -1;
    size_t s = this->vertices.size();
    currentIndex = (unsigned int)s; //the index of the current added element
    this->vertices.push_back( Vertex<T>(currentIndex, value) );    

    return currentIndex;
}

template <typename T>
void Graph<T>::EditVertexData(int vertex_id ,T value){
    for(auto & vi : vertices)
        if (vertex_id == vi.GetId()) 
            vi.SetData(value);
}

template <typename T>
void Graph<T>::AddEdge(int start_id, int end_id, double cost){
    for(auto & vi : vertices)
        if (start_id == vi.GetId()) 
            vi.AddEdge(end_id, cost);
}

template <typename T>
void Graph<T>::RemoveEdge(int start_id, int end_id){
    for(auto & vi : vertices)
        if (start_id == vi.GetId()) 
            vi.RemoveEdge(end_id);
}

template <typename T>
const T & Graph<T>::GetVertexData(unsigned int vertex_id) const{
    //T rtValue;
    for(auto & vi : vertices)
        if (vertex_id == vi.GetId())
            return vi.GetData();
}

template <typename T>
std::vector<int> Graph<T>::GetAllVertexIDs() const {
    std::vector<int> v;
    for( auto & vi : this->vertices ) {
        v.push_back(vi.GetId());
    }    

    return v;
}

template <typename T>
const Vertex<T>& Graph<T>::GetVertex(int verId) const{
    //Vertex<T> rtValue;
    for(auto & vi : vertices)
        if (verId == vi.GetId())
            return vi;

    //return rtValue; //Segmentation fault, may be = and copy constructor needed
}

//get distance to all vertices
//TOD: Implement the Algoirthm separatly out of the Graph object
template <typename T>
std::vector<int> Graph<T>::DijkstraSPF(int start_id, int target_node) const{
    //Vars
    std::vector<int> rtValue; //Holds the Ids of the Path as a return value
    size_t sz = this->vertices.size();
    std::priority_queue< std::pair<int,int>  > q; //to sort max
    Vertex<T> av;
    bool found = false;
    int distances[sz];
    
    //Init all to INFINITY
    for (int i = 0; i <= sz - 1; i++){
        distances[i] = std::numeric_limits<int>::max(); //set the distance to all points to infinity
        //use const cast as the function is const safe
        const_cast<Graph<T>*>(this)->vertices[i].SetVisited(false); //TODO: instead you can take a copy of vertices to work with, or to make a local processed[] array
    }

    av = this->GetVertex(start_id);

    //if found, set to zero and start search 
    //Set Distance of staring point to 0
    distances[start_id] = 0; //the distance of the start node is 0
    q.push({0,start_id});    //Push the start node to the queue

    std::cout << start_id << "->";
    while (!q.empty() && !found) {
        int a = q.top().second; q.pop(); //Get the vertex with lowerst cost, and pop
        rtValue.push_back(a);
        av = this->GetVertex(a);
        int cost = 0;
        if (av.GetVisited()) continue; //if the node is already visited then skip
        av.SetVisited(true);
        for (auto &u : av.GetEdges()) {
            int b = u.GetDestID(), cost = u.GetCost();
            std::cout << b << "->";
            if (distances[a]+cost < distances[b]) { //Assign every node cost,if it's lower then what it have (initially it was INF)
                distances[b] = distances[a]+cost;
                q.push({-distances[b],b}); //the -ve sign to revert the queue
            }

            //If we already found the target
            if(target_node == b){
                found = true;
                break;
            }
        }
    }
    if(found){
        T data = this->vertices[target_node].GetData();
        std::cout << "none=" << typeid(data).name() << ":" << target_node << std::endl;
    }

    return rtValue; //Segemetation Fault gone when this return value is defined, Woow !!!   
}

template <typename T>
void Graph<T>::Print() const{
    std::cout << "ID: "<< "G_" << guid << std::endl;
    
    //Print Vertices
    std::cout << "V: ";
    size_t sz = vertices.size();
    for(auto &vi : vertices){
        std::cout << vi.GetId() << ' ';
    }
    std::cout << std::endl;

    //Print the edges
    std::cout << "E: [{";
    for(auto &vi : vertices){
        std::cout << vi.GetId() << ": (";
        for( auto &edge : vi.GetEdges() ){
            std::cout <<edge.GetDestID() << ',';
        }
        std::cout << "none), ";
    }
    std::cout << "}]" << std::endl;
}

template<typename T>
std::ostream & operator<<(std::ostream &out, const Graph<T> &g){
    out << "ID: "<< "G_" << g.guid << std::endl;
    
    //Print Vertices
    out << "V: ";
    for(auto &vi : g.vertices){
        out<< vi.GetId() << ' ';
    }
    out << std::endl;

    //Print the edges
    out << "E: [{";
    for(auto &vi : g.vertices){
        out << vi.GetId() << ": (";
        for( auto &edge : vi.GetEdges() ){
            out <<edge.GetDestID() << ',';
        }
        out << "none), ";
    }
    out << "}]" << std::endl;
    
    return out;
}

template<typename T>
Graph<T>::~Graph(){


}

}



