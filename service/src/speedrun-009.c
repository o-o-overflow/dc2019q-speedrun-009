#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

/* 

   Compilation:
   gcc -o speedrun-009 -O0 -static -pie -Wno-format-security speedrun-009.c && strip speedrun-009

   Also need to take the glibc version to give to folks.

 */

void say_hello()
{
   printf("<insert something clever>\n");
}

void print_menu()
{
   printf("Choose wisely.\n");
   printf("1, 2, or 3\n");
}

void what_do_they_say()
{
   char buf[1024];
   char line[200];
   char choice;
   ssize_t result;

   while (1)
   {
	  print_menu();
	  result = read(0, &choice, 1);

	  if (result != 1)
	  {
		 return;
	  }
	  if (choice == '1')
	  {
		 read(0, buf, 1500);
	  }
	  else if (choice == '2')
	  {
		 read(0, &line, 200);
		 line[199] = '\0';
		 if (strstr(line, "n") == NULL)
		 {
			printf("Is that it \"");
			printf(line);
			printf("\"?\n");
		 }
		 else
		 {
			printf("nope\n");
		 }
	  }
	  else
	  {
		 return;
	  }
   }
}

void say_goodbye()
{
   printf("<ending message>\n");
}


int main(int argc, char** argv)
{
   setvbuf(stdout, NULL, _IONBF, 0);

   if (getenv("DEBUG") == NULL)
   {
	  alarm(5);
   }
   
   say_hello();
   what_do_they_say();
   say_goodbye();
   exit(0);
}
