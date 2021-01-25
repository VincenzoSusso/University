function [valore_integrale] = metodoDeiTrapezi(f, a, b, n)

    if n >= 1
        h = (b-a) / n;
        
        x_0 = a;
        valore_integrale = f(x_0);
        for j = 1:n-1
            x_j = a + (j * h);
            valore_integrale = valore_integrale + (2 * f(x_j));
        end
        
        x_n = a + (j * n);
        valore_integrale = valore_integrale + f(x_n);
        valore_integrale = h/2 * valore_integrale;
    else
        valore_integrale = NaN;
    end

end

