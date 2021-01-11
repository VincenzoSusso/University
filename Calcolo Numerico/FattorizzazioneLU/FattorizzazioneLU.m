% Fattorizzazione LU: https://it.wikipedia.org/wiki/Decomposizione_LU

%{
    Input:
        - matrice

    Output:
        - lower -> matrice triangolare inferiore
        - upper -> matrice triangolare superiore
%}

function [lower, upper] = FattorizzazioneLU(matrice)
    errore = false;
    
    n = size(matrice, 1);
    
    lower = eye(n);
    
    k = 1;
    
    if n == size(matrice, 2)
        while(k <= n-1 && ~errore)
            if((det(matrice(1:k, 1:k))) ~= 0 && (matrice(k,k) ~= 0))
                
                i = k + 1;
                while(i <= n && ~errore)
                    lower(i,k) = matrice(i,k) / matrice(k,k);
                    
                    j = k + 1;
                    while(j <= n && ~errore)
                        matrice(i,j) = matrice(i,j) - (lower(i,k) * matrice(k,j));
                        j = j + 1;
                    end
                    
                    i = i + 1;
                end
            else
                errore = true;
            end
            
            k = k + 1;
        end
    else
        errore = true;
    end
    
    if(errore == true)
        lower = [];
        upper = [];
    else
        upper = triu(matrice);
    end
    
end