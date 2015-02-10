// C++ Program to check and print Hamiltonian cycle in a graph given by user
#include<iostream>
using namespace std;
 
void printSolution(int path[], int V);
 

void add_edge(int **adj, int origin, int destin, int n)
  {
    if (origin > n || destin > n || origin < 0 || destin < 0)
    {
      cout << "Invalid edge!\n";
    }
    else
    {
      adj[origin - 1][destin - 1] = 1;
      adj[destin - 1][origin - 1] = 1;
    }
  }


bool check_adjacent(int v, int **adj, int path[], int pos)
{
    if (adj [ path[pos-1] ][ v ] == 0)
        return false;
 
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}
 
bool base_case(int **adj, int path[], int pos, int V)
{
    if (pos == V)
    {
        if ( adj[ path[pos-1] ][ path[0] ] == 1 )
           return true;
        else
          return false;
    }
 
    for (int v = 0; v < V; v++)
    {
        if (check_adjacent(v, adj, path, pos))
        {
            path[pos] = v;
 
            if (base_case (adj, path, pos+1, V) == true)
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonian_cycle(int **adj, int V)
{    
     int s;
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
 
    path[0] = s;
    if ( base_case(adj, path, 1, V) == false )
    {
      cout<<"\nOops !! there is no Hamiltonian cycle .";
        return false;
    }
 
    printSolution(path, V);
    return true;
}
 
void printSolution(int path[], int V)
{
    cout<<"Yes I found Hamiltonian cycle shown below :\n";
    for (int i = 0; i < V; i++)
        cout<<path[i]<<"   -->   ";
 
    cout<<path[0]<<"\n";
}
 

  void display(int **adj, int n)
  {
    int i, j;
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        cout << adj[i][j] << "  ";
      cout << endl;
    }
  }

// here comes the main
int main()
{

  int nodes, max_edges, start, end, weight, want, from, ch;
  cout<<"Enter the number of nodes\n";
  cin>>nodes;
   int **adj;

   adj = new int*[nodes];
    for (int i = 0; i < nodes; i++)
    {
      adj[i] = new int[nodes];
      for (int j = 0; j < nodes; j++)
      {
        adj[i][j] = 0;
      }
    }

  max_edges = nodes * (nodes - 1);

  for (int i = 0; i < max_edges; i++)
  {
    cout << "Enter edge (-1 -1 to exit): ";
    cin >> start >> end;
    if ((start == -1) && (end == -1))
    {
      want = 1;
      break;
    }
    add_edge(adj, start, end, nodes);
  }

  while(ch != 0){

      cout<< "###### HAMILTONIAN CYCLE PROGRAM ######\n"
      << "0.EXIT\n"
      << "1.Adjacency matrix\n"
      << "2.Find the Hamiltonian cycle if exist and show the path\n"
      << "Enter your choice ( 0-2 )\n";
    cin >> ch;
    switch (ch)
    {
    case 0: //exit(0);
      break;
    case 1:cout << "The Adjacency matrix of the Graph is :\n";
      display(adj, nodes);
      break;
    case 2: hamiltonian_cycle(adj, nodes);
      break;
    default:cout << "wake up you entered wrong choice\n";
      break;
    }
  }
    return 0;
}