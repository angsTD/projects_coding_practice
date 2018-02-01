#include <vector>
#include "stdint.h"
#include <iostream>

using namespace std;

typedef enum startstatetype
{
  CMINUS,
  RPLUS,
  CPLUS,
  RMINUS  
}START_STATE;

typedef enum positiontype
{
  TOP_ROW,
  LEFT_COL,
  BOT_ROW,
  RIGHT_COL


}POSITION;

START_STATE getnextstate(POSITION pos)
{
  switch(pos)
  {
    case TOP_ROW:
      return CMINUS;
    case LEFT_COL:
      return RPLUS;
    case BOT_ROW:
      return CPLUS;
    case RIGHT_COL:
      return RMINUS;
    default:
      break;
  }
}
void findrotatedindex(int rstart, int rend, int cstart, int cend, int ri, int ci,int &rri,int &rci, int rot)
{
  POSITION pos;
  int R = rend-rstart+1;
  int C = cend-cstart+1;
  int rot_mod = 2*(R+C-2);
  rot_mod = (!rot_mod)?1:rot_mod;
  int rot_rem = rot%rot_mod;
//  printf("rstart:%d,rend:%d,cstart:%d,cend:%d,ri:%d,ci:%d",rstart,rend,cstart,cend,ri,ci);
//  printf("rot rem : %d \n\n",rot_rem);
  rri = ri;
  rci = ci;
  while(rot_rem)
  {
    if(rri==rstart && rri== rend && rci==cstart && rci==cend)
    {
      rot_rem = 0;
    }
    //if its the top row
    if((rri==rstart) && (rci >cstart))
    {
//      printf("Top Row\n");
      if(rot_rem > (rci-cstart))
      {
        rot_rem = rot_rem-(rci-cstart);
        rci = cstart;
      }
      else
      {
        rci = rci-rot_rem;
        rot_rem = 0;
      }
    }
    //if it is the left column
    if((rci == cstart) && (rri<rend))
    {
//      printf("Left Column\n");
      if(rot_rem>(rend-rri))
      {
        rot_rem = rot_rem - (rend-rri);
        rri = rend;
      }
      else
      {
        rri = rri+rot_rem;
        rot_rem = 0;
      }
    }
    //if it is the bottom row
    if((rri==rend)&&(rci<cend))
    {
//      printf("Bottom row\n");
      if(rot_rem>(cend-rci))
      {
        rot_rem = rot_rem-(cend-rci);
        rci = cend;
      }
      else
      {
        rci+=rot_rem;
        rot_rem=0;
      }
    }
    //if it is the right column
    if((rci == cend)&&(rri>rstart))
    {
//      printf("right column");
      if(rot_rem>(rri-rstart))
      {
        rot_rem = rot_rem - (rri-rstart);
        rri = rstart;
      }
      else
      {
        rri = rri-rot_rem;
        rot_rem = 0;
      }
    }
  }
}


void rotate_submatrix(int rstart,int rend,int cstart,int cend, vector <vector<int> >matrix,int rot, vector <vector<int> >&rot_mat)
{
  if(rend<rstart || cend<cstart) 
    {
//      printf("Not rotating any more\n");
      return;
    }

  int rind = rstart, cind = cstart;
  int rri=0,rci=0;
  
  for(rind=rstart;rind<=rend;rind++)
  {
//    printf("Rotating left column\n");
    findrotatedindex(rstart,rend,cstart,cend,rind,cind,rri,rci,rot);
//    printf("finding rotated index rind:%d, cind:%d, rrind:%d, rcind:%d\n",rind,cind,rri,rci);    
    rot_mat[rri][rci]=matrix[rind][cind];

  }

  rind = rend;
  for(cind = cstart; cind<=cend;cind++)
  {
//    printf("Rotating bottom  row\n");    
    findrotatedindex(rstart,rend,cstart,cend,rind,cind,rri,rci,rot);
//    printf("finding rotated index rind:%d, cind:%d, rrind:%d, rcind:%d\n",rind,cind,rri,rci);
    rot_mat[rri][rci]=matrix[rind][cind];
  }

  cind = cend;
  for(rind = rend; rind >=rstart; rind--)
  {
//    printf("Rotating right column\n");
    findrotatedindex(rstart,rend,cstart,cend,rind,cind,rri,rci,rot);
//    printf("finding rotated index rind:%d, cind:%d, rrind:%d, rcind:%d\n",rind,cind,rri,rci);
    rot_mat[rri][rci]=matrix[rind][cind];
  }

  rind = rstart;
  for(cind = cend; cind>=cstart; cind--)
  {
//    printf("Rotating top row\n");
    findrotatedindex(rstart,rend,cstart,cend,rind,cind,rri,rci,rot);
//    printf("finding rotated index rind:%d, cind:%d, rrind:%d, rcind:%d\n",rind,cind,rri,rci);
    rot_mat[rri][rci]=matrix[rind][cind];
  }

  for(int rindx=0;rindx<3;rindx++)
  {
    for(int cindx=0;cindx<3;cindx++)
    {
//      printf("%d ",rot_mat[rindx][cindx]);
    }
//    printf("\n");
  }
  rotate_submatrix(rstart+1,rend-1,cstart+1,cend-1,matrix,rot,rot_mat);

}



void matrixRotation(vector < vector<int> > matrix, int rot) {
    // Complete this function
  int C = matrix[0].size();
  int R = matrix.size();

//  printf("R: %d, C: %d \n",R,C);

  vector< vector<int> >rot_mat(R,vector<int>(C));

  int rstart = 0;
  int rend = R-1;
  int cstart= 0;
  int cend = C-1;

  //int act_rot = rot%(2*(R+C-2));

  rotate_submatrix(rstart,rend,cstart,cend,matrix,rot,rot_mat);

  for(int rind=0;rind<R;rind++)
  {
    for(int cind=0;cind<C;cind++)
    {
      printf("%d ",rot_mat[rind][cind]);
      matrix[rind][cind]=rot_mat[rind][cind];
    }
    printf("\n");
  }

}

int main() {
    int m;
    int n;
    int r;
    cin >> m >> n >> r;
    vector< vector<int> > matrix(m,vector<int>(n));
    for(int matrix_i = 0;matrix_i < m;matrix_i++){
       for(int matrix_j = 0;matrix_j < n;matrix_j++){
          cin >> matrix[matrix_i][matrix_j];
       }
    }
    printf("matrixRotation\n");
    matrixRotation(matrix,r);
    return 0;
}