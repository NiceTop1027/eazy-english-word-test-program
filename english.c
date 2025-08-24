#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void init(){
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    setbuf(stderr, NULL);
}

void logo(){
    printf("====================================\n");
    printf("=                                  =\n");
    printf("=      영어 단어 시험 프로그램     =\n");
    printf("=          made by s13w00          =\n");
    printf("=                                  =\n");
    printf("====================================\n");
}

int main(){
    init();
    logo();
    int n;

    printf("총 단어의 계수를 적어주세요 : ");
    scanf("%d", &n);
    printf("입력하신 단어의 총 개수는 %d개 입니다.\n", n);

    char word[n][20];
    char answer[n][20];
    int score = 0;

    printf("단어와 정답을 입력하세요\n");
    for(int i = 0; i < n; i++){
        printf("단어 : ");
        ssize_t len = read(0, word[i], 19);
        if (len > 0) word[i][len - 1] = '\0';

        printf("뜻 : ");
        len = read(0, answer[i], 19);
        if (len > 0) answer[i][len - 1] = '\0';
    }
    puts("입력을 모두 마쳤습니다.\n");
    puts("본격적으로 영어 단어 테스트를 시작합니다.");
    puts("==먼저 첫번째는 단어만 보고 뜻 맞추기 입니다.==");
    puts("=====================================");
    for(int i = 0; i < n; i++){
        printf("단어 : %s\n", word[i]);
        char input[20];
        printf("뜻 : ");
        scanf("%s", input, sizeof(input));
        if(strcmp(input, answer[i]) == 0){
            puts("정답입니다!");
            score++;
            puts("=====================================");
        }
        else{
            puts("틀렸습니다.");
            puts("=====================================");
        }
    }
    printf("뜻 맞추기 테스트가 끝났습니다. 밑에 점수를 확인해주세요 !\n");
    printf("첫번째 뜻 맞추기 테스트의 점수는 합계 %d점 입니다.\n", score);
    puts("======================================");
    int score2 = 0;
    printf("두번째는 뜻만 보고 단어 맞추기 입니다.\n");
    for(int i = 0; i < n; i++){
        printf("뜻 : %s\n", answer[i]);
        char input[20];
        printf("단어 : ");
        scanf("%s", input, sizeof(input));
        if(strcmp(input, word[i]) == 0){
            puts("정답입니다!");
            score2++;
            puts("=====================================");
        }
        else{
            puts("틀렸습니다.");
            puts("=====================================");
        }
    }
    printf("뜻 맞추기 테스트가 끝났습니다. 밑에 점수를 확인해주세요 !\n");
    printf("두번째 뜻 맞추기 테스트의 점수는 합계 %d점 입니다.\n", score2);
    puts("======================================");
    printf("최종 점수는 뜻 : %d점, 단어 : %d점 입니다.\n", score, score2);
    puts("프로그램을 종료합니다.");
    return 0;
}