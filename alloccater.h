/*
    this is the tring steps or method this project,
    the function in this header file are not in use,
    just for leaving the record.
                                editor: Kevin Tan

    usage: paste this in the importer::resultable()
        alloccater tabler(sizer);
        tabler.maxpanersubset(sizer,array1,array2);
        tabler.maxpanersubset_2dv(sizer,map1);//linkline);
        tabler.maxplannersubproblem(0,sizer,linkline);
        tabler.printmaxsheet(sizer);
        cout<<" max = "<<tabler.chordtable[0][sizer-1];
    note!! the code in this file was abandoned! which is not finished!!
    it can just print the maxchord number with longer time!    
*/
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class alloccater
{
public:
    alloccater(int circlesizes);
    int circlesize = 0;
    int maxchord = 0;
    vector< vector<int> > chordtable; //set all element to 0
    void printmaxsheet(int circlesize);
    
    void maxpanersubset(int circlesize, vector<int> array1,vector<int> array2);
    int linkchord(int i,int j,vector<int> array1,vector<int> array2);
    
    void maxpanersubset_2dv(int circlesize, unordered_map<int,int> maper);//vector<vector<int>> linkline);
    int linkchord_2dv(int i,int j,unordered_map<int,int> maper);//vector<vector<int>> linkline);

    void maxpanersubset_topdown(int circlesize, vector<int> array1,vector<int> array2);
    int lookup_chain(int i,int j, vector<int> array1,vector<int> array2);
    
    int maxplannersubproblem(int i,int j, vector< vector<int> > linkline);
    int linkchorder(int j,vector< vector<int> > linkline);

};

alloccater::alloccater(int circlesizes)
{   
    vector< vector<int> > buffer(circlesizes, vector<int> (circlesizes,0));
    chordtable = buffer;
    circlesize = circlesizes;
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

inline void alloccater::maxpanersubset(int circlesize, vector<int> array1,vector<int> array2)
{   // n  = size-1;
    int j = 0,q = 0,link = 0;
    for (int l = 2; l <= circlesize; l++)
    {
        cout<<"l =  "<<l<<" ";
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
// Unuse
inline void alloccater::maxpanersubset_2dv(int circlesize, unordered_map<int,int> maper)//vector<vector<int>> linkline)
{// n  = size-1;
    int j = 0,q = 0,link = 0;
    for (int l = 2; l <= circlesize; l++)
    {
        for (int i = 0; i < circlesize-l+1; i++)
        {
            j = i+l-1;
            link = linkchord_2dv(i,j,maper);
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

inline int alloccater::linkchord_2dv(int i, int j, unordered_map<int,int> maper)//vector<vector<int>> linkline)
{
    vector<int>::iterator it;
    int temp = 0;
    if (i == maper[j]) return 1;
    
    // it = find(linkline[0].begin(), array1.end(),i);
    // for (int c = 0; c <  circlesize/2; c++)
    // {
        // if (i == linkline[c][0])
        // {
        //     if (j == linkline[c][1])
        //     {
        //         return 1;
        //     }            
        // }
        // if (i == linkline[c][1])
        // {
        //     if (j == linkline[c][0])
        //     {
        //         return 1;
        //     }            
        // }
    // }
    
    return 0;
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

inline int alloccater::maxplannersubproblem(int i, int j, vector<vector<int>> linkline)
{
    // j's pair
    int k = 0;
    for (int col = 1; col < circlesize; col++) //j = row + col
    {
        // cout<<" col = "<<col<<endl;
        for (int row = 0; row < circlesize-col; row++) //i
        {
            k = linkchorder(row+col,linkline);
            //case 3: [i,j] = [k,j]
            if (k == row)
            {
                chordtable[row][row+col] = chordtable[row+1][row+col-1]+1;
            }
            //case 4 j = i+1,and k is not i
            else if( col == 1)
            {
                chordtable[row][row + col] = 0;
            }
            //case 1: k is out of [i,j]
            else if ( k < row || k > col+row)
            {
                chordtable[row][row+col] = chordtable[row][row+col-1];
            }
            //case 2 k in [i,j]
            else{
                
                chordtable[row][row+col] = max(chordtable[row][row+col-1],(chordtable[row][k-1] + chordtable[k+1][row+col-1] + 1));
            }
        }   
    }
    maxchord = chordtable[0][circlesize-1];
    return 0;
}

inline int alloccater::linkchorder(int j, vector<vector<int>> linkline)
{
    vector<int>::iterator it;
    // cout<<" j = "<<j<<"\n";
    // if (j>circlesize/2)
    // {
     
        // for (int c = circlesize/2-1 ; c > 0; c--)
        // {
        //     if ((j == linkline[c][1]))
        //     {
        //         return linkline[c][0]; //the c is the location of pair of j
        //     }
        //     if ((j == linkline[c][0]))
        //     {
        //         return linkline[c][1];
        //     }
        // }        

    // }    
    // else
    // {
        for (int c = 0; c < circlesize-1; c++)
        {
            if ((j == linkline[c][1]))
            {
                return linkline[c][0]; //the c is the location of pair of j
            }
            if ((j == linkline[c][0]))
            {
                return linkline[c][1];
            }
            
        } 
    // }    
    // it = find(linkchord.begin(), linkchord.end(),i);
    // temp = it-array1.begin();
    // if ( temp  == size(array1) )
    // {
    //     it = find(array2.begin(), array2.end(),i);
    //     temp = it-array2.begin();
    //     if (array1[temp] == j) return 1;
    // }
    // else if (array2[it-array1.begin()] == j) return 1; 
    return -1;
}
