#include "GraphSet.hpp"

namespace DynamicPlatformD {

GraphBase* GraphSet::GetGraph(int guid){
    //TODO: this function should define a 
    //dynamic memeory through smart pointers
	//std::make_shared();
    GraphBase* temp = nullptr;

    if(guid < GRAPH_SIZE)
        temp = setPtr[guid];

    return temp;
}

int GraphSet::GetGraphId(GraphBase* b) {
    int rtValue=-1;    
    
    //Check first if the graph already in the set, then return it
    bool found = false;    
    for(auto& ptr: setPtr){
        if(ptr == b){
            rtValue = ptr->getId(); //Return the found graph id
            break;
        }
    }

    if(!found && (setPtr.size() < GRAPH_SIZE)){
        //Assing a new id
        int sz = setPtr.size();
        b->setId(sz);
        setPtr.push_back(b);
        rtValue = sz;
    }

    return rtValue;
}

}