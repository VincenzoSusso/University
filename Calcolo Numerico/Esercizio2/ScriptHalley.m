f = @(x) sin(x) - x^3;
f_primo = @(x) cos(x) - 3*x^2;
f_secondo = @(x) -sin(x) - 6*x;

x_0 = 1;
tolleranza = 1e-12;
max_iterate = 50;

[zero_funzione, iterate, residuo] = MetodoDiHalley(f, f_primo, f_secondo, x_0, tolleranza, max_iterate);

fprintf("Zero di funzione: %.12f\n", zero_funzione);
fprintf("Iterate: %d\n", iterate);
fprintf("Residuo: %.12f\n", residuo);

disp("Premi un pulsante per continuare");
pause;

clc;
clear;