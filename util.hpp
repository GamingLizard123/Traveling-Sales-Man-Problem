#include <iostream>

namespace util
{
    //node class
    class Node
    {
        //each node has an id
        int id;

        public:
            Node(int givenId = NULL)
            {
                id = givenId;
            }

            int getId()
            {
                return id;
            }
    };

    //edge class (undirected, unweigthed)
    class Edge
    {
        //each edge has an ID
        int edgeId;

        //each edge connects 2 nodes
        Node node1;
        Node node2;

        public:
            Edge(Node givenNode1, Node givenNode2, int givenId)
            {
                node1 = givenNode1;
                node2 = givenNode2;
                edgeId = givenId;
            }

            //returns a pointer to a node array
            Node* getEdge()
            {
                static Node returnArray [2];

                returnArray[0] = node1;
                returnArray[1] = node2;

                return returnArray;
            }

            int getId()
            {
                return edgeId;
            }
    };
}