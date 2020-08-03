/*
	This was originally developed in Turbo C, but later modified for gcc
*/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<process.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
int N, number_of_lines;
int * arr = new int[100];

class contest
{
		int roll;
		float x;
		char name[20],question_string[100],ans[100];
		void questions();
	public:
		contest()
		{
			x=0.0;
		}
		void rndm(int ar[10]);
		void init();
		void conductQuiz(int q,int ar[10]);
		void selectQNo();
		void display();
		void edit();
		void findLines();
};
void contest::selectQNo()
{
	ifstream in;
	char A;
	int i=1;
	rndm(arr);
	//questions();
	in.open("ques.txt");
	{
		while(i<11)
		{
			cout<<i<<")";
			conductQuiz(i-1,arr);
			i++;
		}
		return;
	}
	in.close();
}
void contest::conductQuiz(int p,int array[])
{
	ifstream in,fin;
	in.open("ques.txt");
	fin.open("ques.txt");
	char A,answer;
	int i=0,j=1,cur_line_no=0,q_no;
	while(!fin.eof())
	{
		i++;
		if(i%5==1)
			in>>q_no;
		if(q_no==array[p])
		{
			do
			{
				fin.getline(question_string,100);
				cur_line_no++;
			}
			while(cur_line_no<(q_no-1)*5+2);
			cout<<endl<<question_string<<endl;
			{
				if(j%5==3)
				{
					fin.get(A);
				lb:
					cout<<"\nEnter your choice: ";
					cin>>ans;
					i=-1;
					j=-1;
					answer=tolower(ans[0]);
					//if() goto lb;
					if(answer<'a'||answer>'d')
					{
						cout<<"Invalid Option";
						goto lb;
					}
					else if(answer==A)
					{
						x=x+5;
						cout<<"your answer is correct\n";
					}
					else
					{
						if(x>0)
							x=x-2.5;
						cout<<"wrong answer\n";
						cout<<"the correct answer is "<<A<<endl;
					}
					system("pause");
					system("cls");

					cout<<endl<<endl;
					return;
				}
				j++;
			}
		}

		if(i%5==1)q_no++;
	}
	in.close();
	fin.close();
}
void contest::rndm(int p[])
{
	//randomize();
//shuffle p
 for (int i = 0; i < N; i++)       // fill array
		p[i] = i;
	for (int i=0; i<N; i++)
	{
		int temp=p[i];
		int random_index=rand()%N;
		p[i] = p[random_index];
		p[random_index] = temp;
	}
	int ar[10];
	//copy first n elements from p to arr
	for ( int i=0; i<10; ++i)
		ar[i] = p[i];
}
/*void contest::questions()
{
	ofstream file;
	file.open("ques.txt");
	file<<"1\n  When computer was first invented?\n";
	file<<" a.1820  \t  b.1823\n";
	file<<" c.1834  \t  d.1922\n";
	file<<'a'<<"\n";
	file<<"2\n Which day is celebrated as 'World Computer Literacy day'?\n";
	file<<" a.October 6 \t b.December 2\n";
	file<<" c.October 4 \t d.May 15\n";
	file<<'b'<<"\n";
	file<<"3\n Who is known as human computer of India?\n";
	file<<" a. Sundar Pichai   \t b.Sathya Nathella\n";
	file<<" c. Shakunthala Devi\t c.Derek o brein\n";
	file<<'c'<<"\n";
	file<<"4\n 'Do no evil' is the tag line of\n";
	file<<" a. Adobe \t b. Microsoft\n";
	file<<" c. Linux \t d. Google\n";
	file<<'d'<<"\n";
	file<<"5\n Extension of PDF\n";
	file<<" a. Portable Document Format \t b. Personal Document Format\n";
	file<<" c. Portable Digital format  \t d. Presentation Document Format\n";
	file<<'a'<<"\n";
	file<<"6\n Which company invented floppy disk?\n";
	file<<" a. Microsoft \t b. Apple\n";
	file<<" c. Intel     \t d.IBM\n";
	file<<'a'<<endl;
	file<<"7\n IC chips are usually made of\n";
	file<<" a. Lead      \t b. Silicon\n";
	file<<" c. Chromium  \t d. Gold\n";
	file<<'b'<<endl;
	file<<"8\n Technology no longer protected by copyrights and available to all is \n";
	file<<" a. Proprietary  \t b. Open\n";
	file<<" c. Experimental \t d. Free\n";
	file<<'a'<<endl;
	file<<"9\n In binary language each alphabet is made up of unique combination of \n";
	file<<" a. 8 bytes     \t b.8 kbytes\n";
	file<<" c. 8 character \t d. 8 bits\n";
	file<<'d'<<endl;
	file<<"10\n The term bit is short for\n";
	file<<" a. Byte         \t b. Binary language\n";
	file<<" c. Binary digit \t d.Binary number\n";
	file<<'c'<<endl;
	file<<"11\n Who invented graphical use interface(GUI)?\n";
	file<<" a.Microsoft \t b.Apple\n";
	file<<" c.Xerox     \t d. IBM\n";
	file<<'c'<<endl ;
	file<<"12\n What is the transfer rate of a satandard USB2.0?\n";
	file<<" a.100Mbit/s \t b.480 Mbit/s\n";
	file<<" c.1 Gbit/s  \t c. 250 Mbit/c\n";
	file<<'b'<<endl;
	file<<"13\n Who invented USB?\n";
	file<<" a. HP    \t b.Samsung\n";
	file<<" c. Intel \t d. AMD\n";
	file<<'c'<<endl;
	file.close();
}*/
void contest::edit()
{
	char password[25],q[100],a[100],b[100],c[100],d[100],answer;
	int no;
	cout<<"enter password \t";
	cin>>password;
	if(strcmp(password,"admin")==0)
	{
		ofstream out;
		out.open("ques.txt",ios::app);
		out<<++N<<endl;
		cout<<"Enter question\n";
		cin.ignore();cin.getline(q,100);
		out<<" "<<q<<"\n";
		cout<<"enter options\n";
		cout<<"Enter option a\n";
		cin.ignore();cin.getline(a,100);
		out<<" a. "<<a<<"\t\t";
		cout<<"Enter option b\n";
		cin.ignore();cin.getline(b,100);
		out<<"b. "<<b<<"\n";
		cout<<"Enter option c\n";
	 cin.ignore();cin.getline(c,100);
		out<<" c. "<<c<<"\t\t";
		cout<<"Enter option d\n";
		cin.ignore();cin.getline(d,100);
		out<<"d. "<<d<<"\n";
		cout<<"enter correct option\n";
		cin>>answer;
		out<<answer<<"\n";
		out.close();
	}
}
void contest::init()
{
	cout<<"Contestant name    : ";
	gets(name);
	cout<<"Contestant roll no : ";
	cin>>roll;
}
void contest::display()
{
	cout<<"\nResult: "<<name<<" got "<<x<<" marks out of 50 \n";
}
void contest::findLines()
{
	FILE *fd = NULL;
	int cnt, ch;

	fd = fopen("ques.txt","r");
	if (fd == NULL)
	{
		perror("ques.txt");
		exit(-1);
	}
	while(EOF != (ch = fgetc(fd)))
	{
		if (ch == '\n')
			++number_of_lines;
	}
	N=number_of_lines/5;
}
int main()
{
	system("cls");
	contest r;
	cout<<" \n\n\n\t\t\t Quiz Contest\n";
	cout<<"GENERAL INSTRUCTIONS\n";
	cout<<"This is a multiple choice quiz contest.\n";
	cout<<"5 points will be awarded for each correct answer and\n";
	cout<<"\t2.5 marks will be DEDUCTED for each wrong answer.\n";
	cout<<"If more than one options are entered,";
	cout<<"\n\t FIRST OPTION to be entered will be considered\n";
//cout<<"Press any key to continue\n";
	system("pause");
	system("cls");
	cout<<endl<<endl;
	r.init();
	r.findLines();
	char reply;
	do
	{
		cout<<"\nSelect your choice \n\t1 Start\n\t2 Display results\n\t3 Add questions\n";
		cout<<"\t0 Quit\n";
		//cout<<"number of questions "<<N<<endl;
		int c;
		cin>>c;
		system("cls");
		switch(c)
		{
			case 1:
				r.selectQNo();
				break;
			case 2:
				r.display();
				break;
			case 3:
				r.edit();
				break;
			case 0:
				cout<<"\n\n\nTHANKS FOR SPENDING YOUR VALUABLE TIME";
				cout<<"\nDone by Shivakumar\n";
				system("pause");
				system("cls");
				return 0;

			default:
				cout<<"wrong choice \n";
		}
		cout<<"\nenter your reply : Press y for continuing \t";
		cin>>reply;
	}
	while(reply=='y'||reply=='Y');
	system("cls");
	cout<<"\n\n\nTHANKS FOR SPENDING YOUR VALUABLE TIME";
	cout<<"\nDone by Shivakumar\n";
	system("pause");

	return 0;
}

