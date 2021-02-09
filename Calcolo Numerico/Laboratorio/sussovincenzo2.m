function [zero_funzione, iterate, residuo] = sussovincenzo2(f, x_0, tolleranza, max_iterate)

    x_k = x_0;
    errore_relativo = tolleranza + 1;
    
    iterate = 0;
    while iterate <= max_iterate && errore_relativo > tolleranza
        f_x_k = f(x_k);
        
        x_k_1 = x_k - ( (f_x_k)^2 / ( f(x_k + f_x_k) - f_x_k) );
        
        errore_relativo = abs(x_k_1 - x_k) / abs(x_k_1);
        
        x_k = x_k_1;
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