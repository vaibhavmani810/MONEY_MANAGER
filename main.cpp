#include<iostream>

using namespace std;
#include"Network.h"

int main(){
	Network friends;

	cout<<"\t--------------MONEY MANAGER---------------"<<endl;
	cout<<endl;
	cout<<"\t1. Add a new Transaction "<<endl;
	cout<<"\t2. View all Transactions "<<endl;
	cout<<"\t3. Optimise the Transactions "<<endl;
	cout<<"\t4. Exit"<<endl;
	cout<<endl;

	int ch=1;
	while(ch!=4){
		cout<<"\tChoose an option : ";
		cin>>ch;
		if(ch==1){
			string dnr,brwr;
			int amt;
			cout<<"\tEnter Donor's Name : ";
			cin>>dnr;
			cout<<"\tEnter Reciever's Name : ";
			cin>>brwr;
			cout<<"\tEnter Amount : ";
			cin>>amt;
			friends.addTransaction({dnr,brwr,amt});
			cout<<"\tAdded Successfully"<<endl;
			cout<<endl;
		}
		else if(ch==2){
			friends.print();
		}
		else if(ch==3){
			friends.optimiseTransaction();
		}
		else if(ch!=4){
			cout<<"\tWrong Choice ! Enter again! "<<endl;
		}
	}
	cout<<"\tThank You "<<endl;
	return 0;
}
