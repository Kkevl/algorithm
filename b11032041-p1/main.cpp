#include <cstdlib>
#include <cstring>
#include"importer.h"
using namespace std;

int main(int argc, char **argv)
{	
	if(argc != 3)
    {
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
        exit(1);
    }
    //my function to solve the answer
    importer loater;
    loater.getnumarray(argv[1]);
    loater.resultable();   

    // parse the input file
    cout << "======================" << endl;
    cout << "        Parser        " << endl;
    cout << "======================" << endl;

    // open the output file
    fstream fout;
    fout.open(argv[2],fstream::out);
    if(!fout.is_open())
    {
        cout << "Error: the output file is not opened!!" << endl;
	    exit(1);
    }

    // output something to the output file
    cout<<"#Chords = "<<loater.maxchord<<endl;
    fout<<loater.maxchord<<endl;
    for (int i = 0; i < loater.firstendpointarray.size(); i++)
    {
        cout<<"Chord("<<loater.firstendpointarray[i]<<","<<loater.array1[loater.firstendpointarray[i]]<<")"<<endl;
        fout<<loater.firstendpointarray[i]<<" "<<loater.array1[loater.firstendpointarray[i]]<<endl;
    }
    return 0;
}

