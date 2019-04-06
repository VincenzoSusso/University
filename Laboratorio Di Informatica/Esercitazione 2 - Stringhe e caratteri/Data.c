// -- Librerie --
#include "Data.h"

// -- Procedure & Funzioni --
Data_t generaDataCasuale(void) //Genera una data casuale
{
    Data_t data = {MIN_ANNO, gennaio, MIN_GIORNO};

    // Generazione valori casuali
    data.anno = generaValoreCasuale(MIN_ANNO, MAX_ANNO);
    data.mese = generaValoreCasuale(gennaio, dicembre);
    data.giorno = generaValoreCasuale(MIN_GIORNO, MAX_GIORNO);

    return data;
}

bool isDataCorretta(Data_t data)
{
    bool data_corretta = true;

    if(data.mese == febbraio)
    {
        if((!(data.anno % ANNO_SECOLARE) && !(data.anno % ANNO_BISESTILE_SECOLARE)) || ((data.anno % ANNO_SECOLARE) && !(data.anno % ANNO_BISESTILE)))
        {
            // L'anno è bisestile quindi è composto da 29 giorni
            if(data.giorno > MAX_GIORNO_FEBBRAIO)
            {
                data_corretta = false;
            }
        }
        else
        {
            // L'anno NON è bisestile quindi è composto da 28 giorni
            if(data.giorno > MAX_GIORNO_FEBBRAIO - 1)
            {
                data_corretta = false;
            }
        }
    }
    
    if(data.mese == aprile || data.mese == giugno || data.mese == settembre || data.mese == novembre)
    {
        // Il mese è composto da 30 giorni
        if(data.giorno > MAX_GIORNO - 1)
        {
            data_corretta = false;
        }
    }

    return data_corretta;
}

bool areDateUguali(Data_t prima_data, Data_t seconda_data)
{
    bool date_uguali = false;

    if(prima_data.anno == seconda_data.anno)
    {
        // L'anno della prima e della seconda data coincidono
        if(prima_data.mese == seconda_data.mese)
        {
            // Il mese della prima e della seconda data coincidono
            if(prima_data.giorno == seconda_data.giorno)
            {
                // La prima data e la seconda coincidono
                date_uguali = true;
            }    
        }
    }

    return date_uguali;
}

Data_t dataPiuRecente(Data_t prima_data, Data_t seconda_data)
{
    Data_t data_recente = {MIN_ANNO, gennaio, MIN_GIORNO};

    if(prima_data.anno == seconda_data.anno)
    {
        // L'anno della prima e della seconda data coincidono
        if(prima_data.mese == seconda_data.mese)
        {
            // Il mese della prima e della seconda data coincidono
            if(prima_data.giorno >= seconda_data.giorno)
            {
                // La prima data e la seconda coincidono oppure la prima data è più recente
                data_recente = prima_data;
            }
            else
            {
                // La seconda data è più recente
                data_recente = seconda_data;
            }
        }
        else if(prima_data.mese > seconda_data.mese)
        {
            // Il mese della prima data è più recente
            data_recente = prima_data;
        }
        else
        {
            // Il mese della seconda data è più recente
            data_recente = seconda_data;
        }
        
    }
    else if(prima_data.anno > seconda_data.anno)
    {
        // L'anno della prima data è più recente
        data_recente = prima_data;
    }
    else
    {
        // L'anno della seconda data è più recente
        data_recente = seconda_data;
    }
    
    return data_recente;
}
Data_t dataMenoRecente(Data_t prima_data, Data_t seconda_data)
{
    Data_t data_meno_recente = {MAX_ANNO, dicembre, MAX_GIORNO};

    if(prima_data.anno == seconda_data.anno)
    {
        // L'anno della prima e della seconda data coincidono
        if(prima_data.mese == seconda_data.mese)
        {
            // Il mese della prima e della seconda data coincidono
            if(prima_data.giorno <= seconda_data.giorno)
            {
                // La prima data e la seconda coincidono oppure la prima data è meno recente
                data_meno_recente = prima_data;
            }
            else
            {
                // La seconda data è meno recente
                data_meno_recente = seconda_data;
            }
        }
        else if(prima_data.mese < seconda_data.mese)
        {
            // Il mese della prima data è meno recente
            data_meno_recente = prima_data;
        }
        else
        {
            // Il mese della seconda data è più recente
            data_meno_recente = seconda_data;
        }
        
    }
    else if(prima_data.anno < seconda_data.anno)
    {
        // L'anno della prima data è meno recente
        data_meno_recente = prima_data;
    }
    else
    {
        // L'anno della seconda data è meno recente
        data_meno_recente = seconda_data;
    }

    return data_meno_recente;        
}