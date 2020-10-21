% Metodo Delle Successive Bisezioni: https://it.wikipedia.org/wiki/Metodo_della_bisezione

%{
    Input:
        - f -> funzione
        - a,b -> estremi dell'intervallo
        - tolleranza
        - max_iterazioni

    Output:
        - zero_funzione
        - n_iterazioni
%}

function [zero_funzione, n_iterazioni] = MetodoSuccessiveBisezioni(f, a, b, tolleranza, max_iterazioni)
    n_iterazioni = 0;
    zero_funzione = (a + b) ./ 2;
    
    while n_iterazioni < max_iterazioni && ((b - a) ./ 2) > tolleranza
        if (f(a) .* f(zero_funzione)) < 0
            b = zero_funzione;
        elseif f(b) .* f(zero_funzione) < 0
            a = zero_funzione;
        else
            % Forzo l'uscita dal ciclio
            n_iterazioni = max_iterazioni;
        end
        zero_funzione = (a + b) ./ 2;
        n_iterazioni = n_iterazioni + 1;
    end
    
    if n_iterazioni == max_iterazioni || ((b - a) ./ 2) > tolleranza
        % Nessun zero di funzione trovato
        zero_funzione = NaN;
        n_iterazioni = -1;
    end
    
end