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
    int farmingCategories[7][100];
    vector<int> seeds;
    //vector<vector<vector<int>>> fatmingCategories;

    if(myFile.is_open())
    {
        int digit = 0;
        getline(myFile, input);
        for(int i = 0; i < input.length(); ++i)
        {
            if(isdigit(input[i]))
                digit = digit*10 + (input[i] - 0x30);
            if(i == input.length()-1 || digit > 0)
            {
                seeds.push_back(digit);
                digit = 0;
            }
        }

        // for(int x : seeds)
        //     cout << x;


        int section = -1;
        while(getline(myFile, input))
        {
            if(input.find("map") != string::npos)
            {
                section++;
                continue;
            }
            
            
        }
        myFile.close();
    }
    else
    {
        cout << "File oppening filed";
        return 1;
    }


    return 0;
}
