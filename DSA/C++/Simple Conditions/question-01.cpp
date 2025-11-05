#include<iostream>
using namespace std;
 int main()
 {

    // Take a number and print whether 
    // it’s positive, negative, or zero.

    cout<<" here is question one so enter a nubmer ";
    int num ;
    cin>> num;
    if(num=0||num>0)
    {
        cout<<"it positive";
    }
    else if(num=0)
    {
        cout<<"it zero";

    }
    else{
        cout<<" it negative";
    }

    return 0;
 }