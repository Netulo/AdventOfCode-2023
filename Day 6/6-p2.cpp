#include<iostream>
#include<fstream>
#include<string>

using namespace std;


long long strToint(string str)
{
    string numStr = "";
    for(int i = 0; i < str.length(); ++i)
        if(isdigit(str[i]))
            numStr += str[i];

    return stoll(numStr);
}


int main()
{
    fstream myFile("input.txt");
    string input;

    if(!myFile.is_open())
    {
        cout << "File oppening failed";
        return -1;
    }
    long long time, distance;

    getline(myFile, input);
    time = strToint(input);

    getline(myFile, input);
    distance = strToint(input);

    long long count = 0;
        for(int t = 1; t <= time; ++t)
        {
            long long boatDis;
            boatDis = (time-t)*t;
            if(boatDis > distance)
                count++;
        }


     cout << "Sum is: " << count;


    return 0;
}
