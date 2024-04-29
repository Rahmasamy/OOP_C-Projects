#include <iostream>
#include<conio.h>
#include<string>

using namespace std;
class book{
private:
    string isbn,title,author,edition,publication;
public:
    book(){
    isbn="";
    title="";
    author="";
    edition="";
    publication="";
    }
    book(string isbn,string title,string author,string edition,string publication){
     this->isbn=isbn;
     this->title=title;
     this->author=author;
     this->edition=edition;
     this->publication=publication;
    }
   void setIsbn(string isbn){ this->isbn=isbn; }
    void setTitle(string title){ this->title=title; }
     void setAuthor(string author){ this->author=author; }
      void setEdition(string edition){ this->edition=edition; }
       void setPublication(string publication){ this->publication=publication; }
   string getisbn(){
       return isbn;
   }
   string gettitle(){
     return title;
   }
   string getauthor(){
     return author;
   }
   string getedition(){
     return edition;
   }
   string getpublication(){
     return publication;
   }
};
int counter=0;
void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void quit();


//function for incrementing counter
void increment(int a){
	a++;
	counter=a;
}

//function for decrementing counter
void decrement(int a){
	a--;
	counter=a;
}

//Book class array initialization
book books[10];
int main()
{


  char choice='a';
//Main Menu

   cout<<"==================HELLO IN OUR LIBRARY MANAGEMENT SYSTEM======================\n";
   cout<<"[1]ADD BOOK\n";
   cout<<"[2]DELETE BOOK\n";
   cout<<"[3]EDIT BOOK\n";
   cout<<"[4]SEARCH BOOK\n";
   cout<<"[5]VIEW ALL BOOKS\n";
   cout<<"[6]QUIT\n\n";
  cout<<"ENTER CHOICE: ";
   cin>>choice;
  if (choice=='1'){  addBook(counter);}
   else if (choice=='2'){  deleteBook(counter);  }
 else if (choice=='3'){ editBook(counter);          }
 else if (choice=='4'){   searchBook(counter);     }
 else if (choice=='5'){  viewAllBooks(counter);          }
  else if (choice=='6'){ quit();             }
  else {
    main();
  }

    return 0;
}
void addBook( int counter){
  string isbn,title,author,edition,publication;
  cout<<"ADD BOOK\n\n";
	if(counter<10){
		cout<<"Enter ISBN: ";
		cin>>isbn;
		cout<<"Enter Title: ";
		cin>>title;
		cout<<"Enter Author: ";
		cin>>author;
		cout<<"Enter Edition: ";
        cin>>edition;
		cout<<"Enter Publication: ";
		cin>>publication;
		books[counter].setIsbn(isbn); //assigning the values entered to book object
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);
		increment(counter);	//calling function to increment counter
		cout<<"\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
		_getch();
		   main();

	}
	else {
      cout<<"YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TOBE ADDED!\n\nPress any key to continue . . .";
		getch();
		main();

	}
}
void deleteBook( int counter){
  string isbn;
  int choice;
  cout<<"===============deleting book===================="<<endl;
  if (counter==0){
     cout<<"there is no book to delete "<<endl;
     main();
  }
  cout<<"Enter ISBN: "<<endl;
	cin>>isbn;
  for (int i=0;i<counter;i++){
    if(books[i].getisbn()==isbn){
        cout<<"\nBOOK FOUND\n\n";
        cout<<"Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
        cin>>choice;
        if(choice==1){
            books[i].setIsbn(""); //setting the value to none
            books[i].setTitle("");
            books[i].setAuthor("");
            books[i].setEdition("");
            books[i].setPublication("");
				for(int a=i;a<counter;a++){
					//adjusting the values after deletion of data eg. data from book[4] copied to book[3]
					books[a] = books[a+1];
				}
				books[9].setIsbn(""); //adjustment if the library is full(10 books)
				books[9].setTitle("");
				books[9].setAuthor("");
				books[9].setEdition("");
				books[9].setPublication("");
				decrement(counter); //calling function to decrement counter
				cout<<"\nBOOK SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
				main();

       }
       else{ main();}

  }
  }


}
void editBook(int counter){
   string editIsbn,choice;
   string isbn,title,author,edition,publication;
   cout<<"=====================edit book====================="<<endl;
   cout<<"\nEDIT BOOK\n\n";
	if(counter==0){
		cout<<"THERE IS NO BOOK TO EDIT!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"enter the isbn of the book :"<<endl;
	cin>>editIsbn;
	for (int i=0;i<counter;i++){
        if (books[i].getisbn()==editIsbn){
          cout<<"===========book is found================"<<endl;
          cout<<"the Isbn is :"<<books[i].getisbn()<<endl;
          cout<<"the title is :"<<books[i].gettitle()<<endl;
          cout<<"the Author is :"<<books[i].getauthor()<<endl;
          cout<<"the publicationis is :"<<books[i].getpublication()<<endl;
          cout<<"the edition is :"<<books[i].getedition()<<endl;
          cout<<"do u want to continue in editing ?\n [1] yes \n [2] no "<<endl;
          cin>>choice;
          if (choice=="1"){
          cout<<"=============updating data is begaining=================="<<endl;
          cout<<"enter the new Isbn "<<endl;
          cin>>isbn;
          books[i].setIsbn(isbn);
          cout<<"enter the new author "<<endl;
          cin>>author;
          books[i].setAuthor(author);
          cout<<"enter the new title"<<endl;
          cin>>title;
          books[i].setAuthor(title);
           cout<<"enter the new publication "<<endl;
           cin>>publication;
          books[i].setAuthor(publication);
          cout<<"enter the new edition "<<endl;
          cin>>edition;
          books[i].setEdition(edition);

          cout<<"\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
				_getch();
				editBook(counter);//function call to self
				 main();
          }
			else{
				main();
			}
        }
	}
        cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	   _getch();
	    main();
	}
void searchBook(int counter){
  string isbn;
	int choice;
	bool print = false; //boolean expression to decide which to print
	cout<<"SEARCH BOOK\n\n";
	if(counter==0){
		cout<<"THERE IS NO BOOK TO SEARCH!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter ISBN: ";
	cin>>isbn;


	for (int i=0;i<counter;i++){
        if (books[i].getisbn()==isbn){
          cout<<"===========book is found================"<<endl;
          cout<<"the Isbn is :"<<books[i].getisbn()<<endl;
          cout<<"the title is :"<<books[i].gettitle()<<endl;
          cout<<"the Author is :"<<books[i].getauthor()<<endl;
          cout<<"the publicationis is :"<<books[i].getpublication()<<endl;
          cout<<"the edition is :"<<books[i].getedition()<<endl;
          print=true;
        }
	}
   if (print){
    cout<<"\n\nPress any key to continue . . .";
		_getch();
		main();

   }
   else{
		cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
}
void viewAllBooks(int counter){
	//iterating all the values on the library using book array
	if (counter==0){
        cout<<"there is no books to view :"<<endl;
        main();

	}
	cout<<"VIEW ALL BOOKS\n\n";

	for(int i=0;i<counter;i++){
		cout<<"BOOK DETAILS\n\n";
		cout<<"ISBN: "<<books[i].getisbn()<<endl;
		cout<<"TITLE: "<<books[i].gettitle()<<endl;
		cout<<"AUTHOR: "<<books[i].getauthor()<<endl;
		cout<<"EDITION: "<<books[i].getedition()<<endl;
		cout<<"PUBLICATION: "<<books[i].getpublication()<<endl;
	}
	cout<<"Press any key to continue . . .";
	_getch();
	main();
}
void quit(){
    cout<<"===============thanks for visiting us ================="<<endl;
    exit(1);
}
