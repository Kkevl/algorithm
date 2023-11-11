#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"MPS.h"
using namespace std;
class importer
{
public:
    int sizer = 0,maxchord = 0;
    int* linetable;
    importer();
    vector<int> array1,firstendpointarray;
    vector< vector<int> > linkline;
    void printsize(){cout<<sizer;}
    void getnumarray(string filename);
    void printarrays();
    void resultable();
};

inline importer::importer()
{
    vector< vector<int> > bufferpair(sizer/2, vector<int> (2,0));
    linkline = bufferpair;
    return;
}

inline void importer::getnumarray(string filename)
{
    ifstream handler;
    handler.open(filename);
    handler>>sizer; //
    int loader,loader2;
    vector<int> buffer(sizer);
    array1 = buffer;

    if(handler.is_open()){
        for (int iter = 0; iter < sizer/2; iter++)
        {
            handler>>loader>>loader2;
            array1[loader] = loader2;
            array1[loader2] = loader;
        }
        handler.close();
    }
    else{
        cout << "Error: the input file is not opened!!" << endl;
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
        exit(1);
    }   
    return;
}

// for debug usage
inline void importer::printarrays(){  
    cout<<"linkline :\n";
    for (int i = 0; i < sizer/2; i++)
    {
        cout<<linkline[i][0]<<" "<<linkline[i][1]<<"\n";
    }
    cout<<endl;
    return;
}

inline void importer::resultable(){
    MPS mps(sizer);
    mps.maxplannersubproblem_1d(0,sizer,array1);
    mps.routeing(0,sizer-1,array1);
    maxchord = mps.maxchord;
    //save the chords in sorted way 
    for (int i = mps.lastarray.size()-1 ; i>=0 ; i--)
    {
        firstendpointarray.push_back(array1[mps.lastarray[i]]);
    }
    sort(firstendpointarray.begin(),firstendpointarray.end());
    return;
}
