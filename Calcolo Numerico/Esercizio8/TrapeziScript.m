f = @(x) sin(pi * x);
a = 0;
b = 1;

tolleranza = 1e-3;

n = 4;
[i_0] = metodoDeiTrapezi(f, a, b, n);
n = n*2;
[i_1] = metodoDeiTrapezi(f, a, b, n);

errore_assoluto = abs(i_1 - i_0);
while errore_assoluto > tolleranza
    n = n*2;
    i_0 = i_1;
    [i_1] = metodoDeiTrapezi(f, a, b, n);
    errore_assoluto = abs(i_1 - i_0);
end

fprintf("Approssimazione integrale: %f\n", i_1)
fprintf("n: %d\n", n)

disp("Premi per continuare")
pause

clc
clear