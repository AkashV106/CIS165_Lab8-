#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int SIZE = 5;
const int MAX = 9;
const int MIN = 0;

int main()
{
    int winningDigits[SIZE];
    int player[SIZE];
    int matches = 0;
    unsigned seed = static_cast<unsigned int>(std::time(nullptr));
    srand(seed);
    
    for (int i = 0; i < SIZE; i++){
        cout<<"Enter 5 Numbers(0-9) Number "<<i+1<<"= ";
        cin>>player[i];
    }
    cout<<"The Winning Digits are ";
    for(int i = 0; i < SIZE; i++){
        winningDigits[i] = rand() % (MAX - MIN + 1) + MIN;
        cout<<winningDigits[i];
        if(winningDigits[i]==player[i]){
            matches++;
        }
    }
    cout<<endl;
    cout<<"You entered: ";
    for (int i = 0; i < SIZE; i++){
        cout<<player[i];
    }
    cout<<endl;
    
    if (matches != 0){
        cout<<"You have "<<matches<<" matches "<<endl;
    }
    else{
        cout<<endl<<"Sorry you didn't have any match"<<endl;
    }
    
    return 0;
}
