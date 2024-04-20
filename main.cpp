#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "util.hpp"

using namespace std;
using namespace util;

//constants
    const int populationSize = 10;
    int Matrixsize = 5;
    Node* nodeArray;
    adjacencyMatrix* masterMatrix;
    vector<populationMatrix> currentPopulation;

    //Stores the average fitness of population over iterations
    vector<int> fitnessOverIterations;

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

void initializePopulation()
{
    for(int i = 0; i < populationSize; i++)
    {
        //create a new population matrix
        populationMatrix tmpMatrix;

        //set the variable
        for(int j = 0; j < masterMatrix->getSize(); j++)
        {
            for(int k = 0; masterMatrix -> getSize(); k++)
            {
                int value = static_cast<double>(rand()) / RAND_MAX;
                tmpMatrix.updateMatrix(j, k, value);
            }
        }

        //store the tmp matrix
        currentPopulation.push_back(tmpMatrix);
    }
}

int main(int argc, char* argv[])
{
    //seed random
    srand(static_cast<unsigned int>(time(nullptr)));
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

    //initialize a population
    initializePopulation();
    cout << "Done";
    //loop for x number of iterations
    //for each iteration
    //get fitness of population
    //log average fitness
    //get top 4
    //tournament style elimination (bias towards parent of greater fitness)
    //create new temporary population vector
    //store parents
    //create children and induce random mutation
    //store children in tmp population vector
    //replace old population
}


// TODO: make a fitness function