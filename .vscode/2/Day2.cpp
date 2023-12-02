#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    fstream myFile("input.txt");
    string input;
    int sum = 0;
    int gameId = 0;

    while(getline(myFile, input))
    {
        gameId++;
        input = input.substr(input.find(':'));
        bool isValid = true;
        int num;

        for(int i = 0; i < input.length(); ++i)
        {
            if(isdigit(input[i]))
            {
                num = input[i] - 0x30;
                if(i+1 < input.length() && isdigit(input[i+1]))
                {
                    num = num*10 + (input[i+1] - 0x30);
                    i++;
                }
            }
            else
            {
                if(input.length()-1-i >= 4 && input.substr(i, 4) == "blue" && num > 14)
                {
                    isValid = false;
                    break;
                }
                else if(input.length()-1-i >= 5 && input.substr(i, 5) == "green" && num > 13)
                {
                    isValid = false;
                    break;
                }
                else if(input.length()-1-i >= 3 && input.substr(i, 3) == "red" && num > 12)
                {
                    isValid = false;
                    break;
                }
            }
        }

        if(isValid)
            sum += gameId;
    }
    myFile.close();

    printf("Sum is: %d", sum);
}