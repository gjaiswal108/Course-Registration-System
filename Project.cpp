//-------Source Code for Course Registration System-------//
/* Created by
	Gaurav Jaiswal
*/
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<windows.h>
using namespace std;
//Function declarations
class CourseRegistration{
	char name[50],fname[50],username[20],password[20],password1[20],course[50],email[50],mob[11],address[100],hper[5],iper[5];
	fstream file;
	public:
		void Register();
		void Login();
		void MainMenu();
};
//Driver-function
int main(){
	system("color F4");
	CourseRegistration obj;
	obj.MainMenu();
	
}
//For register
void CourseRegistration:: Register(){
	
	cout<<"---------------------------Register---------------------------\n\n";
	cout<<"Enter your name: ";
	fflush(stdin);
	gets(name);
	cout<<"Enter your father's name: ";
	fflush(stdin);
	gets(fname);
	cout<<"Enter your email id: ";
	fflush(stdin);
	gets(email);
	cout<<"Enter your contact number: ";
	fflush(stdin);
	gets(mob);
	cout<<"Enter your address: ";
	fflush(stdin);
	gets(address);
	cout<<"Enter your High School percentage: ";
	cin>>hper;
	cout<<"Enter your Intermediate percentage: ";
	cin>>iper;
	cout<<"\nSelect your course choice:\n\n";
	cout<<"1.Civil Engineering\n";
	cout<<"2.Computer Science and Engineering\n";
	cout<<"3.Electrical Engineering\n";
	cout<<"4.Electronics and Communiction Engineering\n";
	cout<<"5.Mechanical Enginering\n";
	cout<<"6.Chemical Engineering\n";
	int choice;
	do{
		cin.clear();
		fflush(stdin);
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"Your selected choice is: ";
			cout<<"Civil Engineering\n";
			strcpy(course,"Civil Engineering");break;
		case 2:
			cout<<"Your selected choice is: ";
			cout<<"Computer Science and Engineering\n";
			strcpy(course,"Computer Science and Engineering");break;
		case 3:
			cout<<"Your selected choice is: ";
			cout<<"Electrical Engineering\n";
			strcpy(course,"Electrical Engineering");break;
		case 4:
			cout<<"Your selected choice is: ";
			cout<<"Electronics and Communiction Engineering\n";
			strcpy(course,"Electronics and Communiction Engineering");break;
		case 5:
			cout<<"Your selected choice is: ";
			cout<<"Mechanical Enginering\n";
			strcpy(course,"Mechanical Enginering");break;
		case 6:
			cout<<"Your selected choice is: ";
			cout<<"Chemical Engineering\n";
			strcpy(course,"Chemical Engineering");break;
		default:
			cout<<"Invalid choice,try again\n";
		}
	}while(choice>6||choice<1);
	while(1){
	cout<<"Enter your username: ";
	cin>>username;
	file.open(username);
	if(file){
		cout<<"Username already exist,try different\n\n";
		file.close();
	}
	else{
		file.close();break;
	}
	}
	while(1){
		char ch;int i=0;
	cout<<"Enter your password: ";
	ch=getch();
	while(ch!=13){
	password[i++]=ch;
	cout<<"*";
	ch=getch();
	}password[i]='\0';i=0;
	cout<<endl;
	cout<<"Re-enter your password: ";
	ch=getch();
	while(ch!=13){
	password1[i++]=ch;
	cout<<"*";
	ch=getch();
	}password1[i]='\0';
	cout<<endl;
	if(strcmp(password,password1)==0)
		break;
	cout<<"Password mismatched,try again\n";
	}
	file.open(username,ios::out);
	file<<"Name: "<<name<<endl;
	file<<"Father's name: "<<fname<<endl;
	file<<"Course name: "<<course<<endl;
	file<<"Email: "<<email<<endl;
	file<<"Contact: "<<mob<<endl;
	file<<"Address: "<<address<<endl;
	file<<"High School percentage: "<<hper<<endl;
	file<<"Intermediate percentage: "<<iper<<endl;
	file.close();
	file.open("data",ios::app);
	file<<username<<" ";
	file<<password<<" ";
	file.close();
	cout<<"\n\nRegistered successfully\n\n\n";
	cout<<"---------------------------------\n";
	cout<<"Press any key for main menu . . . \n";
			getch();
			system("cls");
			MainMenu();
	
}
//For login
void CourseRegistration:: Login(){
	char username[20],password[20],ch;
	int i=0;
	cout<<"---------------------------Login---------------------------\n\n";
	cout<<"Enter username: ";
	cin>>username;
	cout<<"Enter password: ";
	ch=getch();
	while(ch!=13){
	password[i++]=ch;
	cout<<"*";
	ch=getch();
	}i=0;
	cout<<endl;
	ifstream file("data");
	if(!file){
		cout<<"Data not found\n";
		exit(0);	
	}
	char s1[20],s2[20],temp=1;
	while(!file.eof()){
		file>>s1;file>>s2;
		if((strcmp(username,s1)==0)&&(strcmp(password,s2)==0)){temp=0;
			file.close();
			system("cls");
			ifstream f1(username);
			char ch;
			f1.get(ch);
			while(!f1.eof()){
				cout<<ch;
				f1.get(ch);	
			}f1.close();
			cout<<"\n\n\n---------------------------------\n";
			cout<<"Press any key for main menu . . . \n";
			getch();
			system("cls");
			MainMenu();
			getch();break;
		}
	}if(temp)
		{
			cout<<"\nInvalid username/password\n\n\n";
			file.close();
			cout<<"---------------------------------\n";
			cout<<"Press any key for main menu . . . \n";
			getch();
			system("cls");
			MainMenu();
		}
	
}
//Front page(main menu) of program
void CourseRegistration:: MainMenu(){
	cout<<"---------------------------Main Menu---------------------------\n\n";
	cout<<"Enter your option:\n";
	cout<<"1.Register\n2.Login\n3.Exit\n\n";
	char ch;
	cin>>ch;
	system("cls");
	switch(ch){
		case '1':
			Register(); break;
		case '2':
			Login(); break;
		case '3':
			exit(0);break;
		default:
			cout<<"Invalid option,try again\n\n";
			MainMenu();
	}
}
