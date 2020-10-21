% Esempio 1: f(x) = x^2 - 2 in [1,2]

f = @(x) x.^2 - 2;
a = 1;
b = 2;
tolleranza = 1e-6;
max_iterazioni = 60;
format longe
[zero_funzione, n_iterazioni] = MetodoSuccessiveBisezioni(f, a, b, tolleranza, max_iterazioni);

disp("Funzione: x^2 - 2");
MostraRisultatoZeroFunzione(f, [1,2], zero_funzione, n_iterazioni);
disp("Premi un pulsante per proseguire");
pause;


% Esempio 2: f(x) = x in [-5,6]

f = @(x) x;
a = -5;
b = 6;
tolleranza = 1e-6;
max_iterazioni = 60;
format longe
[zero_funzione, n_iterazioni] = MetodoSuccessiveBisezioni(f, a, b, tolleranza, max_iterazioni);

fprintf("\nFunzione: x\n");
MostraRisultatoZeroFunzione(f, [-5,6], zero_funzione, n_iterazioni);
disp("Premi un pulsante per proseguire");
pause;

% Esempio 3: f(x) = x^2 in in [5,15]

f = @(x) x^2;
a = 5;
b = 15;
tolleranza = 1e-6;
max_iterazioni = 60;
format longe
[zero_funzione, n_iterazioni] = MetodoSuccessiveBisezioni(f, a, b, tolleranza, max_iterazioni);

fprintf("\nFunzione: x^2\n");
MostraRisultatoZeroFunzione(f, [5,15], zero_funzione, n_iterazioni);

clear