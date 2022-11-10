/*
 * LinkedList.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: 20102
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include<stdint.h>

#define Dprintf(...)			{fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}
//user data
typedef struct{
	unsigned char name[40];
	unsigned int id;
	float height;
}sdata;

// node data
typedef struct{
	sdata student;
	struct SStudent* pnextstudent;
}SStudent;



void add_student();
int delete_student();
void print_student();
void delete_all();
void reverse_student();
int count_elements();
int get_Nth_node_end(int index);
int get_Nth_node(int index);
int mid_student();

#endif /* LINKEDLIST_H_ */
