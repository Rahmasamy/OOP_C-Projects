#include <iostream>
#include<string.h>
#include<conio.h>
#define max 100 //constant
using namespace std;
class customer{
//name address phone from data to data  payment_advance int booking_id;
public:
char name[20];
char address[20];
char phone[12];
char from_date[20];
char to_date[20];
float paymentadvance;
int bookingid;

};
class room{
public:
char type;
char stype;
char ac;
int roomNumber;
int rent;
int status;
room(){
type='a';
 stype='a';
 ac='a';
 roomNumber=0;
 rent=0;
status=0;

}
class customer cust;
class room addroom(int);
void searchRoom(int);
void deleteRoom(int);
void displayRoom(room);
};
//Global Declarations
class room rooms[max];
int counter=0;

room room::addroom(int roomnumber){ //return type of room
 class room rooms;
rooms.roomNumber=roomnumber;
cout<<"enter the type AC/Non-AC (A/N)"<<endl;
cin>>rooms.ac;
cout<<"\nType Comfort (S/N) : ";
cin>>rooms.type;
cout<<"\nType Size (B/S) : ";
cin>>rooms.stype;
cout<<"\nDaily Rent : ";
cin>>rooms.rent;
rooms.status=0;
cout<<"\n Room Added Successfully!";
getch();
return rooms;

}
void room::searchRoom(int roomnumber){
int i, found=0;
for ( i=0;i<counter;i++){
    if (rooms[i].roomNumber==roomnumber){
            found=1;
            cout<<"the room is found :"<<endl;
            break;

    }
}
  if (found==1){
    cout<<"room details "<<endl;
    if (rooms[i].status==1){
        cout<<"the room is servesed :"<<endl; }
    else {
        cout<<"the room is avaliable :"<<endl;
    }
    displayRoom(rooms[i]);
    getch();
  }
  else {  cout<<"the room is not found :"<<endl;
             getch();
  }

}
void room::displayRoom(room roomnumber){
  cout<<"\nRoom Number: \t"<<roomnumber.roomNumber;
  cout<<"\nType AC/Non-AC (A/N) "<<roomnumber.ac;
  cout<<"\nType Comfort (S/N) "<<roomnumber.type;
  cout<<"\nType Size (B/S) "<<roomnumber.stype;
  cout<<"\nRent: "<<roomnumber.rent;

}
class hotelmangement:protected room{
public:
void checkIn();
void getAvailRoom();
void searchCustomer(char *);
void checkOut(int);
void guestSummaryReport();


};
void hotelmangement::checkIn(){
  int i,found=0,roomnumber;
  cout<<"\nEnter Room Number: ";
  cin>>roomnumber;
  for ( i=0;i<counter;i++){
    if (rooms[i].roomNumber==roomnumber){
            found=1;
            cout<<"the room is found :"<<endl;
            break;

    }
}
  if (found==1){
    cout<<"room details "<<endl;
    if (rooms[i].status==1){
        cout<<"the room is already booked :"<<endl;
        getch();
         return;
         }
    cout<<"enter the booking id :"<<endl;
    cin>>rooms[i].cust.bookingid;
    cout<<"\nEnter Customer Name (First Name): ";
    cin>>rooms[i].cust.name;
    cout<<"\nEnter Address (only city): ";
    cin>>rooms[i].cust.address;
    cout<<"\nEnter Phone: ";
    cin>>rooms[i].cust.phone;
    cout<<"\nEnter From Date: ";
    cin>>rooms[i].cust.from_date;
    cout<<"\nEnter to  Date: ";
    cin>>rooms[i].cust.to_date;
    cout<<"\nEnter Advance Payment: ";
   cin>>rooms[i].cust.paymentadvance;
    rooms[i].status=1;
   cout<<"\n Customer Checked-in Successfully..";
   getch();
}
}

void hotelmangement::getAvailRoom(){
  int i,found=0;
  for (i=0;i<counter;i++){
    if (rooms[i].status==0){
        displayRoom(rooms[i]);
       cout<<"\n\nPress enter for next room";
       found=1;
       getch();

    }
  }
  if(found==0)
{
cout<<"\nAll rooms are reserved";
getch();
}

}
void hotelmangement::searchCustomer(char*pname){
 int i,found=0;
 for (int i=0;i<counter;i++){
    if (rooms[i].status==1&&stricmp(rooms[i].cust.name,pname)==0){
        cout<<"the name of the custor :"<<rooms[i].cust.name<<endl;
        cout<<"the number of the room  :"<<rooms[i].roomNumber<<endl;
        cout<<"\n\nPress enter for next record";
         found=1;
         getch();
    }
 }
  if(found==0)
{
cout<<"\nPerson not found.";
getch();
}
}
void hotelmangement::checkOut(int roomnum){
  int i,found,days=0;
  float billAmount=0.0;
  for (int i=0;i<counter;i++){
    if(rooms[i].status==1 && rooms[i].roomNumber==roomnum){
        found=1;
        getch();
        break;
    }
  }
  if (found==1){
    cout<<"\nEnter Number of Days:\t";
    cin>>days;
    billAmount=days * rooms[i].rent;
    cout<<"\t################ CheckOut Details ###############\n";
    cout<<"\nCustomer Name : "<<rooms[i].cust.name;
    cout<<"\nRoom Number : "<<rooms[i].roomNumber;
    cout<<"\nAddress : "<<rooms[i].cust.address;
    cout<<"\nPhone : "<<rooms[i].cust.phone;
    cout<<"\nTotal Amount Due : "<<billAmount<<" /";
    cout<<"\nAdvance Paid: "<<rooms[i].cust.paymentadvance<<" /";
    cout<<"\n*** Total Payable: "<<billAmount-rooms[i].cust.paymentadvance<<"/ only";
    rooms[i].status=0;



  }
  getch();
}
void hotelmangement::guestSummaryReport(){
if (counter==0){cout <<"soOory!! no guest in the hotel :"<<endl;}
 for(int i=0;i<counter;i++)
{
if(rooms[i].status==1)
{
cout<<"\n Customer First Name : "<<rooms[i].cust.name;
cout<<"\n Room Number : "<<rooms[i].roomNumber;
cout<<"\n Address (only city) : "<<rooms[i].cust.address;
cout<<"\n Phone : "<<rooms[i].cust.phone;
cout<<"\n---------------------------------------";
}
}

getch();

}
void manageroom(){
class room room2;
int option,roomnumb,i,flag=0;
char ch;
do
{

cout<<"\n########################### Manage Rooms ###############"<<endl;
cout<<"\n1. Add Room"<<endl;
cout<<"\n2. Search Room"<<endl;
cout<<"\n3. Back to Main Menu"<<endl;
cout<<"\n\nEnter Option: "<<endl;
cin>>option;
switch(option){
   case 1:
       cout<<"\nEnter Room Number: "<<endl;
       cin>>roomnumb;
       for(int i=0;i<counter;i++){
        if (rooms[i].roomNumber==roomnumb){
            flag=1;
            getch();
        }

       }
     if (flag==1){
        cout<<"the room is present :"<<endl;
        flag=0;
        getch();
     }
     else
             {
             rooms[counter]=room2.addroom(roomnumb);
             counter++;
             }
             break;
   case 2:
      cout<<"\nEnter room number: ";
      cin>>roomnumb;
     room2.searchRoom(roomnumb);
     break;
  case 3:
    //nothing to do
     break;
  default:
     cout<<"\nPlease Enter correct option";
      break;

}
} while(option!=3);
}
int main()
{
   hotelmangement hotel;
   int i,j,option,roomnumber;
   char ch;
   char pname[100];
   do
{

cout<<"###############Hotel Management #####################\n";
cout<<"\n 1. Manage Rooms";
cout<<"\n 2. Check-In Room";
cout<<"\n 3. Available Rooms";
cout<<"\n 4. Search Customer";
cout<<"\n 5. Check-Out Room";
cout<<"\n 6. Guest Summary Report";
cout<<"\n 7. Exit";
cout<<"\n\nEnter Option: ";
cin>>option;
switch(option){
  case 1:
      manageroom();
  case 2:
      if(counter==0)
    {
    cout<<"\nRooms data is not available.\nPlease add the rooms first.";
    getch();
    }
else{
    hotel.checkIn();
    break;
    }
  case 3:
      if(counter==0)
      {
      cout<<"\nRooms data is not available.\nPlease add the rooms first.";
        getch();
      }
else{
    hotel.getAvailRoom();
    break;
}
  case 4:
      if(counter==0)
    {
    cout<<"\nRooms are not available.\nPlease add the rooms first.";
    getch();
    }
   else
      {
         cout<<"Enter Customer Name: ";
         cin>>pname;
       hotel.searchCustomer(pname);
      }
       break;
  case 5:
      if(counter==0)
          {
          cout<<"\nRooms are not available.\nPlease add the rooms first."<<endl;
          getch();
          }
         else
         {
       cout<<"Enter Room Number : "<<endl;
       cin>>roomnumber;
       hotel.checkOut(roomnumber);
         }
         break;
  case 6:
      hotel.guestSummaryReport();
  case 7:
      cout<<"\nTHANK YOU! FOR USING SOFTWARE";
      exit(0);
      break;
  default:
      cout<<"please enter correct option : "<<endl;
      break;



}

} while(option!=7);
    return 0;
}
