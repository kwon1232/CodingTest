#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool IsPrime(long long n)
{
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) 
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string convertNumber = "";

    while (n > 0)
    {
        convertNumber += to_string(n % k);
        n /= k;
    }

    reverse(convertNumber.begin(), convertNumber.end());

    string tmp = "";
    for (int i = 0; i < convertNumber.size(); i++)
    {
        if (convertNumber[i] == '0')
        {
            if (!tmp.empty() && IsPrime(stoll(tmp)))
                answer++;
            tmp = "";
        }
        else
            tmp += convertNumber[i];
    }
    if (!tmp.empty() && IsPrime(stoll(tmp)))
        answer++;


    return answer;
}

