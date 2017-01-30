#include<iostream>
#include<string>
#include<string.h>

using namespace std;
 static int rem,iter,iterde,counter2=0;
static int counter=0;
static int case1=0, case1de=0;
string reverse(string inp)
{
  string temp = "";
  int len = inp.length()-1; int i;
  for( i = len ; i>= 0 ; i--)
  {
    temp = temp + inp.at(i) ;
  }
 // cout << "The reversed string is : " << temp << endl; 
  return temp;
}

void rotate(char  mat[][6])
{ int i,j;
  char newmat[6][6]={'\0'};
  
  for( i=0; i<6; i++)
    for( j=0; j<6; j++){
      newmat[i][j]= mat[5-j][i];
    }
    
  for(  i=0; i<6; i++)
    for(  j=0; j<6; j++){
      mat[i][j]= newmat[i][j];
    }
} 



void fill(char  mat[][6], string toenc) // fill it out!
{
  mat[0][1] = toenc.at(counter++);
  mat[0][3] = toenc.at(counter++);
  mat[0][5] = toenc.at(counter++);
  mat[1][4] = toenc.at(counter++);
  mat[2][2] = toenc.at(counter++);
  mat[3][1] = toenc.at(counter++);
  mat[3][4] = toenc.at(counter++);
  mat[4][5] = toenc.at(counter++);
  mat[5][3] = toenc.at(counter++);
}

string encrypt(char  mat[][6], string toenc)  //fill it out!!
{ 
  string enc;
  iter ++;
  
  while(iter >1 || case1 ==1 )
  {
    //cout << iter << "hiiiiiiiiii -------" << endl;
  fill(mat, toenc);
  rotate(mat);
  
  
  fill(mat, toenc);
  rotate(mat);
  
  
  fill(mat, toenc);
  rotate(mat);
  
  
  fill(mat, toenc);
  rotate(mat);
  
  
  for(int i=0; i<6; i++)
  {
    for(int j=0; j<6; j++)
      enc = enc + mat[i][j];
  }
  iter--;
  case1--;
  //cout<< "See iter --->: "<<iter-- <<"The enc string is: "<< enc << endl ;
  }
  return enc;
}
 
// encryption done. Now decryption + the ones to be filled out remains!!!
 
string decrypt(string input)
{
  string get;
  //cout<< "hiiiiii!! \n\n\n";
  static int counter2=0;
  char mat[6][6]= {'\0'};
  iterde++;
  while(iterde>1 || case1de ==1 ){
  for(int i=0; i<6; i++)
  {
    for(int j=0; j<6; j++)
      mat[i][j] = input.at(counter2++ ) ;
 }
 
 
 get= get + mat[0][1]+ mat[0][3]+ mat[0][5]+ mat[1][4]+ mat[2][2]+ mat[3][1]+ mat[3][4]+ mat[4][5]+ mat[5][3];

 rotate(mat);
 get= get + mat[0][1]+ mat[0][3]+ mat[0][5]+ mat[1][4]+ mat[2][2]+ mat[3][1]+ mat[3][4]+ mat[4][5]+ mat[5][3];
 
 rotate(mat);
 get= get + mat[0][1]+ mat[0][3]+ mat[0][5]+ mat[1][4]+ mat[2][2]+ mat[3][1]+ mat[3][4]+ mat[4][5]+ mat[5][3];
 
 rotate(mat);
 get= get + mat[0][1]+ mat[0][3]+ mat[0][5]+ mat[1][4]+ mat[2][2]+ mat[3][1]+ mat[3][4]+ mat[4][5]+ mat[5][3];
  
    iterde --;
    case1de--;
  }
 return get;
}

int main()
{
  
  cout<< "\n Welcome to Sandorfs encryption program!!" << "\n \n " << endl;
  cout << "Enter the string to be encrypted  :" ;
  
  
  string input;
  
  getline(cin, input);
  
  cout << '\n' << endl;
  int len= input.length();
  //cout << "The string length of input string is: " << len << '\n' << endl ;
  if(len <= 36)
  {
    case1= 1;
    rem = 36-len;
    iter = 0;
    iterde= 0;
    case1de=1;
  }
  if(len > 36)
  {
   
     iterde= len/36 +1  ;
     iter = len/36 +1  ;
     rem= iter* 36 -len;
     case1=0;
     case1de=0;
  }
 // cout << "this is the remainder #'s : " << rem << endl;
  
  
  while(rem != 0)
  {
    input = input + '#';
    rem--;
  }
  
  string inp = reverse(input);
  //cout<< input << endl ;
  cout << "reversed input" << inp  << endl << endl ;
  
  string enc, dec;
  char mat[6][6]= {'\0'};
  enc = encrypt(mat, inp);
  
  dec = decrypt(enc); 
  dec = reverse(dec);
  cout<< "encrypted string: " << enc << endl << endl ;
  cout << "Decrypted String: " << dec << endl << endl ;
  
}
