#include <iostream>
#include "Triangle.h"
#include "Edge.h"
#include "Point.h"
#include "tetra.h"

#include <array>
#include <vector>
#define N 2

//alledge recieve all edge from the mesh  meshT
void getAllEdge(std::set<Edge<N>> & alledge , const std::set<Triangle<N>> &  meshT){
        std::vector<std::set<Edge<N>>> et;
	//get the edge from each triangle of the mesh
        for(auto s:meshT) {
            et.push_back(s.getEdge());
        }
	//add all the edge on a set
        for(auto st:et) {
            for(auto se:st){
                alledge.insert(se);
            }
	}
}

//boundary recieve the edge from the boundary of the mesh  meshT
void getBoundary(std::set<Edge<N>> & boundary ,const std::set<Triangle<N>> &  meshT){
        std::vector<std::set<Edge<N>>> et;
        std::pair<std::set<Edge<N>>::iterator,bool> ret;
	//get the edge from each triangle of the mesh
        for(auto s:meshT) {
            et.push_back(s.getEdge());
        }
	//add all the boundary edge on a set
        for(auto st:et) {
            for(auto se:st){
                ret = boundary.insert(se);
                if(!ret.second) boundary.erase(se);
            }
        }
    }

int main(){

    //gera Mesh
    Point<N> p1({0.,1.});
    Point<N> p2({1.,0.});
    Point<N> p3({0.,0.});
    Point<N> p4({1.,1.});
    Triangle<N> t1({p1,p2,p3});
    Triangle<N> t2({p1,p2,p4});
    std::set<Triangle<N>> meshT({t1,t2});

    //Search AllEdge and Boundary
    std::set<Edge<N>> alledge;
    getAllEdge(alledge,meshT);
    std::set<Edge<N>> boundary;
    getBoundary(boundary,meshT);

    //Print AllEdge and Boundary
    std::cout << "All Edge" << std::endl;
    for(auto s:alledge) std::cout << s << std::endl;
    std::cout << "Boundary Edge" << std::endl;
    for(auto s:boundary) std::cout << s << std::endl;

    return 0;
}


