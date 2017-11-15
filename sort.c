/************************************
作用：练习常见排序算法
************************************/

#include <stdio.h>
#include <malloc.h>


//交换两个元素的值
void swap(int *a,int *b) { //a不能等于b
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void printarry(int arry[],int n) {
  int i;
  for(i=0;i<n;i++) putchar(arry[i]+48),putchar(' ');
  putchar('\n');
}
//插入排序，从小到大
void insert_sort(int arry[] , int n) {
  int i,j,temp;
  for(i=1;i < n;i++) {
    temp = arry[i];
    for(j=i-1;j>=0;j--) //[0,i-1]已排好序，可使用二分法和i比较来快速确定i的位置
      if(arry[j] > temp) arry[j+1] = arry[j];
      else break;
    if(j+1 != i) arry[j+1] = temp; //if判断可以去掉
  }
}

//冒泡排序
void bubble_sort(int arry[] , int n) {
  int i,j;
  for(j=n-1;j>0;j--)  //可以改写成双向的
    for(i=0;i < j;i++)
      if(arry[i] > arry[i+1]) swap(arry+i,arry+i+1);
}

//选择排序
void select_sort(int arry[] , int n) {
  int i,j,min;
  for(i=0;i<n-1;i++) {
    min = i;
    for(j=i+1;j<n;j++)
      if(arry[j] < arry[min]) min=j;
    if(min != i) swap(arry+i,arry+min);
  }
}

//希尔排序，简明版
void shell_sort(int arry[],int n) {
  int gap = n/2;
  int i,j,k,temp;
  for(gap=n>>1;gap>0;gap>>=1)
    for(i=0;i<gap;i++) //i为各组首元素
      for(j=i+gap;j<n;j+=gap) { //j为当前分组准备插入的元素
        temp = arry[j] ; 
        for(k=j-gap;k>=0 && arry[k]>temp;k-=gap) 
          arry[k+gap] = arry[k];
        arry[k+gap] = temp;
      }
}

//递归版归并排序
void recursion_merge_sort(int arry[],int n) {
  if(n==1) return ;
  int left = n>>1;
  int right = n-left;
  recursion_merge_sort(arry,left);
  recursion_merge_sort(arry+left,right);
  int *larry = malloc(sizeof(int)*left);
  int *rarry = malloc(sizeof(int)*right);
  int i,j,k;
  for(i=0;i<left;i++) larry[i] = arry[i];
  for(i=0;i<right;i++) rarry[i] = arry[left+i];
  for(i=0,j=0,k=0;;i++) {
    if(larry[j]>rarry[k]) arry[i] = rarry[k++];
    else arry[i] = larry[j++];
    if(j==left || k==right) break;
  }
  while(j < left) arry[++i] = larry[j++];
  while(k < right) arry[++i] = rarry[k++];
}


int main()
{
  int arry[8] = {1,2,6,1,5,4,8,7};
  //insert_sort(arry,8);
  //bubble_sort(arry,8);
  //select_sort(arry,8);
  shell_sort(arry,8);
  //recursion_merge_sort(arry,8);
  printarry(arry,8);
}
