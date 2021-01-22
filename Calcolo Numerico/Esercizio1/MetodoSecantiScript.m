f = @(x) ((sin(x)/x) - x);
x_0 = 1;
x_1 = 0.9;
tolleranza = 1e-6;
max_iterate = 50;

[zero_funzione, iterate] = MetodoSecanti(f, x_0, x_1, tolleranza, max_iterate);

fprintf("Zero di funzione: %.16f\n", zero_funzione);
fprintf("Numero di iterate: %d\n", iterate);
fprintf("f(zero di funzione): %.16f\n", f(zero_funzione));

disp("Premere un pulsante per continuare");
pause;

clc
clear