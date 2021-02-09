disp("Quesito 1: ")

f = @(x) (x - ((x^3)/6) - cos(x));
x_0 = 1;
tolleranza = 10^-8;
max_iterate = 20;

[zero_funzione, iterate, residuo] = sussovincenzo2(f, x_0, tolleranza, max_iterate);

fprintf("\nApprossimazione zero funzione: %.8f\n", zero_funzione)
fprintf("Iterate: %d\n", iterate)
fprintf("Residuo: %e\n\n", residuo)

disp("Premere un tasto per continuare")
pause
clc
clear

disp("Quesito 2: ")

A = [13, 2, 0; 2, 1, 3; 0, 3, 22];
x_0 = [1; 1; 1;];
tolleranza = 10^-6;
max_iterate = 20;

[autovalore, iterate] = sussovincenzo3(A, x_0, tolleranza, max_iterate);

fprintf("\nApprossimazione autovalore di minimo modulo: %.6f\n", autovalore)
fprintf("Iterate: %d\n\n", iterate)

disp("Premere un tasto per continuare")
pause
clc
clear