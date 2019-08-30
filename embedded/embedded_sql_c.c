/* Processed by ecpg (10.10) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "prog1.pgc"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#line 1 "C:/Program Files/PostgreSQL/10/include/SQLCA.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif							/* __CYGWIN__ */
#endif							/* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern "C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.             */

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 6 "prog1.pgc"
  
int main()
{
    /* exec sql begin declare section */  
                /* Employee ID (from user)         */  
          /* Retrieved salesperson name      */  
	   
	   
	   
	   
	
#line 10 "prog1.pgc"
 int id ;
 
#line 11 "prog1.pgc"
 char name [ 10 ] ;
 
#line 12 "prog1.pgc"
 char firstname [ 10 ] ;
 
#line 13 "prog1.pgc"
 char lastname [ 10 ] ;
 
#line 14 "prog1.pgc"
 char email [ 30 ] ;
 
#line 15 "prog1.pgc"
 char username [ 30 ] ;
/* exec sql end declare section */
#line 16 "prog1.pgc"
  

    { ECPGconnect(__LINE__, 0, "tcp:postgresql://localhost:5432/Ecommerce" , "postgres" , "letmein99" , NULL, 0); }
#line 18 "prog1.pgc"


	/* Set up error processing */  
	/* exec sql whenever sqlerror  goto  query_error ; */
#line 21 "prog1.pgc"
  
	/* exec sql whenever not found  goto  bad_number ; */
#line 22 "prog1.pgc"
  

	/* declare Ecommerce_info cursor for select U . firstname , U . lastname , U . email , U . id from \"user\" as U */
#line 25 "prog1.pgc"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare Ecommerce_info cursor for select U . firstname , U . lastname , U . email , U . id from \"user\" as U", ECPGt_EOIT, ECPGt_EORT);
#line 27 "prog1.pgc"

if (sqlca.sqlcode < 0) goto query_error;}
#line 27 "prog1.pgc"


	/* exec sql whenever not found  break ; */
#line 29 "prog1.pgc"


	printf("\t\t\t\t************************\n");                                           
	printf("\t\t\t\t*      List of User    *\n");                                           
	printf("\t\t\t\t************************\n");   

	printf("%-5s\t\t %-10s\t\t %10s\t\t %20s\n\n","Id","First Name", "Last Name", "Email");

	while (SQLCODE==0)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch in Ecommerce_info", ECPGt_EOIT, 
	ECPGt_char,(firstname),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(lastname),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(email),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 39 "prog1.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;
#line 39 "prog1.pgc"

if (sqlca.sqlcode < 0) goto query_error;}
#line 39 "prog1.pgc"

		
		printf("%-5d\t\t %-10s\t\t %10s\t\t %20s\n\n",id,firstname,lastname,email);

	}

	
	printf ("\n Enter email to search: ");  
	scanf_s("%s", &username, 30);

	ECPGset_var( 0, ( username ), __LINE__);\
 /* declare user_detail cursor for select U . firstname , U . lastname , U . email , U . id from \"user\" as U where email = $1  */
#line 51 "prog1.pgc"
  ;

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare user_detail cursor for select U . firstname , U . lastname , U . email , U . id from \"user\" as U where email = $1 ", 
	ECPGt_char,(username),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 53 "prog1.pgc"

if (sqlca.sqlcode < 0) goto query_error;}
#line 53 "prog1.pgc"


	/* exec sql whenever not found  break ; */
#line 55 "prog1.pgc"



	printf("\n\n\t\t\t\t************************\n");                                           
	printf("\t\t\t\t*      User Details    *\n");                                           
	printf("\t\t\t\t************************\n");   

	printf("%-5s\t\t %-10s\t\t %10s\t\t %20s\n\n","Id","First Name", "Last Name", "Email");

	while (SQLCODE==0)
	{
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch in user_detail", ECPGt_EOIT, 
	ECPGt_char,(firstname),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(lastname),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(email),(long)30,(long)1,(30)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 66 "prog1.pgc"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;
#line 66 "prog1.pgc"

if (sqlca.sqlcode < 0) goto query_error;}
#line 66 "prog1.pgc"

		
		printf("%-5d\t\t %-10s\t\t %10s\t\t %20s\n\n",id,firstname,lastname,email);

	}

	printf("\n\n");

    { ECPGdisconnect(__LINE__, "CURRENT");
#line 74 "prog1.pgc"

if (sqlca.sqlcode < 0) goto query_error;}
#line 74 "prog1.pgc"


    query_error:  
	printf("SQLCODE    = %d\n",sqlca.sqlcode);                                      
    printf("SQLSTATE    = %5s",sqlca.sqlstate);  
	return 0; 

	bad_number:  
	printf ("Invalid order number.\n");  
	return 0;

    return 0;
}