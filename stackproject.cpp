// stackproject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
using namespace std;

#define SIZE 5

template <class T> class Stack {
    // Pubic access modifier
public:
    // Empty constructor
    Stack();
    void push(T k);
    T pop();
    T topElement();
    bool isFull();
    bool isEmpty();
    bool isbalanced(string expr);
    string infixtopostfix(string exp);
    int priority(char ch);

private:
    int top;
    T st[SIZE];
};

template <class T> Stack<T>::Stack() { top = -1; }
template <class T> void Stack<T>::push(T k)
{
    if (isFull()) {
        cout << "Stack is full\n";
    }
    cout <<"inserted element is : "<< k<<" "<<endl;
    top = top + 1;
    st[top] = k;
}
template <class T> bool Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
template <class T> bool Stack<T>::isFull()
{
    if (top == (SIZE - 1))
        return 1;
    else
        return 0;
}
template <class T> T Stack<T>::pop()
{

    T popped_element = st[top];
    top--;
    return popped_element;
}
template <class T> T Stack<T>::topElement()
{
    T top_element = st[top];
    return top_element;
}

template <class T> bool Stack<T>:: isbalanced( string expr){
 Stack<char> s;
   char ch;
   for (int i=0; i<expr.length(); i++) {    //for each character in the expression, check conditions
      if (expr[i]=='('||expr[i]=='['||expr[i]=='{') {    //when it is opening bracket, push into     stack
         s.push(expr[i]);
         continue;
      }
      if (s.isEmpty())    //stack cannot be empty as it is not opening bracket, there must be closing     bracket
         return false;
         switch (expr[i]) {
            case ')':    //for closing parenthesis, pop it and check for braces and square brackets
               ch = s.topElement(); //last one in the stack
               s.pop();
               if (ch=='{' || ch=='[')
                  return false;
                  break;
            case '}': //for closing braces, pop it and check for parenthesis and square brackets
               ch = s.topElement();
               s.pop();
               if (ch=='(' || ch=='[')
                  return false;
                  break;
            case ']': //for closing square bracket, pop it and check for braces and parenthesis
               ch = s.topElement();
               s.pop();
               if (ch =='(' || ch == '{')
                  return false;
                  break;
         }
      }
      return (s.isEmpty()); //when stack is empty, return true
}
template <class T> string Stack<T>::infixtopostfix(string exp){
  Stack <char> stk;
  string output="";
  for (int i=0;i<exp.length();i++){
    if (exp[i]==' ')
        continue;
    if (isdigit(exp[i])||isalpha(exp[i]))
        output+=exp[i];
    else if (exp[i]=='(')
         stk.push('(');
    else if (exp[i]==')'){
        while (stk.topElement()!='('){
            output+=stk.topElement();
            stk.pop();
          }
          stk.pop(); //pop the (
    }
else {
     while(!stk.isEmpty()&&priority(exp[i])<=priority(stk.topElement())){
        output+=stk.topElement();
        stk.pop();
    }
    stk.push(exp[i]);
    }
  }
  while (!stk.isEmpty()){
    output+=stk.topElement();
    stk.pop();
  }
   return output;
}
template<class T > int Stack<T>::priority(char ch){
    if (ch=='+'|| ch=='-')
        return 1;
    else if (ch=='*'|| ch=='/')
        return 2;
    else if (ch=='^')
        return 3;
    else
        return 0;
}



int _tmain(int argc, _TCHAR* argv[])
{
	Stack<int> integer_stack;
    Stack<string> string_stack;
    integer_stack.push(2);
    integer_stack.push(54);
    integer_stack.push(255);
    string_stack.push("Welcome");
    string_stack.push("to");
    string_stack.push("GeeksforGeeks");
    cout << integer_stack.pop() << " is removed from stack"<< endl;
    cout << string_stack.pop() << " is removed from stack "<< endl;
    cout << "Top element is " << integer_stack.topElement()<< endl;
    cout << "Top element is " << string_stack.topElement()<< endl;
    cout<<"===================================================="<<endl;
    string expr = "[{}(){()}]";
     cout<<"the infix expression is : "<<expr<<endl;
   if (integer_stack.isbalanced(expr))
      cout << "Balanced"<<endl;
   else
      cout << "Not Balanced"<<endl;
   cout<<"===================================================="<<endl;
   string  infixexpresstion="(3+2)+7/2*((7+3)*2)";
   cout<<"the infix expression is : "<<infixexpresstion<<endl;
   cout<<"the post fix of the expression is :"<<integer_stack.infixtopostfix(infixexpresstion)<<endl;
	system("pause");
	return 0;
}

