/*
 * LinkedList.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 20102
 */

#include "LinkedList.h"
SStudent * gpfirst=NULL;
SStudent * gplast=NULL;

void add_student(){
	SStudent* pnewstudent;
	unsigned char temp_text[40];
	if(gpfirst==NULL){
		pnewstudent =(SStudent*)(malloc(sizeof(SStudent)));
		gpfirst=pnewstudent;
	}
	else{
		gplast=gpfirst;
		while(gplast->pnextstudent!=NULL){
			gplast=gplast->pnextstudent;
		}
		pnewstudent=(SStudent*)(malloc(sizeof(SStudent)));
		gplast->pnextstudent= pnewstudent;
	}
	//adding student data
	Dprintf("\n Enter student id:");
	gets(temp_text);
	pnewstudent->student.id=atoi(temp_text);


	Dprintf("\n Enter student height:");
	gets(temp_text);
	pnewstudent->student.height=atof(temp_text);

	Dprintf("\n Enter student full name:");
	gets(pnewstudent->student.name);



	//set nextstudent to null
	pnewstudent->pnextstudent=NULL;
}
int delete_student(){
	unsigned char temp_text[20];
	unsigned int  selected_id;
	// read id
	Dprintf("\nEnter id number:");
	gets(temp_text);
	selected_id=atoi(temp_text);
	if(gpfirst){
		SStudent* PselectdStudent=gpfirst;
		SStudent* PpreviousStudent='\0';
		//loop in all record
		while(PselectdStudent)
		{
			// compare each id with slected id
			if(PselectdStudent->student.id==selected_id)
			{
				if(PpreviousStudent)// first is selected not
				{

					PpreviousStudent->pnextstudent=PselectdStudent->pnextstudent;
				}
				else // selected is == id
				{
					gpfirst=PselectdStudent->pnextstudent;

				}
				free(PselectdStudent);
				return 1;
			}
			PpreviousStudent=PselectdStudent;
			PselectdStudent=PselectdStudent->pnextstudent;
		}


	}
	return 0;
}
void print_student(){
	SStudent* pcurentstudent;
	uint16_t counter=0;
	if(gpfirst==NULL){
		Dprintf("Empty");
	}
	else{
		pcurentstudent=gpfirst;
		while(pcurentstudent){
			printf("\n RECORD student %d ",(counter+1));
			Dprintf("\n student id %d",pcurentstudent->student.id);
			Dprintf("\n student full name  %s",pcurentstudent->student.name);
			Dprintf("\n student id %f",pcurentstudent->student.height);
			Dprintf("\n===============\n");
			counter ++;
			pcurentstudent=pcurentstudent->pnextstudent;
		}
	}
}
void delete_all(){
	SStudent* pcurentstudent;

	int counter;
	if(gpfirst==NULL){
		Dprintf("Empty");
	}
	else{
		pcurentstudent=gpfirst;
		while(pcurentstudent){
			SStudent* ptempstudent=pcurentstudent;
			pcurentstudent=pcurentstudent->pnextstudent;
			free(ptempstudent);
		}
		gpfirst=NULL;
	}
}
int count_elements()
{

	//check is empty
	if(gpfirst==NULL)
		Dprintf("empty");
	uint8_t count=0;
	SStudent* pcurrentelement=gpfirst;
	while(pcurrentelement)
	{
		pcurrentelement=pcurrentelement->pnextstudent;
		count++;

	}
	Dprintf("\n number of student is :%d",count);
	return count;
}
void reverse_student()
{
	SStudent* pcurrentStudent=gpfirst;
	SStudent* pnext=gpfirst;
	SStudent* pprevious='\0';
	while(pcurrentStudent){
		pnext=pcurrentStudent->pnextstudent;
		pcurrentStudent->pnextstudent=pprevious;
		pprevious=pcurrentStudent;
		pcurrentStudent=pnext;

	}
	gpfirst=pprevious;
	Dprintf("reverse is done\n");

}

int mid_student()
{
	unsigned int length=count_elements();
	//if length is odd
	if(length==1||length==2){
		Dprintf("no middle student");
		return 0;}
	else if(length%2!=0)
	{
		length=(length/2);
		get_Nth_node(length);
	}
	// if length is even
	else
	{
		Dprintf("\nlinked list is even\n");
		length=(length/2);
		get_Nth_node(length-1);
		get_Nth_node(length);
	}
}

int get_Nth_node(int index)
{
	unsigned int count=0;

	SStudent* pcurrent_index=gpfirst;
	//loop while list
	while(pcurrent_index!='\0')
	{
		if(count==index){
			Dprintf("the node at index %d is %d\n",count,pcurrent_index->student.id);
			return 0;
		}
		else{
			pcurrent_index=pcurrent_index->pnextstudent;
			count ++;
			continue;

		}

	}
	Dprintf("\n index is not Exist\n");
	return 0;
}
// Nth node from the end
int get_Nth_node_end(int index){
	unsigned int length=count_elements();
	unsigned int len=(length-index);
	unsigned int count=0;
	SStudent* pcurrent_index=gpfirst;
	//loop while list
	while(pcurrent_index!='\0')
	{
		if(count==len){
			Dprintf("the node at index %d is %d\n",count,pcurrent_index->student.id);
			return 0;
		}
		else{
			pcurrent_index=pcurrent_index->pnextstudent;
			count ++;
			continue;
		}

	}
	Dprintf("\n index is not Exist\n");
	return 0;
}
