#include <iostream>
#include "Triangle.h"
#include "Edge.h"
#include "Point.h"
#include "tetra.h"

#include <array>
#include <vector>
#define N 3

//allTriangle recieve all Triangle from the mesh  meshTetra
void getAllTriangle(std::set<Triangle<N>> & allTriangle,const std::set<tetra<N>> &  meshTetra){
        std::vector<std::set<Triangle<N>>> vectorTriangle;
	//get the Triangles from each tetrahedron of the mesh
        for(auto s:meshTetra) {
            vectorTriangle.push_back(s.getTriangle());
        }
	//add all the Triangle on a set
        for(auto st:vectorTriangle) {
            for(auto s:st){
                allTriangle.insert(s);
            }
        }
}

//boundary recieve all Triangle from the boundary of the mesh meshTetra
void getBoundary(  std::set<Triangle<N>> & boundary, const std::set<tetra<N>> &  meshTetra){
        std::vector<std::set<Triangle<N>>> vectorTriangle;
        std::pair<std::set<Triangle<N>>::iterator,bool> ret;
	//get the Triangles from each tetrahedron of the mesh
        for(auto s:meshTetra) {
            vectorTriangle.push_back(s.getTriangle());
        }
	//add all the Triangle on a set
        for(auto st:vectorTriangle) {
            for(auto s:st){
                ret = boundary.insert(s);
                if(!ret.second) boundary.erase(s);
            }
        };
    }

int main(){

    //gera Mesh
    Point<N> p1({0.,0.,0.});
    Point<N> p2({1.,0.,0.});
    Point<N> p3({0.,1.,0.});
    Point<N> p4({0.,0.,1.});
    Point<N> p5({1.,1.,1.});
    tetra<N> te1({p1,p2,p3,p4});
    tetra<N> te2({p2,p3,p4,p5});
    std::set<tetra<N>> meshTetra({te1,te2});

    //Search AllEdge and Boundary
    std::set<Triangle<N>> allTriangle;
    getAllTriangle(allTriangle,meshTetra);
    std::set<Triangle<N>> boundary;
    getBoundary(boundary,meshTetra);

    //Print AllEdge and Boundary
    std::cout << "All triangle" << std::endl;
    for(auto s:allTriangle) std::cout << s << std::endl;
    std::cout << "Boundary triangle" << std::endl;
    for(auto s:boundary) std::cout << s << std::endl;



    return 0;
}


