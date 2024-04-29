#include <iostream>
using namespace std;
class profile{
public:
    string name;
    string rollno;
    void getdata(){
    system("color 0a");
    cout<<"Welcome to UOG CGPA calculator program designed by :\n";
    cout<<"\t\tMuqadas Saleem\n";
    cout<<"Enter your name\n";
    cin>> name;
    cout<<"Enter your roll number \n";
    cin>> rollno;

    }

};
class gpa:public profile{
 public:
     void claculate(){
     float gpa1,gpa2,gpa3,gpa4,gpa5,gpa6,gpa7,gpa8,gpa9,totalgpa=0.0;
     int numbersubjects;
     cout<<"how many subjects :"<<endl;
     cin>>numbersubjects;
     int ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9=0;
     cout<<"--------------------------------------------------------------------------------\n";
      cout<<"                              SCALE                                             \n";
      cout<<"--------------------------------------------------------------------------------\n";
      cout<<"                                                                                \n";
      cout<<"________________________________________________________________________________\n";
      cout<<"       marks in %age   |      Grade            |    GPA    |  Grade key         \n";
      cout<<"_______________________|_______________________|___________|____________________\n";
      cout<<"        84.5 and above |        A+             |    4.00   |     1 for A+       \n";
      cout<<"                       |                       |           |                    \n";
      cout<<"        79.5 to 84     |        A              |    3.70   |     2 for A        \n";
      cout<<"                       |                       |           |                    \n";
      cout<<"        74.5 to 79     |        B+             |    3.40   |     3 for B+       \n";
      cout<<"                       |                       |           |                    \n";
      cout<<"        69.5 to 74     |        B              |    3.00   |     4 for B        \n";
      cout<<"                       |                       |           |                    \n";
      cout<<"        64.5 to 69     |        B-             |    2.50   |     5 for B-       \n";
      cout<<"                       |                       |           |                    \n";
      cout<<"        59.5 to 64     |        C+             |    2.00   |     6 for C+       \n";
      cout<<"                       |                       |           |                    \n";
      cout<<"        54.5 to 59     |        C              |    1.50   |     7 for C        \n";
      cout<<"                       |                       |           |                    \n";
      cout<<"        49.5 to 54     |        D              |    1.00   |     8 for D        \n";
      cout<<"                       |                       |           |                    \n";
      cout<<"        49 and below   |        F              |    0.00   |     9 for F        \n";
      cout<<"--------------------------------------------------------------------------------\n";
      cout<<"                                                                                \n";
      cout<<"--------------------------------------------------------------------------------\n";
       cout<<"\n\n\n    NOTE :(use special keys for grading as above in scale)\n\n\n";
       cout<<"please enter only 1 to 9 for grades as above in scale\n\n";
       int grade=0;
       for (int i=0;i<numbersubjects;i++){
        cout<<"enter your grade :"<<endl;
        cin>>grade;
           if(grade==1)
      {
      cout<<"Enter credit hours:\n";
      cin>>ch1;
       gpa1=4.00*ch1;
      }
      else if(grade==2)
      {
      cout<<"Enter credit hours:\n";
      cin>>ch2;
       gpa2=3.70*ch2;
      }
      else if(grade==3)
      {
      cout<<"Enter credit hours:\n";
      cin>>ch3;
       gpa3=3.40*ch3;
      }
      else if(grade==4)
      {
      cout<<"Enter credit hours:\n";
      cin>>ch4;
       gpa4=3.00*ch4;
      }
      else if(grade==5)
      {
      cout<<"Enter credit hours:\n";
      cin>>ch5;
       gpa5=2.50*ch5;
      }
      else if(grade==6)
      {
      cout<<"Enter credit hours:\n";
      cin>>ch6;
       gpa6=2.00*ch6;
      }
      else if(grade==7)
      {
      cout<<"Enter credit hours:\n";
      cin>>ch7;
       gpa7=1.50*ch7;
      }
      else if(grade==8)
      {
      cout<<"Enter credit hours:\n";
      cin>>ch8;
       gpa8=1.00*ch8;
      }
      else if(grade==9)
      {
      cout<<"Enter credit hours:\n";
      cin>>ch9;
       gpa9=0.00*ch9;
      }
      else
      {cout<<"wrong value :"<<endl; }

       }
      totalgpa=gpa1+gpa2+gpa3+gpa4+gpa5+gpa6+gpa7+gpa8+gpa9;
     int tch=+ch1+ch2+ch3+ch4+ch5+ch6+ch7+ch8+ch9;
     float cgpa= totalgpa/tch;
     cout<< "dear "<<name;
      if (cgpa >= 3)
        cout << "\nCongratulations, your GPA is "  << cgpa << endl;
      else
        cout << "\nSorry dude, your GPA is "  << cgpa << endl;
     cout<<"THE END\n";
     }


};
int main()
{
    gpa obj;
    obj.getdata();
    obj.claculate();
    return 0;
}
