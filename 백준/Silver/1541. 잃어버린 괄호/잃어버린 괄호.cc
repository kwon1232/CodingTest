#include <vector>
#include <iostream> 
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <set>
#include <regex>
#include <tuple>
#include <cmath>


using namespace std;


vector<string> split(string input, char delimiter);
int mySum(string a);



int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    int answer = 0;
    string example;
    cin >> example;
    vector<string> str = split(example, '-');

    for (int i = 0; i < str.size(); i++)
    {
        int temp = mySum(str[i]);
        
        if (i == 0)
        {
            answer = answer + temp;
        }
        else {
            answer = answer - temp;
        }
    }

    cout << answer << "\n";
    
    return 0;
}

vector<string> split(string input, char delimiter)
{
    vector<string> result;
    stringstream ss(input);
    string splitdata;

    while (getline(ss, splitdata, delimiter))
    {
        result.push_back(splitdata);
    }

    return result;
}

int mySum(string a)
{
    int sum = 0;
    vector<string> temp = split(a, '+');

    for (int i = 0; i < temp.size(); i++)
    {
        sum += stoi(temp[i]);
    }
    return sum;
}