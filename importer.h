#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"alloccater.h"
#include"MPS.h"
using namespace std;
class importer
{
public:
    int sizer = 0;
    int* linetable;
    importer();
    vector<int> array1,firstendpointarray;
    vector< vector<int> > linkline;
    unordered_map<int,int> map1,map2;
    void printsize(){cout<<sizer;}
    void getnumarray(string filename);
    void printarrays();
    void resultable();
    // void sortdata(int asizer,vector<int> sortarray);
    // void quicksorter(vector< int > linklineq, int start,int end);
    // int partion(vector< int > linklinep, int p,int r);
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
    // vector< vector<int> > bufferpair(sizer/2, vector<int> (2,0));
    // linkline = bufferpair;
    // linetable = new int(sizer);

    cout<<sizer<<endl;
    if(handler.is_open()){
        for (int iter = 0; iter < sizer/2; iter++)
        {
            handler>>loader>>loader2;
            array1[loader] = loader2;
            array1[loader2] = loader;
            // linetable[loader] = loader2;
            // linetable[loader2] = loader;
            // map1.insert({loader,loader2});
            // map1.insert({loader2,loader});
            // array1.push_back(loader);
            // handler>>loader;
            // array2.push_back(loader2);
            // handler>>linkline[i][0]>>linkline[i][1];            
        }
        // for (int i = 0; i < sizer; i++)
        // {
        //     cout<<i<<" : "<<array1[i]<<endl;
        // }
        handler.close();
    }
    else cout<<"noting open!";    
    
    
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
    cout<<"\nmax = "<<mps.maxchord;
    mps.routeing(0,sizer-1,array1);

    // printing out 
    cout<<"\nChords: \n";
    for (int i = mps.lastarray.size()-1 ; i>=0 ; i--)
    {
        firstendpointarray.push_back(array1[mps.lastarray[i]]);
    }
    
    sort(firstendpointarray.begin(),firstendpointarray.end());
    for (int i = 0; i < firstendpointarray.size(); i++)
    {
        cout<<i<<" :"<<firstendpointarray[i]<<" "<<array1[firstendpointarray[i]]<<endl;
    }
    

    return;
}

// //unused
// inline void importer::sortdata(int asizer,vector<int> sortarray){
//     quicksorter(sortarray,0,asizer-1);
//     return;
// }

// inline void importer::quicksorter(vector< int > linklineq, int start, int end)
// {
//     if(start<end){
//         int q = partion(linklineq,start,end);
//         quicksorter(linklineq,start,q-1);
//         quicksorter(linklineq,q+1,end);
//     }
// }

// inline int importer::partion(vector< int > linklinep, int p, int r)
// {
//     int i = p - 1;
//     int x = linklinep[r];
//     for (int j = p; j < r; j++)
//     {
//         if (linklinep[j] <= x)
//         {
//             swap< int >(linklinep[++i],linklinep[j]);
//         }
//     }
//     swap< int >(linklinep[++i],linklinep[r]);
//     return 0;
// }
