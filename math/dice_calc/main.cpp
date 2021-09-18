#include <iostream>

using namespace std;

bool has2or3(int a,int b,int c)
{
    return a == 2 ||
           a == 3 ||
           b == 2 ||
           b == 3 ||
           c == 2 ||
           c == 3;
}



int main()
{
    int desiredNo = 0, possibleNo = 0;

    for(int a = 1; a <=6; a++)
        for(int b = 1; b <=6; b++)
            for(int c = 1; c<=6; c++)
            {
                if(has2or3(a,b,c)) {
                    desiredNo++;
                    cout << "+ ";
                }
                possibleNo++;
                cout << a << b << c << endl;

            }

    cout << "When rolling three (fair) fuzzy dice, the probability of rolling 2 or 3 on either of them is " << desiredNo << "/" << possibleNo << "." << endl;
    return 0;
}
