#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int total_size=0;
int*list1=new int[total_size];
int cs=0;  //current size
int cl=-1;   //clear
      void menue();
/*01*/void create_list(); //done
/*02*/void delete_list(); //done
/*03*/void clear_list();   //done
/*04*/void display_list();  //done
/*05*/void add_item(int);   //done
/*06*/void add_item_by_position(int,int); //done
/*07*/void remove_item(); //done
/*08*/void remove_item_by_position(); //done
/*09*/void swapp_items(int,int); //done
/*10*/void swapp_items_by_position(int,int); //done
/*11*/int find_item(int);   //done
/*12*/int find_item_by_pos(int);  //done
/*13*/void copy_list(); //done
/*14*/void update_item(int,int); //done
/*15*/void update_item_by_position(int,int); //done
/*16*/void check_size_of_list(); //done
/*17*/int get_element_by_position(int); //done
/*18*/int isfull();  //done
/*19*/int isempty(); //done
void menue(){
 int option=0;
   cout<<"************************welcome to list application*******************\n";
   cout<<"press 1  to exit\n";           //
   cout<<"press 2  to create list\n";    //
   cout<<"press 3 to delete list\n";   //
   cout<<"press 4  to clear list\n";   //
   cout<<"press 5  to display list\n";  //
   cout<<"press 6  to add item in list\n"; //
   cout<<"press 7  to add item at particular position\n"; //
   cout<<"press 8  to remove item from list\n";
   cout<<"press 9  to remove item from particular position\n";
   cout<<"press 10  to swap items\n";//
   cout<<"press 11 to swap items by position\n";//
   cout<<"press 12 to find item in list\n";   //
   cout<<"press 13 to find item by position\n";   //
   cout<<"press 14 to copy list\n";//
   cout<<"press 15 to update item\n"; //
   cout<<"press 16 to update item by position\n"; //
   cout<<"press 17 to check size of list\n"; //
   cout<<"press 18 to get element\n"; //
   cout<<"enter 19 to check if list is full\n"; //
   cout<<"enter 20 to check if list is empty\n"; //
   cout<<"enter option:";
   cin>>option;
switch(option){

    case 1:
          {exit(0);
                                        //built in function to exit from program
          }
        break;
        ///////////////////////////////////////////////////////////////////////
    case 2:
         {
         create_list();
         menue();

         }
    break;
///////////////////////////////////////////////////////////////////////////////////////
    case 3:
          {
            delete_list();
            menue();
          }

         break;
////////////////////////////////////////////////////////////////////////////////////////
    case 4:
          {
         clear_list();
        menue();
         }
    break;
///////////////////////////////////////////////////////////////////////////////////////////
    case 5:
          {
         display_list();
          menue();
         }
    break;
/////////////////////////////////////////////////////////////////////////////////////////////////
    case 6:
        { int item;
          if (cl=-1)
            cout<<"the array is not created :"<<endl;
          else if (isfull()==1)
            cout<<"the array is already full :"<<endl;
          else {
            do {
                cout<<"enter the item you want to add :"<<endl;
                cin>>item;
                 if(find_item(item)==1)
               cout<<"item is already in list\n";
            } while(find_item(item)==1);
             add_item(item);
            cout<<"item added successfully in list\n";
             cs++;
          }

        }
        menue();
        break;
    case 7:{
         int it,pos;
         if(cl==-1)
         cout<<"list is not created\n";
         else
          do
          {
          cout<<"enter item:";
          cin>>it;
          if(find_item(it)==1)
          cout<<"item is already in list\n";
          }
          while(find_item(it)==1);
         cout<<"enter position:";
         cin>>pos;
         if(cl==1&&pos<cs)
         {
         for(int i=cs-1;i>pos-1;i--)
         {
                 list1[i+1]=list1[i];
         }
         add_item_by_position(it,pos);

         cout<<"item added successfully at pos :"<<pos<<endl;
         cs++;
         }
         else

         if(cl==1&&pos>=cs&&pos<total_size)

         {
         list1[cs]=it;
         cs++;
         }
         else
         cout<<"position out of range\n";
         }
           menue();
           break;
/////////////////////////////////////////////

    case 8:{
         if(cs==0)
         cout<<"list is empty\n";
         else
         if(cl==-1)
         cout<<"list is not created\n";
         else
         remove_item();
         cout<<"item is successfully removed\n";


      }
         menue();
         break;
    case 9:{

     if(cs==0)
         cout<<"list is empty\n";
         else
         if(cl==-1)
         cout<<"list is not created\n";
         else
         remove_item_by_position();
         cout<<"item successfully deleted\n";

          }
          menue();
         break;
    case 10:
        {
         int it1,it2;
         if(cs==0)
         cout<<"list is empty\n";
         else
         if(cl==-1)
         cout<<"list is not created\n";
         else
         do
         {
         cout<<"enter item 1: ";
         cin>>it1;
         if(find_item(it1)!=1)
         cout<<"item is not in list\n";
         }
         while(find_item(it1)!=1);
         do
         {
         cout<<"enter item 2: ";
         cin>>it2;
         if(find_item(it1)!=1)
         cout<<"item is not in list\n";
         }
         while(find_item(it2)!=1);
         swapp_items(it1,it2);
         cout<<"items successfully swapped\n";

         }
         menue();
         break;
         ///////////////////////////////////////////////////////////////////////////////
    case 11:
          {
          int pos1,pos2;
         if(cs==0)
         cout<<"list is empty\n";
         else
         if(cl==-1)
         cout<<"list is not created\n";
         else
         do
         {
         cout<<"enter position 1:";
         cin>>pos1;
         if (pos1<0||pos1>=cs){
            cout<<"soOory ...your position is invalid :"<<endl;
         }
         }
         while(pos1<0||pos1>=cs);
         do
         {
         cout<<"enter position 2:";
         cin>>pos2;
          if (pos2<0||pos2>=cs){
            cout<<"soOory ...your position is invalid :"<<endl;
         }
         }
         while(pos2<0||pos2>=cs);

         swapp_items_by_position(pos1,pos2);
         cout<<"items successfully swapped\n";
         }
         menue();
         break;
///////////////////////////////////////////////////////////////////////////////
    case 12:{
         int it;
         if(cs==0)
         cout<<"list is empty\n";
         else
         if(cl==-1)
         cout<<"list is not created\n";
         else
         {
         cout<<"enter item to check its presence in list\n";
         cin>>it;
         find_item(it);
         if(find_item(it)==1)
         {
         cout<<"item is present in list";
         int i=0;
         while(list1[i]!=it)
         {
         i++;
         }
         cout<<"at position "<<i<<endl;
         }
         else
         cout<<"item not found\n";
         }
         menue();
         }
         break;
//////////////////////////////////////////////

    case 13:
         {
         int pos;
         if(cs==0)
         cout<<"list is empty\n";
         else
         if(cl==-1)
         cout<<"list is not created\n";
         else
         {
         do
         {
         cout<<"enter position to find its item\n";
         cin>>pos;
         if (pos<0||pos>total_size){
            cout<<"the position isnot valid :"<<endl;
         }
         }
         while(pos<0||pos>total_size);
         find_item_by_pos(pos);
         }
         menue();
         }
         break;
//////////////////////////////////////////////
    case 14:
        {
         if(cs==0)
         cout<<"list is empty\n";
         else
         if(cl==-1)
         cout<<"list is not created\n";
         else
         copy_list();
         cout<<"list copied successfully\n";
         }
         menue();
         break;
/////////////////////////////////////////////

    case 15:
       {
          int it1,it2;
          if(cs==0)
          cout<<"list is empty\n";
          else
          if(cl==-1)
          cout<<"list is not created\n";
          else
          {
          do
          {
          cout<<"enter item to be updated\n";
          cin>>it1;
          if(find_item(it1)!=1)
          cout<<"item is not in list\n";
          }
          while(find_item(it1)!=1);
          do
          {
          cout<<"enter new item to be replaced\n";
          cin>>it2;
          if(find_item(it2)==1)
          cout<<"item is already in list\n";
          }
          while(find_item(it2)==1);
          update_item(it1,it2);
         }
         }
         menue();
         break;
////////////////////////////////////////////
    case 16:
        {
          int it,pos;
          if(cs==0)
          cout<<"list is empty\n";
          else
          if(cl==-1)
          cout<<"list is not created\n";
          else
          {
           do
           {
           cout<<"enter item:";
           cin>>it;
           if(find_item(it)==1)
           cout<<"item already present\n";
           }
           while(find_item(it)==1);
           cout<<"enter position:";
           cin>>pos;
           if(pos<cs)
           update_item_by_position(it,pos);
           else
           cout<<"item at "<<pos<<" is not available to be updated\n";
          }


         }
         menue();
         break;
///////////////////////////////////////////

    case 17:
         {
         if(cs==0)
         cout<<"list is empty\n";
         else
         if(cl==-1)
         cout<<"list is not created\n";
         else
         check_size_of_list();

         }
         menue();
         break;
//////////////////////////////////////////
    case 18:
          {
              int a,pos;
              if(cs==0)
              cout<<"list is empty\n";
              else
              if(cl==-1)
              cout<<"list is not created\n";
              else
              do
              {
              cout<<"enter position to get from list:";
              cin>>pos;
              }
              while(pos<0||pos>cs);
              a=get_element_by_position(pos);
              cout<<"here is your item from list :"<<a<<endl;
         }
         menue();
         break;
//////////////////////////////////////////
    case 19:
       {
         if(cs==0)
         cout<<"list is empty\n";
         else
         if(cl==-1)
         cout<<"list is not created\n";
         else
         if(isfull()==1)
         cout<<"list is full\n";
         else
         cout<<"list is not full\n";
         }
         menue();
         break;
/////////////////////////////////////////
    case 20 :
        {
         if(cs==0)
         cout<<"list is empty\n";
         else
         if(cl==-1)
         cout<<"list is not created\n";
         else
         if(isempty()==1)
         cout<<"list is empty\n";
         else
         cout<<"list is not empty\n";
         }
         menue();
         break;
/////////////////////////////////////////
    default:
       {
       cout<<"incorrect option ..Try again..!!"<<endl;
       menue();
        break;
       }

}



}
void create_list(){
   int item;
     cout<<"enter total size of list:"<<endl;
     cin>>total_size ;
     do
     {
     cout<<"enter current size of list:"<<endl;
     cin>>cs; //current size in global variables
     }
     while(cs<1||cs>=total_size);
     int i=0;
     while(i<cs){
     cout<<"enter the item :"<<endl;
     cin>>item;
         if(find_item(item)!=1)
     {

     list1[i]=item;
     i++;
     }
     else
     cout<<"item already present\n";
        //while closed

     }
      cl=1; //function closed
}

int find_item(int item){
  for (int i=0;i<total_size;i++){
    if (list1[i]==item)
        return 1;
  }

}
int find_item_by_pos(int position ){
 cout<<"the item in position "<<position<<"is :"<<list1[position]<<endl;
}
void display_list(){
if (cl==-1){cout<<"list is n't created yet :"<<endl;}
else if (cs==0){cout<<"there is no list to display :"<<endl;}
else{
for (int i=0;i<total_size;i++){
    cout<<"the array list is :"<<list1[i]<<endl;
}

}
}
void delete_list(){
    if(cl==-1)
     cout<<"list is not created\n";
     else
     cl=-1;
     cout<<"list is successfully deleted\n";
}
void clear_list(){
    if (cl==-1){cout<<"list is n't created yet :"<<endl;}
   else if (cs==0){cout<<"there is no list to clear :"<<endl;}
   else {
    cs=0;
    cout<<"the list cleared successfully :"<<endl;
   }
}
 void add_item(int item)
     {
      list1[cs]=item;
     }
//////////////////////////////////////////////
void add_item_by_position(int item,int position){
    list1[position]=item;
     cout<<"item at position "<<position<<" is successfully updated\n";
     cout<<"new item is :"<<item<<endl;
}
/////////////////////////////////////////////////////
 int isfull()
    {
    if(cs==total_size)
    return 1;
    else
    return -1;
    }
///////////////////////////////////////////////////////////
 int isempty()
    {
    if(cs==0)
    return 1;
    else
    return 0;
    }
   /////////////////////////////////////////////
    int get_element_by_position(int pos){
             return list1[pos];
    }
////////////////////////////////////////////////////////////////
void update_item(int item1,int item2){
if (find_item(item1)==1){
    int i;
    for(i=0;list1[i]!=item1;i++)
    int a=list1[i];
    list1[i]=item2;
    cout<<"at"<<i<<"="<<list1[i]<<endl;
    cout<<"item successfully updated\n";
}
else {
   cout<<item1<<"is not in list\n";
}

}

/////////////////////////////////////////////////////////////////////
void update_item_by_position(int item,int position){
int  a=list1[position];
    list1[position]=item;
    cout<<"item at position "<<position<<" is successfully updated\n";
    cout<<"old item was:"<<a<<endl;
    cout<<"new item is :"<<item<<endl;
}
///////////////////////////////////////////////////////////////////
 void check_size_of_list(){
  cout<<"the current size is :"<<cs<<endl;
 }
///////////////////////////////////////////////////////////////////

 //////////////////////////////////////////////////////////////////
 void swapp_items(int item1,int item2){
   int j,k=0;
   do{
    j++;
   } while(list1[j]!=item1);
   do{
    k++;
   } while(list1[k]!=item2);
   int temp=0;
   temp=list1[j];
   list1[j]=list1[k];
   list1[k]=temp;

 }
 //////////////////////////////////////////////////////////////////////////
  void swapp_items_by_position(int pos1,int pos2){
     int temp=0;
    temp=list1[pos1];
    list1[pos1]=list1[pos2];
    list1[pos2]=temp;
  }
  //////////////////////////////////////////////////////////////////////////
   void copy_list(){
    int i,j=0;
    int*copylist=new int[cs];
    for (i=0;i<cs;i++)
        copylist[i]=list1[i];
    cout<<"your copied list is\n";
    for(j=0;j<cs;j++)
    cout<<copylist[j]<<endl;

   }
////////////////////////////////////////////////////////////////////////
 void remove_item(){
     int item;
    do{
   cout<<"enter the item you want to remove first :"<<endl;
   cin>>item;
   if (find_item(item)!=1){
    cout<<"your item is not in the list :"<<endl;
   }
    } while(find_item(item)!=1);
   int i=0;
  do
  {
  i++;  //save the index of the item
  }
  while(list1[i]!=item);
  int a;
  a=list1[i];
  for(int j=i;j<cs-1;j++)
  {
  list1[j]=list1[j+1];
  }
  cs--;
  }
 //////////////////////////////////////////////////////////////
  void remove_item_by_position(){
    int pos;
    do
    {
    cout<<"enter position:"<<endl;
    cin>>pos;
    if(pos<0||pos>cs)
    cout<<"there is no item at position "<<pos<<endl;
    }
    while(pos<0||pos>cs);
    int a;
    a=list1[pos];
    for(int i=pos;i<cs;i++)
    {
     list1[i]=list1[i+1];
    }
    cs--;
   }
int main()
{
    menue();
    getch();
    return 0;
}
