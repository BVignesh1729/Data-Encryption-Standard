#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<math.h>
#include<bitset>
#include "ClassProg.cpp"

using namespace std;


inline char KeyGenerator1(char k,char g)//For Key Generation
{
  bitset<8> k1;
  bitset<8> k2;
  bitset<8> g1;
  k1=k;
  g1=g;
  for(int i=0;i<8;i++)
  {
    k2[i]=0;
	for(int j=0;j<8;j++)
	{
	  k2[i]=(k2[i]+(k1[j]*g1[j]))%2;//Cumulative XOR gate	
	}
	k1[1]=k1[2];//LFSR(Linear Feedback Shift Register)
	k1[2]=k1[3];
	k1[3]=k1[4];
	k1[4]=k1[5];
	k1[5]=k1[6];
	k1[6]=k1[7];
	k1[7]=k2[i];	
  }
  char c=0;
  for(int i=0;i<8;i++)
  c+=(k2[i]*pow(2,i));
  return c;
}

inline char KeyGenerator2(char k,char A[])//For Key Generation; 
{
   bitset<8> k1=k;
   k=0;
   for(int i=0;A[i];i++)
   {
     k=k^(A[i]*k1[i]);//Selective usage of XOR gate for producing next key byte using previous key byte;		
   }
   return k;
}

inline void KeyInitializer1(char A[],char &k,char &g)//For Key initialization
{
   int n=strlen(A);
   k=0;
   g=0;
   for(int i=0;i<(n/2);i++)
   {
     k=k^A[i];
	 g=g^A[n-1-i];		
   }
}

inline void KeyInitializer2(char A[],char &k)//For Key initialization;
{
   k=0;
   for(int i=0;A[i];i++)
   {
     k=k^A[i];//First key byte is produced by using XOR gate for all characters of the file password;
   }
}

inline char Algorithm1(char p,char k)//For Encryption as well as Decryption
{
  bitset<8> p1;
  bitset<8> k1;
  bitset<8> c1;
  p1=p;
  k1=k;
  for(int i=0;i<8;i++)
  {
    c1[i]=(p1[i]+k1[i]+1)%2;//XNOR gate;	
  }
  char c=0;
  for(int i=0;i<8;i++)
  c+=(c1[i]*pow(2,i));
  return c;
}

inline char Algorithm2(char p,char k)//For Encryption as well as Decryption;
{
   char c;
   c=p^k;
   return c;
}
