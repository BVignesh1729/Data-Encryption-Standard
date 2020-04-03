#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<time.h>
#include<windows.h>
#include"Encrypt.cpp"

using namespace std;

int main()
{
	system("COLOR F0");
	char FileName[20],Password[20];
    ifstream fbin("FileDatabase.dat",ios::binary|ios::in);
    char P[20],Q[20];
    File f;
    while(fbin.read((char*)&f,sizeof(f)))
    {
	   f.getname(P);
	   f.getpass(Q);
	   Cryption(P,Q);	
	}
	fbin.close();
	char opt;
	int k=1;
	int l=0;
	do
	{	
	 do
	 {
	  system("cls");
	  cout.width(50);
	  cout << "FILE ACCESSING POINT" << endl << endl;
	  cout.width(50);
	  cout << "Available Files are: " << endl << endl;
	  ifstream fin("FileDatabase.dat",ios::binary|ios::in);
	  File f;
	  while(fin.read((char*)&f,sizeof(f)))
	  {
	     cout.width(35);
	     char fname[20];
	     f.getname(fname);
	     cout << "-->" << fname << endl << endl;	
	  }
	  fin.close();
	  ifstream fin2("FileDatabase.dat",ios::binary|ios::in);
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
      cin.getline(FileName,20);
      cout << endl;
	  while(fin2.read((char*)&f,sizeof(f)) && k!=0)
	  {
	     char flname[20];
	     f.getname(flname);
 		 k=strcmp(FileName,flname);	
 	  }
 	  fin2.close();
	  if(k!=0)
	  {
	     system("cls");		
	  }
	  l++;
	 }while(k!=0);
	 ifstream fin3("FileDatabase.dat",ios::binary|ios::in);
	 File z;
	 char flpass[20];
	 int r=1;
	 while(fin3.read((char*)&z,sizeof(z)) && r!=0)
	 {
	    char flname[20];
	    z.getname(flname);
	    r=strcmp(flname,FileName);
	    if(r==0)
	    z.getpass(flpass);
	 }	
	 cout.width(45);
	 cout << "Enter password : ";
	 char c;
     int h=0;
     c=getch();
     while(c!=13 && h<20)
     {
	   if(c!=8)
	   {
	    cout << "*";
	    Password[h]=c;  
	    h++;
	   }
	   if(c==8)
	   {
	     if(h!=0)
	     {
 		  cout << c;
 		  cout << " ";
 		  cout << c;
		  h--;
		 }
		 if(h==0)
		 ;		
	   }
	   c=getch();	
	 }
	 Password[h]='\0';
	 if(strcmp(Password,flpass)==0)
	 {
	    Cryption(FileName,Password);
        cout << endl << endl << endl;
        cout.width(45);
        for(int i=0;i<2;i++)
        {
	      cout << "LOADING";
	      Sleep(500);	
	      cout << ".";
	      Sleep(500);	
	      cout << ".";
	      Sleep(500);	
	      cout << ".";
	      Sleep(500);
 		  for(int j=1;j<=10;j++)
 	      cout << (char)8 << " " << (char)8;	
        }
	   system(FileName);
	 }
	 else
	 { 
	    system("cls");
        system("COLOR FC");
	    cout.width(445);
	    for(int i=1;i<=3;i++)
	    {	
	      cout << "ACCESS DENIED!!!";
	      Sleep(500);
	      for(int j=1;j<=16;j++)
	      cout << (char)8 << " " << (char)8;
	      Sleep(500);
	      cout << "INVALID PASSWORD!!";
	      Sleep(500);
	      for(int j=1;j<=18;j++)
	      cout << (char)8 << " " << (char)8;
	      Sleep(500);
	    } 
	    system(FileName);
	 }
	 system("cls");
	 cout << endl << endl << endl;
	 cout.width(40);
	 system("COLOR F0");
	 cout << "Do you wish to continue(Y/N): ";
	 cin >> opt;
	 k=1;
	 l=-1;
	 if(!(opt=='Y' || opt=='y'))
	 {
	  Sleep(1000);
	  exit(0);
     }
    }while(opt=='Y' ||opt=='y');
}
