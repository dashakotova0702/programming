clear all;
clc;
x = 0:2:300;
y = [187, 187, 187, 186, 186, 185, 184 183, 182, 180, 178, 176, 174, 172, 169, 166, 163, 160, 157, 152, 148, 144, 140, 135, 130, 126, 122, 118, 114, 110, 106, 102, 97, 92, 87, 83, 77, 72, 67, 62, 57, 53, 49, 45, 41, 37, 33, 30, 26, 24, 21, 19, 17, 14, 13, 11, 9, 8, 7, 6, 5, 4, 4, 3, 3, 3, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8, 9, 10, 11, 13, 15, 17, 19, 22, 25, 28, 31, 34, 37, 40, 42, 44, 45, 47. 48, 49, 49, 50, 50, 50, 50, 51, 51, 52, 53, 54, 55, 58, 60, 62, 65, 68, 70, 76, 81, 86, 89, 92, 95, 97, 100, 101, 102, 103, 104, 105, 107, 108, 109, 111, 113, 116, 120, 125, 130, 135, 139, 142, 146, 150, 152, 155, 158, 160, 163, 166, 169, 172, 174, 175];
y_23dots = [187, 187, 186, 182, 169, 148, 102, 67, 26, 11, 3, 8, 37, 50, 76, 100, 104, 113, 139, 150, 158, 172, 175];
x_23dots = [0, 2, 6, 16, 28, 40, 62, 76, 96, 110, 130, 150, 178, 200, 228, 242, 250, 262, 274, 280, 286, 296, 300];
%-------------Lagrange------------
n = length(x_23dots);
y_lagrange = 0;
for k = 1:n
    t = 1;
    for j = [1:k-1, k+1:n]
        t = t .* (x-x_23dots(j))./(x_23dots(k)-x_23dots(j));
    end
    y_lagrange = y_lagrange + y_23dots(k) .* t;
end
hold on;
plot(x, y_lagrange, 'blue');
plot (x, y, 'red');
title('Lagrange');
xlabel('x[mm]')
ylabel('y[mm]')
figure;
%--------------Newton-------------
y_newton = 1;
for i = 1:length(y_23dots)
    delta_y (1, i) = y_23dots(i);
end
for i = 2:length(y_23dots)
    for j = 1:length(y_23dots)
        if (j < i)
           delta_y(i, j) = 0; 
        else 
           delta_y(i, j) = (delta_y(i-1, j) - delta_y(i-1, j-1)) / (x_23dots(j) - x_23dots(j-i+1));
        end
    end
end
for i=1:length(y_23dots)
    t = 1;
    for j=1:i-1
        t = t .* (x - x_23dots(j));
    end
    y_newton = y_newton + delta_y(i, i) * t;
end
hold on;
plot (x, y_newton, 'blue');
plot (x, y, 'red');
title('Newton');
xlabel('x[mm]')
ylabel('y[mm]')
figure;
%------------Spline------------
y_10dots = [187, 169, 26, 34, 40, 53, 105, 113, 150, 176];
x_10dots = [0, 28, 96, 176, 180, 210, 250, 262, 280, 300];
Matrix_coeff_left = zeros (26, 26);
Matrix_coeff_right = zeros (1, 26);
for i = 1:9
   Matrix_coeff_right(1, i) = y_10dots(i+1) - y_10dots(i);
end
j = 1;
for i = 1:9
   if i == 1
      Matrix_coeff_left (i, j) = x_10dots(j+1) - x_10dots(j);
      Matrix_coeff_left (i, j+17) = (x_10dots(j+1) - x_10dots(j))^3;
   else
      Matrix_coeff_left (i, j) = x_10dots(j+1) - x_10dots(j);
      Matrix_coeff_left (i, j+8) = (x_10dots(j+1) - x_10dots(j))^2;
      Matrix_coeff_left (i, j+17) = (x_10dots(j+1) - x_10dots(j))^3;
   end
   j = j + 1;
end
j = 1;
for i = 10:17
   if i == 10
      Matrix_coeff_left (i, j) = 1;
      Matrix_coeff_left (i, j+1) = -1;
      Matrix_coeff_left (i, j+17) = 3*((x_10dots(j+1) - x_10dots(j))^2);
   else
      Matrix_coeff_left (i, j) = 1;
      Matrix_coeff_left (i, j+1) = -1;
      Matrix_coeff_left (i, j+8) = 2*(x_10dots(j+1) - x_10dots(j));
      Matrix_coeff_left (i, j+17) = 3*((x_10dots(j+1) - x_10dots(j))^2);
   end
   j = j + 1;
end
j = 1;
for i = 18:25
   if i == 18
      Matrix_coeff_left (i, j+9) = -1;
      Matrix_coeff_left (i, j+17) = 3*(x_10dots(j+1) - x_10dots(j));
   else
      Matrix_coeff_left (i, j+8) = 1;
      Matrix_coeff_left (i, j+9) = -1;
      Matrix_coeff_left (i, j+17) = 3*(x_10dots(j+1) - x_10dots(j));
   end
   j = j + 1;
end
Matrix_coeff_left (26, 17) = 1;
Matrix_coeff_left (26, 26) = 3*(x_10dots(10) - x_10dots(9));
Matrix_coeff_right = Matrix_coeff_right';
coeff_spl = Matrix_coeff_left\Matrix_coeff_right;
x_10dots_1 = 0:0.1:28;
x_10dots_2 = 28:0.1:96;
x_10dots_3 = 96:0.1:176;
x_10dots_4 = 176:0.1:180;
x_10dots_5 = 180:0.1:210;
x_10dots_6 = 210:0.1:250;
x_10dots_7 = 250:0.1:262;
x_10dots_8 = 262:0.1:280;
x_10dots_9 = 280:0.1:300;
S_1 = y_10dots(1) + coeff_spl(1)*(x_10dots_1-x_10dots(1)) + coeff_spl(18)*((x_10dots_1-x_10dots(1)).^3);
S_2 = y_10dots(2) + coeff_spl(2)*(x_10dots_2-x_10dots(2)) + coeff_spl(10)*((x_10dots_2-x_10dots(2)).^2) + coeff_spl(19)*((x_10dots_2-x_10dots(2)).^3);
S_3 = y_10dots(3) + coeff_spl(3)*(x_10dots_3-x_10dots(3)) + coeff_spl(11)*((x_10dots_3-x_10dots(3)).^2) + coeff_spl(20)*((x_10dots_3-x_10dots(3)).^3);
S_4 = y_10dots(4) + coeff_spl(4)*(x_10dots_4-x_10dots(4)) + coeff_spl(12)*((x_10dots_4-x_10dots(4)).^2) + coeff_spl(21)*((x_10dots_4-x_10dots(4)).^3);
S_5 = y_10dots(5) + coeff_spl(5)*(x_10dots_5-x_10dots(5)) + coeff_spl(13)*((x_10dots_5-x_10dots(5)).^2) + coeff_spl(22)*((x_10dots_5-x_10dots(5)).^3);
S_6 = y_10dots(6) + coeff_spl(6)*(x_10dots_6-x_10dots(6)) + coeff_spl(14)*((x_10dots_6-x_10dots(6)).^2) + coeff_spl(23)*((x_10dots_6-x_10dots(6)).^3);
S_7 = y_10dots(7) + coeff_spl(7)*(x_10dots_7-x_10dots(7)) + coeff_spl(15)*((x_10dots_7-x_10dots(7)).^2) + coeff_spl(24)*((x_10dots_7-x_10dots(7)).^3);
S_8 = y_10dots(8) + coeff_spl(8)*(x_10dots_8-x_10dots(8)) + coeff_spl(16)*((x_10dots_8-x_10dots(8)).^2) + coeff_spl(25)*((x_10dots_8-x_10dots(8)).^3);
S_9 = y_10dots(9) + coeff_spl(9)*(x_10dots_9-x_10dots(9)) + coeff_spl(17)*((x_10dots_9-x_10dots(9)).^2) + coeff_spl(26)*((x_10dots_9-x_10dots(9)).^3);
hold on;
plot(x_10dots_1, S_1, 'blue');
plot(x_10dots_2, S_2, 'blue');
plot(x_10dots_3, S_3, 'blue');
plot(x_10dots_4, S_4, 'blue');
plot(x_10dots_5, S_5, 'blue');
plot(x_10dots_6, S_6, 'blue');
plot(x_10dots_7, S_7, 'blue');
plot(x_10dots_8, S_8, 'blue');
plot(x_10dots_9, S_9, 'blue');
plot (x, y, 'red');
title('Spline');
xlabel('x[mm]')
ylabel('y[mm]')
figure;
%------------Approximation----------------
N = length(x_10dots);
m = 2;
POWERX = zeros(2*m);
for k = 1:2*m
    for i = 1:N
       POWERX(k) =  POWERX(k) + x_10dots(i).^k;
    end
end
SUMX = zeros(m+1, m+1);
for l = 1:m+1
    for j = 1:m+1
        if (j == 1 && l == 1)
            SUMX(l, j) = N;
        else
            SUMX(l, j) = POWERX(l + j - 2);
        end
    end
end
PRAW = zeros(m+1);
for l = 1:m+1 
    for i = 1:N
        PRAW(l) = PRAW(l) + y_10dots(i).*(x_10dots(i).^(l-1));
    end
end
coeff_mnk = SUMX.'\PRAW;
coeff_mnk = coeff_mnk.';
S2 = 1;
for i = 1:N
    S2_ = y_10dots(i);
    for j = 1:m+1
        S2_ = S2_ - coeff_mnk(j).*(x_10dots.^(j-1)); 
    end
    S2 = S2 + (S2_.^2);
end
S2 = S2./(N-m-1);
sigma = sqrt(S2);
x_appr = 0:0.5:300;
y_appr = coeff_mnk(1, 3)*x_appr.^2 + coeff_mnk(1, 2)*x_appr + coeff_mnk(1, 1);
hold on;
plot (x_appr, y_appr, 'blue');
plot (x, y, 'red');
title('Approximation');
xlabel('x[mm]')
ylabel('y[mm]')
figure;
%-----------Differentiation---------------
subplot(1, 2, 1);
hold on;
x_function = 0:1:300;
n = length(x_23dots);
y_function = 0;
for k = 1:n
    t = 1;
    for j = [1:k-1, k+1:n]
        t = t .* (x_function-x_23dots(j))./(x_23dots(k)-x_23dots(j));
    end
    y_function = y_function + y_23dots(k) .* t;
end

d_y_1 = zeros (301);
for i = 1:300
    d_y_1(i) = (y_function(i)-y_function(i+1));
end
plot(x_function, d_y_1, 'green');

d_y_2 = zeros (301);
for i = 2:301
    d_y_2(i) = (y_function(i-1)-y_function(i));
end
plot(x_function, d_y_2, 'magenta');

Margin_of_error_back_and_forth = 1/2;

d_y_3 = zeros (301);
for i = 2:300
    d_y_3(i) = (y_function(i-1)-y_function(i+1))/2;
end
plot(x_function, d_y_3, 'blue');

Margin_of_error_center_first_diff = 1/6;

d_y_4 = zeros (301);
for i = 2:300
    d_y_4(i) = (y_function(i-1)-2*y_function(i)+y_function(i+1))/2;
end
plot(x_function, d_y_4, 'black');

Margin_of_error_center_second_diff = 1/12;
disp('Margin of error of differentiation:');
disp('Back and forth : '); 
disp(Margin_of_error_back_and_forth);
disp('Center (first): ');
disp(Margin_of_error_center_first_diff);
disp('Center (second): ');
disp(Margin_of_error_center_second_diff);

title('Differentiation');
xlabel('x[mm]')
ylabel('y[mm]')
subplot(1, 2, 2);
plot (x, (y), 'red');
xlabel('x[mm]')
ylabel('y[mm]')
figure;
%--------------Integration---------------
subplot(1,2,1);
hold on;
i_y_1 = zeros (301);
for i = 1:301
    if i == 1
        i_y_1(i) = y_function(i);
    else
        i_y_1(i) = y_function(i) + i_y_1(i-1); 
    end
end
plot(x_function, i_y_1, 'green');

i_y_2 = zeros (301);
for i = 1:300
    if i == 1
        i_y_2(i) = y_function(i+1);
    else
        i_y_2(i) = y_function(i+1) + i_y_2(i-1); 
    end
end
plot(x_function, i_y_2, 'blue');

Margin_of_error_left_and_right_integration = 1/2;

i_y_3 = zeros (151);
for i = 1:150
    if i == 1
        i_y_3(i) = y_function(((2*i-1)+(2*i+1))/2) * 2;
    else
        i_y_3(i) = y_function(((2*i-1)+(2*i+1))/2) * 2 + i_y_3(i-1); 
    end
end
plot(x, i_y_3, 'magenta');

Margin_of_error_center_integration = 2/24;

i_y_4 = zeros (301);
for i = 1:300
    if i == 1
        i_y_4(i) = ((y_function(i)+y_function(i+1))/2);
    else
        i_y_4(i) = ((y_function(i)+y_function(i+1))/2) + i_y_4(i-1); 
    end
end
plot(x_function, i_y_4, 'yellow');

Margin_of_error_trapeziod_integration = 1/4320;

i_y_5 = zeros (151);
for i = 1:150
    if i == 1
        i_y_5(i) = 1/3 * (y_function(2*i-1)+4*y_function(((2*i-1)+(2*i+1))/2)+y_function(2*i+1));
    else
        i_y_5(i) = 1/3 * (y_function(2*i-1)+4*y_function(((2*i-1)+(2*i+1))/2)+y_function(2*i+1)) + i_y_5(i-1); 
    end
end
plot(x, i_y_5, 'black');

Margin_of_error_simpson_integration = 2/2880;

disp('Margin of error of integration:');
disp('Left and right : '); 
disp(Margin_of_error_left_and_right_integration);
disp('Center: ');
disp(Margin_of_error_center_integration);
disp('Trapeziod: ');
disp(Margin_of_error_trapeziod_integration);
disp('Simpson: ');
disp(Margin_of_error_simpson_integration);

title('Integration');
xlabel('x[mm]')
ylabel('y[mm]')
subplot(1, 2, 2);
plot (x, y, 'red');
xlabel('x[mm]')
ylabel('y[mm]')