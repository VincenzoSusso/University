A = [2.4, -.8, -.7; .5, 1.5, .7; -.1, .8, 2.1];
b = [.9; 2.7; 2.8];
x_0 = [.9; .9; .9];
max_iterate = 50;
tolleranza = 1e-5;

[soluzione, iterate, residuo] = MetodoGaussSeidel(A, b, x_0, max_iterate, tolleranza);

disp("Approssimazione soluzione: ")
disp(soluzione)
fprintf("Iterate: %d\n", iterate)
fprintf("Residuo: %f\n", residuo)

disp("Premi un pulsante per continuare")
pause

clc
clear