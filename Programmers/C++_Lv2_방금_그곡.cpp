#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string replaceAll(string &m, string from, string to){
    int pos = 0;
    while((pos=m.find(from))!=-1){
        m.replace(pos,from.length(), to);
    }
    return m;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    pair<int,string> ans = {0,""};
    replaceAll(m, "A#","a");
    replaceAll(m, "B#","b");
    replaceAll(m, "C#","c");
    replaceAll(m, "D#","d");
    replaceAll(m, "E#","e");
    replaceAll(m, "F#","f");
    replaceAll(m, "G#","g");
    for(int i=0; i<musicinfos.size(); i++){
        int t = 0, idx = 0, pos = 0;
        string h1,h2,m1,m2, title = "", scale = "";
        h1 = musicinfos[i].substr(0,2);
        m1 = musicinfos[i].substr(3,2);
        h2 = musicinfos[i].substr(6,2);
        m2 = musicinfos[i].substr(9,2);
        t = abs(stoi(h2)-stoi(h1))*60;
        if(m1>m2){
            t-=60;
            t+=(stoi(m2)-stoi(m1))+60;
        }
        else t+=stoi(m2)-stoi(m1);
        for(int j=12; j<musicinfos[i].size(); j++){
            if(musicinfos[i][j]==','){
                idx = j+1;
                break;
            }
            title += musicinfos[i][j];
        }
        for(int j=idx; j<musicinfos[i].size(); j++) scale+=musicinfos[i][j];
        replaceAll(scale, "A#","a");
        replaceAll(scale, "B#","b");
        replaceAll(scale, "C#","c");
        replaceAll(scale, "D#","d");
        replaceAll(scale, "E#","e");
        replaceAll(scale, "F#","f");
        replaceAll(scale, "G#","g");
        if(t/scale.size()>=1){
            int a = (t/scale.size())-1;
            string temp = scale;
            for(int j=0; j<a; j++) scale+=temp;
            for(int j=0; j<t%temp.size(); j++) scale+=temp[j];
        }
        else{
            string temp = "";
            for(int j=0; j<t; j++) temp+=scale[j];
            scale = temp;
        }
        idx = scale.find(m);
        if(idx!=-1&&ans.first<t){
            ans.first = t;
            ans.second = title;
        }
    }
    answer = ans.second;
    if(answer=="") answer = "(None)";
    return answer;
}
