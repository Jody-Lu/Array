#include <cstdio>
#include <algorithm>
using namespace std;
struct dictionary{
    char w[10];
    int map;
}dic[102];
bool cmp (dictionary a,dictionary b){
    for (int i=0; ; i++)
        if (a.w[i] != b.w[i]) return a.w[i] < b.w[i];
}
int main(){
    freopen ("input.txt","rt",stdin);
    int nOfdic=0,i;
    for (i=0;;i++){
        gets(dic[i].w);
        if (dic[i].w[0]=='X' && dic[i].w[1]=='X' && dic[i].w[2]=='X' &&
            dic[i].w[3]=='X' && dic[i].w[4]=='X' && dic[i].w[5]=='X') break;
        dic[i].map = 0;
        for (int j=0; dic[i].w[j]; j++){
            int t = dic[i].w[j];
            dic[i].map += (3.56*t*t*t+2*t*t+337);
        }
    }
    nOfdic = i;
    sort (dic,dic+nOfdic,cmp);

    char line[10];
    while (gets(line)){
        if (line[0]=='X' && line[1]=='X' && line[2]=='X' &&
            line[3]=='X' && line[3]=='X' && line[5]=='X') break;
        int n = 0;
        for (i=0; line[i]; i++){
            int t = line[i];
            n += (3.56*t*t*t+2*t*t+337);
        }
        bool valid=0;
        for (i=0; i<nOfdic; i++){
            if (n == dic[i].map){
                valid = 1;
                printf("%s\n",dic[i].w);
            }
        }
        if (!valid) printf("NOT A VALID WORD\n");
        printf("******\n");
    }
}