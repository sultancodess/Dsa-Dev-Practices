#include <iostream>
using namespace std;

// Function to input two numbers
void ADD(int &a, int &b)
{
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
}

// Function to calculate and display sum
void SUM(int a, int b)
{
    int sum = a + b;
    cout << "The sum is: " << sum << endl;
}

int main()
{
    int a, b;
    ADD(a, b);
    SUM(a, b);
    return 0;
}
