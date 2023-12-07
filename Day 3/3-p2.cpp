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
    vector<string> table;
    vector<vector<int>> gears;


    getline(myFile, input);
    table.push_back(string(input.length(), '.'));
    table.push_back(input);

    while(getline(myFile, input))
        table.push_back(input);
    
    table.push_back(string(input.length(), '.'));



    int digit = 0;
    for(int i = 1; i < table.size()-1; ++i)
    {
        for(int j = 0; j < table[i].length(); ++j)
        {
            if(isdigit(table[i][j]))
            {
                digit = digit*10 + (table[i][j] - 0x30);
                if(j != table[i].length()-1 && isdigit(table[i][j+1]))
                    continue;
                
            }
            if(digit > 0)
            {
                vector<int> gear;

                int l = to_string(digit).length();
                int x, stop, start;
                    if(j-l < 0)
                    {
                        start = j-l+1;
                        stop = j+1;
                    }
                    else if(j == table[i].length()-1)
                    {
                        start = j-l;
                        stop = j;
                    }
                    else
                    {
                        start = j-l;
                        stop = j+1;
                    }
                    
                    for(int y = i-1; y <= i+1; ++y)
                        {
                            for(x = start; x <= stop; ++x)
                            {
                        
                            if(table[y][x] == '*')
                            {
                                int z = 0;
                                do
                                {
                                        if(gears.size() != 0 && gears[z][0] == x && gears[z][1] == y)
                                        {
                                            gears[z].push_back(digit);
                                            break;
                                        }
                                        if(gears.size() == 0 || z == gears.size()-1)
                                        {
                                            gear.push_back(x);
                                            gear.push_back(y);
                                            gear.push_back(digit);
                                            gears.push_back(gear);
                                            gear.clear();
                                            break;
                                        }
                                        z++;
                                } while (z < gears.size());
                            }
                        }
                    }
                digit = 0;
            }
        }
        digit = 0;
    }

    for(int i = 0; i < gears.size(); ++i)
        if(gears[i].size()-2 == 2)
            sum += gears[i][2]*gears[i][3];
        
    printf("Sum is: %d", sum);
}

//87605697