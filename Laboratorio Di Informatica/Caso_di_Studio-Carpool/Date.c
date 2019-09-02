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

bool isValidDate(const Date_t date, const unsigned short min_year, const unsigned short max_year)
{
	// Those variable are used in order to avoid bugs due to the use of the same variable for many scopes
	bool valid_date = false;


	// If the year or the month is not valid, all the date is wrong
	if(isIncluded(january, december, date.month) && isIncluded(min_year, max_year, date.year))
	{
		if(date.month == february)
		{
			if(isLeapYear(date.year))
			{
				// The year is a lap year so the month has twenty-nine days
				valid_date = isIncluded(MIN_DAY, MAX_DAY_FEBRUARY, date.day);
			}
			else
			{
				// The year is not a lap year so the month has twenty-eight days
				valid_date = isIncluded(MIN_DAY, MAX_DAY_FEBRUARY - 1, date.day);
			}
		}
		else if(date.month == april || date.month == june || date.month == september || date.month == november)
		{
			// The month has thirty days
			valid_date = isIncluded(MIN_DAY, MAX_DAY - 1, date.day);
		}
		else
		{
			// The month has thirty-one days
			valid_date = isIncluded(MIN_DAY, MAX_DAY, date.day);
		}
	}

	return valid_date;
}

void resetDate(Date_t *date)
{
	date -> year = 0;
	date -> month = january - 1;
	date -> day = MIN_DAY - 1;
}

// The procedure set a valid value to the date passed by pointer
void setDate(Date_t *date, const unsigned short min_year, const unsigned short max_year, const char printf_value[])
{
	bool flag = false;
	char date_input[MAX_LENGHT_DATE_STRING_INPUT] = NULL_STRING; // This string is used in order to take the input

	// Thoose pointer are used to point to the part of the date
	char *year = NULL;
	char *month = NULL;
	char *day = NULL;

	resetDate(date);

	do
	{
		flag = false;

		printf("\nEnter the %s (yyyy%smm%sdd): ", printf_value, DATE_DELIMITER, DATE_DELIMITER);
		scanf("%10[^\n]s", date_input);
		addNullCharacterString(date_input);
		clearBuffer();

		year = strtok(date_input, DATE_DELIMITER);
		month = strtok(NULL, DATE_DELIMITER);
		day = strtok(NULL, NULL_STRING);

		if(month && day)
		{
			// The string that the user has entered has a valid format
			if(isNumberString(year) && isNumberString(month) && isNumberString(day))
			{
				// The string has the correct characters
				date -> year = (unsigned short) strtoul(year, NULL, BASE_STRTOL);
				date -> month = (unsigned short) strtoul(month, NULL, BASE_STRTOL);
				date -> day = (unsigned short) strtoul(day, NULL, BASE_STRTOL);
			}
		}

		flag = !isValidDate(*date, min_year, max_year);
		if(flag)
		{
			printf("\nThe %s that you have entered is not valid", printf_value);
		}

	}
	while(flag);
}

bool isValidTime(const Time_t time)
{
	bool valid_time = false;

	if(isIncluded(MIN_HOUR, MAX_HOUR, time.hour) && isIncluded(MIN_MINUTE, MAX_MINUTE, time.minute))
	{
		valid_time = true;
	}

	return valid_time;
}

void resetTime(Time_t *time)
{
	time -> hour = MIN_HOUR - 1;
	time -> minute = MIN_MINUTE - 1;
}

void setTime(Time_t *time, const char printf_value[]) // The procedure set a valid value to the time passed by pointer
{
	bool flag = false;
	char time_input[MAX_LENGHT_TIME_STRING_INPUT] = NULL_STRING; // This string is used in order to take the input

	// Thoose pointer are used to point to the part of the date
	char *hour = NULL;
	char *minute = NULL;

	resetTime(time);

	do
	{
		flag = false;

		printf("\nEnter the %s (hh%smm): ", printf_value, TIME_DELIMITER);
		scanf("%5[^\n]s", time_input);
		addNullCharacterString(time_input);
		clearBuffer();

		hour = strtok(time_input, TIME_DELIMITER);
		minute = strtok(NULL, NULL_STRING);

		if(minute)
		{
			// The string that the user has entered has a valid format
			if(isNumberString(hour) && isNumberString(minute))
			{
				// The string has the correct characters
				time -> hour = (unsigned short) strtoul(hour, NULL, BASE_STRTOL);
				time -> minute = (unsigned short) strtoul(minute, NULL, BASE_STRTOL);
			}
		}

		flag = !isValidTime(*time);
		if(flag)
		{
			printf("\nThe %s that you have entered is not valid", printf_value);
		}

	}
	while(flag);
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
