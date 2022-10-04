//This file will represent the a_star algorithm, using nodes and length of 1 for the edges
/*
------------- How It Works ------------------
Starting at the end start node begin to create a path to the end node.
This occurs by setting every nodes positon (x, y) on the graph in addition to if it's an obstacle
After setting up all the nodes add the start node to a list of nodes that need to be checked making it visited.
Then go through the list of nodes with a repeated process for each one, First sort the list of nodes by global value(I'll explain in one second)
Next, check to see if it's neighbors have been visited. If it hasn't been visited and isn't an obstacle then add it to the list.

After being added to the list we will determine two values, a local and global, the local is always the current node's local
plus the distance between nodes in this format it is 1, if that local is less than the neighbor's local value then it will become the
neighbor's local value. Additionally because the current node's local value is less than the neighbor's, the neighbor's parent node will
become the current node. These details are important when finding the shortest path, this neighbor node then gets a global value equal to the heuristic.
The heuristic is a guess from this neighbor node to the ending node, using the pythagorem theorm. 

This process will then repeat until either the nodes to check list is empty or we find the end node, technically to find the maximum shortest path
the user could ignore finding the end node, but this would then cost more time and slightly more resources.

------------- How It Works ------------------

-------------Inputs---------------------
During this example the nodes lay on a 64 x 32 grid as it is the easiest way to use this algorithm, but each of the nodes have already been determined.
Therefore, this algorithm requires two things, the end and start nodes, specifically their positions.
As a bonus you can also add some obstacle nodes to change and observe the path
-------------Inputs---------------------

-------------Time and Space------------
Where e = edges, v = vertices

Time: O(e)
Space: O(v)

-------------Time and Space------------

*/

//List of Standard Libraries Needed
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <cmath>
#include <array>
#include <cfloat>

//This is a Node Class for our a_star algoirthm

class Node {
    public:
    //Position of the node
    unsigned short x_coord;
    unsigned short y_coord;
    //Node Requirements to see if they're valid
    bool visited = false;
    bool obstacle = false;

    //Global Val is the f(x), Local Val is the g(x)
    float global_val = FLT_MAX;
    float local_val = FLT_MAX;

    std::vector<Node*> neighbors;
    Node* parent = nullptr;
};



//Need to use a vector of points because we need to allocate based on start and end points

//Need to access every node to change them
//The nice part about arrays is that they're preallocated
std::array<Node, 2048> grid;

//Need a certain start and stop
Node* start_node = nullptr;
Node* end_node = nullptr;
Node* current_node = nullptr;

// ---------------------- Search Alogirthms ------------------- //

void create_astar();
std::vector<Node> create_path();

// ---------------------- Search Alogirthms ------------------- //

unsigned short grid_height = 32;
unsigned short grid_length = 64;


void create_astar()
{
    //Clear the grid excess features
    //This grid represents a 2D map with length 64, width 32
    for(int x = 0; x < grid_length; x++)
        for(int y = 0; y < grid_height; y++){
            grid.at(y * grid_length + x).local_val = INFINITY;
            grid.at(y * grid_length + x).global_val = INFINITY;
            grid.at(y * grid_length + x).visited = false;
            grid.at(y * grid_length + x).parent = nullptr;
        }

    //Create a heurisitic function that will determine the distance from current_node to end_node
    //This is needed to estimate a total distance when determining the faster route
    auto heuristic = [](Node* cur_node, Node* end_node){
        float x_distance = cur_node->x_coord - end_node->x_coord;
        float y_distance = cur_node->y_coord - end_node->y_coord;

        //Square these values
        x_distance *= x_distance;
        y_distance *= y_distance;

        float final_return = sqrt(x_distance + y_distance);

        return final_return;
    };


    //Must Inititalize starting node  
    start_node->local_val = 0.0f; //It's 0 distance from the start
    start_node->global_val = heuristic(start_node, end_node);

    //Create a list which all the nodes that need to be reviewed, go in
    std::list<Node*> NodesToCheck;
    NodesToCheck.push_back(start_node);

    current_node = start_node;

    //This loop ends when the path is from start_node to the end_node
    while(!NodesToCheck.empty() && current_node != end_node){
        //Global_Val = g(n) + h(n) : h is the heurisitc, g is the cost of the path from start to nth node

        //At each step sort, and remove the node with the lowest global_val, the f and g of neighbors are then updated
        NodesToCheck.sort([](Node* rhs, Node* lhs){ return lhs->global_val < rhs->global_val; } );

        while(!NodesToCheck.empty() && NodesToCheck.front()->visited)
            NodesToCheck.pop_front();

        if(NodesToCheck.empty())
            break;

        current_node = NodesToCheck.front();
        current_node->visited = true;

        //Neighbors should always be added to the list then marked as visited once hit
        for(auto& neighbor_node : current_node->neighbors){
            if(!neighbor_node->visited && !neighbor_node->obstacle)
                NodesToCheck.push_back(neighbor_node);

            //The local_val always adds 1, because that's the distance between nodes on this graph
            float lowest_value = current_node->local_val + 1.0f;

            if(lowest_value < neighbor_node->local_val){
            //Make this neighbor node a piece of the path by setting up it's value
                neighbor_node->parent = current_node;
                neighbor_node->local_val = lowest_value;

                neighbor_node->global_val = heuristic(neighbor_node, end_node);
            }
        }

    }
}