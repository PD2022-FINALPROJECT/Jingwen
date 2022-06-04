#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void recommend()
{
    int weight, sex;
    double body_coefficient;
    printf("We will calculate your calorie requirement using the formula below：\n");
    printf("----------------------------------------\n");
    printf("體重(公斤)x(女生22/男生24)x身體活動係數\n");
    printf("身體活動係數如下：\n");
    printf("【1.1】長期臥床或無法走動\n");
    printf("【1.3】久坐或少量活動\n");
    printf("【1.5】偶爾走動或站立\n");
    printf("【1.7】長期走動或站立\n");
    printf("【1.9】努力工作者，活動量極高\n");
    printf("------------------\n");

    printf("請輸入您的體重：");
    scanf("%d", &weight);
    printf("請輸入您的性別代號 【22】女生【24】男生：");

    scanf("%d", &sex);
    while(sex != 24 && sex !=22)
    {
        printf("Please input the right formula.\n");
        printf("請輸入您的性別代號 【22】女生【24】男生：");
        scanf("%d", &sex);

    }
    printf("請輸入您的身體活動係數：");
    scanf("%lf", &body_coefficient);

    double need_calories = weight * sex * body_coefficient;
    printf("您的每日所需熱量為：%.2lf\n", need_calories);

    int sum_calories = 1000;
    if(sum_calories > need_calories)
    {
        printf("You have consumed more calories than your recommended daily requirement.\n");
        return 0;
    }

    int differ_calories = need_calories - sum_calories;
    int recommend_calories = 0;
    int recommend_count = 0;
    int rand_type, rand_food;
    int cal;

    printf("We recommend the following diet (kcal/100g):\n");
    while(recommend_calories < differ_calories-50)
    {
        time_t time_seed;
        time_seed=time(NULL);
        srand(time_seed);

        do
        {
            rand_type=rand()%4;
            rand_food = rand() % type_num[rand_type];
            cal = atoi(food_data[rand_type][rand_food][1]);
        } while (cal + recommend_calories > differ_calories);

        recommend_count++;
        recommend_calories = recommend_calories + cal;
        printf("【%d】%s：%s\n", recommend_count, food_data[rand_type][rand_food][0], food_data[rand_type][rand_food][1]);
        Sleep(1000);
    }
    printf("If you eat them, your final calories is：%d kcal\n", recommend_calories + sum_calories);
}