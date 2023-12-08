#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    fstream myFile("input.txt");
    string input;
    vector<int> cardsAndPoints;
    int sum = 0;
    int cardSet = 0;

    if(myFile.is_open())
    {
        while(getline(myFile, input))
        {
            cardSet++;
            vector<int> winingNums;
            vector<int> givenNums;

            if(cardsAndPoints.size() < cardSet)
                cardsAndPoints.push_back(1);

            input = input.substr(input.find(":") + 1);

            bool tableChange = true;
            int digit = 0;

            for(int i = 0; i < input.length()+1; ++i)
            {
                if(input[i] == '|')
                    tableChange = false;
                
                if(isdigit(input[i])) 
                    digit = digit*10 + (input[i] - 0x30);
                
                if(i == input.length() || !isdigit(input[i]) && digit > 0)
                {
                    
                    if(tableChange)
                        winingNums.push_back(digit);
                    else
                        givenNums.push_back(digit);
                    
                    digit = 0;
                }
            }

            int points = 0;
            for(int i = 0; i < winingNums.size(); ++i)
                for(int j = 0; j < givenNums.size(); ++j)
                    if(winingNums[i] == givenNums[j])
                        points++;
            
            //cout << "Points: " << points;

            int temp;
                    for(int x = 0; x < cardsAndPoints[cardSet-1]; ++x)
                        for(int i = 1; i <= points; ++i)
                            if(cardsAndPoints.size() < cardSet+i)
                            {
                                
                                cardsAndPoints.push_back(2);
                            }
                            else if(cardsAndPoints.size() >= cardSet+i)
                            {
                                cardsAndPoints[cardSet-1+i]++;
                            }
                
                //  for(int x : cardsAndPoints)
                //      cout << x << endl;

                // cout << "---------------------------"<<endl;
            winingNums.clear();
            givenNums.clear();
        }
         
        myFile.close();
    }
    else
    {
        cout << "File oppening filed";
        return 1;
    }

    for(int x : cardsAndPoints)
        sum += x;
        
    printf("Sum is %d", sum);

    return 0;
}
