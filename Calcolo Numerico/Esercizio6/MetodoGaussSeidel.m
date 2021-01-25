function [soluzione, iterate, residuo] = MetodoGaussSeidel(A, b, x_0, max_iterate, tolleranza)

    x_k = x_0;
    L = tril(A);
    U = triu(A, 1);
    
    iterate = 0;
    while true
        x_k_1 = L \ (b - (U * x_k));
        
        errore_relativo = norm(x_k_1 - x_k, inf) / norm(x_k_1, inf);
        
        x_k = x_k_1;
        
        if iterate > max_iterate || errore_relativo <= tolleranza
            break
        end
        iterate = iterate + 1;
    end
    
    if errore_relativo <= tolleranza && iterate <= max_iterate
        soluzione = x_k_1;
        residuo = norm((A * soluzione) - b, inf);
    else
        soluzione = NaN;
        residuo = NaN;
    end
end

