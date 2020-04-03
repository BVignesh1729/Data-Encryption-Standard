#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>

using namespace std;

class File
{
   char name[20];
   char password[20];
   public:
   void accept()
   {
    cout.width(30);
	cout << "Enter File name(along with extension) : ";
	cin.getline(name,20);
	cout << endl << endl;
	cout.width(30);
	cout << "Enter Password : ";
	cin.getline(password,20);		
   }
   void modifyaccept()
   {
    cout.width(45);
    cout << "Modification: " << endl << endl;
    cout.width(30);
	cout << "Enter File name(along with extension) : ";
	cin.getline(name,20);
	cout << endl << endl;
	cout.width(30);
	cout << "Enter Password : ";
	cin.getline(password,20);		
   }
   void getname(char N[])
   {
     strcpy(N,name);		
   }
   void getpass(char M[])
   {
      strcpy(M,password);		
   }
};
