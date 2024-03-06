#include <iostream>
using namespace std;
char space[3][3]={{'1' ,'2' , '3'},{'4' , '5', '6'},{'7' ,'8' ,'9'}};
int row;
int col;
bool tie=false;
string n1="";
string n2="";
char token='x';
 void Matrixsturcture(){
  // code for sturcture of matrix
  cout<< "    |     |  \n";
  cout<< " "<<space[0][0]<<"  | "<<space[0][1]<<"   | "<<space[0][2]<<" \n";
  cout<< "_|_|_ \n";
  cout<< "    |     |  \n";
  cout<< " "<<space[1][0]<<"  | "<<space[1][1]<<"   | "<<space[1][2]<<" \n";
  cout<< "_|_|_\n";
  cout<< "    |     |  \n";
  cout<< " "<<space[2][0]<<"  | "<<space[2][1]<<"   | "<<space[2][2]<<" \n";
  cout<< "    |     |  \n";
}
void ForRowandColumns(){
  int digit;
  if(token=='x')
  {
    cout<<n1<<" "<<"please enter : ";
    cin>>digit;
  }
  if(token=='0')
  {
    cout<<n2<<" "<<"please enter : ";
    cin>>digit;
  }
  // for row[0][0]
  if(digit==1)
  {
    row=0;
    col=0;
  }
  // for row[0][1]
  if(digit==2)
  {
    row=0;
    col=1;
  }
  // for row[0][2]
  if(digit==3)
  {
    row=0;
    col=2;
  }
  // for row[1][0]
  if(digit==4)
  {
    row=1;
    col=0;
  }
  // for row[1][1]
  if(digit==5)
  {
    row=1;
    col=1;
  }
  // for row[1][2]
  if(digit==6)
  {
    row=1;
    col=2;
  }
  // for row[2][0]
  if(digit==7)
  {
    row=2;
    col=0;
  }
  // for row[2][1]
  if(digit==8)
  {
    row=2;
    col=1;
  }
  // for row[2][2]
  if(digit==9)
  {
    row=2;
    col=2;
  }
  else if(digit<1 || digit>9 ){
    cout<<"Invalid !!!"<<endl;
  }
  if(token=='x' && space[row][col]!='x'&& space[row][col]!='0')
  {
    space[row][col]='x';
    token='0';
  }
  else  if(token=='0' && space[row][col]!='x'&& space[row][col]!='0')
    {
      space[row][col]='0';
      token='x';
    }
  // no space left in  the matrxi
  else {
    cout<<"There is no empty space !!!"<<endl;
    ForRowandColumns();
  }
  Matrixsturcture();
}
bool ForWinner(){
  // conditions for Winner in the game
  for(int i=0;i<3;i++)
    {
      if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        return true;
    }
  if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
    {
      return true;
    }
  // Conditions for tie match
  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
        {
          if(space[i][j]!='x' && space[i][j]!='0')
          {
            return false;
          }
        }
    }
  tie=true;
  return true;
}
int main(){
  // Here to enter the names of players
  cout<<"Enter the name of 1st player: \n";
  getline(cin,n1);
  cout<<"Enter the name of 2nd player: \n";
  getline(cin,n2);
  cout<<n1<<" "<<"Is player1 so he/she will play first \n";
   cout<<n2<<" "<<"Is player2 so he/she will play second \n";

  while(!ForWinner())
    {
      Matrixsturcture();
      ForRowandColumns();
      ForWinner();
    }
  // game won by player two
  if(token=='x' && tie==false)
  {
    cout<<n2<<" "<<"Wins !!"<<endl;
  }
    // game won by player one
  else if(token=='0' && tie==false)
  {
    cout<<n1<<" "<<"Wins !!"<<endl;
  }
    // game is Tie
  else{
    cout<<"Match Tie"<<endl;
  }

}
