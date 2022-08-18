/*
 * Sorting_Algorithms.c
 *
 *  Created on: Aug 18, 2022
 *      Author: omar
 */

#include "Sorting_Algorithms.h"

void BubbleSort(int arr[],int size)
{
	int i,j,temp;
	for( i = 0; i < size; i++)
	{
		for( j = 0; j < size - 1; j++)
		{
			if( arr[j] > arr[ j + 1 ])
			{
				temp = arr[j];
				arr[j] = arr[ j + 1 ];
				arr[ j + 1] = temp;
			}
		}
	}
}

void SelectionSort(int arr[],int size)
{
	int i,j,temp,min;
	for( i = 0; i < size; i++)
	{
		min = i;
		for( j = i; j < size ; j++)
		{
			if( arr[min] > arr[j])
			{
				min = j;
			}
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

void InsertionSort(int arr[],int size)
{
	int i,j,temp,min;
	for( i = 1; i < size; i++)
	{
		min = i;
		for( j = i-1; j >= 0 ; j--)
		{
			if( arr[min] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[ min];
				arr[ min] = temp;
				min = j;
			}
			else
			{
				break;
			}
		}
	}
}











