#include <stdio.h>

#include <string.h>

int main(){

    char king[5],dol[5],w[5];

    int n =0;

    scanf("%s %s %d",king,dol,&n);

    while(n--){

        int x=0,y=0; 

// 매번 옮길 좌표 초기화 

        w[0]=0; w[1]=0;

// 마찬가지로 입력될 이동방향 초기화 

        scanf("%s",w);

        if(w[0]=='R'){

// 오른쪽 , 오른쪽 위 , 오른쪽 아래

            x++;

            if(w[1]=='T')

                y++;

            else if(w[1]=='B')

                y--;

        }else if(w[0]=='L'){

// 왼쪽, 왼쪽 위 , 왼쪽 아래 

            x--;

            if(w[1]=='T')

                y++;

            else if(w[1]=='B')

                y--;

        }else if(w[0]=='T')

// 위

            y++;

        else if(w[0]=='B')

// 아래

            y--;

// 이렇게 if문에 2중으로 하면 8가지의 방향을 짧게 걸러 낼 수 있다.

  

        if(king[0]+x>'H'||king[0]+x<'A'||king[1]+y>'8'||king[1]+y<'1') continue;

// 킹 아웃 확인

        king[0]+=x; king[1]+=y;

// 킹 아웃 아니면 방향대로 옮김 

        if(king[0]==dol[0] && king[1]==dol[1]){

// 옮긴 킹아래에 돌이 존재하면 돌님도 똑같이 옮기고 아웃 확인

            if(dol[0]+x>'H'||dol[0]+x<'A'||dol[1]+y>'8'||dol[1]+y<'1') {

                king[0]-=x; king[1]-=y;

// 아웃이면 킹님 재위치 

                continue;

            }

            dol[0]+=x; dol[1]+=y;

// 아웃도 아니면 돌님 이동 좌표 저장

        }

    }

    printf("%s\n",king);

    printf("%s",dol);

    return 0;

}