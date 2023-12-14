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
    map<unsigned long long, unsigned long long> farmingCategories;
    
    vector<unsigned long long> seeds;

    if(myFile.is_open())
    {
        unsigned long long digit = 0;
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
         vector<vector<unsigned long long>> instructions;

        while(!myFile.eof())
        {
            getline(myFile, input);
            if(input.find("map") != string::npos)
            {
                section++;
                
                continue;
            }
            
            digit = 0;
            bool isZero = false;
            vector<unsigned long long> temp;
            for(int i = 0; i < input.length(); ++i)
            {
                
                if(isdigit(input[i]))
                {
                    digit = digit*10 + (input[i] - '0');
                    if(digit == 0)
                        isZero = true;
                }
                if(i == input.length()-1 || isZero || digit > 0 && !isdigit(input[i]))
                {
                    temp.push_back(digit);
                    digit = 0;
                    isZero = false;
                }
            }
            if(temp.size())
                instructions.push_back(temp);
            temp.clear();

            if(input != "")
                continue;
            
            for(int s = 0; s < seeds.size(); ++s)
                
                for(int i = 0; i < instructions.size(); ++i)
                        if(seeds[s] >= instructions[i][1] && seeds[s] < instructions[i][1]+instructions[i][2])
                        {
                            seeds[s] = seeds[s]-instructions[i][1]+instructions[i][0];
                            
                            break;
                        }
            instructions.clear();

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