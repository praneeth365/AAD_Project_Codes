#include<bits/stdc++.h>
using namespace std;
int subset_XOR(int arr[], int size, int match){
   int highest = arr[0];
   for (int i = 1; i < size; i++){
      if(arr[i] > highest){
         highest = arr[i];
      }
   }
   int temp = (1 << (int)(log2(highest) + 1) ) − 1;
   if( match > temp){
      return 0;
   }
   int arr_2[size+1][temp+1];
   for (int i = 0; i<= size; i++){
      for (int j = 0; j<= temp; j++){
         arr_2[i][j] = 0;
      }
   }
   arr_2[0][0] = 1;
   for (int i=1; i<=size; i++){
      for (int j=0; j<=temp; j++){
         int temp_2 = arr_2[i−1][j ^ arr[i−1]];
         arr_2[i][j] = arr_2[i−1][j] + temp_2;
      }
   }
   return arr_2[size][match];
}
int main(){
   int arr[] = {4, 2, 8, 10, 3, 4, 4};
   int match = 2;
   int size = sizeof(arr)/sizeof(arr[0]);
   cout<<"Count of number of subsets having a particular XOR value are: "<<subset_XOR(arr, size, match);
   return 0;
}
