#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int random=(rand() % 10) + 1;
    int ans,flag=0;
    while(flag!=1)
    {
        cout<<"Enter your guess: ";
        cin>>ans;
        if(ans==random)
        {
            cout<<"Your guess is correct!"<<endl;
            flag=1;
        }

        else if(ans > random) cout<<"The guess is too high."<<endl;
        else cout<<"The guess is too low."<<endl;
    }
    return 0;
}
