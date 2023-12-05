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
    vector<string> table;


    getline(myFile, input);
    table.push_back(string(input.length(), '.'));
    table.push_back(input);

    while(getline(myFile, input))
        table.push_back(input);
    
    table.push_back(string(input.length(), '.'));

    //Komentarz

    int digit = 0;
    for(int i = 1; i < table.size()-1; ++i)
    {
        for(int j = 0; j < table[i].length(); ++j)
        {
            if(table[i][j] == '*')
            {
                for(int x = j-; x <= stop; ++x)
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
            }
            
        }
        digit = 0;
    }
        
    printf("Sum is: %d", sum);
}