#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
    fstream myFile("input.txt");
    string input;
    map<unsigned int, unsigned int> farmingCategories;
    
    vector<unsigned int> seeds;

    if(myFile.is_open())
    {
        unsigned int digit = 0;
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

        getline(myFile, input);
        int section = -1;
        while(getline(myFile, input))
        {
            if(input.find("map") != string::npos)
            {
                section++;
                continue;
            }
            
            vector<unsigned int> instructions;
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
                    instructions.push_back(digit);
                    digit = 0;
                    isZero = false;
                }
            }

            
            for(int i = 0; i < seeds.size(); ++i)
            {
                if(seeds[i] >= instructions[1] &&)
            }

            if(input == "")
            {
                for(int i = 0; i < seeds.size(); ++i)
                if(farmingCategories.find(seeds[i]) != farmingCategories.end())
                    seeds[i] = farmingCategories[seeds[i]];

                farmingCategories.clear();
                continue;
            }

        }
        myFile.close();

            cout << "Lowest location: " << *min_element(seeds.begin(), seeds.end());
    }
    else
    {
        cout << "File oppening filed";
        return 2;
    }
    return 0;
}
