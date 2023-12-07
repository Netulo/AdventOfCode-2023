#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    fstream myFile("input.txt");
    string input;
    int sum = 0;

    while(getline(myFile, input))
    {
        
        input = input.substr(input.find(':'));
        bool isValid = true;
        int num, numRed = 0, numBlue = 0, numGreen = 0;

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
                if(input.length()-i >= 4 && input.substr(i, 4) == "blue")
                {
                    if(numBlue == 0 || numBlue < num)
                        numBlue = num;
                }
                else if(input.length()-i >= 5 && input.substr(i, 5) == "green")
                {
                    if(numGreen == 0 || numGreen < num)
                        numGreen = num;
                }
                else if(input.length()-i >= 3 && input.substr(i, 3) == "red")
                {
                    if(numRed == 0 || numRed < num)
                        numRed = num;
                }
            }
        }

        sum += numBlue*numGreen*numRed;
    }
    myFile.close();

    printf("Sum is: %d", sum);
}