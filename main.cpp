#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "util.hpp"

using namespace std;
using namespace util;

//constants
    int Matrixsize = 5;
    Node* nodeArray;
    adjacencyMatrix* masterMatrix;

void readData(string fileName)
{
    vector<Edge> edgeVector;

    //open file
    ifstream reader(fileName);

    //read file using while loop
    string text;
    int count = 0;
    while(getline(reader, text))
    {
        

        if(count == 0)
        {
            //convert to integer and set it to Matrixsize
            Matrixsize = stoi(text);
            
            //create the nodes       
            nodeArray = new Node[Matrixsize];     
            for(int i = 0; i < Matrixsize; i++)
            {
                //create new node
                Node tnode(i);
                //store it in the array of nodes
                nodeArray[i] = tnode;
            }
        }
        else
        {
            //create edges
            string tmpdata;
            vector<int> data;

            //split string and add it to data vector
            for(int i = 0; i < text.length() + 1; i++)
            {

                if(text[i] != ',' && text[i] != '\0'){
                tmpdata += text[i];
                }
                else{

                    data.push_back(stoi(tmpdata));

                    tmpdata = "";
                }
            }
            
            //create a new edge
            Edge newEdge(nodeArray[data.at(0)], nodeArray[data.at(1)], data.at(2));

            //add edge to list of edges
            edgeVector.push_back(newEdge);
        }
        //reset text string to be empty
        text = "";

        count++;
    }

    masterMatrix = new adjacencyMatrix(Matrixsize, edgeVector);
}

int main(int argc, char* argv[])
{
   //ensure that there is a command line argument
   if(argc != 2)
   {
    cout << "File requires 1 command line argument of file name"<<endl;
    return 1;
   }
   
   //get the name of file
    string fileName = argv[1];

   
    //read the file and input data
    readData(fileName);
    
    populationMatrix::setMasterMatrix(*masterMatrix);
}

