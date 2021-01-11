matrice = [3 -2 -3 1; -3 3 4 0; 6 -8 -13 -1; -3 -2 -1 -2];

[l,u] = FattorizzazioneLU(matrice);

disp("Matrice: ")
disp(matrice)

disp("L: ")
disp(l)

disp("U: ")
disp(u)

disp("Matrice = LU")
disp(l * u)

disp("Premi un pulsante per proseguire");
pause;

clear
clc