/*
 * Searching_Algorithms.c
 *
 *  Created on: Aug 17, 2022
 *      Author: omar
 */

#include "Searching_Algorithms.h"

int LinearSearch(int arr[],int size,int data)
{
	int i;
	for ( i = 0 ; i < size ; i++)
	{
		if( arr[i] == data)
			return i;
	}
	return -1;
}
int BinarySearch(int arr[],int size,int data)
{
	if(data < arr[0] || data > arr[size - 1])
	{
		return -1;
	}
	int start = 0,end = size;
	int mid = (start + end) /2;
	while( start != end )
	{
		if( arr[mid] == data)
		{
			return mid;
		}
		if( arr[mid] > data)
		{
			end = mid - 1;
			if(end < 0)
				break;
		}
		else
		{
			start = mid + 1;
		}
		mid = (start + end) /2;
		//printf("mid: %d\n",mid);
	}
	if( arr[mid] == data)
	{
		return mid;
	}
	return -1;
}
int JumpSearch(int arr[],int size,int data)
{
	if(data < arr[0] || data > arr[size - 1])
	{
		return -1;
	}
	int jump = floor(sqrt(size)) - 1;
	int i = 0,j;
	printf("jump : %d\n",jump);

	while( i < size)
	{
		if( arr[i] == data)
		{
			return i;
		}
		if( arr[i] > data)
		{
			for( j = i; j > i - jump; j--)
			{
				if( arr[j] == data)
				{
					return j;
				}
			}
		}
		i = i + jump;
		if(i > size)
		{
			for( j = size - 1; j > i - jump; j--)
			{
				if( arr[j] == data)
				{
					return j;
				}
			}
		}
	}
	return -1;
}

