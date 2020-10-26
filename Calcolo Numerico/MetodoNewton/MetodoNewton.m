% Metodo Di Newton: https://it.wikipedia.org/wiki/Metodo_delle_tangenti

%{
    Input:
        - f -> funzione
        - df -> deriata della funzione
        - x_0 -> stima iniziale
        - tolleranza
        - max_iterazioni

    Output:
        - zero_funzione
        - n_iterazioni
%}

function [zero_funzione, n_iterazioni] = MetodoNewton(f, df, x_0, tolleranza, max_iterazioni)
    errore = false;
    n_iterazioni = 1;
    while n_iterazioni < max_iterazioni && ~errore
        
        if abs(dfx)<1e-14 % Derivata troppo piccola
            errore = true;
            break;
        end
        
        delta_x = - (f(x_0)/df(x_0));
        zero_funzione = x_0 + delta_x;
        
        if abs(delta_x) <= tolleranza % Errore assoluto, è possibile cambiarlo con quello relativo
            % Trovato zero di funzione
            return
        end
        
        x_0 = zero_funzione;
        n_iterazioni = n_iterazioni + 1;
    end
    
    if errore == true || n_iterazioni == max_iterazioni
        % Nessun zero di funzione trovato
        zero_funzione = NaN;
        n_iterazioni = -1;
    end
    
end