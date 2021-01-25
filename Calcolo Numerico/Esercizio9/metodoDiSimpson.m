function [valore_integrale] = metodoDiSimpson(f, a, b, n)

    if mod(n,2) == 0
        h = (b-a)/n;
        x_0 = a;
        valore_integrale = f(x_0);
        
        for j = 1:(n-1)
            x_j = a + (j * h);
            if mod(j,2) == 0
                valore_integrale = valore_integrale + (2 * f(x_j));
            else
                valore_integrale = valore_integrale + (4 * f(x_j));
            end
        end
        
        x_n = a + (h*n);
        valore_integrale = h/3 * (valore_integrale + f(x_n));
    else
        valore_integrale = NaN;
    end

end

