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
    int sum = 0;
    map<string, string> farmingCategories[7];
    
    vector<string> seeds;

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
                seeds.push_back(to_string(digit));
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
            
            string instructions[3] = {"0"};
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
                    instructions[size++] = to_string(digit);
                    digit = 0;
                    isZero = false;
                }
            }

                // for(int x : instructions)
                //     cout << x << " ";
                // cout << endl;

            
            for(int i = 0; i < stoul(instructions[2]); ++i)
            {
                farmingCategories[section].insert(pair<string, string>(instructions[1], instructions[0]));
                instructions[1] = to_string(stoul(instructions[1])+1);
                instructions[0] = to_string(stoul(instructions[0])+1);
            }

        }
        myFile.close();

        // for(int x : seeds)
        //     cout << x << endl;
        
        for(int i = 0; i < seeds.size(); ++i)
        {
            for(int j = 0; j < 7; ++j)
            {
                if(farmingCategories[j].find(seeds[i]) != farmingCategories[j].end())
                {
                    seeds[i] = farmingCategories[j][seeds[i]];
                    //cout << seeds[i] << endl;
                }
                //cout << seeds[i] << " " << farmingCategories[j][seeds[i]] << endl;
            }
        }


            cout << "Lowest location: " << *min_element(seeds.begin(), seeds.end());
    }
    else
    {
        cout << "File oppening filed";
        return 2;
    }


    return 0;
}
