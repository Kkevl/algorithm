#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class MPS
{
public:
    MPS(int circlesize);
    int maxchord = 0,sizer = 0;
    vector<int> lastarray;
    vector< vector<int> > chordtable, routetable; //seted all element to 0
    void printmaxsheet(int circlesize);
    void maxplannersubproblem_1d(int i,int j, vector<int > linkline);
    void routeing(int i,int j, vector< int > linkline);
};

MPS::MPS(int circlesize)
{
    sizer = circlesize;
    vector< vector<int> > buffer(circlesize, vector<int> (circlesize,0));
    chordtable = buffer;
    routetable = buffer;
}

//debug use
inline void MPS::printmaxsheet(int circlesize)
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
    cout<<"route table:\n";
      for (int i = 0; i < circlesize; i++)
    {
        cout<<"i = "<<i<<" :: ";
        for (int j = 0; j < circlesize; j++)
        {
            cout<<routetable[i][j]<<" ";
        }
        cout<<endl;
    }
    maxchord = chordtable[0][sizer-1];
    return;
}

inline void MPS::maxplannersubproblem_1d(int i, int j, vector<int> linkline)
{
    int k = 0; // k is j's pair
    for (int col = 1; col < sizer; col++) //j = row + col
    {
        for (int row = 0; row < sizer-col; row++) //i
        {
            k = linkline[row+col];
            //case 1: [i,j] = [k,j]
            if (k == row)
            {
                chordtable[row][row+col] = chordtable[row+1][row+col-1]+1;
                routetable[row][row+col] = 1;
            }
            //case 2 j = i+1,and k is not i
            else if( col == 1)
            {
                chordtable[row][row + col] = 0;
                routetable[row][row+col] = 2;
            }
            //case 4: k is out of [i,j]
            else if ( k < row || k > col+row)
            {
                chordtable[row][row+col] = chordtable[row][row+col-1];
                routetable[row][row+col] = 4;
            }
            //case 3,5 k in [i,j]
            else{                
                chordtable[row][row+col] = max(chordtable[row][row+col-1],(chordtable[row][k-1] + chordtable[k+1][row+col-1] + 1));
                //case 5: use previous
                if (chordtable[row][row+col-1]<(chordtable[row][k-1] + chordtable[k+1][row+col-1] + 1) )
                {
                   routetable[row][row+col] = 5;  
                }
                // case 3: the one is noet optimize but count
                else
                {
                   routetable[row][row+col] = 3; 
                }
            }
        }   
    }
    maxchord = chordtable[0][sizer-1];
    return;
}

//this function is for printing out the chords' points
inline void MPS::routeing(int i,int j, vector<int > linkline)
{
    if(chordtable[i][j] == 0 || i < 0 || j < 0 ) return;

    else if (routetable[i][j] == 5 || routetable[i][j] ==1)
    {
        lastarray.push_back(j);
        routeing( linkline[j] + 1 , j , linkline );
        routeing( i , linkline[j] - 1 , linkline );
    }
    else{
        routeing( i , j - 1 , linkline );
    } 
    return;
}