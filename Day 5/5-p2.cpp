#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<algor
#include <map>

using namespace std;

const int NUM_CATEGORIES = 7;

int main()
{
    fstream myFile("input.txt");
    string input;
    map<int64_t, int64_t> farmingCategories[NUM_CATEGORIES];
    vector<int64_t> seeds;

    if (!myFile.is_open())
    {
        cout << "Error: Unable to open the file." << endl;
        return 2;
    }

    // Reading seeds from the first line
    getline(myFile, input);
    int64_t digit = 0;
    for (int i = 0; i < input.length(); ++i)
    {
        if (isdigit(input[i]))
            digit = digit * 10 + (input[i] - '0');
        if (i == input.length() - 1 || digit > 0 && !isdigit(input[i]))
        {
            seeds.push_back(digit);
            digit = 0;
        }
    }

    int section = -1;
    while (getline(myFile, input))
    {
        if (input.find("map") != string::npos)
        {
            section++;
            continue;
        }
        else if (input == "")
            continue;

        int64_t instructions[3] = {0};
        int size = 0;
        digit = 0;
        bool isZero = false;
        for (int i = 0; i < input.length(); ++i)
        {
            if (isdigit(input[i]))
            {
                digit = digit * 10 + (input[i] - '0');
                if (digit == 0)
                    isZero = true;
            }
            if (i == input.length() - 1 || isZero || (digit > 0 && !isdigit(input[i])))
            {
                instructions[size++] = digit;
                digit = 0;
                isZero = false;
            }
        }

        for (int i = 0; i < instructions[2]; ++i)
        {
            farmingCategories[section][instructions[1]] = instructions[0];
            instructions[1]++;
            instructions[0]++;
        }
    }

    myFile.close();

    // Map seeds to their lowest location
    for (auto &seed : seeds)
    {
        for (int j = 0; j < NUM_CATEGORIES; ++j)
        {
            auto it = farmingCategories[j].find(seed);
            if (it != farmingCategories[j].end())
            {
                seed = it->second;
                break;
            }
        }
    }

    // Output the lowest location
    cout << "Lowest location: " << *min_element(seeds.begin(), seeds.end()) << endl;

    return 0;
}