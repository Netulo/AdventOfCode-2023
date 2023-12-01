#include<iostream>
#include<string>
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
    int answ = 0;
    fstream inputFile ("input.txt");

    while(getline(inputFile,input))
    { 
        int numL = 0;
        int numR = 0;
        
        for(auto str : nums)
            for(int i = input.length()/2; i >= 0; --i)
                if(input.find(str.first) < input.length())
                    input.replace(input.find(str.first), str.first.length(), str.second);

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

//poprawna 54418