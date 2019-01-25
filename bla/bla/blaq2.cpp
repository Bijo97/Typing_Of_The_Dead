//#include<iostream>
//#include<fstream>
//using namespace std;
//
//void main(){
//	int nilai=1000;
//	int temp;
//	int misal[10];
//	int cek=0;
//	int cek2=10;
//	fstream nama;
//	nama.open("makan.txt", ios::in);
//	while(!nama.eof()){
//		nama>>misal[cek];
//		cek++;
//	}
//	for(int i=0; i<cek;i++){
//		for(int j=0; j<cek-1; j++){
//			if(misal[j]>misal[j+1]){
//				int temp;
//				temp=misal[j];
//				misal[j]=misal[j+1];
//				misal[j+1]=temp;
//			}
//		}
//	}
//	for(int i=0; i<cek; i++){
//		if(nilai>misal[i]){
//			for(int j=i+1; j<cek; i++){
//				temp=misal[j];
//				misal[j]=misal[j];
//				misal[j+1]=temp;
//			}
//			misal[i]=nilai;
//		}
//	}
//	nama.close();
//	/*nama.open("makan.txt", ios::out);
//	for(int i=0; i<cek; i++){
//		nama<<misal[i]<<endl;
//	}
//	nama.close();*/
//}
//
//
