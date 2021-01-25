function [autovalore, iterate] = metodoDellePotenze(A, x_0, tolleranza, max_iterate)

    [n_righe_A, n_colonne_A] = size(A);
    [n_righe_x0, ~] = size(x_0);
    if (n_righe_A == n_colonne_A) && (n_righe_A == n_righe_x0)

        y_k = x_0 / norm(x_0, 2);
        x_k = A * y_k;
        v_k = (y_k') * x_k;
        
        iterate = 0;
        while true
            
            y_k_1 = x_k / norm(x_k, 2);
            x_k_1 = A * y_k_1;
            v_k_1 = (y_k_1') * x_k_1;
            
            errore = abs(v_k_1 - v_k);
            
            x_k = x_k_1;
            v_k = v_k_1;
            
            if iterate > max_iterate || errore < (tolleranza * abs(v_k_1))
                break
            end
            iterate = iterate + 1;
        end
        
        if errore < (tolleranza * abs(v_k_1)) && iterate <= max_iterate
            autovalore = v_k_1;
        else
            autovalore = NaN;
        end
        
    else
        autovalore = NaN;
        iterate = NaN;
    end

end

