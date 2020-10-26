% Esempio 1: f(x) = x^2 - 2 in [1,2]

f = @(x) x.^2 - 2;
df = @(x) 2.*x;
x_0 = 1.5;
tolleranza = 1e-8;
max_iterazioni = 10;
format longe
[zero_funzione, n_iterazioni] = MetodoNewton(f, df, x_0, tolleranza, max_iterazioni);

disp("Funzione: x^2 - 2");
MostraRisultatoZeroFunzione(f, [1,2], zero_funzione, n_iterazioni);
disp("Premi un pulsante per proseguire");
pause;

% Calcolare le prime 10 cifre significative dell'unico zero positivo di f(x) = x^6 - x - 1 
% Fornire una approssimazione iniziale che abbia almeno 2 cifre corrette.

f = @(x) x.^6 - x - 1;
df = @(x) 6.*x.^5 - 1;
x_0 = 1.1;
tolleranza = 1e-10;
max_iterazioni = 10;

[zero_funzione, n_iterazioni] = MetodoNewton(f, df, x_0, tolleranza, max_iterazioni);

fprintf("\nFunzione: x^6 - x - 1\n");
MostraRisultatoZeroFunzione(f, [0,2], zero_funzione, n_iterazioni);
disp("Premi un pulsante per proseguire");
pause;

clear