#include <iostream>
#include<windows.h>
using namespace std;
class bank{
private:
 char name[100],father[100],type[100],add[100];
 float balance,withdraw;
public:
bank(){
    for (int i=0;i<100;i++){
        name[i]='a';
        father[i]='a';
        type[i]='a';
        add[i]='a';
    }
    balance=0.0;

}
 void openaccount();
 void depositemoney();
 void withdrawemoney();
 void viewaccount();
};
void bank::openaccount(){
cout<<"--------------------hello in our bank -----------------------"<<endl;
cout<<"enter your name :"<<endl;
cin.ignore();
cin.getline(name,100);
cout<<"enter your father name :"<<endl;

cin.getline(father,100);
cout<<"enter type of account (save (s),current (c) :"<<endl;

cin.getline(type,100);
cout<<"enter your address :"<<endl;
cin.getline(add,100);
cout<<"enter your balance :"<<endl;
cin>>balance;
}
void bank::depositemoney(){
int amount=0;
cout<<"enter amount of money you want to deposite :"<<endl;
cin>>amount;
balance+=amount;
cout<<"your balance or current money :"<<balance<<endl;


}
void bank::withdrawemoney(){
int withdraw=0;
cout<<"enter amount of money you want to deposite :"<<endl;
cin>>withdraw;
balance-=withdraw;
cout<<"your balance or current money :"<<balance<<endl;

}
 void bank:: viewaccount(){
 cout<<" -------------thanks,your service is completed---------------"<<endl;
cout<<"your name is :"<<name<<father<<endl;

cout<<"your account type is :"<<type<<endl;
cout<<"your address is :"<<add<<endl;
cout<<"your balanced money is : "<<balance<<endl;
 }
 /////////////////////////another program for bank mangement system/////////////////////
 class bank2{
 public :
  int total;
  string Id;
  struct person{
   string name,id,address;
   int contact,cash;

  } person[100]; //maximum 100
 void choice();
  void persondata();
  void show();
  void update();
  void check();
  void trans();
  void del();
 bank2(){ total=0;
  Id=""; }


 };
  void bank2::choice(){
  char ch;
  while(1){
    cout<<"---------------hello in our bank2-------------"<<endl;
    cout<<"1-open account :"<<endl;
    cout<<"2--view customers list  :"<<endl;
    cout<<"3- update the information of account:"<<endl;
    cout<<"4- check the details of account"<<endl;
    cout<<"5-for transactions :"<<endl;
    cout<<"6-remove existing accont :"<<endl;
    cout<<"7-exit"<<endl;
    cin>>ch;
  switch(ch){
   case '1':
       bank2::persondata();
      break;
   case '2':
       bank2::show();
      break;
   case '3':
       bank2::update();
      break;
   case '4':
       bank2::check();
      break;
   case '5':
      bank2::trans();
      break;
   case '6':
       bank2::del();
      break;
   case '7':
       exit(1);
       break;
   default:
       cout<<"enter valid input"<<endl;
       break;

  }
  }
  }
   void bank2::persondata(){
   cout<<"enter the data for person "<<total+1<<endl; //notice!! there is no increament in fact in total it just a print
   cout<<"enter the name :"<<endl;
   cin>>person[total].name;
   cout<<"enter the id:"<<endl;
   cin>>person[total].id;
   cout<<"enter the address :"<<endl;
   cin>>person[total].address;
   cout<<"enter the cash :"<<endl;
   cin>>person[total].cash;
   cout<<"enter the contact :"<<endl;
   cin>>person[total].contact;
   total++;
   }
    void bank2::show(){
    for (int i=0;i<total;i++){
    cout<<"the data of person "<<i+1<<endl;
    cout<<"the name :"<<endl;
    cout<<person[i].name<<endl;
     cout<<"the id:"<<endl;
    cout<<person[i].id<<endl;
     cout<<"the address :"<<endl;
    cout<<person[i].address<<endl;
     cout<<"the cash :"<<endl;
    cout<<person[i].cash<<endl;
     cout<<"the contacy:"<<endl;
    cout<<person[i].contact<<endl;
    }

    }
      void bank2::update(){

      cout<<"enter the id of student you want to update:"<<endl;
      cin>>Id;
      for (int i=0;i<total;i++){
      if (Id==person[i].id){
        cout<<"the previous data is :"<<endl;
        cout<<"the name :"<<endl;
        cout<<person[i].name;
        cout<<"the id:"<<endl;
        cout<<person[i].id;
        cout<<"the address :"<<endl;
        cout<<person[i].address;
        cout<<"the cash :"<<endl;
        cout<<person[i].cash;
        cout<<"the contacy:"<<endl;
        cout<<person[i].contact;
        cout<<"enter the data you want to update:"<<endl;
        cout<<"enter the name :"<<endl;
       cin>>person[i].name;
       cout<<"enter the id:"<<endl;
       cin>>person[i].id;
       cout<<"enter the address :"<<endl;
       cin>>person[i].address;
       cout<<"enter the cash :"<<endl;
       cin>>person[i].cash;
       cout<<"enter the contact :"<<endl;
       cin>>person[i].contact;
       cout<<"your data is updated,thank you !!"<<endl;
       break;
      }
      }
      }
      void bank2::check(){
      cout<<"enter the id of student you want to search:"<<endl;
      cin>>Id;
      for (int i=0;i<total;i++){
      if (Id==person[i].id){
        cout<<"the data is :"<<endl;
        cout<<"the name :"<<endl;
        cout<<person[i].name<<endl;
        cout<<"the id:"<<endl;
        cout<<person[i].id<<endl;
        cout<<"the address :"<<endl;
        cout<<person[i].address<<endl;
        cout<<"the cash :"<<endl;
        cout<<person[i].cash<<endl;
        cout<<"the contact:"<<endl;
        cout<<person[i].contact<<endl;
        break;
      }}
      }
     void bank2::trans(){
      int cash1;
      char ch;
      cout<<"enter the id of student you want to search:"<<endl;
      cin>>Id;
      for (int i=0;i<total;i++){
      if (Id==person[i].id){
        cout<<"the name :"<<endl;
        cout<<person[i].name<<endl;
        cout<<"the id:"<<endl;
        cout<<person[i].id<<endl;
        cout<<"the address :"<<endl;
        cout<<person[i].address<<endl;
        cout<<"the cash :"<<endl;
        cout<<person[i].cash<<endl;
        cout<<"the contact:"<<endl;
        cout<<person[i].contact<<endl;
        cout<<"press 1 for deposit "<<endl;
        cout<<"press 2 for withdraw "<<endl;
        cin>>ch;
        switch(ch){
     case '1':
        cout<<"enter the amount of money you want to deposite :"<<endl;
        cin>>cash1;
        person[i].cash+=cash1;
        cout<<"your new cash is :"<<person[i].cash<<endl;
        break;
     case '2':
        back:
        cout<<"enter the amount of money you want to withdraw :"<<endl;
        cin>>cash1;
        if (cash1>person[i].cash) {
            cout<<"you have just a : "<<person[i].cash<<endl;
            Sleep(300);

            goto back ; }
        else  {
        person[i].cash-=cash1;
        cout<<"your new cash is :"<<person[i].cash<<endl;
        break;
        }
     default:
        cout<<"enter valid input:"<<endl;
        break;
        }
        break;
     }
      if (i==total-1)
            cout<<"no much records are found :"<<endl;
      }
      }
       void bank2::del(){
       char ch;
       cout<<"do you want to delete specific record or remove all records (1 for all 2 for one):"<<endl;
       cin>>ch;
       switch(ch){
       case '1':
           total=0;
           cout<<"all records are deleted sucessfully "<<endl;
           break;
       case '2':
           cout<<"enter the id of student you want to delete:"<<endl;
           cin>>Id;
          for (int i=0;i<total;i++){
           if (Id==person[i].id){
            for (int j=i;j<total;j++){
                person[j].name= person[j+1].name;
                person[j].id= person[j+1].id;
                person[j].address= person[j+1].address;
                person[j].contact= person[j+1].contact;
                person[j].cash= person[j+1].cash;
                total--;
                break;
            }

       }
       if (i==total-1)
         cout<<"no much records are found :"<<endl;
       }
       default:
        cout<<"enter valid input:"<<endl;
        break;
       }
       }
int main()
{
    bank2 o;
    o.choice();
   bank obj;
    char option='a';
    cout<<"---------------hello in our bank-------------"<<endl;
    cout<<"1-open account :"<<endl;
    cout<<"2- deposite money :"<<endl;
    cout<<"3-withdraw money :"<<endl;
    cout<<"4-view your account :"<<endl;
    cout<<"5-exsit :"<<endl;
    int case1=0;
    do{
    cout<<"enter what do you want (1,2,3,...etc)"<<endl;
    cin>>case1;

    switch (case1){
   case 1:
    cout<<"open account :"<<endl;
    obj.openaccount();
    break;
   case 2:
    cout<<"deposite money :"<<endl;
    obj.depositemoney();
    break;
   case 3:
    cout<<"withdraw money :"<<endl;
       obj.withdrawemoney();
    break;
   case 4:
   cout<<"open account :"<<endl;
    obj.viewaccount();
    break;
   case 5:
    exit(1);
    break;
   default:
    cout<<" try again and choose a correct operation :"<<endl;
    break;
    }

    cout<<"do you want to continue without exiting ? (Y/N) :"<<endl;
    cin>>option;
    if ((option=='n')||(option=='N'))
        exit(0);
    } while((option=='y')||(option=='Y'));

    return 0;
}
