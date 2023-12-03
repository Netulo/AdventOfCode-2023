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
                //cout << table[i][j+1] << endl;
                int l = to_string(digit).length();
                int x, stop;
                    if(j-l < 0)
                    {
                        x = j-l+1;
                        stop = j+1;
                    }
                    else if(j == table[i].length()-1)
                    {
                        x = j-l;
                        stop = j;
                    }
                    else
                    {
                        x = j-l;
                        stop = j+1;
                    }
                    for(; x <= stop; ++x)
                    {
                        
                        if(
                            !isdigit(table[i+1][x]) && table[i+1][x] != '.' 
                            || !isdigit(table[i][x]) && table[i][x] != '.'
                            || !isdigit(table[i-1][x]) && table[i-1][x] != '.'
                            )
                        {
                            //cout << digit << endl;
                            sum += digit;
                            break;
                        }
                    }      
                digit = 0;
            }
        }
        digit = 0;
    }
        
    printf("Sum is: %d", sum);
}