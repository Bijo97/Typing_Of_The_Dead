#include<fstream>
#include<iostream>
#include <fstream>
using namespace std;

void main()
{
	int score = 1200;
	int mydata[10];
	int jumlah = 0;
	ifstream OutputFile("Scroes.txt");
	for(int i=0; i<10; i++){
		OutputFile>>mydata[i];
		cout<<mydata[i]<<endl;
	}
	OutputFile.close();
	ofstream InputFile("Scroes.txt");
	if(InputFile.is_open()){
		for(int i=0; i<10; i++){
			for(int j=0; j<9; j++){
				if(mydata[j]<mydata[j+1]){
					int temp;
					temp=mydata[j];
					mydata[j]=mydata[j+1];
					mydata[j+1]=temp;
				}
			}
		}

		mydata[9] = score;

		for(int i=0; i<10; i++){
			for(int j=0; j<9; j++){
				if(mydata[j]<mydata[j+1]){
				int temp;
				temp=mydata[j];
				mydata[j]=mydata[j+1];
				mydata[j+1]=temp;
				}
			}
		}

		/*for(int i=0; i<10; i++){
			if(score>mydata[i]){
				for(int j=i; j<10; j++){
					for(int k=i; k<9;k++){
						int temp;
						temp=mydata[k];
						mydata[k]=mydata[k+1];
						mydata[k+1]=temp;	
					}
				break;
				}
				mydata[i]=score;
				break;
			}
		}*/
	}
	for(int i=0; i<10; i++){
		InputFile<<mydata[i];
		InputFile<<endl;
	}
	InputFile.close();
}

void LihatHighScore(){
	int mydata[10];
	ifstream LihatScore("Scroes.txt");
	for(int i=0; i<10; i++){
		LihatScore>>mydata[i];
		cout<<mydata[i]<<endl;
	}
}