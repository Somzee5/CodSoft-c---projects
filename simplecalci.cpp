#include<iostream>
using namespace std;

int main()
{
    cout << "\nSimple Calculator:\n";
    while(1)
    {
        double no1,no2;
        cout << "\n\nEnter 2 numbers to perform the calculation:";
        cin >> no1 >> no2;

        char opt;
        cout << "\nSelect any operator :\n + : Addition\n - : Subtraction\n * : Multiplication\n / : Division\n $ : Terminate\n\nChoice:";
        cin >> opt;

        if(opt=='$')
            break;

        switch(opt)
        {
            case '+':
                cout << no1 << "+" << no2 << " = " << no1+no2;
                break;

            case '-':
                cout << no1 << "-" << no2 << " = " << no1-no2;
                break;

            case '*':
                cout << no1 << "*" << no2 << " = " << no1*no2;
                break;

            case '/':
                if(no2!=0)
                {
                    cout << no1 << "/" << no2 << " = " << no1/no2;
                    break;
                }
                else
                {
                    cout << "\nInvalid operation**\nDivision by 0 is not possible\nGive a different number if you want to perform the same operation";
                    continue;
                } 

            case '$':
                break;  

            default:
                cout << "\nWrong selection of operator**\n Select any operation from available options only";
                continue;
        }
    }
    return 0;
}

