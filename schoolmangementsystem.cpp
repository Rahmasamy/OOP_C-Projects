#include <iostream>
#include<conio.h>
using namespace std;
int counter=0;
struct student{
string name,studentclass,rollnumber;
float totalmarks,obtainedmarks,per;
student(){
name,studentclass,rollnumber="";
totalmarks,obtainedmarks,per=0.0;
}
}s[10];
void control_panel(){
int choice;
cout<<"*************************************************************"<<endl;
cout<<"*****************hello in our school*************************"<<endl;
cout<<"*************************************************************"<<endl;
cout<<endl;
cout<<"please choose from the menu"<<endl;
cout<<"1-insert the student"<<endl;
cout<<"2-search the student"<<endl;
cout<<"3-display the students"<<endl;
cout<<"4-update the student"<<endl;
cout<<"5-delete the student"<<endl;
cout<<"6-Exite"<<endl;


}
void inserting(student s[]){
cout<<"********************inserting student*********************"<<endl;
cout<<"enter the roll number :"<<endl;
cin>>s[counter].rollnumber;
cout<<"enter your name :"<<endl;
cin>>s[counter].name;
cout<<"enter the student of the class :"<<endl;
cin>>s[counter].studentclass;
cout<<"enter the total marks :"<<endl;
cin>>s[counter].totalmarks;
cout<<"enter the obtained marks :"<<endl;
cin>>s[counter].obtainedmarks;
s[counter].per=(s[counter].totalmarks/s[counter].obtainedmarks)*100;
counter++;
}
void display (student s[]){

  int c=0;
  cout<<"*******************display the students **********************"<<endl;

  if (counter>1){
    for (int i=0;i<counter;i++){
      cout<<"student: "<<c<<endl;
      cout<<"the roll num of student :"<<s[i].rollnumber<<endl;
      cout<<"the name of student :"<<s[i].name<<endl;
      cout<<"the class of the student :"<<s[i].studentclass<<endl;
      cout<<"the total marks is :"<<s[i].totalmarks<<endl;
      cout<<"the obtain marks of student :"<<s[i].obtainedmarks<<endl;
      cout<<"the per marks is :"<<s[i].per<<endl;
      cout<<"******************************************"<<endl;
      c++;

    }
  }
  else { cout<<"there is no student to show :"<<endl;}

}

void searching( student s[]){
  string roll="";


  if (counter>1){
  cout<<"enter the roll number :"<<endl;
  cin>>roll;
  cout<<"******************please wait for searching****************"<<endl;
    for(int i=0;i<counter;i++){
      if (roll==s[i].rollnumber){
      cout<<"the roll num of student :"<<s[i].rollnumber<<endl;
      cout<<"the name of student :"<<s[i].name<<endl;
      cout<<"the class of the student :"<<s[i].studentclass<<endl;
      cout<<"the total marks is :"<<s[i].totalmarks<<endl;
      cout<<"the obtain marks of student :"<<s[i].obtainedmarks<<endl;
      cout<<"the per marks is :"<<s[i].per<<endl;
      cout<<"******************************************"<<endl;
      }
      else { cout<<"there is no sudent with that roll"<<endl;}

    }


  }
  else {
    cout<<"soOory!! there 's no student to search"<<endl;
  }

}
void update(student s[]){
    string roll="";
     char updateyn='y';
  if (counter>1){
    cout<<"enter the roll number :"<<endl;
    cin>>roll;
    cout<<"******************please wait for searching****************"<<endl;
    for(int i=0;i<counter;i++){
      if (roll==s[i].rollnumber){
      cout<<"the roll num of student :"<<s[i].rollnumber<<endl;
      cout<<"the name of student :"<<s[i].name<<endl;
      cout<<"the class of the student :"<<s[i].studentclass<<endl;
      cout<<"the total marks is :"<<s[i].totalmarks<<endl;
      cout<<"the obtain marks of student :"<<s[i].obtainedmarks<<endl;
      cout<<"the per marks is :"<<s[i].per<<endl;
      cout<<"******************************************"<<endl;
      cout<<"do you want to update your data (y/n)"<<endl;
      cin>>updateyn;
      if (updateyn=='y'){
          cout<<"enter the roll number :"<<endl;
          cin>>s[i].rollnumber;
          cout<<"enter your name :"<<endl;
          cin>>s[i].name;
          cout<<"enter the roll number :"<<endl;
          cin>>s[i].studentclass;
          cout<<"enter the total marks :"<<endl;
          cin>>s[i].totalmarks;
          cout<<"enter the obtained marks :"<<endl;
          cin>>s[i].obtainedmarks;
          s[i].per=(s[i].totalmarks/s[i].obtainedmarks)*100;
          cout<<"the perctantage is :"<<s[i].per<<endl;

          }
     else{
        cout<<"thanks for helping "<<endl;
        exit(1);
     }
      }
      else { cout<<"there is no student with that roll"<<endl;}

    }

  }

  else {
    cout<<"soOory!! there 's no student to search"<<endl;
  }




}
void delet( student s[]){
       char ch;
       string roll="";
       cout<<"do you want to delete specific record or remove all records (1 for all 2 for one):"<<endl;
       cin>>ch;
       switch(ch){
       case '1':
           counter=0;
           cout<<"all records are deleted sucessfully "<<endl;
           break;
       case '2':
           cout<<"enter the roll num of student you want to delete:"<<endl;
           cin>>roll;
          for (int i=0;i<counter;i++){
           if (roll==s[i].rollnumber){
            for (int j=i;j<counter;j++){
                s[j].name=s[j+1].name;
                s[j].studentclass= s[j+1].studentclass;
                s[j].totalmarks= s[j+1].totalmarks;
                s[j].obtainedmarks= s[j+1].obtainedmarks;
                s[j].per= s[j+1].per;
                s[j].rollnumber=s[j].rollnumber;
                counter--;
                break;


       }
           }
       if (i==counter-1)
         cout<<"no much records are found :"<<endl;
       }
       default:
        cout<<"enter valid input:"<<endl;
        break;
       }
       }


int main()
{
while (1){
  int choice;
  char again='y';
  control_panel();
  cin>>choice;
  switch(choice){
  case 1:
      do{
      inserting(s);
      cout<<"do you want to insert again ?(y/n)"<<endl;
      cin>>again;

      } while(again=='y');
      break;
     case 2:
			display(s);
			break;
     case 3:
			searching(s);
			break;
		case 4:
			update(s);
			break;
		case 5:
			delet(s);
			break;
		case 6:
			exit(0);
		default:
			cout<<"\n\n Invalid Value...Please Try Again...";

  }
}
    return 0;
}
