#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class A 
{
	char *p;
	public:

	A()//default constructor
	{
		p=new char[0];
	}



	~A()
	{
		cout << "---Destructor---" << endl;
		if(p!=0)
			return;
		delete []p;

		cout << endl;
	}



	A(const char *s)//parametrized
	{
		p=new char[strlen(s)+1];
		strcpy(p,s);
	}

	A(const A &temp)//copy
	{


		p=temp.p;
	}


	void printdata()
	{
		cout<<"string=";
		for(int i=0;p[i];i++)		
			cout<<p[i];
		cout<<endl;

	}


	A operator =(const A &temp)
	{
		p=temp.p;
	}

	bool operator ==(A &temp)
	{

		if((strcmp(p,temp.p))==0)
			return true;
		else 
			return false;
	}


	bool operator >(A &temp)
	{

		if(strcmp(p,temp.p)>0)
			return 1;
		else 
			return 0;
	}
	bool operator <(A &temp)
	{

		if(strcmp(p,temp.p)<0)
			return 1;
		else 
			return 0;
	}


	bool operator >=(A &temp)
	{

		if(strcmp(p,temp.p)>=0)
			return 1;
		else 
			return 0;
	}


	bool operator <=(A &temp)
	{

		if(strcmp(p,temp.p)<=0)
			return 1;
		else 
			return 0;
	}


	bool operator !=(A &temp)
	{

		if(strcmp(p,temp.p)!=0)
			return 1;
		else 
			return 0;
	}

	A operator +(A &s2)
	{
		A ret;
		int i,j;
		ret.p=new char[strlen(p)+strlen(s2.p)+1];
		for(i=0;p[i];i++)
			ret.p[i]=p[i];

		ret.p[i]=32;//space ascii
		cout<<i<<endl;
		for(j=0,i=i-1;s2.p[j];j++,i++)
			ret.p[i]=s2.p[j];
		return ret;
	}

	//friend A operator +(A &t1,A &t2);
	friend istream& operator >>(istream &in,A &temp);

	friend ostream& operator <<(ostream &out,A &temp);
};


istream& operator >>(istream &in,A &temp)
{
	FILE *fp;
	char ch=0;
	int l=1;
	fp=fopen("data","w+");

	while(ch!='\n')
	{
		scanf("%c",&ch);
		fputc(ch,fp);
		l++;
	}
	rewind(fp);
	temp.p=new char[l+1];
	fgets(temp.p,l+1,fp);

	remove("data");
	return in;
}


ostream& operator <<(ostream &out,A &temp)
{
	out<<temp.p;
	return out;
}


main()
{
	int n;
	cout<<"enter size of string"<<endl;
	cin>>n;

	char s[n];
	cout<<"enter the string"<<endl;
	cin>>s;
	bool ret;
	A s1,s2(s),s3(s2), s4;
	cout<<"parametrized constructor"<<endl;
	s2.printdata();

	cout<<"copy constructor"<<endl;
	s3.printdata();
	int i;
	cout<<boolalpha;

	while(1)
	{
	cout<<endl<<"enter the choice"<<endl<<"1.Assignment(=)"<<endl<<"2.compare(==)"<<endl<<"3.(>)"<<endl<<"4.(<)"<<endl<<"5.(>=)"<<endl<<"6.(<=)"<<endl<<"7.(!=)"<<endl<<"8.concatnation"<<endl<<"9. Exit "<<endl;
		cin >>i;
		switch(i)
		{
			case 1:	
				cout<<"Assignment operator"<<endl;
//				s4=s2;
//				s4.printdata();
				break;

			case 2:
				cout<<"enter two data"<<endl;
				cin.ignore();	
				cin>>s1;
				cout << "Enter second string" << endl;
				cin>>s2;
				ret= s1==s2;
				cout<<ret<<endl;
				break;

			case 3:
				cout<<"enter two data"<<endl;
				cin.ignore();	
				cin>>s1;
				cout << "Enter second string" << endl;
				cin>>s2;

				ret= s1>s2;
				cout<<ret<<endl;
				break;


			case 4:
				cout<<"enter two data"<<endl;
				cin.ignore();	
				cin>>s1;
				cout << "Enter second string" << endl;
				cin>>s2;

				ret= s1<s2;
				cout<<ret<<endl;
				break;


			case 5:
				cout<<"enter two data"<<endl;
				cin.ignore();	
				cin>>s1;
				cout << "Enter second string" << endl;
				cin>>s2;

				ret= s1>=s2;
				cout<<ret<<endl;
				break;


			case 6:
				cout<<"enter two data"<<endl;
				cin.ignore();	
				cin>>s1;
				cout << "Enter second string" << endl;
				cin>>s2;

				ret= s1<=s2;
				cout<<ret<<endl;
				break;

			case 7:
				cout<<"enter two data"<<endl;
				cin.ignore();	
				cin>>s1;
				cout << "Enter second string" << endl;
				cin>>s2;

				ret= s1!=s2;
				cout<<ret<<endl;
				break;


			case 8:
				cout<<"enter two data"<<endl;
				cin.ignore();	
				cin>>s1;
				cout << "Enter second string" << endl;
				cin>>s2;

				//s4=s1+s2;
				//cout<<s4<<endl;

				break;
			case 9:
				return 0;


			default:
				cout<<"enter right chioce "<<endl;
		}

	}


}











