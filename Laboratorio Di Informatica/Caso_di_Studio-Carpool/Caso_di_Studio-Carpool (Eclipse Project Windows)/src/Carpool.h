/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
   This library was developed in order to manage drivers, travels, and the booking of travels.
*/

/**
 * @file Carpool.h
 * @author Vincenzo Susso
 * @date 2019 Sep 10
 * @version 1.0
 * @brief This library was created in order to manage drivers and travels.
 *
 * This library was developed to create, edit and delete drivers and travels, furthermore this library allows to save drivers
 * and travels into files.
 */

// -- Libraries --
#ifndef Carpool_h
	#define Carpool_h

#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include "Date.h"
#include "Utilities.h"
#include "File.h"

// -- Constant --
/**
 * @def DRIVER
 * This boolean is used to indicates that the a struct of Driver_t will be modified into the procedure and functions.
 */
#define DRIVER true


/**
 * @def TRAVEL
 * This boolean is used to indicates that the a struct of Travel_t will be modified into the procedure and functions.
 */
#define TRAVEL false


/**
 * @def MAX_LENGHT_STRINGS
 * This integer is used to indicates the maximum lenght of strings.
 */
#define MAX_LENGHT_STRINGS 20


/**
 * @def MIN_LENGHT_STRINGS
 * This integer is used to indicates the minimum lenght of strings.
 */
#define MIN_LENGHT_STRINGS 2


/**
 * @def MAX_LENGHT_EMAIL
 * This integer is used to indicates the maximum lenght of emails.
 */
#define MAX_LENGHT_EMAIL 40


/**
 * @def MIN_LENGHT_PASSWORD
 * This integer is used to indicates the minimum lenght of passwords.
 */
#define MIN_LENGHT_PASSWORD 8


/**
 * @def MIN_LENGHT_PHONE_NUMBER
 * This integer is used to indicates the minimum lenght of phone number.
 */
#define MIN_LENGHT_PHONE_NUMBER 8 // For more information, please visit here: https://stackoverflow.com/questions/14894899/what-is-the-minimum-length-of-a-valid-international-phone-number


/**
 * @def MAX_LENGHT_PHONE_NUMBER
 * This integer is used to indicates the maximum lenght of phone_number.
 */
#define MAX_LENGHT_PHONE_NUMBER 18 // This constant was obtained by Country code lenght + space + subscriber number lenght + null character


/**
 * @def MAX_LENGHT_ADDITIONAL_NOTES
 * This integer is used to indicates the maximum lenght of additional notes.
 */
#define MAX_LENGHT_ADDITIONAL_NOTES 40


/**
 * @def MAX_LENGHT_NUMBER_INPUT
 * This integer is used to indicates lenght of string that is used to take a number as input.
 */
#define MAX_LENGHT_NUMBER_INPUT 8


/**
 * @def MIN_YEAR_BIRTHDAY
 * This integer is used to indicates the minimum valid year to be a driver.
 */
#define MIN_YEAR_BIRTHDAY 1915


/**
 * @def MAX_YEAR_BIRTHDAY
 * This integer is used to indicates the maximum valid year to be a driver.
 */
#define MAX_YEAR_BIRTHDAY 2001


/**
 * @def MIN_YEAR_TRAVEL
 * This integer is used to indicates the minimum valid year to create a travel.
 */
#define MIN_YEAR_TRAVEL 2019


/**
 * @def MAX_YEAR_TRAVEL
 * This integer is used to indicates the maximum valid year to create a travel.
 */
#define MAX_YEAR_TRAVEL 2050


/**
 * @def MIN_PRICE
 * This double is used to indicates the minimum travel's price.
 */
#define MIN_PRICE 0.01


/**
 * @def MAX_PRICE
 * This double is used to indicates the maximum travel's price.
 */
#define MAX_PRICE 9999.99


/**
 * @def DOLLAR_STRING
 * This string is used in order to indicates the currency of the travel's price.
 */
#define DOLLAR_STRING "$"


/**
 * @def MIN_NUMBER_TOTAL_SEATS
 * This integer is used to indicates the minimum number of total seats in a veicle (It include the driver's seat).
 */
#define MIN_NUMBER_TOTAL_SEATS 2


/**
 * @def MAX_NUMBER_TOTAL_SEATS
 * This integer is used to indicates the maximum number of total seats in a veicle (It include the driver's seat).
 */
#define MAX_NUMBER_TOTAL_SEATS 9 // For more information, please visit here: https://www.moneymaxim.co.uk/faq/car-hire/maximum-occupancy


/**
 * @def MIN_NUMBER_FREE_SEATS
 * This integer is used to indicates the mimimum number of free seats in a veicle.
 */
#define MIN_NUMBER_FREE_SEATS 0


/**
 * @def MAX_NUMBER_FREE_SEATS
 * This integer is used to indicates the maximum number of free seats in a veicle.
 */
#define MAX_NUMBER_FREE_SEATS 8 // Max Total seats - driver's seat

// Thoose constant are used in order to assign a literal output of the gender
/**
 * @def LENGHT_ARRAY_GENDER
 * This integer is used to indicates the lenght of the array that is used to converts the numeral output of gender to
 * letteral output.
 */
#define LENGHT_ARRAY_GENDER 3


/**
 * @def READ_GENDER_MALE
 * This string is used as string that will be shown instead of numeral output.
 */
#define READ_GENDER_MALE "Male"


/**
 * @def READ_GENDER_FEMALE
 * This string is used as string that will be shown instead of numeral output.
 */
#define READ_GENDER_FEMALE "Female"


/**
 * @def READ_GENDER_CUSTOM
 * This string is used as string that will be shown instead of numeral output.
 */
#define READ_GENDER_CUSTOM "Custom"

// Those constant are used in order to assign a graphic output of the rating
/**
 * @def LENGHT_ARRAY_RATING
 * This integer is used to indicates the lenght of the array that is used to converts the numeral output of rating to
 * letteral output.
 */
#define LENGHT_ARRAY_RATING 6


/**
 * @def READ_RATING_NONE
 * This string is used as string that will be shown instead of numeral output.
 */
#define READ_RATING_NONE "None"


/**
 * @def READ_RATING_ONE_STAR
 * This string is used as string that will be shown instead of numeral output.
 */
#define READ_RATING_ONE_STAR "*"


/**
 * @def READ_RATING_TWO_STAR
 * This string is used as string that will be shown instead of numeral output.
 */
#define READ_RATING_TWO_STAR "**"


/**
 * @def READ_RATING_THREE_STAR
 * This string is used as string that will be shown instead of numeral output.
 */
#define READ_RATING_THREE_STAR "***"


/**
 * @def READ_RATING_FOUR_STAR
 * This string is used as string that will be shown instead of numeral output.
 */
#define READ_RATING_FOUR_STAR "****"


/**
 * @def READ_RATING_FIVE_STAR
 * This string is used as string that will be shown instead of numeral output.
 */
#define READ_RATING_FIVE_STAR "*****"


/**
 * @def ALREADY_SORTED
 * This integer is used to see if the number of record is one, this case means that the records are already sorted.
 */
#define ALREADY_SORTED 1

// Those constant are used to manage the offset of the ID files
/**
 * @def OFFSET_ID_DRIVER
 * This integer is used to update the driver's ID.
 */
#define OFFSET_ID_DRIVER 0


/**
 * @def OFFSET_ID_TRAVEL
 * This integer is used to update the travel's ID.
 */
#define OFFSET_ID_TRAVEL 1

/**
 * @def MERGE_TEMP_FILE_PATH
 * This string is used to indicates the relative path of a temporary file used during the sorting.
 */
#define MERGE_TEMP_FILE_PATH "../Files/TempSort.dat"


/**
 * @def BOOK_TRAVEL_TEMP_FILE_PATH
 * This string is used to indicates the relative path of a temporary file used during the booking of a travel.
 */
#define BOOK_TRAVEL_TEMP_FILE_PATH "../Files/TempBook.dat"

// -- User-Defined types --
/**
 * @enum Rating_t
 * This user-defined type is used to evalutate the driver's capacity, this user-defined type was also created in order
 * to improve the readability.
 */
typedef enum {none, /**< This member is used when driver has no rating */            //!< none
			 one_star, /**< This member is used to assign one star rating to the driver */    //!< one_star
			 two_star, /**< This member is used to assign two star rating to the driver */    //!< two_star
			 three_star, /**< This member is used to assign three star rating to the driver *///!< three_star
			 four_star, /**< This member is used to assign four star rating to the driver */  //!< four_star
			 five_star /**< This member is used to assign five star rating to the driver */   //!< five_star
} Rating_t;


/**
 * @enum Gender_t
 * This user-defined type is used to know the gender of the driver, this user-defined type was also created in order to improve
 * the readability.
 */
typedef enum {male, /**< This member is used to indicate that the driver's gender is male */
			 female, /**< This member is used to indicate that the driver's gender is female */
			 custom /**< This member is used to indicate that the driver's gender is custom */
} Gender_t;


/**
 * @enum Driver_members_t
 * This user-defined type is used in order to define the member of the struct Driver_t, this user-defined type was created in
 * order to edit the member of the struct Driver_t.
 */
typedef enum {id_driver = -1, /**< This member is used to indicates the driver's ID */
			 name, /**< This member is used to indicate the driver's name */
			 surname, /**< This member is used to indicate the driver's surname */
			 email, /**< This member is used to indicate the driver's email */
			 password, /**< This member is used to indicate the driver's password */
			 phone_number, /**< This member is used to indicate the driver's phone_number */
			 birthday, /**< This member is used to indicate the driver's birthday */
			 gender, /**< This member is used to indicate the driver's gender */
			 deleted_driver /**< This member is used to indicate the driver's deletion */
} Driver_members_t;


/**
 * @enum Driver_sort_key
 * This user-defined type is used in order to sort the drivers using several sort-key.
 */
typedef enum {inc_id_driver, /**< This member is used to sort drivers using increasing ID as sorting-key */
			 dec_id_driver, /**< This member is used to sort drivers using decreasing ID as sorting-key */
			 inc_name, /**< This member is used to sort drivers using increasing driver's name as sorting-key */
			 dec_name, /**< This member is used to sort drivers using decreasing driver's name as sorting-key */
			 inc_surname, /**< This member is used to sort drivers using increasing driver's surname as sorting-key */
			 dec_surname, /**< This member is used to sort drivers using decreasing driver's surname as sorting-key */
			 inc_birthday, /**< This member is used to sort drivers using increasing driver's birthday as sorting-key */
			 dec_birthday, /**< This member is used to sort drivers using decreasing driver's birthday as sorting-key */
			 inc_gender, /**< This member is used to sort drivers using increasing driver's gender as sorting-key */
			 dec_gender, /**< This member is used to sort drivers using decreasing driver's gender as sorting-key */
			 inc_driving_capacity, /**< This member is used to sort drivers using increasing driver's driving capacity as sorting-key */
			 dec_driving_capacity, /**< This member is used to sort drivers using decreasing driver's driving capacity as sorting-key */
			 inc_comfort_capacity, /**< This member is used to sort drivers using increasing driver's comfort capacity as sorting-key */
			 dec_comfort_capacity, /**< This member is used to sort drivers using decreasing driver's comfort capacity as sorting-key */
			 inc_average_rating, /**< This member is used to sort drivers using increasing driver's average rating as sorting-key */
			 dec_average_rating /**< This member is used to sort drivers using decreasing driver's average rating as sorting-key */
} Driver_sort_key;


/**
 * @enum Travel_members_t
 * This user-defined type is used in order to define the member of the struct Travel_t, this user-defined type was created in
 * order to edit the member of the struct Travel_t.
 */
typedef enum {id_travel = -2, /**< This member is used to indicates the travel's ID */
			 id_driver_, /**< This member is used to indicates the ID of the driver that will offer the travel */
			 departure_destination, /**< This member is used to indicates the travel's departure destination */
			 arrival_destination, /**< This member is used to indicates the travel's arrival destination */
			 departure_date, /**< This member is used to indicates the travel's departure date */
			 departure_time, /**< This member is used to indicates the travel's departure time */
			 total_seats, /**< This member is used to indicates the veicle's total seats */
			 free_seats, /**< This member is used to indicates the veicle's free seats */
			 price, /**< This member is used to indicates the travel's price */
			 additional_notes, /**< This member is used to indicates the travel's additional notes */
			 deleted_travel /**< This member is used to indicate the travel's deletion */
} Travel_members_t;


/**
* @enum Driver_sort_key
* This user-defined type is used in order to sort the travels using several sort-key.
*/
typedef enum {inc_id_travel, /**< This member is used to sort travels using increasing ID as sorting-key */
			 dec_id_travel, /**< This member is used to sort travels using decreasing ID as sorting-key */
			 inc_departure_destination, /**< This member is used to sort travels using increasing departure destination as sorting-key */
			 dec_departure_destination, /**< This member is used to sort travels using decreasing departure destination as sorting-key */
			 inc_arrival_destination, /**< This member is used to sort travels using increasing arrival destination as sorting-key */
			 dec_arrival_destination, /**< This member is used to sort travels using decreasing arrival destination as sorting-key */
			 inc_departure_date,  /**< This member is used to sort travels using increasing departure date as sorting-key */
			 dec_departure_date, /**< This member is used to sort travels using decreasing departure date as sorting-key */
			 inc_price, /**< This member is used to sort travels using increasing price as sorting-key */
			 dec_price, /**< This member is used to sort travels using decreasing price as sorting-key */
			 inc_total_seats, /**< This member is used to sort travels using increasing veicle's total seats as sorting-key */
			 dec_total_seats, /**< This member is used to sort travels using decreasing veicle's total seats as sorting-key */
			 inc_free_seats, /**< This member is used to sort travels using increasing veicle's free seats as sorting-key */
			 dec_free_seats /**< This member is used to sort travels using decreasing veicle's free seats as sorting-key */
} Travel_sort_key;


/**
 * @struct Driver_t
 * This user-defined type is used in order to manage drivers.
 */
typedef struct
{
	int id; /**< This member is used to store the driver's ID */
	char name[MAX_LENGHT_STRINGS]; /**< This member is used to store the driver's name */
	char surname[MAX_LENGHT_STRINGS]; /**< This member is used to store the driver's surname */
	char email[MAX_LENGHT_EMAIL]; /**< This member is used to store the driver's email */
	char password[MAX_LENGHT_STRINGS]; /**< This member is used to store the driver's password */
	char phone_number[MAX_LENGHT_PHONE_NUMBER]; /**< This member is used to store the driver's phone number */
	Date_t birthday; /**< This member is used to store the driver's birthday */
	Gender_t gender; /**< This member is used to store the driver's gender */
	Rating_t driving_capacity; /**< This member is used to store the driver's driving capacity */
	Rating_t comfort_capacity; /**< This member is used to store the driver's comfort capacity */
	Rating_t average_rating; /**< This member is used to store the driver's average rating */
	bool deleted; /**< This member is used to know if the driver is deleted, if this member is true, means that the driver is deleted */
} Driver_t;


/**
 * @struct Travel_t
 * This user-defined type is used in order to manage travels.
 */
typedef struct
{
	int id; /**< This member is used to store the travel's ID */
	int id_driver; /**< This member is used to store the ID of the driver that will offer the travel */
	char departure_destination[MAX_LENGHT_STRINGS]; /**< This member is used to store the travel's departure destination */
	char arrival_destination[MAX_LENGHT_STRINGS]; /**< This member is used to store the travel's arrival destination */
	char additional_notes[MAX_LENGHT_ADDITIONAL_NOTES]; /**< This member is used to store the travel's additional notes */
	Date_t departure_date; /**< This member is used to store the travel's departure date */
	Time_t departure_time; /**< This member is used to store the travel's departure time */
	double price; /**< This member is used to store the travel's price */
	unsigned short total_seats; /**< This member is used to store the veicle's total seats (It must include the driver's seat) */
	unsigned short free_seats; /**< This member is used to store the veicle's free seats */
	bool deleted; /**< This member is used to know if the travel is deleted, if this member is true, means that the travel is deleted */
} Travel_t;


/**
 * @struct Rating_file_t
 * This user-defined type is used in order to save rating into a file.
 */
typedef struct
{
	int id_driver; /**< This member is used to store the ID of the driver that has been evalutated */
	bool option_rating; /**< This member is used to know which evalutation the user wants to do, if \"option rating\" is true it means that rating refers to driver capacity, otherwise it refers to comfort capacity */
	Rating_t rating; /**< This member is used to store the evalutation that the user has made */
} Rating_file_t;


/**
 * @struct Booking_travel_t
 * This user-defined type is used in order to book a travel.
 */
typedef struct
{
	char departure_destination[MAX_LENGHT_STRINGS]; /**< This member is used to store the departure destination of the travel that the user wants to book */
	char arrival_destination[MAX_LENGHT_STRINGS]; /**< This member is used to store the arrival destination of the travel that the user wants to book */
	Date_t departure_date; /**< This member is used to store the departure date of the travel that the user wants to book */
	Time_t departure_time; /**< This member is used to store the departure time of the travel that the user wants to book */
	unsigned short number_seats; /**< This member is used to store the number of seats that the user needs in order to book the travel */
} Booking_travel_t;

// -- Procedure & Functions Prototypes --
/**
 * @fn *readGender(const Gender_t *gender)
 * This function returns the letteral output using the pointer *gender as a index of array's string.
 * For more information, please visit here: https://stackoverflow.com/questions/1496313/returning-c-string-from-a-function
 * @param gender is used to return a letteral output.
 * @return \"Male\" if (*gender) is equal to 0, \"Female\" if (*gender) is equal to 1, otherwise It will return \"Custom\".
 */
const char *readGender(const Gender_t *gender);


/**
 * @fn *readRating(const Rating_t *rating)
 * This function returns the letteral output using the pointer *rating as a index of array's string.
 * For more information, please visit here: https://stackoverflow.com/questions/1496313/returning-c-string-from-a-function
 * @param rating is used to return a letteral output.
 * @return \"None\" if (*rating) is equal to 0, \"*\" if (*rating) is equal to 1, \"**\" if (*rating) is equal to 2,
 * \"***\" if (*rating) is equal to 3, \"****\" if (*rating) is equal to 4 and \"*****\" if (*rating) is equal to 5.
 */
const char *readRating(const Rating_t *rating);


/**
 * @fn setWord(char word[], const char printf_value[])
 * This procedure is used to set a valid value to the word passed by pointer.
 * A valid word is made of only latin characters and it is not void.
 * @param word is set to a valid string.
 * @param printf_value is used to ask to the user what he should enter.
 */
void setWord(char word[], const char printf_value[]);


/**
 * @fn setEmail(char email[])
 * This procedure is used to set a valid value to the email passed by pointer.
 * A valid email has the following format \"localpart\@domain\".
 * @param email is set to a valid email.
 */
void setEmail(char email[]);


/**
 * @fn setPassword(char password[])
 * This procedure is used to set a valid value to the password passed by pointer.
 * The password should contains at least one uppercase character and one digit.
 * @param password is set to a valid password.
 */
void setPassword(char password[]);


/**
 * @fn setPhoneNumber(char phone_number[])
 * This procedure is used to set a valid value to the number phone passed by pointer.
 * A valid number phone has the followig format \"+xxx xxxxxxxxxxxx\".
 * @param phone_number is set to a valid number phone.
 */
void setPhoneNumber(char phone_number[]);


/**
 * @fn setAdditionalNotes(char additional_notes[])
 * This procedure is used to set a valid value to the additional notes passed by pointer.
 * The additional notes should not be void strings and can contains spaces.
 * @param additional_notes is set to a valid additional notes.
 */
void setAdditionalNotes(char additional_notes[]);


/**
 * @fn setPrice(double *price)
 * This procedure is used to set a valid value to the price passed by pointer.
 * @param price is set to a valid price.
 */
void setPrice(double *price);


/**
 * @fn setNumberInput(int *input, const int min, const int max, const char printf_value_input[], const char printf_value_error[])
 * This procedure is used to set a valid value to the input passed by pointer.
 * A valid value is made only of digits.
 * @param input is set to a valid number.
 * @param min is the minimun valid number.
 * @param max is the maximum valid number.
 * @param printf_value_input is used to ask to the user what he should enter.
 * @param printf_value_error is used to report to the user if there was an error during the entering of the number.
 */
void setNumberInput(int *input, const int min, const int max, const char printf_value_input[], const char printf_value_error[]);


/**
 * @fn resetDriver(Driver_t *driver)
 * This procedure reset the driver passed by pointer assigning invalid values to all the driver's members.
 * @param driver is resetted by the procedure.
 */
void resetDriver(Driver_t *driver);


/**
 * @fn setDriver(Driver_t *driver, const int *id)
 * This procedure set valid value to every members of the driver passed by pointer.
 * @param driver is used to set valid value to every members.
 * @param id is the unique id of the driver.
 */
void setDriver(Driver_t *driver, const int *id);


/**
 * @fn readDriver(const Driver_t *driver)
 * This procedure prints every members of the drivers passed by pointer.
 * P.S: if the driver is deleted, the procedure will not read the driver.
 * @param driver is printed.
 */
void readDriver(const Driver_t *driver);


/**
 * @fn isIdDriverEqual(const Driver_t *driver, const int *id)
 * This function is used to compare the driver's ID passed by pointer with the other id passed by pointer.
 * P.S: if the driver is deleted, the function will not compares the ID.
 * @param driver is used as first member of the comparision.
 * @param id is used as the second member of the comparision.
 * @return true if the driver's ID is equal to id, otherwise the function will return false.
 */
bool isIdDriverEqual(const Driver_t *driver, const int *id);


/**
 * @fn showMemberDriver(void)
 * This procedure is used to show all the driver's member.
 * This procedure is used during the editing of driver's member.
 */
void showMemberDriver(void);

/**
 * @fn showSortKeyDriver(void)
 * This procedure is used to show all the driver's sort-key.
 */
void showSortKeyDriver(void);


/**
 * @fn resetTravel(Travel_t *travel)
 * This procedure reset the travel passed by pointer assigning invalid values to all the travel's members.
 * @param travel is resetted by the procedure.
 */
void resetTravel(Travel_t *travel);


/**
 * @fn setTravel(Travel_t *travel, const int *id, const char path_file_travel[], const char path_file_driver[])
 * This procedure set valid value to every members of the travel passed by pointer.
 * @param travel is used to set valid value to every members.
 * @param id is the unique id of the driver.
 * @param path_file_driver is used to get the ID of the driver that will offer the travel.
 */
void setTravel(Travel_t *travel, const int *id, const char path_file_driver[]);


/**
 * @fn readTravel(const Travel_t *travel, const char path_driver_file[])
 * This procedure prints every members of the travel passed by pointer.
 * P.S: if the travel is deleted, the procedure will not read the travel.
 * @param travel is printed.
 * @param path_driver_file is used to print information of the driver that will offer the travel.
 */
void readTravel(const Travel_t *travel, const char path_driver_file[]);


/**
 * @fn isIdTravelEqual(const Travel_t *travel, const int *id)
 * This function is used to compare the travel's ID passed by pointer with the other id passed by pointer.
 * P.S: if the travel is deleted, the function will not compares the ID.
 * @param travel is used as first member of the comparision.
 * @param id is used as second member of the comparision.
 * @return true if the travel's ID is equal to id, otherwise the function will return false.
 */
bool isIdTravelEqual(const Travel_t *travel, const int *id);


/**
 * @fn showMemberTravel(void)
 * This procedure is used to show all the travel's member.
 * This procedure is used during the editing of travel's member.
 */
void showMemberTravel(void);


/**
 * @fn showSortKeyTravel(void)
 * This procedure is used to show all the travel's sort-key.
 */
void showSortKeyTravel(void);



/**
 * @fn resetBookingTravel(Booking_travel_t *booking_travel)
 * This procedure reset the booking_travel passed by pointer assigning invalid values to all the booking_travel's members.
 * @param booking_travel is resetted by the procedure.
 */
void resetBookingTravel(Booking_travel_t *booking_travel);

// Those function uses files
/**
 * @fn addStruct(const char path_file_driver[], const char path_file_travel[], const int *id, bool select_struct)
 * This function is used to set a struct between Driver_t and Travel_t and save them into a file.
 * @param path_file_driver is the relative path of the driver's file.
 * @param path_file_travel is the relative path of the travel's file.
 * @param id is the unique ID of driver or travel.
 * @param select_struct is used to set Driver_t or Travel_t, if select_struct is equal to \"DRIVER\" then a driver will
 * be added to the system, if select_struct is equal to \"TRAVEL\" then a travel will be added to the system.
 * @return 2 if the struct is added to the system, otherwise this function will return 0.
 */
File_status_t addStruct(const char path_file_driver[], const char path_file_travel[], const int *id, bool select_struct);


/**
 * @fn editStruct(const char path_file_driver[], const char path_file_travel[], bool select_struct);
 * This function is used to edit a struct between Driver_t and Travel_t and save them into a file.
 * @param path_file_driver is the relative path of the driver's file.
 * @param path_file_travel is the relative path of the travel's file
 * @param select_struct is used to edit Driver_t or Travel_t, if select_struct is equal to \"DRIVER\" then a driver will
 * be edited and added to the system, if select_struct is equal to \"TRAVEL\" then a travel will be edited and added to
 * the system.
 * @return 2 if the struct has been edited and added to the system, otherwise this function will return 0.
 */
File_status_t editStruct(const char path_file_driver[], const char path_file_travel[], bool select_struct);


/**
 * @fn deleteStruct(const char path_file_driver[], const char path_file_travel[], bool select_struct)
 * This function is used to delete a struct between Driver_t and Travel_t.
 * @param path_file_driver is the relative path of the driver's file.
 * @param path_file_travel is the relative path of the travel's file
 * @param select_struct is used to delete Driver_t or Travel_t, if select_struct is equal to \"DRIVER\" then a driver will
 * be deleted, if select_struct is equal to \"TRAVEL\" then a travel will be deleted.
 * @return 2 if the struct has been deleted, otherwise this function will return 0.
 */
File_status_t deleteStruct(const char path_file_driver[], const char path_file_travel[], bool select_struct);


/**
 * @fn showAllStructs(const char path_file_driver[], const char path_file_travel[], bool select_struct)
 * This function is used to show all records of Driver_t or Travel_t.
 * @param path_file_driver is the relative path of the driver's file.
 * @param path_file_travel is the relative path of the travel's file
 * @param select_struct is used to read all records of Driver_t or Travel_t, if select_struct is equal to \"DRIVER\"
 * then all drivers will be read (except the deleted ones), if select_struct is equal to \"TRAVEL\" then all travels
 * will be read (except the deleted ones).
 * @return 1 if all the records has been read, otherwise this function will return 0.
 */
File_status_t showAllStructs(const char path_file_driver[], const char path_file_travel[], bool select_struct);


/**
 * @fn bookTravel(const char path_file_driver[], const char path_file_travel[])
 * This function is used in order to book a travel.
 * @param path_file_driver is the relative path of the driver's file.
 * @param path_file_travel is the relative path of the travel's file
 * @return true if a travel has been booked, otherwise this function will return false
 */
bool bookTravel(const char path_file_driver[], const char path_file_travel[]);


/**
 * @fn manageRating(const char path_file_driver[], const char path_file_rating[])
 * This function is used in order to assign the evalutations to the drivers.
 * @param path_file_driver is the relative path of the driver's file.
 * @param path_file_rating is the relative path of the rating's file.
 * @return 1 if evalutations have been assigned to the drivers, otherwise this function will return 0.
 */
File_status_t manageRating(const char path_file_driver[], const char path_file_rating[]);


/**
 * @fn evaluateDriver(const char path_file_driver[], const char path_file_rating[])
 * This function is used in order to allow users to enter evaluations to the drivers.
 * @param path_file_driver is the relative path of the driver's file.
 * @param path_file_rating is the relative path of the rating's file.
 * @return 1 if the user has evaluate driver, otherwise this function will return 0.
 */
File_status_t evaluateDriver(const char path_file_driver[], const char path_file_rating[]);


/**
 * @fn updateID(const char path_file[], const long int offset, int *id)
 * This function is used in order to update the ID passed by pointer and save its into the file.
 * @param path_file is the relative path where IDs are stored.
 * @param offset can be set to \"OFFSET_ID_DRIVER\" in order to update the unique ID of the drivers, otherwise offset
 * can be set to \"OFFSET_ID_TRAVEL\" in order to update the unique ID of the travels.
 * @param id is the unique identifier that will be updated.
 * @return 1 if the ID was updated, otherwise the function will return 0
 */
File_status_t updateID(const char path_file[], const long int offset, int *id);


/**
 * @fn getIndexUser(const char path_file_driver[], const char path_file_travel[], const char printf_value_input[], const char printf_value_error[], bool select_struct)
 * This function is used to return the index of the ID that is entered by the user using keyboard.
 * @param path_file_driver is the relative path of the driver's file.
 * @param path_file_travel is the relative path of the travel's file.
 * @param printf_value_input is used to ask to the user to enter the ID of the struct he needs.
 * @param printf_value_error is used to report to the user if there was an error during the entering of the ID that he needs.
 * @param select_struct is used to get index of Driver_t or Travel_t, if select_struct is equal to \"DRIVER\" then the
 * driver's index will be searched, if select_struct is equal to \"TRAVEL\" then the travel's index will be searched.
 * @return the index of the struct if it has been found, otherwise the function will return 0.
 */
long int getIndexUser(const char path_file_driver[], const char path_file_travel[], const char printf_value_input[], const char printf_value_error[], bool select_struct);


/**
 * @fn getIndex(const char path_file[], const int *id, bool select_struct)
 * This function is used to return the index of the ID that is passed by pointer.
 * @param path_file is the relative path of the driver's file.
 * @param id is used to search the index of the struct.
 * @param select_struct is used to get index of Driver_t or Travel_t, if select_struct is equal to \"DRIVER\" then the
 * driver's index will be searched, if select_struct is equal to \"TRAVEL\" then the travel's index will be searched.
 * @return the index of the struct if it has been found, otherwise the function will return 0.
 */
long int getIndex(const char path_file[], const int *id, bool select_struct);



/**
 * @fn setSort(const char path_file[], long int start, long int end, bool select_struct)
 * This function is used to ask to the user to enter the key_sort.
 * @param path_file is the relative path of the file that the user wants to sort.
 * @param start is the offset of the first record of the file.
 * @param end is the offset of the last record of the file.
 * @param select_struct is used to sort Driver_t or Travel_t, if select_struct is equal to \"DRIVER\" then the
 * drivers will be sorted, if select_struct is equal to \"TRAVEL\" then the travels will be sorted.
 * @return the time that the sorting has spent, otherwise this function will return 0.
 */
double setSort(const char path_file[], long int start, long int end, bool select_struct);


/**
 * @fn mergeSort(const char path_file[], long int start, long int end, bool select_struct, int key_sort)
 * This procedure is used to split the records.
 * @param path_file is the relative path of the file that the user wants to sort.
 * @param start is the offset of the first record of the file.
 * @param end is the offset of the last record of the file.
 * @param select_struct is used to sort Driver_t or Travel_t, if select_struct is equal to \"DRIVER\" then the
 * drivers will be sorted, if select_struct is equal to \"TRAVEL\" then the travels will be sorted.
 * @param key_sort is used to indicate the key sort of the sorting.
 */
void mergeSort(const char path_file[], long int start, long int end, bool select_struct, int key_sort);


/**
 * @fn mergeDriver(const char path_file[], long int start, long int middle, long int end, int key_sort)
 * This procedure is used to merge the driver's records.
 * @param path_file is the relative path of the driver's file that the user wants to sort.
 * @param start is the offset of the first record of the file.
 * @param middle is the offset of the medium driver's record.
 * @param end is the offset of the last record of the file.
 * @param key_sort is used to indicate the key sort of the sorting.
 */
void mergeDriver(const char path_file[], long int start, long int middle, long int end, int key_sort);


/**
 * @fn mergeTravel(const char path_file[], long int start, long int middle, long int end, int key_sort)
 * This procedure is used to merge the travel's records.
 * @param path_file is the relative path of the travel's file that the user wants to sort.
 * @param start is the offset of the first record of the file.
 * @param middle is the offset of the medium driver's record.
 * @param end is the offset of the last record of the file.
 * @param key_sort is used to indicate the key sort of the sorting.
 */
void mergeTravel(const char path_file[], long int start, long int middle, long int end, int key_sort);

#endif
