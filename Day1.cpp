#include<iostream>
#include<string.h>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    string input = " ";
    char chL, chR;
    int answ = 0;

    //getline(cin,input,' ')
    while(1)
    {
        getline(cin,input);
        if(input.empty())
            break;
            
        chL = 0;
        chR = 0;
        bool loop = true;
        for(int i = 0; i < input.length() || i >= 0;)
        {
            if(loop)
            {
                if(input[i] >= '0' && input[i] <= '9')
                {
                    chL = input[i];
                    loop = false;
                    i = input.length() - 1;
                    continue;
                }
                i++;
            }
            else
            {
                if(input[i] >= '0' && input[i] <= '9')
                {
                    chR = input[i];
                    break;
                    continue;
                }
                i--;
            }
        }
        string temp = "";
        temp += chL;
        temp += chR;
        int temp1 = 0;

        stringstream t;
        t << temp;
        t >> temp1;
        answ += temp1;
    }
    cout << answ;
    return answ;
}