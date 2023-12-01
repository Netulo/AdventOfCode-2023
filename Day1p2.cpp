#include<iostream>
#include<string.h>
#include<string>
#include<sstream>

using namespace std;

int FunFor(string input, int start, string nums[])
{
    
    for(int y = 0; y < 9; ++y)
    {
        if(nums[y] == input.substr(start, nums[y].length()))
            return y+1;

    }
    return 0;
}

int FunBack(string input, int start, string nums[])
{
    
    for(int y = 0; y < 9; ++y)
    {
        if(start < nums[y].length())
            break;
        if(nums[y] == input.substr(start - nums[y].length()+1, nums[y].length()))
            return y+1;

    }
    return 0;
}

int main()
{

    string nums[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
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
        int t = 0;
        for(int i = 0; i < input.length() || i >= 0;)
        {
            if(loop)
            {
                int funForOut = FunFor(input, i, nums);
                if(funForOut)
                {
                    chL = funForOut + 48;
                    //input.erase(i+1);
                    loop = false;
                    t = i + nums[funForOut-1].length()-1;
                    i = input.length() - 1;
                    continue;
                }
                if(input[i] >= '0' && input[i] <= '9')
                {
                    chL = input[i];
                    //input.erase(i);
                    loop = false;
                    i = input.length() - 1;
                    continue;
                }
                i++;
            }
            else
            {
                int funBackOut = FunBack(input, i, nums);
                if(funBackOut && t != i)
                {
                    chR = funBackOut + 48;
                    break;
                }
                if(input[i] >= '0' && input[i] <= '9')
                {
                    chR = input[i];
                    break;
                }
                i--;
            }
        }
        string temp = "";
        temp += chL;
        temp += chR;
        int temp1 = 0;

        stringstream tstr;
        tstr << temp;
        tstr >> temp1;
        cout << temp1 << endl;
        answ += temp1;
    }
    cout << answ;
    return answ;
}