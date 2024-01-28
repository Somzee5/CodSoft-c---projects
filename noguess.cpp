#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int no = rand()%200 + 1;
    cout << "\nPlease Enter a number between 1 to 200";
    int guess,cnt=0;

    while(1)
    {
        cout << "\nEnter your guess: ";
        cin >> guess;
        
        if(guess<1 || guess>200)
        {
            cout << "\nYour guess is out of the boundaries\nGuess a number between the range- 1 to 200 only";
            continue;
        }
        else
        {
            if(guess>no)
            {
                cout << "\nYour guess is too high... Try to give a lower guess";
                continue;
            }
            else
            {
                if(guess<no)
                {
                    cout << "\nYour guess is too low... Try to give a higher guess";
                    continue;
                }
                else
                {
                    cout << "\nYou have guessed it right!!!";
                    break;
                }   
            }
        }
        cnt++;
    }
    return 0;
}