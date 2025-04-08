#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> idMap;

    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string cmd, id, name;
        ss >> cmd;
        if (cmd.compare("Enter") == 0) {
            ss >> id >> name;
            idMap[id] = name;
        }
        else if (cmd.compare("Change") == 0) {
            ss >> id >> name;
            idMap[id] = name;
        }
    }
    
    for (string &it : record) {
        stringstream ss(it);
        string cmd, id;
        ss >> cmd;
        if (cmd.compare("Enter") == 0) {
            ss >> id;
            answer.push_back(idMap[id] + "님이 들어왔습니다.");
        }else if (cmd.compare("Leave") == 0){
            ss >> id;
            answer.push_back(idMap[id] + "님이 나갔습니다.");
        }
    }

    return answer;
}