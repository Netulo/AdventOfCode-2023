#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{

    string input = " ";
    char chL, chR;
    int answ = 0;
    fstream inputFile ("input.txt");

    //getline(cin,input,' ')
    while(getline(inputFile,input))
    {
        int numL = 0;
        int numR = 0;
        
        for(int i = 0; i < input.length(); ++i)
        {

            if(isdigit(input[i]))
                if(numL == 0)
                {
                    numL = input[i] - 0x30;
                    numR = input[i] - 0x30;
                }
                else
                    numR = input[i] - 0x30;
        }
        
        int temp = numL*10 + numR;
        answ += temp;
    }
    inputFile.close();

    printf("%d\n", answ);
    return answ;
}