function [zero_funzione, iterate] = MetodoSecanti(f, x_0, x_1, tolleranza, max_iterate)

    x_k_2 = x_0;
    x_k_1 = x_1;
    
    iterate = 1;
    
    %while iterate <= max_iterate && errore_relativo > tolleranza
    while true
        x_k = x_k_1 - ((f(x_k_1) * (x_k_1 - x_k_2))/(f(x_k_1) - f(x_k_2)));
        errore_relativo = abs(x_k - x_k_1) / abs(x_k);
        x_k_2 = x_k_1;
        x_k_1 = x_k;
        
        if errore_relativo < tolleranza || iterate > max_iterate
            break;
        end
        
        iterate = iterate + 1;
    end
    
    if errore_relativo < tolleranza && iterate <= max_iterate
        zero_funzione = x_k;
    else
        zero_funzione = NaN;
    end
end

