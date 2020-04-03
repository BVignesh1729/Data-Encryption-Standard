#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include "BrainProg.cpp"

using namespace std;

void Cryption(char A[],char X[])
{
 ifstream fout(A,ios::binary|ios::in);
 fstream fout2("Temp.txt",ios::binary|ios::out);
 char gate=0;
 char key=0;
 char s;
 KeyInitializer2(X,key); 
 while (fout.read(&s, sizeof(char)))
 {

  s = Algorithm2(s,key);
  fout2.write(&s, sizeof(s));
  key=KeyGenerator2(key,X);
 }
 fout.close();
 fout2.close();
 fout.open("Temp.txt", ios::binary | ios::in);
 fout2.open(A, ios::binary|ios::out);
 s=0;
 key=0;
 while (fout.read(&s, sizeof(char)))
 {
  fout2.write(&s, sizeof(s));
 }
 fout.close();
 fout2.close();
}
