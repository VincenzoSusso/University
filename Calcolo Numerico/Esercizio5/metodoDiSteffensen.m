function [zero_funzione, iterate, residuo] = metodoDiSteffensen(f, x_0, tolleranza, max_iterate)
    x_k = x_0;
    
    iterate = 0;
    while true
        x_k_1 = x_k - ( ( (f(x_k))^2 ) / ( f(x_k + f(x_k)) - f(x_k) ) );
        errore_relativo = abs(x_k - x_k_1) / abs(x_k);
        x_k = x_k_1;
        
        if iterate > max_iterate || errore_relativo <= tolleranza
            break
        end
        
        iterate = iterate + 1;
    end
    
    if errore_relativo <= tolleranza && iterate <= max_iterate
        zero_funzione = x_k_1;
        residuo = f(x_k_1);
    else
        zero_funzione = NaN;
        residuo = NaN;
    end
    
end

