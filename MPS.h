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
    // ~MPS();
    int maxchord = 0;
    int sizer = 0;
    vector< vector<int> > chordtable, routetable; //seted all element to 0
    void printmaxsheet(int circlesize);
    int maxplannersubproblem_1d(int i,int j, vector<int > linkline);
    int linkchord_1d(int j,vector< int > linkline);

    int maxplannersubproblem(int i,int j, vector< vector<int> > linkline);
    int linkchord(int j,vector< vector<int> > linkline);
};

MPS::MPS(int circlesize)
{
    sizer = circlesize;
    vector< vector<int> > buffer(circlesize, vector<int> (circlesize,0));
    chordtable = buffer;
    routetable = buffer;
}

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
      for (int i = 0; i < circlesize-1; i++)
    {
        cout<<"i = "<<i<<" :: ";
        for (int j = 0; j < circlesize-1; j++)
        {
            cout<<routetable[i][j]<<" ";
        }
        cout<<endl;
    }
    maxchord = chordtable[0][sizer-1];
    return;
}

inline int MPS::maxplannersubproblem_1d(int i, int j, vector<int> linkline)
{
    // j's pair
    int k = 0;
    for (int col = 1; col < sizer; col++) //j = row + col
    {
        // cout<<" col = "<<col<<endl;
        for (int row = 0; row < sizer-col; row++) //i
        {
            // k = linkchord(row+col,linkline);
            k = linkline[row+col];
            //case 1: [i,j] = [k,j]
            if (k == row)
            {
                chordtable[row][row+col] = chordtable[row+1][row+col-1]+1;
                routetable[row][row+col-1] = 1;
            }
            //case 2 j = i+1,and k is not i
            else if( col == 1)
            {
                chordtable[row][row + col] = 0;
                routetable[row][row+col-1] = 2;
            }
            //case 4: k is out of [i,j]
            else if ( k < row || k > col+row)
            {
                chordtable[row][row+col] = chordtable[row][row+col-1];
                routetable[row][row+col-1] = 4;
            }
            //case 3 k in [i,j]
            else{                
                chordtable[row][row+col] = max(chordtable[row][row+col-1],(chordtable[row][k-1] + chordtable[k+1][row+col-1] + 1));
                routetable[row][row+col-1] = 3;
            }
        }   
    }
    maxchord = chordtable[0][sizer-1];
    return 0;
}

// not finished!!!!!

//use to return the number of j, which is the linknode of node i
inline int MPS::linkchord(int j,vector< vector<int> > linkline)
{
    vector<int>::iterator it;
    // cout<<" j = "<<j<<"\n";
    // if (j>sizer/2)
    // {
     
        // for (int c = sizer/2-1 ; c > 0; c--)
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
        for (int c = 0; c < sizer-1; c++)
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

//row and col mode not ready
inline int MPS::maxplannersubproblem(int i, int j, vector<vector<int>> linkline)
{
    // j's pair
    int k = 0;
    for (int col = 1; col < sizer; col++) //j = row + col
    {
        // cout<<" col = "<<col<<endl;
        for (int row = 0; row < sizer-col; row++) //i
        {
            k = linkchord(row+col,linkline);
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
    maxchord = chordtable[0][sizer-1];
    return 0;
}
