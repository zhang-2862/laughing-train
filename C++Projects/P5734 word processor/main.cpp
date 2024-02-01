#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int q;
    char str[100],in[100];
    cin>>q;
    cin>>str;
    for (int i = 0; i < q; ++i) {
        int op;
        cin>>op;
        if(op==1){
            cin>>in;
            strcat(str,in);
            cout<<str<<endl;
            continue;
        } else if(op==2){
            int a,b;
            cin>>a>>b;
            str[a+b]='\0';
            strcpy(in,&str[a]);
            strcpy(str,in);
            cout<<str<<endl;
            continue;
        } else if(op==3){
            int a;
            cin>>a;
            cin>>in;
            strcat(in,&str[a]);
            str[a]='\0';
            strcat(str,in);
            cout<<str<<endl;
            continue;
        } else{
            scanf("%s",in);
            char *ans=strstr(str,in);
            cout<<(ans != NULL ? (int)(ans-str):-1)<<endl;
        }
    }
    return 0;
}