# monte_carlo

モンテカルロ法を用いて円周率πの近似を行う．

---
## Table of contents
- [Environment](https://github.com/MasatoKubotera/monte_carlo/tree/master/#Environment)
- [Plot](https://github.com/MasatoKubotera/monte_carlo/tree/master/#Plot)
- [Calculate](https://github.com/MasatoKubotera/monte_carlo/tree/master/#Calculate)
- [LICENSE](https://github.com/MasatoKubotera/monte_carlo/tree/master/#LICENSE)

---
## Environment
  - ### plot
    - MATLAB R2020b

  - ### calculate
    - Visual Studio Code

---
## Plot
- ### Over view
  MATLABを用いて試行回数1回，10回，100回・・・100万回まで7種類の試行回数で検証を行う．近似値と相対誤差を計算し，モンテカルロ法のプロットの様子とともにディスプレイ表示を行う．名前が実行日時のフォルダを`plot/image/`内に自動作成し，ディスプレイ表示を画像ファイルとして保存する．

- ### Code
  - [monte_carlo.m](plot/monte_carlo.m)

    `plot/monte_carlo.m`

- ### Results
  
  [image](plot/image/14-Jan-2021%2021_34_45)

  `plot/image/14-Jan-2021 21_34_45`

  - 試行回数 : 1回
    <img src="plot/image/14-Jan-2021%2021_34_45/coordinate_N=1.jpg" width="320px">

  - 試行回数 : 10回
    <img src="plot/image/14-Jan-2021%2021_34_45/coordinate_N=10.jpg" width="320px">

  - 試行回数 : 100回
    <img src="plot/image/14-Jan-2021%2021_34_45/coordinate_N=100.jpg" width="320px">

  - 試行回数 : 1000回
    <img src="plot/image/14-Jan-2021%2021_34_45/coordinate_N=1000.jpg" width="320px">

  - 試行回数 : 10000回
    <img src="plot/image/14-Jan-2021%2021_34_45/coordinate_N=10000.jpg" width="320px">

  - 試行回数 : 100000回
    <img src="plot/image/14-Jan-2021%2021_34_45/coordinate_N=100000.jpg" width="320px">

  - 試行回数 : 1000000回
    <img src="plot/image/14-Jan-2021%2021_34_45/coordinate_N=1000000.jpg" width="320px">

---
## Calculate
- ### Over view

  試行回数1回，10回，100回・・・10億回まで10種類の試行回数で10回繰り返して検証を行う．1回ごと・10回平均の2 つのファイルに試行回数・近似値・相対誤差をそれぞれdata.txt・average.txt に書き出す．

- ### Code
  - [monte_carlo.c](https://github.com/MasatoKubotera/monte_carlo/blob/master/calculate/monte_carlo.c)

    `calculate/monte_carlo.c`

- ### Results
  - [average.txt](https://github.com/MasatoKubotera/monte_carlo/blob/master/calculate/average.txt)

    `calculate/average.txt`

  - [data.txt](https://github.com/MasatoKubotera/monte_carlo/blob/master/calculate/data.txt)

    `calculate/data.txt`

---
## LICENSE

- [MIT License](https://github.com/MasatoKubotera/monte_carlo/blob/master/LICENSE)