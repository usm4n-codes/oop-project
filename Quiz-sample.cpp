#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Quiz
{
	private:
		string  pen, complete ;
		int CorrectAns, i,answer[20],UserOption ;
	public:
		void Sample()
		{
			cout << "\t\tQuiz Sample" << endl ;
			cout << "Q1.LED stands for:" << endl ;
			cout << "Option 1.Light Emitting diode" << endl ;
			cout << "Option 2.Light Emit diode" << endl ;
			cout << "Option 3.Light Emmit Diode" << endl ;
			cout << "Option 4.Light Emiting Diode" << endl ;
			cout << "Corrcet Option: 1" << endl ;
		}
		
		void Create()
		{
			ofstream cre, ans ;
			cre.open ("create.txt") ;
			ans.open ("ans.txt") ;
			i = 0 ;
			cout << "\n-------Create Quiz-------" << endl ;
			
			do
			{
				cout << "Q" << i+1 << "." ;
				getline(cin,pen) ;
				cre << "Q" << i+1 << "." << pen << endl ;
				
				cout << "Option 1." ;
				getline (cin,pen) ;			
				cre << "1." << pen ;
				
				cout << "Option 2." ;
				getline (cin,pen) ;
				cre << "\t2." << pen ;
				
				cout << "Option 3." ;
				getline (cin,pen) ;
				cre << "\t3." << pen ;
				
				cout << "Option 4." ;
				getline (cin,pen) ;
				cre << "\t4." << pen << endl ;	
				
				cout << "Correct Option: " ;
				getline (cin,pen) ;
				ans<< pen<<endl ;
				cre << "Correct Option for Q" << i+1 << "." << pen << endl ;

				i++ ;
				cout << "Enter y to end this Quiz Otherwise Enter Any other No OR Alphabet: " ;
				getline (cin,complete) ;
				cout << endl ;
			}while(complete!="y");
			cre.close();
			ans.close();
		}
		
		void take()
		{
			system ("cls") ;
			int linesprint = 1 ;
			CorrectAns = 0 ;
			ifstream ifs,ans;
			i = 0 ;
			ifs.open ("create.txt") ;
			ans.open("ans.txt");
			while(ans>>answer[i]){
            i++;
			}
			ans.close();
			i=0;
			cout<<"\n\n-------Quiz Started-------"<<endl;
			while (!ifs.eof())
			{
				getline (ifs,pen) ;
				if (linesprint%3!=0)
				{
					cout << pen ;
					cout << endl ;
				}
				else
				{
					cout << "\nEnter Correct Option : " ;
					cin >> UserOption ;
					cin.ignore();
					if (UserOption == answer[i])
					{
						cout<<"good";
						CorrectAns++ ;
					}
					cout << endl ;
					i++ ;
				}
				linesprint++ ;
			}
			ifs.close() ;
		}
		
		void Result()
		{
			float avg ;
			avg = (CorrectAns/(float)i) * 100 ;
			cout << "\n\n-------Result-------" << endl ;
			cout << "Your Total Score is " << CorrectAns <<" out  of " << i << endl ;
			cout << "Average of Your Score is : " << avg << "%" << endl ;
		}
};

int main()
{
	Quiz Q1 ;
	Q1.Sample();
	Q1.Create();
	Q1.take();
	Q1.Result();
	system("pause");
	return 0;
}
