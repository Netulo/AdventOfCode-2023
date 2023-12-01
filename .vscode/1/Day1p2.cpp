#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>

using namespace std;

int main()
{
    map<string, string> nums 
    {
    {"one", "o1e"}, 
    {"two", "t2o"}, 
    {"three", "t3e"}, 
    {"four", "f4r"}, 
    {"five", "f5e"}, 
    {"six", "s6x"},
    {"seven", "s7n"}, 
    {"eight", "e8t"},
    {"nine", "n9e"}
    };
    
    string input;
    char chL, chR;
    int answ = 0;
    fstream inputFile ("input.txt");

    while(getline(inputFile,input))
    {
            
        chL = 0;
        chR = 0;
        bool loop = true;
        
        for(auto str : nums)
            for(int i = input.length()/2; i >= 0; --i)
                if(input.find(str.first) < input.length())
                    input.replace(input.find(str.first), str.first.length(), str.second);

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
        //cout << temp1 << endl;
        answ += temp1;
    }
    inputFile.close();
    cout << answ;
    return answ;
}

//poprawna 54418