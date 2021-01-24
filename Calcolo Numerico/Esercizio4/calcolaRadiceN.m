function [approssimazione, iterate] = calcolaRadiceN(S, n, tolleranza, max_iterate)

    if S > 0
        x_k = S;
        
        iterate = 0;
        while true
            x_k_1 = 1/n * ( ((n-1) * x_k) + (S / (x_k^(n-1))) );
            errore_relativo = abs(x_k - x_k_1) / abs(x_k);
            x_k = x_k_1;
            
            if iterate > max_iterate || errore_relativo <= tolleranza
                break
            end
            iterate = iterate + 1;
        end
        
        if errore_relativo <= tolleranza && iterate <= max_iterate
            approssimazione = x_k_1;
        else
            approssimazione = NaN;
            iterate = NaN; 
        end
    else
        approssimazione = NaN;
        iterate = NaN;
    end

end