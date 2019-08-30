// -- Libraries --
#include "Date.h"

// -- Procedure & Functions --
/*Date_t createRandomDate(void)
{
    Date_t date = {MIN_YEAR, january, MIN_DAY};

    // Creation of random value
    date.year = createRandomValue(MIN_YEAR, MAX_YEAR);
    date.month = createRandomValue(january, december);
    date.day = createRandomValue(MIN_DAY, MAX_DAY);


    return date;
}

Time_t createRandomTime(void)
{
	Time_t time = {MIN_HOUR, MIN_MINUTE};

    time.hour = createRandomValue(MIN_HOUR, MAX_HOUR);
    time.minute = createRandomValue(MIN_MINUTE, MAX_MINUTE);

	return time;
}*/

bool isLeapYear(const unsigned short year)
{
	bool leap_year = false;

	// A year is a leap year if it is divisible by four and not by one-hundred or if it is divisible by four-hundred
	if((!(year % LEAP_YEAR) && (year % CENTURY_YEAR)) || !(year % CENTURY_LEAP_YEAR))
	{
		leap_year = true;
	}
	else
	{
		leap_year = false;
	}

	return leap_year;
}

bool isValidDate(const Date_t date)
{
	// Those variable are used in order to avoid bugs due to the use of the same variable for many scopes
	bool valid_year = false;
	bool valid_month = false;
	bool valid_day = false;

	if(date.year >= MIN_YEAR && date.year <= MAX_YEAR)
	{
		valid_year = true;
	}

	if(date.month >= january && date.month<= december)
	{
		valid_month = true;
		if(date.month == february)
		{
			if(isLeapYear(date.year))
			{
				// The year is a lap year so the month has twenty-nine days
				if(date.day >= MIN_DAY && date.day <= MAX_DAY_FEBRUARY)
				{
					valid_day = true;
				}
			}
			else
			{
				// The year is not a lap year so the month has twenty-eight days
				if(date.day >= MIN_DAY && date.day < MAX_DAY_FEBRUARY)
				{
					valid_day = true;
				}
			}
		}
		else if(date.month == april || date.month == june || date.month == september || date.month == november)
		{
			// The month has thirty days
			if(date.day >= MIN_DAY && date.day < MAX_DAY)
			{
				valid_day = true;
			}
		}
		else
		{
			// The month has thirty-one days
			if(date.day >= MIN_DAY && date.day <= MAX_DAY)
			{
				valid_day = true;;
			}
		}
	}

	return (valid_year && valid_month && valid_day);
}

bool isValidTime(const Time_t time)
{
	// Those variable are used in order to avoid bugs due to the use of the same variable for many scopes
	bool valid_hour = false;
	bool valid_minute = false;

	if(time.hour > MIN_HOUR && time.hour <= MAX_HOUR)
	{
		valid_hour = true;
	}

	if(time.minute >= MIN_MINUTE && time.minute <= MAX_MINUTE)
	{
		valid_minute = true;
	}

	return (valid_hour && valid_minute);
}

/*
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
} */
