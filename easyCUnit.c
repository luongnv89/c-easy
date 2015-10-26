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
      return 0;
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
      return 0;
}

/**
 * Test str_compare
 */
void test_str_compare(void){
   CU_ASSERT_EQUAL(0,str_compare(NULL,"Je"));
   CU_ASSERT_EQUAL(0,str_compare("Je",NULL));
   CU_ASSERT_EQUAL(0,str_compare("Je","suis"));
   CU_ASSERT_EQUAL(0,str_compare(str,str0));

   CU_ASSERT_EQUAL(1,str_compare(NULL,NULL));
   CU_ASSERT_EQUAL(1,str_compare(str,str));
   CU_ASSERT_EQUAL(1,str_compare(str0,str0));
}

/**
 * Test str_index
 */
void test_str_index(void){
   CU_ASSERT_EQUAL(-1,str_index(NULL,NULL));
   CU_ASSERT_EQUAL(-1,str_index(str,NULL));
   CU_ASSERT_EQUAL(-1,str_index(NULL,"suis"));
   CU_ASSERT_EQUAL(-1,str_index(str,"Paris"));

   CU_ASSERT_EQUAL(0,str_index(str,"Je"));
   CU_ASSERT_EQUAL(3,str_index(str,"suis"));
   CU_ASSERT_EQUAL(8,str_index(str,"CUnit."));
}

/**
 * Test str_sub
 */
void test_str_sub(void){
   CU_ASSERT_PTR_NULL(str_sub(NULL,1,3));
   CU_ASSERT_PTR_NULL(str_sub(str,-1,5));
   CU_ASSERT_PTR_NULL(str_sub(str,1,199));
   CU_ASSERT_PTR_NULL(str_sub(str,3,3));
   CU_ASSERT_PTR_NULL(str_sub(str,4,3));

   CU_ASSERT_STRING_EQUAL(str_sub(str,1,5),"e sui");   
   CU_ASSERT_STRING_EQUAL(str_sub(str,0,5),"Je sui");
   CU_ASSERT_STRING_EQUAL(str_sub(str,2,strlen(str)-1)," suis CUnit.");
   CU_ASSERT_STRING_EQUAL(str_sub(str,0,strlen(str)-1),"Je suis CUnit.");
}

void test_str_combine(void){

   CU_ASSERT_PTR_NULL(str_combine(NULL,NULL));

   CU_ASSERT_STRING_EQUAL(str,str_combine(str,NULL));
   CU_ASSERT_STRING_EQUAL(str0,str_combine(NULL,str0));
   CU_ASSERT_STRING_EQUAL("Je suis CUnit. Je t'aime",str_combine(str,str0));
   CU_ASSERT_STRING_EQUAL(" Je t'aimeJe suis CUnit.",str_combine(str0,str));
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

   char ** array4 = str_split(str,"CUnit.");
   CU_ASSERT_STRING_EQUAL(array4[0],"Je suis ");
   CU_ASSERT_PTR_NULL(array4[1]);


   char ** array3 = str_split(str,"Je");
   CU_ASSERT_STRING_EQUAL(array3[0]," suis CUnit.");
   CU_ASSERT_PTR_NULL(array3[1]);

   char ** array_test1 = str_split("Je Je Je suis CUnit. Je t'aime.","Je ");
   CU_ASSERT_STRING_EQUAL(array_test1[0],"suis CUnit. ");
   CU_ASSERT_STRING_EQUAL(array_test1[1],"t'aime.");
   CU_ASSERT_PTR_NULL(array_test1[2]);

   char ** array_test2 = str_split("Je suis CUnit. C'est CUnit.CUnit.","CUnit.");
   CU_ASSERT_STRING_EQUAL(array_test2[0],"Je suis ");
   CU_ASSERT_STRING_EQUAL(array_test2[1]," C'est ");
   CU_ASSERT_PTR_NULL(array_test2[2]);
}

void test_str_get_indexes(void){
   
   CU_ASSERT_PTR_NULL(str_get_indexes(NULL,NULL));
   CU_ASSERT_PTR_NULL(str_get_indexes(str,NULL));
   CU_ASSERT_PTR_NULL(str_get_indexes(NULL,"suis"));
   CU_ASSERT_PTR_NULL(str_get_indexes(str,"Paris"));
   // Je suis CUnit.
   CU_ASSERT_EQUAL(str_get_indexes(str,"s")[0],3);
   CU_ASSERT_EQUAL(str_get_indexes(str,"s")[1],6);
   CU_ASSERT_EQUAL(str_get_indexes(str,"s")[2],-1);

   CU_ASSERT_EQUAL(str_get_indexes(str,"J")[0],0);
   CU_ASSERT_EQUAL(str_get_indexes(str,"J")[1],-1);

   CU_ASSERT_EQUAL(str_get_indexes(str,"CUnit.")[0],8);
   CU_ASSERT_EQUAL(str_get_indexes(str,"CUnit.")[1],-1);
}


void test_str_replace(void){
   CU_ASSERT_PTR_NULL(str_replace(NULL,"je","suis"));

   CU_ASSERT_STRING_EQUAL(str_replace(str,"Je",NULL),str);
   CU_ASSERT_STRING_EQUAL(str_replace(str,NULL,"Paris"),str);
   CU_ASSERT_STRING_EQUAL(str_replace(str,"Paris","suis"),str);

   CU_ASSERT_STRING_EQUAL(str_replace(str,"suis","sera"),"Je sera CUnit.");
   CU_ASSERT_STRING_EQUAL(str_replace(str,"Je suis","Tu es"),"Tu es CUnit.");
   CU_ASSERT_STRING_EQUAL(str_replace(str,"CUnit.","Montimage."),"Je suis Montimage.");
   CU_ASSERT_STRING_EQUAL(str_replace(str,"s","z"),"Je zuiz CUnit.");
}

void test_str_subvalue(void){
   //NULL return
   CU_ASSERT_PTR_NULL(str_subvalue(NULL,"je","suis"));
   CU_ASSERT_PTR_NULL(str_subvalue(str,"Paris","suis"));
   CU_ASSERT_PTR_NULL(str_subvalue(str,"Je","aux"));
   CU_ASSERT_PTR_NULL(str_subvalue(str,"suis","Je"));
   CU_ASSERT_PTR_NULL(str_subvalue(str,NULL,NULL));
   CU_ASSERT_PTR_NULL(str_subvalue(str,"Je ","suis"));
   CU_ASSERT_PTR_NULL(str_subvalue(str,"Je s","suis"));


   CU_ASSERT_STRING_EQUAL(str_subvalue(str,"Je",NULL)," suis CUnit.");
   CU_ASSERT_STRING_EQUAL(str_subvalue(str,NULL,"CUnit."),"Je suis ");
   CU_ASSERT_STRING_EQUAL(str_subvalue(str,"Je","CUnit.")," suis ");
}

void test_str_add_string_to_array(void){
   char ** array;
   array = NULL;

   CU_ASSERT_PTR_NULL(str_add_string_to_array(array,NULL));
   // For the first element, need to assign the address for array pointer.
   array = str_add_string_to_array(array,str);
   CU_ASSERT_STRING_EQUAL(array[0],str);
   CU_ASSERT_PTR_NULL(array[1]);

   CU_ASSERT_STRING_EQUAL((str_add_string_to_array(array,NULL))[0],str);
   CU_ASSERT_PTR_NULL((str_add_string_to_array(array,NULL))[1]);

   CU_ASSERT_STRING_EQUAL((str_add_string_to_array(array,str0))[0],str);
   CU_ASSERT_STRING_EQUAL(array[1],str0);
   CU_ASSERT_PTR_NULL(array[2]);

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
      {"test of str_compare", test_str_compare},
      {"test of str_index", test_str_index},
      {"test of str_sub", test_str_sub},
      {"test of str_combine", test_str_combine},
      {"test of str_get_indexes", test_str_get_indexes},
      {"test of str_print_array", test_str_print_array},
      {"test of str_split", test_str_split},
      {"test of str_subvalue", test_str_subvalue},
      {"test of str_replace", test_str_replace},
      {"test of str_add_string_to_array", test_str_add_string_to_array},
      CU_TEST_INFO_NULL,
   };

   // TEST COMMAND FUNCTIONS
   CU_TestInfo test_cmds[]={
      {"test of cmd_run_command", test_cmd_run_command},
      CU_TEST_INFO_NULL,
   };

   // SUITES
   CU_SuiteInfo suites[]={
      {"c-easy: working with command", NULL, NULL,test_cmds},
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