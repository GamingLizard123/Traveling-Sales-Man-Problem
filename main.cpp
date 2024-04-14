#include <iostream>
#include "util.hpp"

using namespace std;
using namespace util;

//


//run main 
int main()
{
    const int length = 5;

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
    

    return 0;
}