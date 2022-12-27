#include <stdio.h>
int main(){
int n;
scanf("%d", &n);
int A[n];
int i;
i = 0;
while(i<n){
scanf("%d", &A[i]);
i++;
}
int Dis[n];
int t;
scanf("%d", &t);
int c = 0;
int flag;
int j;
i = 0;
while(i<n){
flag = 0;
j = 0;
while(j<c){
if(Dis[j]==A[i]){
flag = 1;
break;
}
j++;
}
switch(flag){
case 0: Dis[c] = A[i];
c++;
break;
default : break;

}
i++;
}
int Fr[c];
i = 0;
while(i<c){
Fr[i] = 0;
i++;
}
i = 0;
while(i<n){
j = 0;
while(j<c){
if(A[i]==Dis[j]){
Fr[j]++;
}
j++;
}
i++;
}
int Sorfr[c];
i = 0;
while(i<c){
Sorfr[i] = Fr[i];
i++;
}
int k;
i = 1;
while(i<c){
k = Sorfr[i];
for(j = i-1; j>=0 && Sorfr[j]<=k; j--){

Sorfr[j+1] = Sorfr[j];
}
Sorfr[j+1] = k;
i++;
}
int SorDis[c];
int p = 0;
i = 0;
while(i<c){
j = 0;
while(j<n){
if(Sorfr[i]==Fr[j]){
SorDis[p] = Dis[j];
p++;
}
j++;
}
i++;
}
i = 0;
while(i<t){
printf("%d ", SorDis[i]);
i++;
}
printf("\n");
}