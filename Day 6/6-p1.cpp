#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>


using namespace std;

vector<int> Fun (string input)
{
    stringstream ss;
    vector<int> vec;
    int val;
    string temp;

    ss << input;
    while(!ss.eof())
    {
        ss >> temp;
        if(stringstream(temp) >> val)
            vec.push_back(val);
        temp = "";
    }

    return vec;
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
    
    getline(myFile, input);
    vector<int> time = Fun(input);

    getline(myFile, input);
    vector<int> distance = Fun(input);
    
    int sum = 1;
    int count = 0;
    for(int i = 0; i < time.size(); ++i)
    {
        for(int t = 1; t <= time[i]; ++t)
        {
            int boatDis;
            boatDis = (time[i]-t)*t;
            if(boatDis > distance[i])
                count++;
        }
        sum *= count;
        count = 0;
    }

    cout << "Sum is: " << sum;


    return 0;
}