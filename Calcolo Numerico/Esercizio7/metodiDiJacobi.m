function [soluzione, iterate, residuo] = metodiDiJacobi(A, b, x_0, tolleranza, max_iterate)
    
    R = tril(A, -1) + triu(A, 1);
    D = A - R;
    
    x_k = x_0;
    
    iterate = 0;
    while true
        x_k_1 = b - (R * x_k);
        x_k_1 = D \ x_k_1;
        errore_relativo = norm(x_k - x_k_1) / norm(x_k);
        
        x_k = x_k_1;
        
        if iterate > max_iterate || errore_relativo <= tolleranza
            break
        end
        iterate = iterate + 1;
    end
    
    if errore_relativo <= tolleranza && iterate <= max_iterate
        soluzione = x_k_1;
        residuo = norm( (A*soluzione) - b );
    else
        soluzione = NaN;
        residuo = NaN;
    end
    
end

