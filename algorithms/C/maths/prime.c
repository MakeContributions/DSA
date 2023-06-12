#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

/**********************************************
THIS CODE USES CUNIT TO PROVIDE CODE COVERAGE.
PLEASE DOWNLOAD THE CUNIT HEADER FILES BEFORE
COMPILING
***********************************************/

int prime_check(int i)
{
	float half = i/2;
	
	if( i <= 1 ) return 1;
	
	for(int n = 2; n <= half; n++)
	{
		if( i % n == 0 ) return 1;
	}
	
	return 0;
}


// Everything below sets up tests or tests the prime_check function above
int init_suite_success(void) { return 0; }
int init_suite_failure(void) { return -1; }
int clean_suite_success(void) { return 0; }
int clean_suite_failure(void) { return -1; }

// Test an invalid, positive number
void testInvalidPrime(void)
{
	int num = 9;
	CU_ASSERT_EQUAL(1, prime_check(num));
}

// Test a valid prime number
void testValidPrime(void)
{
	int num = 13;
	CU_ASSERT_EQUAL(0, prime_check(num));
}

// Test a negative integer
void testNegativePrime(void)
{
	int num = -13;
	CU_ASSERT_EQUAL(1, prime_check(num));
}


int main()
{
 CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_success", init_suite_success, clean_suite_success);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "successful_testInvalidPrime", testInvalidPrime)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   
   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "successful_testValidPrime", testValidPrime)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   
   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "successful_testNegativePrime", testNegativePrime)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");

   /* Run all tests using the automated interface */
   CU_automated_run_tests();
   CU_list_tests_to_file();

   /* Run all tests using the console interface */
   CU_console_run_tests();

   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}






