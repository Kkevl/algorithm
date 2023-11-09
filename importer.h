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
    // ~importer(){ delete [] linetable;}
    vector<int> array1,array2;
    vector< vector<int> > linkline;
    unordered_map<int,int> map1,map2;
    void printsize(){cout<<sizer;}
    void getnumarray(string filename);
    void printarrays();
    void resultable();


    void sortdata();
    void quicksorter(vector< vector<int> > linklineq, int start,int end);
    int partion(vector< vector<int> > linklinep, int p,int r);
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
        for (int i = 0; i < sizer; i++)
        {
            cout<<i<<" : "<<array1[i]<<endl;
        }
        cout<<"pass!"<<endl;
        handler.close();
    }
    else cout<<"noting open!";    
    
    
    return;
}

inline void importer::printarrays(){
    // for (int i = 0; i < sizer/2; i++)
    // {
    //     cout<<array1[i]<<" ";
    // }
    // cout<<"\narray2: \n";
    // for (int i = 0; i < sizer/2; i++)
    // {
    //     cout<<array2[i]<<" ";
    // }    
    cout<<"linkline :\n";
    for (int i = 0; i < sizer/2; i++)
    {
        cout<<linkline[i][0]<<" "<<linkline[i][1]<<"\n";
    }
    cout<<endl;
    return;
}

inline void importer::resultable(){
    alloccater tabler(sizer);
    // tabler.maxpanersubset(sizer,array1,array2);
    // tabler.maxpanersubset_2dv(sizer,map1);//linkline);
    // tabler.printmaxsheet(sizer);
    // cout<<" max = "<<tabler.chordtable[0][sizer-1];
    MPS mps(sizer);
    mps.maxplannersubproblem_1d(0,sizer,array1);
    // mps.maxplannersubproblem(0,sizer,linkline);
    mps.printmaxsheet(sizer);
    cout<<" max = "<<mps.maxchord;
    return;
}




//unused
inline void importer::sortdata(){
    quicksorter(linkline,0,sizer-1);
    return;
}

inline void importer::quicksorter(vector<vector<int>> linklineq, int start, int end)
{
    if(start<end){
        int q = partion(linklineq,start,end);
        quicksorter(linklineq,start,q-1);
        quicksorter(linklineq,q+1,end);
    }
}

inline int importer::partion(vector< vector<int> > linklinep, int p, int r)
{
    int i = p - 1;
    int x = linklinep[r][0];
    for (int j = p; j < r; j++)
    {
        if (linklinep[j][0] <= x)
        {
            swap< vector<int> >(linklinep[++i],linklinep[j]);
        }
    }
    swap< vector<int> >(linklinep[++i],linklinep[r]);
    return 0;
}
