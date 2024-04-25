#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
#include "util.hpp"

using namespace std;
using namespace util;

//constants
    const int populationSize = 10;
    int Matrixsize = 5;
    Node* nodeArray;
    adjacencyMatrix* masterMatrix;
    vector<populationMatrix> currentPopulation;
    int iterations = NULL;

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

void printPopMatrix(populationMatrix tmpM)
{
    for(int row = 0; row < tmpM.getSize(); row++)
    {
        for(int col = 0; col < tmpM.getSize(); col++)
        {
            cout << tmpM.getValueAt(row, col) << " ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
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

            for(int k = 0; k < masterMatrix -> getSize(); k++)
            {
                //generate numbers randomly
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dis(0,1);
                int value = dis(gen);

               //ensure that values are between 1 and 0
                if(value < 0 || value > 1)
                {
                    cout << "error in creating population size, value of input is incorrect" << endl;
                    throw exception();
                }
                //update matrix based on random number
                tmpMatrix.updateMatrix(j, k, value);
            }
        }
        printPopMatrix(tmpMatrix);
        //store the tmp matrix
        currentPopulation.push_back(tmpMatrix);
    }
}

// TODO: make a fitness function
int fitnessFunction(populationMatrix givenMatrix)
{
    //find if there are any loops
    //store the nodes that have been iterated
    vector<int> nodesIteratedThrough;
    //if there are any loop return 0
    //else find the the total weight of the graph
}


float averageFitness(vector<int> fitness)
{
    float avg = 0;
    
    //add the each value of the given vector
    for(int i = 0; i < fitness.size(); i++)
    {
        avg += fitness.at(i);
    }

    //divide by the size of the vector
    avg = avg/fitness.size();
    
    //return the average
    return avg;
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

    //initialize a population
    initializePopulation();
    cout << "Finished Generating staring population" << endl;

    

    //get input for iterations
    cout << "Iterations: ";
    string tmpInput;
    getline(cin, tmpInput);
    
    if(tmpInput.empty())
    {
        iterations = 20;
    }
    else{
        iterations = stoi(tmpInput);
    }
    cout << iterations << " Iterations will commence" << endl;

    //loop for x number of iterations
    for(int i = 0; i < iterations; i++)
    {
        //for each iteration get fitness
        vector<int> fitness; 

        //get fitness of population
        for(populationMatrix popMatrix : currentPopulation)
        {
            int popFitness = fitnessFunction(popMatrix);
            fitness.push_back(popFitness);
        }

        //log average fitness
        fitnessOverIterations.push_back(averageFitness(fitness));

        //get top 4
        //tournament style elimination (bias towards parent of greater fitness)
        //create new temporary population vector
        //store parents
        //create children and induce random mutation
        //store children in tmp population vector
        //replace old population
    }
}