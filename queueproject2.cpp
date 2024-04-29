#include <iostream>

using namespace std;
class queue
{
        private :

                int *arr ;
                int front, rear ;
                int MAX ;
        public :
                queue( int maxsize = 10 ) ;
                void addq ( int item ) ;
                int delq( ) ;
} ;

queue :: queue( int maxsize )
{
        MAX = maxsize ;
        arr = new int [ MAX ];
        front = -1 ;
        rear = -1 ;
}

void queue :: addq ( int item )
{
        if ( rear == MAX - 1 )
        {
                cout << "\nQueue is full" ;
                return ;
        }
        rear++ ;
        arr[rear] = item ;
        if ( front == -1 )
                front = 0 ;
}
int queue :: delq( )
{
        int data ;

        if ( front == -1 )
        {
                cout << "\nQueue is Empty" ;
                return NULL ;
        }

        data = arr[front] ;
        arr[front] = 0 ;
        if ( front == rear )
                front = rear = -1 ;
        else
                front++ ;

        return  data ;
}
class circularqueue
{
        private :

                int *arr2 ;
                int front2, rear2 ;
                int MAXAMUM ;
        public :
                circularqueue( int maxsize = 10 ) ;
                void addqc ( int item ) ;
                int delqc( ) ;
} ;

circularqueue :: circularqueue( int maxsize )
{
        MAXAMUM = maxsize ;
        arr2 = new int [ MAXAMUM ];
        front2 = -1 ;
        rear2 = -1 ;
}

void circularqueue :: addqc ( int item )
{
        if ( (rear2+1)%MAXAMUM == front2 )
        {
                cout << "\nQueue is full" ;
                return ;
        }
        rear2=(rear2+1)%MAXAMUM ;
        arr2[rear2] = item ;
        if ( front2 == -1 )
                front2 = 0 ;
}
int circularqueue :: delqc( )
{
        int data ;

        if ( front2 == -1 )
        {
                cout << "\nQueue is Empty" ;
                return NULL ;
        }

        data = arr2[front2] ;
        arr2[front2] = 0 ;
        if ( front2 == rear2 )
                front2 = rear2 = -1 ;
        else
               front2=(front2+1)%MAXAMUM;

        return  data ;
}
int main()
{
     queue a (10 ) ;

        a.addq ( 23 ) ;
        a.addq ( 9 ) ;
        a.addq ( 11 ) ;
        a.addq ( -10 ) ;
        a.addq ( 25 ) ;
        a.addq ( 16 ) ;
        a.addq ( 17 ) ;
        a.addq ( 22 ) ;
        a.addq ( 19 ) ;
        a.addq ( 30 ) ;
        a.addq ( 32 ) ;
        int i = a.delq( ) ;
        cout << "\n\nItem deleted: " << i ;
        i = a.delq( ) ;
        cout << "\n\nItem deleted: " << i ;
        i = a.delq( ) ;
        cout << "\n\nItem deleted: " << i ;

        cout<<"\n";
        cout<<"==================================================="<<endl;
        circularqueue c;
        c.addqc ( 17 ) ;
        c.addqc ( 22 ) ;
        c.addqc ( 19 ) ;
        c.addqc ( 30 ) ;
         int ii = c.delqc( ) ;
        cout << "\n\nItem deleted: " << ii ;
        ii= c.delqc( ) ;
        cout << "\n\nItem deleted: " << ii ;

    return 0;
}
