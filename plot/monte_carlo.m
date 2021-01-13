%{
    Copyright (c) 2021 Masato Kubotera
    Released under the MIT license
    https://opensource.org/licenses/mit-license.php
%}

clc, clear, close all

format long

cd image
name = strrep(datestr(datetime), ':', '_');
mkdir(name)
cd (name)

coordinate = figure('Name','座標','NumberTitle','off','WindowState','maximized');
ang = 0:0.01:2*pi;
x = cos(ang);
y = sin(ang);
t = tiledlayout(1,1,'Padding','none');
t.Units = 'inches';
t.OuterPosition = [0 0 8 8];
nexttile;
plot(x,y,'k');
xlim([0 1.0])
ylim([0 1.0])
xlabel('x','FontSize',12,'FontWeight','bold')
ylabel('y','FontSize',12,'FontWeight','bold')

N = [1 10 100 1000 10000 100000 1000000];

time = 0;

point = zeros(1,numel(N));

for i = 1:numel(N)
    for j = time + 1 : N(i)
        
        x = rand;
        y = rand;
        
        hold on
        
        if x^2+y^2 < 1.0
            plot(x,y,'.r')
            point(i) = point(i)+1;
        else
            plot(x,y,'.b')
        end
    end
    
    % 近似値
    proximate_pi = double(point(i) / N(i) * 4.0);
    
    % 相対誤差
    relative_error = abs((proximate_pi - pi)  / pi);
    
    %タイトル作成
    title(append('N=',num2str(N(i)),', RedPints=',num2str(point(i)),', \pi\approx',num2str(proximate_pi,'%.10f'),', 相対誤差',num2str(relative_error),'%'),'FontSize',12)
    
    % 座標画像を保存
    exportgraphics(coordinate,append('coordinate_N=',num2str(N(i)),'.jpg'),'Resolution',500)
    
    time = N(i);
    if i < numel(N)
        point(i+1) = point(i);
    end
end

cd ..\
cd ..\