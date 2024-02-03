#include <iostream>
#include <cstring>
#include <cctype>

//将字符串转化为小写的函数
void strLower(char *a){
    for (int i = 0; a[i]; ++i) {

            a[i] = tolower(a[i]);

    }
}

int main() {
    char article[1000001],word[10];//文章，单词
    char *p,*q;//定义两个字符指针
    bool flag= false;//用来判断是否为首次找到
    int freq=0;
    int pos=-1;

    //输入
    fgets(word,sizeof (word),stdin);

    if(strlen(word)!=sizeof (word)-1){//未装满
        word[strlen(word)-1]='\0';//将最后一个字符更改为‘\0’
    }
    fgets(article,sizeof(article),stdin);

    if(strlen(article)!=sizeof (article)-1){//未装满
        article[strlen(article)-1]='\0';//将最后一个字符更改为‘\0’
    }
    strLower(word);
    strLower(article);

    p=article;
    int len= strlen(word);
//处理

    for(;q= strstr(p,word);){
        if((q==article || *(q-1)==' ')&&(*(q+len)==' ' || *(q+len)=='\0')){
            freq++;
            if(!flag){
                flag= true;
                pos=q-article;
            }
        }
        p=q+len;
    }
    if(flag){
        printf("%d %d",freq,pos);
    } else{
        printf("-1");
    }

    return 0;
}
