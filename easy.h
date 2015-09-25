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
 int str_compare(char * str1, char * str2);

 /**
  * Get the first index of a substring in a string
  * @param  str    big string
  * @param  substr substring to find the index
  * @return        -1: if @substr is not a substring of string @str
  *               >=0: index of @substr in @str
  */
 int str_index(char * str, char *  substr);

 /**
  * Get a substring of a string with the input of start and end index
  * @param  str         String to get substring from
  * @param  start_index The starting index to get string (>=0)
  * @param  end_index   The ending index of string (< length of @str)
  * @return             NULL: if the input index is invalid
  *                     a new string which is the substring of @str from @start_index to @end_index
  */		
 char * str_sub(char * str, int start_index, int end_index);

/**
 * Get the combination of two strings
 * @param  str1 The first string to combine
 * @param  str2 The second string to combine
 * @return      a new string which is a combination of @str1 and @str2
 */
 char * str_combine(char * str1, char * str2);

/**
 * Replace a substring by another substring in a string
 * @param  str      big string
 * @param  str1     substring is going to be replaced
 * @param  rep replacing string
 * @return          1: if replacing is successful -> @str will become a new string with all substring @str1 are replaced by @rep
 *                  0: if replacing is not successful
 */
 int str_replace(char * str, char * str1, char * rep);


/**
 * Split a string by a spliter
 * @param  str     String is going to be split
 * @param  spliter spliter
 * @return         An array of string
 */
 char ** str_split(char * str, char * spliter);

/**
* Get a substring between 2 substrings
* @param  str     big string
* @param  begin   substring begin of value
* @param  end     substring end of value
* @return         substring between 2 substring
* Example:
* str = "I am the powest hero";
* begin = "am ";
* end = " hero";
* return should be: "the powest"
*/
char * str_subvalue(char *str, char* begin, char * end);

/**
 * Get a substring of a string, start from a substring
 * @param  str   Big string
 * @param  begin String to start
 * @return       substring from string @begin to end of string (not include string @begin)
 * Example:
 * str = "I am the powest hero";
 * begin = "am ";
 * return should be: "the powest hero"
 */
char * str_subend(char *str, char* begin);