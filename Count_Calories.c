#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Below will contain in "myDB.h" document.
int type_num[5] = {fruit_datanum, vegetable_datanum, grains_datanum, protein_datanum, milk_datanum};
const char *food_data[5][100][2] = {{{"Durian", "136"}, {"Canna", "124"}, {"Shakya", "104"}, {"apple banana", "93"}, {"avocado", "92"}, {"American green grapes", "87"}, {"American Purple Grape", "80"}, {"cherry", "75"}, {"longan", "73"}, {"Seedless red grapes", "72"}, {"white cherry", "69"}, {"American red grapes", "69"}, {"Yuhebao Lychee", "68"}, {"passion fruit", "66"}, {"Black Beauty Grape", "66"}, {"Kyoho grapes", "64"}},
                                    {{"哈囉","111"},{"哈","112"},{"fsdf","124"}},
                                    {{"哈囉","111"},{"哈","112"},{"fsdf","124"}},
                                    {{"豬皮", "491"}, {"牛五花肉火鍋肉片", "430"}, {"帶骨牛小排", "360"}, {"豬蹄膀", "331"}, {"鴨賞", "304"}, {"去骨牛小排", "290"}, {"鴨腿", "282"}, {"牛肉火鍋片", "250"}, {"滷豬腳", "237"}, {"豬耳朵", "233"}, {"櫻桃鴨胸肉片", "227"}, {"帶皮雞胸肉", "219"}, {"烤雞翅", "217"}, {"雞腳", "216"}, {"烏骨雞", "213"}, {"豬絞肉", "218"}, {"牛肋條", "225"}, {"烤雞", "233"}, {"司目魚", "200"}, {"鮭魚", "222"}},
                                    {{"dsf","21"},{"awd","11"},{"aw","212"}}};
*/
void count_calories()
{
    int kind; //決定輸入食物類別
    char input_name[100]; //輸入的食物名稱
    int sum_calories = 0; //儲存總類別熱量。
    int temp_calories = 0; //儲存暫時輸入熱量。
    int is_keep_input = 0; //決定是否繼續輸入。

    //此迴圈可以搜尋目標食物，得知其熱量後可輸入攝取值。
    do
    {
        //輸入欲輸入食物類別，並導引目標資料庫
        printf("What kind of food do you want to enter？\n");
        printf("Please enter the corresponding number：");
        printf("【1】水果類【2】蔬菜類【3】全榖根莖類【4】豆蛋魚肉類【5】低脂乳品類\n");
        scanf("%d", &kind);

        //輸入食物名稱
        printf("Please enter the name of the kind you ingested and we will list all items in the database that contain this name. (Please always enter lowercase)！\n");
        printf("Your input：");
        scanf("%s", input_name);

        //輸出結果
        printf("您所輸入的名稱，資料庫中包含以下結果：\n");

        //開始搜尋
        int count = 0; //宣告總結果量
        int room = 0;
        while(room < type_num[kind-1])
        {
            if(strstr(food_data[kind-1][room][0],input_name)!=NULL)
            {
                count++;
                printf("【%d】 %s：%s\t(kcal/100g)\n", count, food_data[kind-1][room][0], food_data[kind-1][room][1]);
                
            }
            room++;
        }
        printf("資料庫總共有 %d 個結果。\n",count);

        //開始輸入攝取熱量
        if(count != 0)
        {
            printf("請輸入您所攝取的熱量：");
            scanf("%d", &temp_calories);
            sum_calories = sum_calories + temp_calories;
        }
        else
        {
            printf("該資料庫不具有包含此名稱之項目。\n");
        }
        
        //詢問是否繼續輸入
        printf("如果要繼續，請輸入【1】，反之則請輸入【0】\n");
        scanf("%d", &is_keep_input);

    } while (is_keep_input == 1);

    //輸出總熱量
    printf("您目前總共攝取的熱量為：%d\n", sum_calories);
    return;
}
