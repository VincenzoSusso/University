% MostraRisultatoZeroFunzione

%{
    Input:
        - f -> funzione
        - intervallo_funzione
        - zero_funzione
        - n_iterazioni

    Output:
        - Grafico della funzione nell'intervallo specificato se lo zero di funzione viene trovato
        - Messaggio di errore altrimenti
%}

function MostraRisultatoZeroFunzione(f, intervallo_funzione, zero_funzione, n_iterazioni)
    if ~isnan(zero_funzione) && n_iterazioni ~= -1
        display("Lo zero di funzione è " + zero_funzione + " infatti f(" + zero_funzione + ") = " + f(zero_funzione));
        display("Sono state necessarie " + n_iterazioni + " iterazioni");

        %Creazione grafico
        fplot(f, intervallo_funzione);
        xlabel("x");
        ylabel("f(x)");
        title("Grafico " + func2str(f));
        hold on
        plot(zero_funzione,f(zero_funzione), "r.");
        hold off
    else
        disp("Si è verificato un errore!");
    end
end

