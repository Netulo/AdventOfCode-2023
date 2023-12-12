#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#define INT_MAX 2147483647

using namespace std;

int main()
{
    fstream myFile("input.txt");
    string input;
    int sum = 0;
    int64_t farmingCategories[7][INT_MAX] = {0};
    for(int i = 0; i < 7; ++i)
        for(int j = 0; j < INT_MAX; ++j)
            farmingCategories[i][j] = j;
    

    vector<int64_t> seeds;
    //vector<vector<vector<int>>> fatmingCategories;

    if(myFile.is_open())
    {
        int64_t digit = 0;
        getline(myFile, input);
        for(int i = 0; i < input.length(); ++i)
        {
            if(isdigit(input[i]))
                digit = digit*10 + (input[i] - 0x30);
            if(i == input.length()-1 || digit > 0 && !isdigit(input[i]))
            {
                seeds.push_back(digit);
                digit = 0;
            }
        }

        //  for(int x : seeds)
        //      cout << x << endl;


        int section = -1;
        while(getline(myFile, input))
        {
            if(input.find("map") != string::npos)
            {
                section++;
                continue;
            }
            else if(input == "")
                continue;
            
            int64_t instructions[3] = {0};
            int size = 0;
            digit = 0;
            bool isZero = false;
            for(int i = 0; i < input.length(); ++i)
            {
                if(isdigit(input[i]))
                {
                    digit = digit*10 + (input[i] - 0x30);
                    if(digit == 0)
                        isZero = true;
                }
                if(i == input.length()-1 || isZero || digit > 0 && !isdigit(input[i]))
                {
                    instructions[size++] = digit;
                    digit = 0;
                    isZero = false;
                }
            }

                // for(int x : instructions)
                //     cout << x << " ";
                // cout << endl;

            
            for(int i = instructions[1]; i < instructions[1]+instructions[2]; ++i)
            {
                farmingCategories[section][i] = instructions[0];
                instructions[0]++;
            }

        }
        myFile.close();

        // for(int x : seeds)
        //     cout << x << endl;
        
        for(int i = 0; i < seeds.size(); ++i)
        {
            for(int j = 0; j < 7; ++j)
            {
                seeds[i] = farmingCategories[j][seeds[i]];
                //cout << seeds[i] << endl;
            }
        }

          for(int x : seeds)
            cout << x << endl;

            cout << "Lowest location: " << *min_element(seeds.begin(), seeds.end());
    }
    else
    {
        cout << "File oppening filed";
        return 1;
    }

    // for(int i = 0; i < 7; ++i)
    // {
    //     cout << i << endl;
    //     for(int j = 0; j < 100; ++j)
    //         cout << j << " " << farmingCategories[i][j] << endl;
    //     cout << endl;
    // }


    return 0;
}
