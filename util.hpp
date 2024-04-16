#include <iostream>
#include <array>

using namespace std;

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

        //each edge has a weight, which by default is 0, and therfore unweighted
        int weight;

        //each edge connects 2 nodes
        Node node1;
        Node node2;

        public:
            Edge(Node givenNode1, Node givenNode2,  int givenWeight = 0)
            {
                node1 = givenNode1;
                node2 = givenNode2;
            
                weight = givenWeight;
            }

            //returns a pointer to a node array
            Node* getEdge()
            {
                static Node returnArray [2];

                returnArray[0] = node1;
                returnArray[1] = node2;

                return returnArray;
            }

            //returns the weight of the edge
            int getWeight()
            {
                return weight;
            }
    };

    //adjecency matrix stores the 2d integer array
    class adjacencyMatrix
    {
        //pointer to 2D array
        int** matrix;
        int sizeOfMatrix;

        public:

        adjacencyMatrix(int givenSize)
        {
            //set size
            sizeOfMatrix = givenSize;
            
            //set the 2d matrix 
            matrix = new int*[sizeOfMatrix];
            for (int i = 0; i < sizeOfMatrix; i++)
            {
                matrix[i] = new int[sizeOfMatrix];
                //populate matrix
                for (int j = 0; j < sizeOfMatrix; j++)
                {
                    matrix[i][j] = 0;
                }
                
            }
            
        }

        //returns the matrix
        int** getMatrix()
        {
            return matrix;
        }

        //returns the size of the matrix
        int getSize()
        {
            return sizeOfMatrix;
        }

        //update matrix
        bool updateMatrix(int i, int j, int value)
        {
            //if the value is 0 or 1 return true and set the value
            if( value == 0 || value == 1)
            {
                matrix[i][j] = value;
                return true;
            }

            //else return false
            return false;
        }

        //get value of matrix
        int getValueAt(int i, int j)
        {
            return matrix[i][j];
        }
    };
}