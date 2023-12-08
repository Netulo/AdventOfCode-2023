#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    fstream myFile("input.txt");
    string input;
    int sum = 0;

    if(myFile.is_open())
    {
        while(getline(myFile, input))
        {
            vector<int> winingNums;
            vector<int> givenNums;

            input = input.substr(input.find(":") + 1);

            bool tableChange = true;
            int digit = 0;

            for(int i = 0; i < input.length()+1; ++i)
            {
                if(input[i] == '|')
                    tableChange = false;
                
                if(isdigit(input[i])) 
                    digit = digit*10 + (input[i] - 0x30);
                
                if(i == input.length() || !isdigit(input[i]) && digit > 0)
                {
                    
                    if(tableChange)
                        winingNums.push_back(digit);
                    else
                        givenNums.push_back(digit);
                    
                    digit = 0;
                }
            }

            int points = 0;
            for(int i = 0; i < winingNums.size(); ++i)
            {
                for(int j = 0; j < givenNums.size(); ++j)
                {
                    
                    if(winingNums[i] == givenNums[j])
                        if(points == 0)
                            points++;
                        else
                            points *= 2;
                }
            }
            sum += points;
            winingNums.clear();
            givenNums.clear();
        }
         
        myFile.close();
    }
    else
    {
        cout << "File oppening filed";
        return 1;
    }

    printf("Sum is %d", sum);

    return 0;
}
