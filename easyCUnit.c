/*
 *  CUnit unit test.
 *  
 */

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
// #include "CUnit/CUnit.h"
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

void test_cmd_run_command(void){
   char *ret;
   ret = cmd_run_command("ls -ll");
   printf("%s\n", ret);
   CU_ASSERT_PTR_NOT_NULL(ret);
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite_string = NULL;
   CU_pSuite pSuite_cmd = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite_string = CU_add_suite("c-easy: working with string", init_suite1, clean_suite1);
   if (NULL == pSuite_string) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   pSuite_cmd = CU_add_suite("c-easy: working with command", init_suite1, clean_suite1);
   if (NULL == pSuite_cmd) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */   
   if ((NULL == CU_add_test(pSuite_string, "test of str_compare()", test_str_compare))||
       (NULL == CU_add_test(pSuite_string, "test of str_index", test_str_index))||
       (NULL == CU_add_test(pSuite_string, "test of str_sub", test_str_sub))||
       (NULL == CU_add_test(pSuite_string, "test of str_combine", test_str_combine)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

     /* add the tests to the suite */   
   if (NULL == CU_add_test(pSuite_cmd, "test of cmd_run_command()", test_cmd_run_command))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

