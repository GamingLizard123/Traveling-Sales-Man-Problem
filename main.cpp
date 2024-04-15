#include <iostream>
#include "util.hpp"

using namespace std;
using namespace util;

//constants
    const int Matrixsize = 5;
    const int length = 5;

//run main 
int main()
{
   

    Node nodeArray [length];

    for(int i = 0; i < length; i++)
    {
        Node tnode(i);

        nodeArray[i] = tnode;
    }
    
    for (int i = 0; i < length; i++)
    {
        Node tnode = nodeArray[i];
        cout << "Node id: " << tnode.getId() << endl;
    }

    Edge newEdge(nodeArray[0], nodeArray[1], 0);
    cout << "New Edge Made: " << newEdge.getEdge()[0].getId() << ", " <<newEdge.getEdge()[1].getId() << endl;


    adjacencyMatrix matrix(Matrixsize);

    cout << "value at 0, 0: " << matrix.getValueAt(0,0) << endl;

    cout << "set value at 1,1: ";
    int value;
    cin >> value;

    bool returnedBool = matrix.updateMatrix(1,1, value);
    
    cout << "Value set succesfully: " << returnedBool << endl;
    cout << "Value at 1,1: " << matrix.getValueAt(1,1) << endl;

    return 0;
}