f = @(x) (1) - ((x^2)/2) - (x^3);
f_primo = @(x) - x - (3 * x^2);
x_0 = 1;
tolleranza = 1e-6;
max_iterate = 50;

[zero_funzione, iterate] = metodoDiTraub(f, f_primo, x_0, tolleranza, max_iterate);

fprintf("Zero funzione: %.10f\n", zero_funzione);
fprintf("f(%.10f) = %.10f\n", zero_funzione, f(zero_funzione));
fprintf("Iterate: %d\n", iterate);

disp("Premi per continuare");
pause;

clc;
clear;