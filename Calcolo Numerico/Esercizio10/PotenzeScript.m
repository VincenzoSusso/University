A = [3, 2, 1; 2, 2, 1; 1, 1, 1];
x_0 = [1; 1; 1];
tolleranza = 1e-6;
max_iterate = 50;

[autovalore, iterate] = metodoDellePotenze(A, x_0, tolleranza, max_iterate);

fprintf("Autovalore: %f\n", autovalore);
fprintf("Iterate: %d\n", iterate);

disp("Premi un tasto per continuare")
pause

clc
clear