#include<iostream>
#include<string>
#include<fstream>
#include<map>

using namespace std;

int main()
{
    fstream myFile("input.txt");

    if(!myFile.is_open())
    {
        cout << "File oppening failed";
        return -1;
    }

    string instruction;
    getline(myFile, instruction);
    
    int count = 0;
    string input;
    map<string, string> maps;
    
    getline(myFile, input);
    while(getline(myFile, input))
    {
        string key;
        key = input.substr(0,3);
        
        input = input.substr(input.find('('));
        
        maps[key] = input;
        
    }

    int loopCount = 0;
    string mapID = "AAA";
    while(true)
    {
        if(loopCount >= instruction.length())
            loopCount = 0;

        if(instruction[loopCount++] == 'L')
            mapID = maps[mapID].substr(1, 3);
        else
             mapID = maps[mapID].substr(6, 3);

        count++;
        if(mapID == "ZZZ")
            break;
    }

    printf("Step count is: %d", count);
}