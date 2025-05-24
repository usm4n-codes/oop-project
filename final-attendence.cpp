#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
	int k;
	ifstream finp;
	finp.open("colindex.txt");
	finp>>k;
	finp.close();
	ofstream fiout;
	fiout.open("colindex.txt");
	fiout<<++k;
	fiout.close();
string a[10][k],line;
	ifstream fin;
	fin.open("attendence-practice.txt");
	stringstream sep;
	for(int i=0;i<10;i++)
	{
		getline(fin,line);
		sep.clear();
		sep.str(line);
		for(int j=0;j<k;j++)
		{
			getline(sep,a[i][j],'|');
		}
		
	 //getline(fin,a[i]);
	}
	fin.close();
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<k;j++)
		{
			cout<<a[i][j]<<"|";
		}
		cout<<endl;
	}
	ofstream fout;
	char aten;
	fout.open("attendence-practice.txt");
	for(int i=0;i<10 ;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(j>k-2)
			{
				en:
				cout<<"enter attendence of roll no "<<a[i][1]<<" :";
				cin>>aten;
				if(aten=='a'||aten=='A'||aten=='p'||aten=='P')
				{
					a[i][j]=toupper(aten);
				}
				else
				{
					cout<<"wrong input try again "<<endl;
					goto en;
				}
			}
			fout<<a[i][j]<<"|";
		}
		fout<<endl;
	}
	fout.close();
	system("cls");
	fin.open("attendence-practice.txt");
	if(!fin.is_open())
	{
		cout<<"error ";
	}
    string output;
    while (getline(fin, output)) 
	{ 
        cout << output << endl;
    }
    fin.close();
    return 0;

}
