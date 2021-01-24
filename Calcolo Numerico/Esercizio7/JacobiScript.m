A = [4, 2, 1; 2, 4, 2; 1, 2, 4];
b = [7; 8; 7];
x_0 = [1.1; 1.1; 1.1];
tolleranza = 10e-5;
max_iterate = 100;

[soluzione, iterate, residuo] = metodiDiJacobi(A, b, x_0, tolleranza, max_iterate);

disp("Soluzione approssimata: ")
disp(soluzione)
fprintf("Iterate: %d\n", iterate)
fprintf("Residuo: %f\n", residuo)

disp("Premi per continuare")
pause

clc
clear