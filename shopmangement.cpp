#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <cstring>
#include<stdio.h>
using namespace std;
class file{
 public:
     file(){
     ofstream out("out.txt");
     out<<" HELLO IN OUR SHOP !! *-*"<<endl;
     out.close();

     }
};
class earn{
  public:
  double profite;
  ifstream x{"file.txt"};
  void show(){
        if(x)
        cout<<"PROFIT = 0 ";
        else{
        x>>profite;
        cout<<"\nTOTAL STARTING PROFIT:  "<<profite<<endl;
        x.close();
        }
  }
};
class product :public virtual earn {
    public: //show profit
    int quantitiy;
    char name[10];
    char id[10];
    double percost,persell,cost,sell;
    void call(){
    cost=percost*quantitiy;
    sell=persell*quantitiy;
    profite=profite +(sell-cost)*365; //profit every year

    }
    void file();
    void get();
};
void product::get(){
int num=0;
cout<<"enter the number of products you want to buy :"<<endl;
cin>>num;
for (int i=0;i<num;i++){
  cout<<"\n input product name: \n";
  cin>>name;
  cout<<"\n input product id: \n";
  cin>>id;
  cout<<"\n input cost price of product: \n";
  cin>>percost;
  cout<<"\n input selling price of product: \n";
  cin>>persell;
  cout<<"\n total product quantity: \n";
  cin>>quantitiy;  //quantity of one product
   call();
   file();
}
}
void product::file(){
  char file[20];
  strcpy(file,id);
  strcat(file,".txt");
  ofstream f (file);
  f<< "\n product name: "<<name<<endl;
  f<< "\n product id: "<<id<<endl;
  f<<"\n cost price of product: " <<percost<<endl;
  f<<"\n selling price of product: "<<persell<<endl;
  f<<"\nquantity: "<<quantitiy<<endl;
  f<<"\n total cost: "<<cost<<endl;
  f<<"\nsell: "<<sell<<endl;
  f.close();

}
class stuff :public virtual earn{
//salary,posy,empid,postquantity
  public :
  int num_emp;
  double salary;
  char empid[10],nameemp[10];
  void cal()
         {
		 profite=(profite-salary*num_emp)*12;
         }
   void getstaff();
   void filestaff();

};
void stuff::getstaff(){
  cout<<"enter salary :"<<endl;
  cin>>salary;
  cout<<"enter number number of emplyees :"<<endl;
  cin>>num_emp;
  for (int i=0;i<num_emp;i++){
     cout<<"enter employee name :"<<endl;
  cin>>nameemp;
  cout<<"enter number id of emplyees :"<<endl;
  cin>>empid;
  }
  cal();
  filestaff();

}
void stuff::filestaff(){
char file[20];
strcpy(file,empid);
strcat(file,".txt");
ofstream f(file);
f<< "\n number of working employees: "<<num_emp<<endl;
f<< "\n employee salary: "<<salary<<endl;
f<<"\n employee name :"<<nameemp<<endl;
f<<"\n employee id: "<<empid<<endl;
f.close();
}
class amount :public product,public stuff{
    public:
    void add();
    void update_item();
    void update_emp();
};
void amount::add(){

while(1){
    char ch;
  cout<<"enter from menue :"<<endl;
  cout<<"1-for customer :"<<endl;
  cout<<"2-for employee :"<<endl;
   cout<<"3-exit:"<<endl;
   cin>>ch;
    if (ch=='1'){
       get();
       ofstream x("file.txt");
       x<<profite;
       x.close();

    }
    else if (ch=='2'){
       getstaff();
       ofstream  x("file.txt");
       x<<profite;
       x.close();

    }
    else if (ch=='3'){
        break;
    }
    else{
      cout<<"you enter invalid choice: "<<endl; }

}
}
void amount::update_item(){
    char id[20];
	char pid[20];
    char c;
    cout<<"\nINPUT product ID to modify\n";
    cin>>id;
    char file[20];
    char file2[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
    if(!fout)
    {
    	cout<<"file couldn't be opened. product ID not found. \n";
	}
	else {
	cout<<"file found! \n";
    cout<<"\n update product name: \n";
  	cin>>name;
 	cout<<"\nupdate percost of product: \n";
  	cin>>percost;
 	cout<<"\nupdate persell of product: \n";
  	cin>>persell;
 	cout<<"\nupdate total product quantity: \n";
 	cin>>quantitiy;
    cost=percost*quantitiy;
    sell=persell*quantitiy;
	profite=profite +(sell-cost)*365;
  	fout<<"\nproduct name: "<<name<< "\nproduct id: "<<id<<"\npercost ofproduct: " <<percost<<"\npersell of product: "<<persell<<"\nquantity: "<<quantitiy<<"\n total cost: "<<cost<<"\nsell: "<<sell;
	fout.close();
}
}
void amount::update_emp(){
 char id[20];
    char c;
    cout<<"\nINPUT employee ID to modify: ";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
     if(!fout)
    {
    	cout<<"file couldn't be opened. product ID not found. \n";
	}
	cout<<"modify employee name: \n";
  	cin>>nameemp;
  	fout<< "\n number of working employees: "<<num_emp<< "\n employee salary: "<<salary<< "\n employee name :"<<nameemp<<"\n employee id: "<<empid;
 	fout.close();
}
void admin(){
while(1){
cout<<"==============================\n";
cout<<"\n WELCOME TO THE SHOP  \n";
cout<<"==============================\n\n";
cout<<"\n* * * * * * * * * * * * * * * *\n";
cout<<"\n. 1-Add Entries\n. 2-Show profit.\n 3-Search Product Details\n 4-Search Employee Details\n 5-Modify Product Details\n 6-Modify Employee Details\n 7- Exit\n";
cout<<"\n Select your choice\n";
int choice;
cin>>choice;
if(choice==1)
  {
  amount a;
  a.show();
  a.add();
}
  else if(choice==2)
  {
  amount d;
  d.show();
}
  else if(choice==3)
  {
   char id[20];
   char c;
    cout<<"\nINPUT ID to search\n";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    ifstream x(file);
    if(!x)
    {
    	cout<<"file couldn't be opened. product ID not found. \n";
	}
    while(x)
    {x.get(c);
     cout<<c;
    }


    x.close();
}
   else if(choice==4)
   {
   	char eid[20];
   	char d;
   	cout<<"\nINPUT employee ID to search\n";
    cin>>eid;
   	char file[20];
   	strcpy(file,eid);
   	strcat(file,".txt");
   	ifstream y(file);
   	 if(!y)
    {
    	cout<<"file couldn't be opened. employee ID not found. \n";
	}
   	while(y)
   	{
   	y.get(d);
   	cout<<d;
   }

   y.close();
}
else if(choice==5)
{
	amount u;
	u.update_item();
}
 else if(choice==6)
 {
 	amount v;
 	v.update_emp();
 }
  else if(choice==7)
  {
  break;
}
  else cout<<"Invalid option. Please select one of the available options\n";
 }

}
int main()
{
int ch;
char  username[20];
char password[20];
char pwd[20];
    while(1){
        cout<<"\n=========================\n";
        cout<<"\ntWELCOME TO MY SHOP\n";
        cout<<"\n=========================\n\n";
        cout<<"\n* * * * * * * * * * * *\n ";
        cout<<"\n 1- ENTER SYSTEM\n";
        cout<<"\n 2-EXIT\n";
        cout<<"\n* * * * * * * * * * * *\n";
        cout<<"\nEnter Your choice: \n";
        cin>>ch;
        switch(ch){
            case 1:
                admin();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout<<"Enter valid choice\n";
                break;
        }
    }
    return 0;
}
