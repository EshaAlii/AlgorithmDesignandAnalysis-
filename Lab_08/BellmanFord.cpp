#include <iostream>
#include <vector>

using namespace std;

// Make Infinity a global var to use throughout our functions
int Infinity = 2147483647;

// Struct defining an Edge in BellmanFord
struct BFE{
  // Source of an Edge (is 0)
  int source;

  // Determined vertex of an Edge (anything aside from source)
  int determined;

  // Weight of an edge w(source, determined)
  int weight;
};

// Struct defining a Graph in BellmanFord
struct BFG{
  // Number of Vertices
  int VerticesNum;

  // Number of Edges
  int EdgesNum;

  // Array of edges that make up our graph
  struct BFE* edges;
};

// Struct pointer which Builds our Graph
struct BFG* BuildBFG(int VerticesNum, int EdgesNum){

  // First we define a new graph called BuiltGraph
  struct BFG* BuiltGraph = new BFG;

  // We then intialize it to point to Number of Vertices/Edges and make it equal to Number of Vertices/Edges (Similar to HashTable Constructor)
  BuiltGraph->VerticesNum = VerticesNum;
  BuiltGraph->EdgesNum = EdgesNum;

  // We then define our edges
  BuiltGraph->edges = new BFE[EdgesNum];

  // And return our graph
  return BuiltGraph;
}

// Intialize Single Source Function
void InitializeSingleSource(struct BFG *BuiltGraph, int source, vector<int> &ReachedDistance){
  
  // For every Vertex in the graph...
  for (int i = 0; i < BuiltGraph->VerticesNum; i++){
    
    // We will initially say the distance to it is infinite (aka its unreachable)
    ReachedDistance[i] = Infinity;
  }
  // And then make our source Vertex the only one to be zero
  ReachedDistance[source] = 0;
}

// Relax Function
void Relax(int s, int d, int w, vector<int> &ReachedDistance){
  
  // If the distance of Determined Vertex (aka the one aside from our source) is greater than Distance of Source Vertex + weight & if Distance of Source Vertex is not Infinite ...
  if (ReachedDistance[d] > ReachedDistance[s] + w  && ReachedDistance[s] != Infinity){
    
    // Distance of Determined Vertex is equal to the Distance of Source Vertex + weight
    ReachedDistance[d] = ReachedDistance[s] + w;
  }
}

// Bellman Ford Algorithm Function
void BellmanFordAlgo(struct BFG* BuiltGraph, int source){
  
  // Intialize the Vertices of our Graph + Edges of our Graph
  int VerticesNum = BuiltGraph->VerticesNum;
  int EdgesNum = BuiltGraph->EdgesNum;

  // Intialize the distance between each Vertices
  vector<int> ReachedDistance(VerticesNum);

  // Intiailize the Source of our distance + the rest of the vertices
  InitializeSingleSource(BuiltGraph, source, ReachedDistance);

  // For each Vertex in the Graph
  for (int i = 0; i < VerticesNum; i++){

    // For each Edge in the Graph
    for (int j = 0; j < EdgesNum; j++){

      // Intialize the source, determined (vertex), and weight of our edges 
      int s = BuiltGraph->edges[j].source;
      int d = BuiltGraph->edges[j].determined;
      int w = BuiltGraph->edges[j].weight;

      // Determine the distance of our yet to be determined vertices
      Relax(s, d, w, ReachedDistance);
      
    }
  }

  // For each Edge in the Graph
  for (int i = 0; i < EdgesNum; i++){

    // Intialize the source, determined (vertex), and weight of our edges
    int s = BuiltGraph->edges[i].source;
    int d = BuiltGraph->edges[i].determined;
    int w = BuiltGraph->edges[i].weight;

    // If Distance of Source Vertex is not Infinite & distance of Determined Vertex (aka the one aside from our source) is greater than Distance of Source Vertex + weight...
    if (ReachedDistance[d] > ReachedDistance[s] + w  && ReachedDistance[s] != Infinity){

      // We state it has a negative weight cycle and output FALSE
      cout << "FALSE" << endl;

      // We then end the function
      return;
    }
  }

  // Otherwise we will output TRUE
  cout << "TRUE" << endl;

  // And Print the distance of each Vertex of the graph
  
  // For each Vertex in our Graph...
  for (int i = 0; i < VerticesNum; i++){

    // If the distance to the Vertex = Infinity (aka unreachable) print out Infinity
    if (ReachedDistance[i] == Infinity){
      cout << "INFINITY" << endl;
    }
      
    // Otherwise we print out the actual distance number
    else{
      cout << ReachedDistance[i] << endl;
    }
  }

  // We then end the function
  return;
  
}

// Main Function
int main(){

  // Intiailize the Number of Vertices and Number of Edges for our graph
  int VerticesNum;
  int EdgesNum;

  // Get User Input
  cin >> VerticesNum >> EdgesNum;

  // Create a graph called BuiltGraph
  struct BFG* BuiltGraph = BuildBFG(VerticesNum, EdgesNum);

  // For each Edge in the Graph
  for (int i = 0; i < EdgesNum; i++){

    // We take in the source, the determined vertex, and the weight of each entry
    cin >> BuiltGraph->edges[i].source >>  BuiltGraph->edges[i].determined >> BuiltGraph->edges[i].weight;

  }

  // We then call our BellmanFord Function
  BellmanFordAlgo(BuiltGraph, 0);

  // End Program
  return 0;
}