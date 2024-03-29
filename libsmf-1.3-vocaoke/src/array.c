/*
Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.  This file is offered as-is,
without any warranty.
*/

#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

array* array_new()
{
	array* a=malloc(sizeof(array));
	a->len=0;
	a->size=16;
	a->data=malloc(sizeof(void*)*a->size);
	return a;
	
}
void array_add(array* a,void* d)
{
	if(a->len==a->size)
	{
		a->size*=2;
		a->data=realloc(a->data,sizeof(void*)*a->size);	
	}
	a->data[a->len]=d;
	a->len++;
}
void array_add_middle(array* a,void* d,int i)
{
	assert(i<a->len);
	assert(i>=0);
	if(a->len==a->size)
	{
		a->size*=2;
		a->data=realloc(a->data,sizeof(void*)*a->size);	
	}
	
	a->len++;
	
	for(int j=a->len-1;j>i;j--)
		a->data[j]=a->data[j-1];
	
	a->data[i]=d;
	
	//using http://code.google.com/p/cocotron/source/browse/Foundation/NSArray/NSMutableArray_concrete.m as a reference	
	
}
void* array_index(array* a,int i)
{
	return a->data[i];
}
void array_free(array* a,bool f)
{
	if(f) free(a->data);
	free(a);
}
void array_remove(array* a,void* v)
{
	bool found=0;
	for(int i=0;i<a->len;i++)
	{
		if(a->data[i]==v) found=1;
		if(found && i!=a->len-1) a->data[i]=a->data[i+1];
	}
	if(found) a->len--;
}
void array_remove_index(array* a,int i)
{
	for(int j=i;i<a->len-1;j++)
	{
		a->data[j]=a->data[j+1];
	}
	a->len--;
}

//FIXME varargs
void g_error(char* msg)
{
	printf(msg);
	exit(1);
}

void g_warning(char* msg)
{
	printf(msg);
}

void g_message(char* msg)
{
	printf(msg);
}

void g_debug()
{
	printf("DEBUG\n");
	exit(2);
}
