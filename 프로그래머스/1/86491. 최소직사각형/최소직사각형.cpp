#include <string>
#include <vector>

using namespace std;

typedef struct Vector2
{
    int x = 0, y = 0;
}Vector2;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    Vector2 size;
    
    for (int i = 0; i < sizes.size(); i++)
    {
        Vector2 card;
        if(sizes[i][0] < sizes[i][1])
        {
            card.x = sizes[i][0];
            card.y = sizes[i][1];
        }
        else
        {
            card.x = sizes[i][1];
            card.y = sizes[i][0];
        }
        
        if(card.x > size.x)
        {
            size.x = card.x;
        }
        if(card.y > size.y)
        {
            size.y = card.y;
        }
    }
    
    
    
    
    return size.x* size.y;
}