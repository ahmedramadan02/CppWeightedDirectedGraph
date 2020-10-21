#ifndef GRAPHSET_FILE_H
#define GRAPHSET_FILE_H
#include <vector>
#include <memory>
#include "graph.hpp"

#define GRAPH_SIZE 10000

namespace DynamicPlatformD {

enum GraphType {
    ginteger,
    gfloat,
    gdouble,
    gcharacter,
    gstring
};

class GraphSet{
public:
    GraphSet(){}
    int GetGraphId(GraphBase* b);;
    GraphBase* GetGraph(int uid);
    //TOTRY: std::shared_ptr<GraphSet> GetGraph(int uid);

private:
    std::vector < GraphBase* > setPtr;
                    
};

}

#include "GraphSet.cpp"

#endif



