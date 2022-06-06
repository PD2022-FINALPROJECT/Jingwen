#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<windows.h>

#include "myDB.h"

void recommend()
{

    int weight, sex;
    char sex_c;
    double body_coefficient;

    printf("We will calculate your calorie requirement using the formula below：\n");
    printf("----------------------------------------\n");
    printf("Weight (kg) x (Girls 22/Boys 24) x Physical Activity Coefficient\n");
    printf("Physical activity coefficients are as follows:\n");
    printf("【1.1】Long-term bedridden or inability to walk\n");
    printf("【1.3】Sedentary or little activity\n");
    printf("【1.5】Occasionally walk or stand\n");
    printf("【1.7】Long-term walking or standing\n");
    printf("【1.9】Hard worker, high activity level\n");
    printf("------------------\n");

    printf("Please enter your weight: ");
    scanf("%d", &weight);
    printf("please input your gender in 'f'(female) or 'm'(male): ");


    scanf("%c",&sex_c);
    while(sex_c != 'f' && sex_c !='m')
    {
        printf("Please input the right formula.\n");
        printf("please input your gender in 'f'(female) or 'm'(male): ");
        scanf("%c", &sex_c);

    }

    if(sex_c == 'f') sex = 22;
    if(sex_c == 'm') sex = 24;

    printf("Please enter your Physical Activity Coefficient: ");
    scanf("%lf", &body_coefficient);

    double need_calories = weight * sex * body_coefficient;
    printf("Your daily calorie requirement is: %.2lf\n", need_calories);

    int sum_calories = 1000;
    if(sum_calories > need_calories)
    {
        printf("You have consumed more calories than your recommended daily requirement.\n");
        return ;
    }

    int differ_calories = need_calories - sum_calories;
    int recommend_calories = 0;
    int recommend_count = 0;
    int rand_type, rand_food;
    int cal;

    printf("We recommend the following diet (kcal/100g): \n");
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
        printf("【%d】%s: %s\n", recommend_count, food_data[rand_type][rand_food][0], food_data[rand_type][rand_food][1]);
        Sleep(1000);
    }
    printf("If you eat them, your final calories is: %d kcal\n", recommend_calories + sum_calories);
}