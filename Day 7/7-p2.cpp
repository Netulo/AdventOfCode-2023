#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int compare(const string &hand1, const string &hand2);
int whatType(const string &hand);
int findF(char arr[], int n, char key);

int main()
{
    fstream myFile("input.txt");
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
        for(int j = 0; j < hands.size()-1; ++j)
            if(compare(hands[j][0], hands[j+1][0]) > 0)
            {
                auto tempVec = hands[j];
                hands[j] = hands[j+1];
                hands[j+1] = tempVec;
            }

    int count = 0;
    int sum = 0;
    for(auto x : hands)
         sum += stoi(x[1]) * (++count);
    

    printf("Sum is %d", sum);
    return 0;
}



int compare(const string &hand1, const string &hand2)
{
    if(whatType(hand1) < whatType(hand2)) return 1;
    if(whatType(hand1) > whatType(hand2)) return -1;
    
    char symbols[] = {'A', 'K', 'Q', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'J'};
    for(int i = 0; i < hand1.length(); ++i)
    {
        int find1 = findF(symbols, 13, hand1[i]);
        int find2 = findF(symbols, 13, hand2[i]);

        if (find1 != find2) return find2 - find1;
    }

    return 0;
}

int whatType(const string &hand)
{
    map<char, int> temp;
    for(int i = 0; i < hand.length(); ++i)
    {
        if(temp.find(hand[i]) != temp.end())
            temp[hand[i]] += 1; 
        else
            temp[hand[i]] = 1; 
    }

    int tempNum = 0;
    for(const auto &x : temp)
    {
        if(x.second > tempNum)
            tempNum = x.second;
    }

    if(temp.size() == 1) return 1;
    if(temp.size() == 2 && (temp.begin()->second == 4 || (temp.rbegin())->second == 4)) return 2;
    if(temp.size() == 2 && (temp.begin()->second == 3 || (temp.rbegin())->second == 3)) return 3;
    if(temp.size() == 3 && (temp.begin()->second == 2 || (temp.rbegin())->second == 2)) return 5;
    if(temp.size() == 3) return 4;
    if(temp.size() == 4) return 6;
    
    return 7;
}

int findF(char arr[], int n, char key)
{
    int index = -1;

    for(int i=0; i<n; i++)
        if(arr[i]==key)
        {
            index=i;
            break;
        }
    return index;
}