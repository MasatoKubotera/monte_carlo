/*
  Copyright (c) 2021 Masato Kubotera
  Released under the MIT license
  https://opensource.org/licenses/mit-license.php
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM 10 //要素数

typedef struct {
  int max_point_num; 
           //最大ポイント数
  unsigned int point_num;     //扇内のポイント数
  double proximate_pi;        //近似 円周率
  double relative_error;      //相対誤差
} Data;

//10の累乗
static unsigned int pow10[NUM] = {
  1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
};

int main(void){
  double x, y; //座標
  srand(time(NULL)); //ランダム値生成

  Data data[NUM];

  for(int i = 0; i < NUM; i++){
    //初期化
    data[i].max_point_num = pow10[i];
    data[i].point_num = 0;
  }

  for(int i = 1,time = 0; time < NUM; i++){
    //ランダムな座標を取得(0.0~1.0)
    x = (double)rand()/RAND_MAX;
    y = (double)rand()/RAND_MAX;
    
    //扇内判定
    if(x*x + y*y < 1.0)
      for(int j = time; j < NUM; j++)
        data[j].point_num = data[j].point_num + 1;

    if(i == data[time].max_point_num)
      time++;
  }

  printf("MAX-------|NUM-------|PI----------|ERROR-------\n");
  for(int i = 0; i < NUM; i++){
    //近似円周率を求める
    data[i].proximate_pi = (double) data[i].point_num / data[i].max_point_num * 4;

    //相対誤差
    data[i].relative_error = fabs((data[i].proximate_pi - M_PI) / M_PI);
    
    printf("%10d|%10d|%.10lf|%.10lf\n", data[i].max_point_num, data[i].point_num, data[i].proximate_pi, data[i].relative_error);
  }
  
  return 0;
}
