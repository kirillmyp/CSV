/*#include <iostream>
#include <cctype>

#ifndef _STACK_H
#define _STACK_H
#include "Stack.h"
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
/*
#define BUF_SIZE (sizeof(unsigned long))

class Pretook{
public:
	virtual void foo()=0;
	virtual void see_what()=0;
};

class Took:public Pretook{
public:
	void foo();
	void see_what();
};

void Took::see_what(){
	cout<<"hello beach\n";
	return;
}

void Took::foo(){}


/*
template<typename T>
class Foo{
public:
	Foo();
	~Foo();
	void took();
};
template<typename T>
void Foo<T>::took(){
	cout<<"asd\n";
	return;
}



void correct(Pretook& object){
	object.see_what();
	return;
}
*/
class CsvKey{
public:
	CsvKey(){};

	vector<string> find(string str){
	//cut key
	string temp1;
	vector<string> vec;
	for(int i=0;i<str.length();++i){
		if(str[i]==','){
			temp1=str.substr(0,i);
			//cout<<temp1<<endl;
			vec.push_back(temp1);
			vec.push_back(str.substr(i,str.length()));
		}
	}
	return vec;
}

	void SortVector(vector<vector<string>> &vec){
	//сортировка
	//sorting result in vectors
	vector<string> tempvec,tempvec2;	
	for(int i=1;i<vec.size();++i){		
		tempvec=vec[i];
		if(atoi(vec[i-1][0].c_str())>atoi(tempvec[0].c_str())){
			tempvec2 = vec[i-1];
			vec[i-1]=tempvec;
			vec[i]=tempvec2;
			if(i>0){
				i=i-1;
			}
			if(i>0){
				i=i-1;
			}
		}
	}
}

	void FillList(ifstream &file,vector<vector<string>> &vec){
	//fill empty vectors
	string str;
	while(!file.eof()){
		file>>str;
		vec.push_back(find(str));
		}

}

	void DoResult(ofstream &file,vector<vector<string>> &vec,vector<vector<string>> &vec2){
	//Do it result 
	for(int i=0;i<vec.size();++i){
		for(int j=0;j<vec2.size();++j){
			if(vec[i][0]==vec2[j][0]){
				file<<vec[i][0]<<vec[i][1]<<vec2[j][1]<<"\n";
			}
		}
	}

}

};

int main(){
/*		countsum();
	Stack<int> ob(10);
	ob.See();	
	Took ob;

	correct(ob);
unsigned char a[BUF_SIZE];
unsigned long b = sizeof(a) / sizeof(a[0]);
cout<<b;
	system("pause");
	return 0;*/
	CsvKey ob;
	ifstream firstfile("input_A.csv");
	ifstream secondfile("input_B.csv");
	char ch;
	string str;
	vector<vector<string>> vec,vec2;
	ob.FillList(firstfile,vec);
	ob.FillList(secondfile,vec2);	
	firstfile.close();
	secondfile.close();
	ob.SortVector(vec);
	ob.SortVector(vec2);
	ofstream thirdfile("result.csv");
	thirdfile.clear();
	ob.DoResult(thirdfile,vec,vec2);
	thirdfile.close();
	}


//#endif // !_STACK_H