#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
    int sum = brown + yellow;
    int width, height = 0;

    for (height = 3; height <= 5000; height++)
    {
        if (!(sum % height))
        {
            width = sum / height;
            if ((width - 2) * (height - 2) == yellow)
            {
                answer.push_back(width);
                answer.push_back(height);

                break;
            }
        }
    }

	return answer;
}
