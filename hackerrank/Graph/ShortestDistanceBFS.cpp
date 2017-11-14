#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        cin >> n >> m;
        vector<int> list[n+1];
        for(int i=1;i<=m;i++){
            int s,d;
            cin >> s >> d;
            list[s].push_back(d);
            list[d].push_back(s);
        }
        int st;
        cin >> st;
        int *distance = new int[n+1];
        bool *visited = new bool[n+1];
        for(int i = 1; i <=n; i++){
        distance[i] = 0;visited[i]=false;}
        queue <int> q;
        distance[st] = 0;
        visited[st]=true;
        q.push(st);
        vector<int>:: iterator i;
        while(!q.empty()){
            int r = q.front();
            q.pop();
            for(i = list[r].begin();i<list[r].end();i++){
                    if(!visited[*i]){
                        distance[*i] = distance[r]+6;
                        visited[*i]=true;
                        q.push(*i);
                    }
            }
            
        }
        for(int m=1;m<=n;m++){
            if(m!=st){
                if(distance[m]==0){cout<<"-1 ";}
                else cout<<distance[m]<<" ";
            }
        }
        cout<<"\n";
   }
   return 0;
}
