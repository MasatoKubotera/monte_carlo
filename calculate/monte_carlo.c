/*
  Copyright (c) 2021 Masato Kubotera
  Released under the MIT license
  https://opensource.org/licenses/mit-license.php
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define INDEX_N 10 //要素数
#define REP 10     //繰り返し

typedef struct {
  unsigned int point; //ポイント
  double pi;          //近似円周率
  double error;       //相対誤差
} Data;

//10の累乗
static unsigned int pow10[INDEX_N] = {
  1, 10, 100, 1000, 10000,
  100000, 1000000, 10000000, 100000000, 1000000000
};

int main(void){
  double x, y; //座標

  Data data[REP][INDEX_N];
  FILE *output_data = fopen("data.txt", "w");

  for(int rep_time = 0; rep_time < REP; rep_time++){
    srand(time(NULL)); //ランダム値生成

    for(int index = 0; index < INDEX_N; index++)
      data[rep_time][index].point = 0;

    for(int index = 1,stage = 0; stage < INDEX_N; index++){
      //ランダムな座標を取得(0.0~1.0)
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      
      //扇内判定
      if(x*x + y*y < 1.0)
        for(int j = stage; j < INDEX_N; j++)
          data[rep_time][j].point++;

      if(index == pow10[stage])
        stage++;
    }

    printf("\n%d-time\nMAX-------|PI----------|ERROR-------\n", rep_time + 1);
    fprintf(output_data,"\n%d-time\n", rep_time + 1);
    for(int index = 0; index < INDEX_N; index++){
      //近似円周率を求める
      data[rep_time][index].pi = (double) data[rep_time][index].point / pow10[index] * 4;

      //相対誤差
      data[rep_time][index].error = fabs((data[rep_time][index].pi - M_PI) / M_PI);
      
      printf("%10d|%.10lf|%.10lf\n", pow10[index], data[rep_time][index].pi, data[rep_time][index].error);
      fprintf(output_data," %d %.10lf %.10lf\n", pow10[index], data[rep_time][index].pi, data[rep_time][index].error);
    }
  }

  fclose(output_data);
  FILE *average = fopen("average.txt", "w");

  //平均処理
  double pi[INDEX_N];     //近似円周率
  double error[INDEX_N];  //相対誤差

  for(int index = 0; index < INDEX_N; index++)
    for(int rep_time = 0; rep_time < REP; rep_time++)
      pi[index] += data[rep_time][index].pi;

  printf("\navg.of-%d-times\nMAX-------|PI----------|ERROR-------\n",REP);
  fprintf(average,"avg.of-%d-times\n",REP);

  for(int index = 0; index < INDEX_N; index++){
    pi[index] /= REP;
    error[index] = fabs((pi[index] - M_PI) / M_PI);
    
    printf("%10d|%.10lf|%.10lf\n", pow10[index], pi[index], error[index]);
    fprintf(average," %d %.10lf %.10lf\n", pow10[index], pi[index], error[index]);
  }

  fclose(average);
  return 0;
}