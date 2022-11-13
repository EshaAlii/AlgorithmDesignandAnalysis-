#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

// SCC Class
class SCC{

  // Number of Vertices
  int VerticesNum;

  // Mark our vertex
  bool WHITE = true; // White tells us it is visited
  bool BLACK = false; // Black tells us it is unvisited

  // List of next pointers that point to next/adjacent part of SCC
  list <int> *next;

  public:

  // SCC Constructor
  SCC(int VerticesNum);

  // Our SCC Functions
  void Edges(int vertices, int edges); // Function that includes Edges into our SCC
  void RecursiveDFS(int vertices, vector<bool> &visit, int temp, vector<int> &vect); // Function that creates our DFS Forest
  void FillStack(int vertices, vector<bool> &visit, stack <int> &Stack); // Function to fill our Stack
  void SecondDFS(int temp, vector<int> &vect); // Function to do DFS again with reversed edges
  void PrintSCCID(int VerticesNum, SCC s); // Function to print the ID of the SCC at each Vertex

};

// SCC Constructor (Similar to Chained HashTable Constructor)
SCC::SCC(int VerticesNum){
  
  // Make a pointer to VerticesNum equal to Vertices Num
  this->VerticesNum = VerticesNum;

  // Create a next pointer with VerticesNum
  next = new list<int> [VerticesNum];
}

// Edges Function
void SCC::Edges(int vertices, int edges){
  
  // We add our Edges to our SCC by doing push front
  next[vertices].push_front(edges);
}

// Recursive DFS Function
void SCC::RecursiveDFS(int vertices, vector<bool> &visit, int temp, vector<int> &vect){
  
  // Mark our vertex as visited
  visit[vertices] = WHITE;

  // Assign our temp variable to be equal to that vertex
  vect[vertices] = temp;

  // Predefine our i
  list <int>::iterator i;
  
  // For all vertices next to our current one in our SCC
  for (i = next[vertices].begin(); i != next[vertices].end(); i++){
    
    // If our index wasn't visited...
    if(visit[*i] == BLACK){
      
      // We call RecursiveDFS with this new index in mind
      RecursiveDFS(*i, visit, temp, vect);
    }
  }

}

// Fill Stack Function (Work with Stack separately from DFS, but have a similar process)
void SCC::FillStack(int vertices, vector<bool> &visit, stack<int> &Stack){

  // Mark our vertices as visited
  visit[vertices] = WHITE;

  // Predefine our i
  list<int>:: iterator i;
  
  // For all the vertices next to our current...
  for (i = next[vertices].begin(); i != next[vertices].end(); i++){
    // If it wasn't visited...
    if (visit[*i] == BLACK){
      
      // We recursively call FillStack with our new *i in mind
      FillStack(*i, visit, Stack);
    }
  }

  // We then push our vertices onto our stack
  Stack.push(vertices);
}
// Second DFS Function
void SCC::SecondDFS(int temp, vector<int> &vect){

  // Create our stack
  stack <int> Stack;

  // Redefine our *visit 
  vector<bool> visit(VerticesNum, 0);

  // Mark the vertices as not visited
  for (int i = 0; i < VerticesNum; i++){
    visit[i] = BLACK;
  }

  // Then fill these unvisited vertices in our Stack
  for (int i = 0; i < VerticesNum; i++){
    if (visit[i] == BLACK){
      FillStack(i, visit, Stack);
    }
  }
  
   // Create an SCC called reverse with the total number of Vertices
  SCC reverse(VerticesNum);

  // Predefine our j
  list <int>::iterator j;

  // Until we reach our number of Vertices...
  for (int i = 0; i < VerticesNum; i++){
    
    // For all the vertices next to our current...
    for (j = next[i].begin(); j!= next[i].end(); j++){
      
      // We reverse it by doing push front
      reverse.next[*j].push_front(i);
    }
  }

  // Mark the vertices as not visited
  for (int i = 0; i < VerticesNum; i++){
    visit[i] = BLACK;
  }

  // While the stack isn't empty...
  while(Stack.empty() == false){
    
    // We create a variable called popvertex which is equal to the top of our Stack
    int popvertex = Stack.top();

    // We then pop that number from our stack
    Stack.pop();

    // If that popped vertex wasn't visited...
    if (visit[popvertex] == BLACK){
      
      // We print out our SCC of that vertex
      reverse.RecursiveDFS(popvertex, visit, popvertex, vect);
      
      // We then create a ID variable equal to our popped vertex (always the first number in our SCC)
      int ID = popvertex;

      // For each temp number (aka node) of our SCC...
      for (int i = 0; i < temp; i++){

        // If the poppedvertex is equal to the temp number (node) at that index and our ID is greater than our index...
        if ((vect[i] == popvertex) && (ID > i)){
          
          // We make the index equal to our ID
          ID = i;

          // And we replace the temp number (node) and set our ID number equal at that index...
          vect[i] = ID;
        }
      }
      
    }
  }
  
}

// Function to print the ID of the SCC at each Vertex
void SCC::PrintSCCID(int VerticesNum, SCC s){
  
  // Create a new vector of size VerticesNum and initialize it to 0
  vector<int> vect(VerticesNum, 0);
  
  // We then go through our Second DFS
  s.SecondDFS(VerticesNum, vect);

  // For each Vertex we visit...
  for (int i = 0; i < VerticesNum; i++){

    // We will print out the SCC ID at that Vertex
    cout << vect[i] << endl;
  }
  
}

// Main Function
int main(){
  
  // Take in User input for the number of Vertices
  int VerticesNum;
  cin >> VerticesNum;
  SCC s(VerticesNum);

  // Take in User input for the number of Edges
  int EdgeNum;
  cin >> EdgeNum;

  // Create two integers for our Edges
  int InputOne;
  int InputTwo;

  // Until we reach the number of edges...
  for (int i = 0;i < EdgeNum; i++){
    
    // We constantly take in User input for the edge
    cin >> InputOne >> InputTwo;

    // And place it through our Edges Function
    s.Edges(InputOne, InputTwo);
  }

  // We then print out our SCC IDs at each visited Vertex
  s.PrintSCCID(VerticesNum, s);
  
  // End Program
  return 0;
}