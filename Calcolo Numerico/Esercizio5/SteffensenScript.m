f = @(x) sin(x) - (x^3);
x_0 = 1;
tolleranza = 1e-12;
max_iterate = 50;

[zero_funzione, iterate, residuo] = metodoDiSteffensen(f, x_0, tolleranza, max_iterate);

fprintf("Zero di funzione: %.12f\n", zero_funzione)
fprintf("Iterate: %d\n", iterate)
fprintf("Residuo: %f\n", residuo)
disp("Premi un tasto per continuare")
pause

clc
clear