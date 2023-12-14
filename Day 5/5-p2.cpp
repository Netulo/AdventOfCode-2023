#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;




int main()
{
    fstream myFile("test.txt");
    string input;
    map<unsigned long, unsigned long> farmingCategories;
    
    vector<unsigned long> seeds;

    if(myFile.is_open())
    {
        unsigned long digit = 0;
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
         vector<vector<unsigned long>> instructions;

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
            vector<unsigned long> temp;
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
            


            
            for(int s = 0; s < seeds.size(); s+=2)
            {
                for(int i = 0; i < instructions.size(); ++i)
                {
                        if(seeds[s] >= instructions[i][1] && seeds[s]+seeds[s+1]-1 < instructions[i][1]+instructions[i][2])
                        {
                            seeds[s] = seeds[s]-instructions[i][1]+instructions[i][0]; 
                            break;
                        }
                        if(seeds[s] >= instructions[i][1] && seeds[s]+seeds[s+1]-1 >= instructions[i][1]+instructions[i][2])
                        {
                            unsigned long tempLen = seeds[s+1];
                            unsigned long tempSeed = seeds[s];

                            seeds[s+1] = instructions[i][1]+instructions[i][2]-seeds[s];
                            seeds[s] = seeds[s]-instructions[i][1]+instructions[i][0];

                            //This is throwing bad_alloc
                            seeds.push_back(tempSeed+seeds[s+1]);
                            seeds.push_back(tempLen-seeds[s+1]);
                            break;
                            
                        }
                }
                
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