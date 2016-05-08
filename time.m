close all
clear all
clc
t_elaps = [0.000519643
0.000141033
0.00693264
0.00250589
0.0530303
0.0245004
0.254798
0.115642
0.821225
0.388637
2.27905
1.05162
10.1828
4.65605
20.9331
9.4429
46.6755
21.8216];

iters = [59
31
311
155
743
366
1347
663
2123
1045
3065
1510
5455
2686
6899
3395
8507
4185];

err = [8.47651e-10
4.57988e-10
2.38652e-09
2.85816e-09
3.92722e-09
5.41854e-09
5.60906e-09
7.84113e-09
7.2963e-09
1.01118e-08
9.07882e-09
1.24241e-08
1.24193e-08
1.70383e-08
1.40874e-08
1.93917e-08
1.5727e-08
2.16591e-08];

N = [5 10 15 20 25 30 40 45 50];
figure(1)
plot(N, t_elaps(1:2:end), '--k', 'LineWidth', 2)
hold on
plot(N, t_elaps(2:2:end), ':k', 'LineWidth', 2)
title('Time')
xlabel('N')
ylabel('time (s)')
legend('Steepest Descent', 'Gauss-Siedel','Location', 'northwest')

figure(2)
plot(N, iters(1:2:end), '--k', 'LineWidth', 2)
hold on
plot(N, iters(2:2:end), ':k', 'LineWidth', 2)
title('Iterations')
xlabel('N')
ylabel('Iterations')
legend('Steepest Descent', 'Gauss-Siedel','Location', 'northwest')

figure(3)
plot(N, err(1:2:end), '--k', 'LineWidth', 2)
hold on
plot(N, err(2:2:end), ':k', 'LineWidth', 2)
title('Error')
xlabel('N')
ylabel('error')
legend('Steepest Descent', 'Gauss-Siedel','Location', 'northwest')

input('Pause...')