#include<iostream>
using namespace std;
int main()
{
    int num1,num2;
    char op;
    do{
    cout<<"\nEnter the number1: ";
    cin>>num1;
    cout<<"\nEnter the number2: ";
    cin>>num2;
    cout<<"\nChoose your operation(+,-,*,/): ";
    cin>>op;
    switch(op)
    {
        case '+': cout<<"\nSum:"<<num1+num2<<endl;break;
        case '-': cout<<"\nSubtract:"<<num1-num2<<endl;break;
        case '*': cout<<"\nProduct:"<<num1*num2<<endl;break;
        case '/': cout<<"\nDivision:"<<num1/num2<<endl;break;
        default: cout<<"\nInvalid Operation!"<<endl;
    }}while(1);
    return 0;
}
