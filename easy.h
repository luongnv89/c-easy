/**
 * c-easy is a c/c++ library which provides many funtions to help working with c/c++ easier.
 */

 
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
/**
 * Compare 2 strings
 * @param  str1 String 1
 * @param  str2 The second string
 * @return      1: if two strings are equal
 *              0: two string are not equal
 */
 int str_compare(char * str1, char * str2); // Passed

 /**
  * Get the first index of a substring in a string
  * @param  str    big string
  * @param  substr substring to find the index
  * @return        -1: if @substr is not a substring of string @str
  *                    if @str1 is NULL
  *                    if @str2 is NULL
  *               >=0: index of @substr in @str
  *               
  */
 int str_index(char * str, char *  substr); // Passed

 /**
  * Get a substring of a string with the input of start and end index
  * @param  str         String to get substring from
  * @param  start_index The starting index to get string (>=0)
  * @param  end_index   The ending index of string (< length of @str)
  * @return             NULL: if @str is NULL
  *                           if @start_index <0
  *                           if @end_index >= length of @str
  *                           if @start_index >= @end_index
  *                     a new string which is the substring of @str from @start_index to @end_index (counts both 2 characters at index @start_index and @end_index)
  */		
 char * str_sub(char * str, int start_index, int end_index); // Passed

/**
 * Get the combination of two strings
 * @param  str1 The first string to combine
 * @param  str2 The second string to combine
 * @return      a new string which is a combination of @str1 and @str2
 *              NULL if both @str1 and @str2 are NULL
 *              A copy of @str1 if @str2 is NULL
 *              A copy of @str2 if @str1 is NULL
 */
 char * str_combine(char * str1, char * str2); // Passed

/**
 * Split a string by a spliter
 * @param  str     String is going to be split
 * @param  spliter spliter
 * @return         An array of string
 *                 NULL if @str or @spliter is(are) NULL
 *                 Array with only 1 element if @spliter does not exists in @str
 *                 Array with only 1 element if @spliter is at the beginning or the end of string
 */
 char ** str_split(char * str, char * spliter); // Passed
 

/**
 * Replace a substring by another substring in a string
 * @param  str      big string
 * @param  str1     substring is going to be replaced
 * @param  rep replacing string
 * @return          1: if replacing is successful -> @str will become a new string with all substring @str1 are replaced by @rep
 *                  0: if replacing is not successful
 */
 char * str_replace(char * str, char * str1, char * rep);


/**
* Get a substring between 2 substrings
* @param  str     big string
* @param  begin   substring begin of value (the first appears in @str)
* @param  end     substring end of value (the first appears in @str)
* @return         substring between 2 substring
*                 if @end is NULL then return substring from @begin to the end of string
*                 if @begin is NULL then return substring from beginning to the string @end
*                 return NULL if: 
*                   @str  is NULL
*                   @begin is not a substring of @str
*                   @end is not a substring of @str
*                   @begin and @end are NULL
*                   @begin and @end are overlap or next each other in @str
*                   @begin is after @end in @str
*/
char * str_subvalue(char *str, char* begin, char * end); // Passed

/**
 * Add a string into an array of string. New string will be filled in the first NULL element of array
 * @param  array Array of string
 * @param  str   String to add
 * @return       new array of string
 *               old array of string if the adding is not successful
 */
char ** str_add_new_string(char **array,char *str);

/**
 * Print string in an array of string until the first NULL element;
 * @param array array string
 */
void str_print_array(char **array); // Passed


/**
 * Executes a command in linux and return the output
 * @param  cmd command to be executed
 * @return     the output of command
 */
char * cmd_run_command(char *cmd); // Passed


/**
 * Get all indexes of a character in a string
 * @param  str string
 * @param  c   ascii code number of character
 * @return     an integer array which contains the list of indexes of character in string
 */
int * str_get_indexes(char *str, int c); // Passed

/**
 * Replace a character by another character in all string
 * @param  str string
 * @param  c1  ascii code number of character will be replaced
 * @param  c2  ascii code number of replacing character
 * @return     new string after replacing
 */
char * str_replace_all_char(char *str,int c1, int c2); // Passed