#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    fstream myFile("test.txt");
    if(!myFile.is_open())
    {
        cout << "File oppening failed";
        return 0;
    }

    string input;
    vector<vector<string>> hands;
    while(getline(myFile, input))
    {
        vector<string> hand;

        string cards = input.substr(0, input.find(' '));
        string bid = input.substr(input.find(' ') + 1);

        hand.push_back(cards);
        hand.push_back(bid);
        hands.push_back(hand);
    }

    for(int i = 0; i < hands.size(); ++i)
    {
        
    }
    return 0;
}