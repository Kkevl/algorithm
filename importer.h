#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"alloccater.h"
using namespace std;
class importer
{
public:
    int sizer = 10;
    vector<int> array1,array2;
    void printsize(){cout<<sizer;}
    void getnumarray(string filename);
    void printarrays();
    void resultable();
    void adjustdata(int delta);
};

inline void importer::getnumarray(string filename){
    ifstream handler;
    handler.open(filename);
    handler>>sizer;

    int loader;
    cout<<sizer<<endl;
    if(handler.is_open()){
        for (int i = 0; i < sizer/2; i++)
        {
            handler>>loader;
            array1.push_back(loader);
            handler>>loader;
            array2.push_back(loader);
        }
        handler.close();
    }
    else cout<<"noting open!";
    return;
}

inline void importer::printarrays(){
    for (int i = 0; i < sizer/2; i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl<<"array2 : ";
    for (int i = 0; i < sizer/2; i++)
    {
        cout<<array2[i]<<" ";
    }
    return;
}

inline void importer::resultable(){
    alloccater tabler(sizer);
    // tabler.maximumplannersubset(sizer,array1,array2);
    // tabler.printmaxsheet(sizer);
    cout<<" max = "<<tabler.chordtable[0][sizer-1];
    return;
}

inline void importer::adjustdata(int delta){
    for (int i = 0; i < size(array1); i++)
    {
        array1[i] = (array1[i]+delta)%sizer;
    }
    for (int i = 0; i < size(array2); i++)
    {
        array2[i] = (array2[i]+delta)%sizer;
    }
    
}


