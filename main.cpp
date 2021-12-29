#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Person{
    int R,G,B;
    bool trade;
};
vector<Person> personList;

int sol(vector<vector<int>> cards){
    int answer = 0;
    int n = cards.size();
    for(auto p : cards) {
        personList.push_back({p[0],p[1],p[2],false});
    }
    for(int i = 0; i < personList.size(); i++) {
        for(int j = i+1; j < personList.size(); j++) {
            if(personList[i].trade || personList[j].trade) continue;
            int firstScore = min(personList[i].R, min(personList[i].G, personList[i].B));
            int secondScore = min(personList[j].R, min(personList[j].G, personList[j].B));
            int fR = personList[i].R; int fG = personList[i].G; int fB = personList[i].B;
            int sR = personList[j].R; int sG = personList[j].G; int sB = personList[j].B;

            if(fR > 0 && sG > 0 && firstScore < min(fR-1, min(fG+1, fB)) && secondScore < min(sR+1, min(sG-1, sB))) {
                personList[i].trade = true; personList[j].trade = true;
                personList[i].R--; personList[i].G++;
                personList[j].R++; personList[j].G--;
            }
            else if(fR > 0 && sB > 0 && firstScore < min(fR-1, min(fG, fB+1)) && secondScore < min(sR+1, min(sG, sB-1))) {
                personList[i].trade = true; personList[j].trade = true;
                personList[i].R--; personList[i].B++;
                personList[j].R++; personList[j].B--;
            }
            else if(fG > 0 && sR > 0 && firstScore < min(fR+1, min(fG-1, fB)) && secondScore < min(sR-1, min(sG+1, sB))) {
                personList[i].trade = true; personList[j].trade = true;
                personList[i].G--; personList[i].R++;
                personList[j].G++; personList[j].R--;
            }
            else if(fG > 0 && sB > 0 && firstScore < min(fR, min(fG-1, fB+1)) && secondScore < min(sR, min(sG+1, sB-1))) {
                personList[i].trade = true; personList[j].trade = true;
                personList[i].G--; personList[i].B++;
                personList[j].G++; personList[j].B--;
            }
            else if(fB > 0 && sR > 0 && firstScore < min(fR+1, min(fG, fB-1)) && secondScore < min(sR-1, min(sG, sB+1))) {
                personList[i].trade = true; personList[j].trade = true;
                personList[i].B--; personList[i].R++;
                personList[j].B++; personList[j].R--;
            }
            else if(fB > 0 && sG > 0 && firstScore < min(fR, min(fG+1, fB-1)) && secondScore < min(sR, min(sG-1, sB+1))) {
                personList[i].trade = true; personList[j].trade = true;
                personList[i].B--; personList[i].G++;
                personList[j].B++; personList[j].G--;
            }
        }
    }
    for(auto p : personList) {
        answer += min(p.G, min(p.R, p.B));
    }

    return answer;
}

int main() {
    cout << sol({{8,11,11},{10,7,13},{15,10,5},{7,17,6}});
//    cout << sol({{0,0,30}, {30,0,0}});
}