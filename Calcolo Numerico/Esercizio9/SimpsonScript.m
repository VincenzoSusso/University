f = @(x) tan(x);
a = 0;
b = pi/4;

tolleranza = 1e-4;

n = 4;
[i_0] = metodoDiSimpson(f, a, b, n);
n = n*2;
[i_1] = metodoDiSimpson(f, a, b, n);

errore_assoluto = abs(i_1 - i_0);

while errore_assoluto > tolleranza
    n = n*2;
    errore_assoluto = abs(i_1 - i_0);
    i_0 = i_1;
    [i_1] = metodoDiSimpson(f, a, b, n);
end

fprintf("Approssimazione Integrale: %.4f\n", i_1);
fprintf("n: %d\n", n);

disp("Premi un pulsante per continuare")
pause

%clc
%clear