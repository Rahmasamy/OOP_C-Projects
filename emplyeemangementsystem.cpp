#include <iostream>
#include<bits/stdc++.h>
#define max 100
using namespace std;
struct employee{
   string name;
    long int code;
    string designation;
    int exp;
    int age;

};
int num=0;
void showmenue();
employee emp[max], tempemp[max],sortemp[max], sortemp1[max];
void buildtable(){
  cout<<"==========================build the table====================="<<endl;
  cout<<"the maximum number of entries is :"<<max<<endl;
  cout<<"enter the number of entries :"<<endl;
  cin>>num;
  if (num>max){
    cout<<"enter the data in the range 100 :"<<endl;
    num=100;

  }
  cout<<"enter the following data :"<<endl;
  for (int i=0;i<num;i++){
    cout<<"enter the name :"<<endl;
    cin>>emp[i].name;
    cout << "enter Employee ID \n";
    cin >> emp[i].code;

    cout << "enter Designation \n";
    cin >> emp[i].designation;

    cout << "enter Experience\n ";
    cin >> emp[i].exp;

    cout << " enter Age\n ";
    cin >> emp[i].age;


  }
    showmenue();

}
void insert(){
  if (num<max){
    int i=num;
    num++;
    cout<<"enter the name :"<<endl;
    cin>>emp[i].name;
    cout << "enter Employee ID \n";
    cin >> emp[i].code;

    cout << "enter Designation \n";
    cin >> emp[i].designation;

    cout << "enter Experience\n ";
    cin >> emp[i].exp;

    cout << " enter Age\n ";
    cin >> emp[i].age;

  }
     else {
        cout << "Employee Table Full\n";
         }

    showmenue();
}
void deleteIndex(int i){
   for (int j = i; j < num - 1; j++) {
        emp[j].name = emp[j + 1].name;
        emp[j].code = emp[j + 1].code;
        emp[j].designation= emp[j + 1].designation;
        emp[j].exp = emp[j + 1].exp;
        emp[j].age = emp[j + 1].age;
    }
    return;
}
void deleterecord(){
 int code=0;
 cout<<"enter the employee id :"<<endl;
 cin>>code;
 for (int i=0;i<num;i++){
     if (emp[i].code == code) {
            deleteIndex(i);
            num--;
            break;
     }
 }
   showmenue();
}
void searchemployee(){
  int code=0;
 cout<<"enter the employee id :"<<endl;
 cin>>code;
 for (int i=0;i<num;i++){
     if (emp[i].code == code) {
       cout << "Name "<< emp[i].name << "\n";

            cout << "Employee ID "<< emp[i].code << "\n";

            cout << "Designation "<< emp[i].designation << "\n";

            cout << "Experience "<< emp[i].exp << "\n";

            cout << "Age "<< emp[i].age << "\n";
            break;

     }
 }
    showmenue();
}
void showmenue(){
cout << "-------------------------"<<endl;
cout<< " Employee Management System"<<endl;
cout<< "-------------------------\n\n";

cout << "Availiable Options:\n\n";
cout << "Build Table         (1)\n";
cout << "Insert New Entry    (2)\n";
cout << "Delete Entry        (3)\n";
cout << "Search a Record     (4)\n";
cout << "Exit                (5)\n";

int choice;

    // Input Options
    cin >>choice;

    // Call function on the bases of the
    // above option
    if (choice == 1) {
        buildtable();
    }
    else if (choice == 2) {
        insert();
    }
    else if (choice == 3) {
        deleterecord();
    }
    else if (choice == 4) {
        searchemployee();
    }
    else if (choice == 5) {
        return;
    }
    else {
        cout << "Expected Options"
             << " are 1/2/3/4/5";
        showmenue();
    }




}
int main()
{
    showmenue();
    return 0;
}
