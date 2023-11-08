#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class alloccater
{
public:
    alloccater(int circlesize);
    ~alloccater();
    int maxchord = 0;
    vector< vector<int> > chordtable; //set all element to 0
    void maxpanersubset(int circlesize, vector<int> array1,vector<int> array2);
    void printmaxsheet(int circlesize);
    void maxpanersubset_topdown(int circlesize, vector<int> array1,vector<int> array2);
    int lookup_chain(int i,int j, vector<int> array1,vector<int> array2);
    int linkchord(int i,int j,vector<int> array1,vector<int> array2);
};

alloccater::alloccater(int circlesize)
{   
    vector< vector<int> > buffer(circlesize, vector<int> (circlesize,0));
    chordtable = buffer;
}

alloccater::~alloccater()
{
}

inline void alloccater::maxpanersubset(int circlesize, vector<int> array1,vector<int> array2)
{   // n  = size-1;
    int j = 0,q = 0,link = 0;
    for (int l = 2; l <= circlesize; l++)
    {
        for (int i = 0; i < circlesize-l+1; i++)
        {
            j = i+l-1;
            link = linkchord(i,j,array1,array2);
            for (int k = i; k < j; k++)
            {
                q = chordtable[i][k]+chordtable[k+1][j]+link;
                if (q>chordtable[i][j])
                {
                    chordtable[i][j] = q;
                    // cout<<"i = "<<i<<" k = "<<k<<" j = "<<j<<endl;
                    //add the movementable!!
                }                
            }
        }
    }
    return;
}

inline void alloccater::printmaxsheet(int circlesize)
{
    for (int i = 0; i < circlesize; i++)
    {
        cout<<"i = "<<i<<" :: ";
        for (int j = 0; j < circlesize; j++)
        {
            cout<<chordtable[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

inline void alloccater::maxpanersubset_topdown(int circlesize, vector<int> array1, vector<int> array2)//too long!!!
{   // n = circlesize-1
    lookup_chain(0,circlesize-1,array1,array2);
    return;
}

inline int alloccater::lookup_chain(int i, int j, vector<int> array1, vector<int> array2)
{
    int q = 0;
    if(chordtable[i][j]>0) return chordtable[i][j]; // don't overwrite
    else{
        for (int c = i;  c < j; c++)
        {
            q = lookup_chain(i,c,array1,array2) + lookup_chain(c+1,j,array1,array2)+linkchord(i,j,array1,array2);
            if(q>chordtable[i][j]){
                chordtable[i][j] = q;
            }
        }
    }
    return chordtable[i][j];
}

inline int alloccater::linkchord(int i, int j, vector<int> array1, vector<int> array2)
{
    vector<int>::iterator it;
    int temp = 0;
    it = find(array1.begin(), array1.end(),i);
    temp = it-array1.begin();
    if ( temp  == size(array1) )
    {
        it = find(array2.begin(), array2.end(),i);
        temp = it-array2.begin();
        if (array1[temp] == j) return 1;
    }
    else if (array2[it-array1.begin()] == j) return 1; 
    return 0;

}

