///*
// * main.c
// *
// *  Created on: 10/11/2022
// *      Author: MO_ALSHREIF
// */
#include "LinkedList.h"

#define Dprintf(...)			{fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

int main()
{
	unsigned char temp_text[40],count;
	while(1)
	{
		Dprintf("\n ======================");
		Dprintf("\n Enter option :");
		Dprintf("\n 1- add student");
		Dprintf("\n 2- print student");
		Dprintf("\n 3- delete student");
		Dprintf("\n 4- delete all student");
		Dprintf("\n 5- number of students");
		Dprintf("\n 6- gets Nth node");
		Dprintf("\n 7- gets Nth node from end ");
		Dprintf("\n 8- gets middle student ");
		Dprintf("\n 9- reverse student ");
		Dprintf("\n ====================== \n ");
		gets(temp_text);
		switch(atoi(temp_text)){
		case 1:
		add_student();
			break;
		case 2:
			print_student();
			break;
		case 3:
			delete_student();
			break;
		case 4:
			delete_all();
			break;
		case 5:
			count=count_elements();
			Dprintf("\n number of student =%d\n",count);
			break;
		case 6:
			Dprintf("\nEnter index:");
			gets(temp_text);
			get_Nth_node(atoi(temp_text));
			break;
		case 7:
			Dprintf("\nEnter index:");
			gets(temp_text);
			get_Nth_node_end(atoi(temp_text));
			break;
		case 8:
			mid_student();
			break;
		case 9:
		 reverse_student();
			break;
		default:
			Dprintf("no option");

		}
	}
	return 0;
}
