function [zero_funzione, iterate] = metodoDiTraub(f, f_primo, x_0, tolleranza, max_iterate)
    x_k = x_0;
    iterate = 0;
    
    while true
        den = f_primo(x_k);
        y_k = x_k - (f(x_k)/den);
        x_k_1 = y_k - (f(y_k)/den);
        errore_relativo = abs(x_k - x_k_1) / abs(x_k);
        x_k = x_k_1;
        
        if iterate > max_iterate || errore_relativo <= tolleranza
            break;
        end
        iterate = iterate + 1;
    end
    
    if errore_relativo <= tolleranza && iterate <= max_iterate
        zero_funzione = x_k_1;
    else
        zero_funzione = NaN;
        iterate = NaN;
    end
end

