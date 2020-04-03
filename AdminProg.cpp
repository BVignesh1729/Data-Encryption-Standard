#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<time.h>
#include<windows.h>
#include "ClassProg.cpp"

using namespace std;

int main()
{
  system("COLOR F0");
  ifstream fin("FileDatabase.dat",ios::binary|ios::in);
  char c=0;
  int i=0;
  File f;	
  while(fin.read((char*)&f,sizeof(f)))
  {	
    i++;	
  }
  fin.close();
  do
  {
   cout.width(45);
   cout << "FILE DATABASE" << endl << endl;
   cout.width(30);
   cout << "1. " << "Add a file to database" << endl << endl;
   cout.width(30);
   cout << "2. " << "Modify file details in database" << endl << endl;
   cout.width(30);
   cout << "3. " << "Delete a file from database" << endl << endl;
   cout.width(30);
   cout << "4." << " Exit Program" << endl << endl;
   cout.width(30);
   cout << "Enter your option: ";
   c=getch();
   while(c!='1' && c!='2' && c!='3' && c!='4')
   c=getch();
   cout << c;
   cin.get();
   if(c=='1')
   {
	 system("cls");
     cout.width(45);
     cout << "FILE DATABASE" << endl << endl;
     cout.width(75);
     cout << "Files present: " << i << endl << endl;
     cout.width(30);
     ofstream fout("FileDatabase.dat",ios::binary|ios::out|ios::app);
	 f.accept();
	 fout.write((char*)&f,sizeof(f));
	 i++;
	 fout.close();
	 system("cls");
   }
   if(c=='2')
   {
	  system("cls");
	  int k=1;
	  int l=0;
	  do
	  {
	   cout.width(45);
	   cout << "FILE DATABASE" << endl << endl;
       cout.width(75);
       cout << "Files present: " << i << endl << endl;
	   cout.width(50);
	   cout << "Available Files are: " << endl << endl;
       ifstream fbin("FileDatabase.dat",ios::binary|ios::in);
       char fname[20];
       while(fbin.read((char*)&f,sizeof(f)))
       {
	     f.getname(fname);
	 	 cout.width(35);
		 cout << "-->" << fname << endl << endl; 
	   }
	   fbin.close();	
	   char P[20];
	   cout.width(45);
       if(l!=0)
       {
	     if(k!=0)
	     {
	       cout << "Invalid File name!!" << endl;		
           cout.width(45);
           cout << "Re-enter File name(along with extension): ";
	     }		
	   }
	   else
       cout << "Enter File name(along with extension): ";
	   cin.getline(P,20);
	   fstream fin("FileDatabase.dat",ios::binary|ios::in); 
	   while(fin.read((char*)&f,sizeof(f)) && k!=0)	
	   {
		  char fname[20];
          f.getname(fname);
          k=strcmp(P,fname);
 		  if(k==0)
 		  {
           f.modifyaccept();	
		  }
	   }
	   l++;
	   system("cls");
     }while(k!=0);
	}
   if(c=='3')
   {
	  system("cls");
	  int k=1;
	  int l=0;
	  int w=0;
	  if(i!=0)
	  {
	  do
	  {
	   cout.width(45);
	   cout << "FILE DATABASE" << endl << endl;
       cout.width(75);
       cout << "Files present: " << i << endl << endl;
	   cout.width(50);
	   cout << "Available Files are: " << endl << endl;
       ifstream fbin("FileDatabase.dat",ios::binary|ios::in);
       char fname[20];
       while(fbin.read((char*)&f,sizeof(f)))
       {
	     f.getname(fname);
	 	 cout.width(35);
		 cout << "-->" << fname << endl << endl; 
	   }
	   fbin.close();	
	   char P[20];
	   cout.width(45);
       if(l!=0)
       {
	     if(k!=0)
	     {
	       cout << "Invalid File name!!" << endl;		
           cout.width(45);
           cout << "Re-enter File name(along with extension): ";
	     }		
	   }
	   else
       cout << "Enter File name(along with extension): ";
	   cin.getline(P,20);
	   fstream fin("FileDatabase.dat",ios::binary|ios::in);
	   fstream fin2("TempDatabase.dat",ios::binary|ios::out); 
	   while(fin.read((char*)&f,sizeof(f)))	
	   {
		  char fname[20];
          f.getname(fname);
          k=strcmp(P,fname);
 		  if(k!=0)
 		  {
           fin2.write((char*)&f,sizeof(f));
		  }
		  else
		  w++;
	   }
	   fin.close();
	   fin2.close();
	   fin.open("FileDatabase.dat",ios::binary|ios::out);
	   fin2.open("TempDatabase.dat",ios::binary|ios::in);
	   while(fin2.read((char*)&f,sizeof(f)))
	   {
	     fin.write((char*)&f,sizeof(f));		
	   }
	   l++;
	   cout << endl << endl << endl;
	   cout.width(55);
	   cout << "THE FILE HAS BEEN SUCCESSFULLY DELETED...";
	   Sleep(5000);
	   system("cls");
	   i--;
     }while(w!=1);
	}
     else
     {
	  cout.width(50);
     cout << "NO FILES PRESENT...." ;
     Sleep(5000);
     exit(0);
	 }
    }
  }while(c!='4');
}
