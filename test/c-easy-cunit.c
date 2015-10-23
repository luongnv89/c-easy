/*
 *  CUnit unit test.
 *  
 */

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "easy.h"

/* Pointer to the file used by the tests. */
// static FILE* temp_file = NULL;

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
   CU_ASSERT(1==str_compare(str1,str1));
   CU_ASSERT(1==str_compare(str2,str2));
   CU_ASSERT(0==str_compare(str1,str2));
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

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test of str_compare()", test_str_compare)) ||
       (NULL == CU_add_test(pSuite, "test of str_index", test_str_index)))
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

