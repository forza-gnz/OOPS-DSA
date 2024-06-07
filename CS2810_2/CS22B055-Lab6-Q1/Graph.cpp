// Roll Number: CS22B055
// Name: Neeraj Bandhey
// CS2810 Lab Number: 6
// Date: 12th of March , 2024, 2pm
// Question No. 1 (2, etc. as appropriate)
// This submission is based entirely on my efforts. I realize that
// any form of academic dishonesty with respect to the Lab assignment
// will result in
// corrective action imposed by the IIT Madras Senate.
#include<iostream>
using namespace std;
#include"Graph.h"


void Graph::setnodecount(int nodecount){
    nodes = nodecount;
}

int Graph::getnodecount(){
    return nodes;
}

void Graph::setedgecount(int edgecount){
    edges = edgecount;
}

int Graph::getedgecount(){
    return nodes;
}

// void Graph::addedge(int src, int dest, int weight){
//     edges++;
// }

// void Graph::deledge(int src, int dest){
//     edges--;
// }
