#include <iostream>
#include <fstream>
#include <string>
#include "util.hpp"

using namespace std;
using namespace util;

//constants
    int Matrixsize = 5;
    Node* nodeArray;


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

   //open file
    ifstream reader(fileName);

    //read file using while loop
    string text;
    int count = 0;
    while(getline(reader, text))
    {
        cout << text << endl;
        //convert text to data
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
            //split the text into string array via the strtok() function
            const int length = text.length();
            char* textArr = new char[length]; 
            
            char* dataArr = strtok(textArr, ",");

        }
        //reset text string to be empty
        text = "";
        count++;
    }

    

    
    
    for (int i = 0; i < Matrixsize; i++)
    {
        Node tnode = nodeArray[i];
        cout << "Node id: " << tnode.getId() << endl;
    }
}