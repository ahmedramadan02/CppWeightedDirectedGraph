#include <iostream>
#include <ostream>
#include <string>
#include <exception>
#include <memory>
#include "graph.hpp"
#include "GraphSet.hpp"
#include "GraphNode.hpp"
#include "GraphNode2.hpp"
#include "UTest/UTest.h"

//#define _TESTING
//#define _USE_GRAPH_BASE

/* G1
    0 -3-> 1
    1 -5-> 2
    2 -7-> 3
    2 -6-> 4
    3 -5-> 4
    4 -2-> 1 
*/

/* G2
    0 -3-> 1
    0 -1-> 2
    0 -3-> 3
    2 -5-> 3
    1 -7-> 3
    1 -4-> 4
    2 -6-> 3
    3 -3-> 4 
*/

//For the Graph Nodes
static DynamicPlatformD::GraphNodePtr<std::string> first = nullptr;
static DynamicPlatformD::GraphNodePtr<int> last = nullptr;

//For the Nodes
static DynamicPlatformD::NodePtr<std::string> firstNode = nullptr;
static DynamicPlatformD::NodePtr<int> lasttNode = nullptr;

int main(int argc, char** argv){
#ifdef _TESTING
    //Init a new test
	UTEST_init( ":::: WDG Search Test :::" );
    int expectedUId = 0;
    std::string expectedEditedValue = "three";
#endif

#ifdef _USE_GRAPH_BASE
    DynamicPlatformD::GraphSet s; //Set Creates an Ids and keeps unique reference
    DynamicPlatformD::Graph<std::string> g, g3; //test set
    DynamicPlatformD::Graph<int> g2;

    DynamicPlatformD::GraphNode<int> g2Node;
    DynamicPlatformD::GraphNode<std::string> g1Node;
 
    s.GetGraphId(g.get()); // Get unique Id and keep a refernce
    s.GetGraphId(g2.get());
#endif

#ifdef _TESTING
    UTEST_testcase("TEST01: Got Unique ID", AssertEquals(g.getId(), expectedUId));
    std::cout << g.getId() << std::endl;
#endif

#ifdef _USE_GRAPH_BASE
    /* G1 */
    //Vertices
    g.AddVertex("Zero");
    g.AddVertex("One");
    g.AddVertex("Two");
    g.AddVertex("Tree");
    g.AddVertex("Four");
    
    //Edges
    g.AddEdge(0, 1, 3);
    g.AddEdge(1 ,2, 5);
    g.AddEdge(2 ,3, 7);
    g.AddEdge(2 ,4, 6);
    g.AddEdge(3 ,4, 5);
    g.AddEdge(4 ,1, 2);

    /* G2 Data*/
    g2.AddVertex(5);
    g2.AddVertex(1);
    g2.AddVertex(17);
    g2.AddVertex(1000);
    g2.AddVertex(300);
    
    //Edges
    g2.AddEdge(0, 1, 3);
    g2.AddEdge(0 ,2, 1);
    g2.AddEdge(0 ,3, 3);
    g2.AddEdge(2 ,3, 5);
    g2.AddEdge(1 ,3, 7);
    g2.AddEdge(1 ,4, 4);
    g2.AddEdge(3 ,4, 3);
#endif

#ifdef _TESTING
    g.EditVertexData(3, "three");
    UTEST_testcase("TEST02: Edit A Vertex Value", AssertIsStrSame ( g.GetVertexData(3).c_str(), "three" ));
#endif

#ifdef _USE_GRAPH_BASE
    g.DijkstraSPF(1, 4);
    std::cout << g << std::endl;

    g.RemoveEdge(2,4);
    g.DijkstraSPF(1, 4);

    g.DijkstraSPF(0, 3);
    std::cout << g2 << std::endl;

    //Switch Graphs
    //For object based switching, Copy and = Operators might be defined
    //Note: for down_casting, dynamic cast will fail as it sees that 
    //a the graph points to an object of GraphBase!, while it refers to normal Graph
    //It doesn't know what is happening in the background!
    auto gptr = 
            reinterpret_cast< DynamicPlatformD::Graph<std::string>* >(s.GetGraph(0));

    if(gptr)
        gptr->Print();
#endif

#ifndef _USE_GRAPH_BASE
    //Using the LinkedList
    DynamicPlatformD::GraphNode<std::string> gnode1;
    DynamicPlatformD::GraphNode<int> gnode2;


    /* G1 */
    //Vertices
    gnode1.AddVertex("Zero");
    gnode1.AddVertex("One");
    gnode1.AddVertex("Two");
    gnode1.AddVertex("Tree");
    gnode1.AddVertex("Four");
    
    //Edges
    gnode1.AddEdge(0, 1, 3);
    gnode1.AddEdge(1 ,2, 5);
    gnode1.AddEdge(2 ,3, 7);
    gnode1.AddEdge(2 ,4, 6);
    gnode1.AddEdge(3 ,4, 5);
    gnode1.AddEdge(4 ,1, 2);

        /* G2 Data*/
    gnode2.AddVertex(5);
    gnode2.AddVertex(1);
    gnode2.AddVertex(17);
    gnode2.AddVertex(1000);
    gnode2.AddVertex(300);
    
    //Edges
    gnode2.AddEdge(0, 1, 3);
    gnode2.AddEdge(0 ,2, 1);
    gnode2.AddEdge(0 ,3, 3);
    gnode2.AddEdge(2 ,3, 5);
    gnode2.AddEdge(1 ,3, 7);
    gnode2.AddEdge(1 ,4, 4);
    gnode2.AddEdge(3 ,4, 3);

    first = std::make_shared< DynamicPlatformD::GraphNode<std::string> >( std::move(gnode1) );
    last = std::make_shared< DynamicPlatformD::GraphNode<int> >( std::move(gnode2) );
    //first->setNext( last ); //Compliation Error, no suitable user-defined conversion from "DynamicPlatformD::NodePtr<int>" to "DynamicPlatformD::NodePtr<std::__cxx11::string>" exists

    auto gPtr = std::shared_ptr< DynamicPlatformD::Graph<std::string> >( new DynamicPlatformD::Graph<std::string>() );
    DynamicPlatformD::Node<std::string> node1;
    firstNode = std::make_shared< DynamicPlatformD::Node<std::string> >( std::move(node1) );

    DynamicPlatformD::Node<int> node2;
    lasttNode = std::make_shared< DynamicPlatformD::Node<int> >( std::move(node2) );
    
    //firstNode->setNext( lasttNode ); //Compliation Error, no suitable user-defined conversion from "DynamicPlatformD::NodePtr<int>" to "DynamicPlatformD::NodePtr<std::__cxx11::string>" exists

#endif

#ifdef _TESTING
    //Get Report
	UTEST_report();
#endif

    return 0;
}