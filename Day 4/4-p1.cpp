#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    fstream myFile("test.txt");
    string input;
    int sum = 0;

    if(myFile.is_open())
    {
        while(getline(myFile, input))
        {
            vector<int> winingNums;
            vector<int> givenNums;

            input = input.substr(input.find(":") + 1);

            cout << input << endl; 
            bool tableChange = true;
            int digit = 0;

            for(int i = 0; i < input.length(); ++i)
            {
                cout << -1;
                if(isdigit(input[i]))
                {
                    //cout << -1;
                    digit = digit*10 + (input[i] - 0x30);
                }
                else if(input[i] == '|')
                    tableChange = false;
                else if(digit > 0)
                {
                    //cout << digit;
                    if(tableChange)
                    {
                        winingNums.push_back(digit);
                    }
                    else
                    {
                        givenNums.push_back(digit);
                    }
                    cout << "winingNumber: " << winingNums[winingNums.back()] << " givenNumber: " << givenNums[givenNums.back()] << endl;
                    digit = 0;
                }
            }

            int points = 0;
            for(int i = 0; i < winingNums.size(); ++i)
            {
                for(int j = 0; i < givenNums.size(); ++j)
                {
                    if(winingNums[i] == givenNums[j])
                        if(!points)
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
