/*
 *  CUnit unit test.
 *  
 */

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include "easy.h"

/* Pointer to the file used by the tests. */
// static FILE* temp_file = NULL;
static char * str = "Je suis CUnit.";
static char * str0 = " Je t'aime";

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{
   // if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      // return -1;
   // }
   // else {
      return 0;
   // }
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
   // if (0 != fclose(temp_file)) {
      // return -1;
   // }
   // else {
      // temp_file = NULL;
      return 0;
   // }
}

/**
 * Test str_compare
 */
void test_str_compare(void){
   char * str1 = "Nguyen";
   char * str2 = "Luong";
   CU_TEST(1==str_compare(str1,str1));
   CU_TEST(1==str_compare(str2,str2));
   CU_TEST(0==str_compare(str1,str2));
}

/**
 * Test str_index
 */
void test_str_index(void){
   char * str1 = "Je suis CUNIT";
   char * str2 = "suis";
   char * str3 = "Hola";
   CU_ASSERT(str_index(str1,str2)>0);
   CU_ASSERT(str_index(str1,str3)==-1);
}

/**
 * Test str_sub
 */
void test_str_sub(void){
   CU_ASSERT_PTR_NOT_NULL(str_sub(str,1,5));
   CU_ASSERT_PTR_NOT_NULL(str_sub(str,0,5));
   CU_ASSERT_PTR_NULL(str_sub(str,1,199));
   CU_ASSERT_PTR_NULL(str_sub(str,-1,5));
}

void test_str_combine(void){
   char * str4 = "Je suis CUnit. Je t'aime";

   CU_ASSERT_PTR_NULL(str_combine(NULL,NULL));

   CU_ASSERT_STRING_EQUAL(str4,str_combine(str,str0));
   CU_ASSERT_STRING_EQUAL(str,str_combine(str,NULL));
   CU_ASSERT_STRING_EQUAL(str0,str_combine(NULL,str0));
}


void test_str_get_indexes(void){
   int * array = str_get_indexes(str,'i');
   int * array2 = str_get_indexes(str,'w');
   CU_ASSERT_EQUAL(5,array[0]);
   CU_ASSERT_EQUAL(11,array[1]);
   CU_ASSERT_EQUAL(-1,array[2]);
   CU_ASSERT_EQUAL(-1,array2[0]);
   CU_ASSERT_PTR_NULL(str_get_indexes(NULL,'c'));
}

void test_str_replace_all_char(void){
   CU_ASSERT_STRING_EQUAL(str_replace_all_char(str,'J','Z'),"Ze suis CUnit.");
   CU_ASSERT_STRING_EQUAL(str_replace_all_char(str,'Z','a'),str);
   CU_ASSERT_PTR_NULL(str_replace_all_char(NULL,'Z','a'));
}

void test_str_print_array(void){
   char * array[5];
   array[0]="Je";
   array[1]=" suis";
   array[2]=" CUnit";
   array[3]=". ";
   array[4]=" Bonjour!";
   array[5]=" Enchantez";
   printf("\n");
   str_print_array(array);
   printf("\n");
}

void test_str_split(void){
   CU_ASSERT_PTR_NULL(str_split(NULL,"suis"));
   CU_ASSERT_PTR_NULL(str_split(str,NULL));
   CU_ASSERT_PTR_NULL(str_split(NULL,NULL));

   char ** array = str_split(str,"hola");
   CU_ASSERT_STRING_EQUAL(array[0],str);
   CU_ASSERT_PTR_NULL(array[1]);

   char ** array2 = str_split(str,"suis");
   CU_ASSERT_STRING_EQUAL(array2[0],"Je ");
   CU_ASSERT_STRING_EQUAL(array2[1]," CUnit.");
   CU_ASSERT_PTR_NULL(array[2]);
}

void test_cmd_run_command(void){
   CU_ASSERT_PTR_NOT_NULL(cmd_run_command("ls -ll"));
   CU_ASSERT_PTR_NOT_NULL(cmd_run_command("uname -a"));
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   // TEST STRING FUNCTIONS
   CU_TestInfo test_strings[]={
      {"test of str_compare()", test_str_compare},
      {"test of str_index", test_str_index},
      {"test of str_sub", test_str_sub},
      {"test of str_combine", test_str_combine},
      {"test of str_get_indexes", test_str_get_indexes},
      {"test of str_replace_all_char", test_str_replace_all_char},
      {"test of str_print_array", test_str_print_array},
      {"test of str_split", test_str_split},
      CU_TEST_INFO_NULL,
   };

   // TEST COMMAND FUNCTIONS
   CU_TestInfo test_cmds[]={
      {"test of cmd_run_command()", test_cmd_run_command},
      CU_TEST_INFO_NULL,
   };

   // SUITES
   CU_SuiteInfo suites[]={
      {"c-easy: working with command", init_suite1, clean_suite1,test_cmds},
      {"c-easy: working with string", init_suite1, clean_suite1,test_strings},
      CU_SUITE_INFO_NULL,
   };

   // REGISTER SUITES
   CU_ErrorCode error = CU_register_suites(suites);
   if(error!=CUE_SUCCESS){
      printf("%d\n", error);
      CU_cleanup_registry();
      return CU_get_error();
   }else{
       /* Run all tests using the CUnit Basic interface */
      CU_basic_set_mode(CU_BRM_VERBOSE);
      CU_basic_run_tests();
      CU_cleanup_registry();
      return CU_get_error();
   }
}