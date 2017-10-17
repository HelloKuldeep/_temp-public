#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y){ int t=*x; *x=*y; *y=t; }
class minHeap{
	int *harr; int cap; int hs;	//cap-capacity hs-heap_size *harr-pointer to heap array
	public:
		minHeap(int c);
		void minHeapify(int);
		int parent(int i){ return (i-1)/2; } int left(int i){ return (i*2+1); } int right(int i){ return (i*2+2); }
		int extractMin();
		void decreaseKey(int i, int val);
		int getMin() { return harr[0]; }
		void deleteKey(int i);
		void insertKey(int k);
};
minHeap::minHeap(int c){ hs=0; cap=c; harr=new int[cap]; }
void minHeap::insertKey(int k){
	if(hs==cap)	return;
	hs++; int i=hs-1; harr[i]=k;
	while(i!=0 && harr[parent(i)]>harr[i]){ swap(&harr[parent(i)],&harr[i]); i=parent(i); }
}
void minHeap::decreaseKey(int i,int k){
	harr[i]=k;
	while(i!=0 && harr[parent(i)]>harr[i]){ swap(&harr[parent(i)],&harr[i]); i=parent(i); }
}
int minHeap::extractMin(){
	if(hs<=0)	return INT_MAX;
	if(hs==1){ hs--; return harr[hs]; }
	int r=harr[0]; harr[0]=harr[hs-1]; hs--;
	minHeapify(0);
	return r;
}
void minHeap::deleteKey(int i){
	decreaseKey(i,INT_MIN);
	extractMin();
}
void minHeap::minHeapify(int i){
	int l=left(i),r=right(i),s=i;
	if(l<hs && harr[l]<harr[s]) s=l;
	if(r<hs && harr[r]<harr[s])	s=r;
	if(s!=i){ swap(&harr[s],&harr[i]); minHeapify(s); }
}
int main(){
	//freopen("input.txt","r",stdin);
	minHeap h(11);
    h.insertKey(3); h.insertKey(2); h.deleteKey(1); h.insertKey(15); h.insertKey(5); h.insertKey(4); h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
	cout<<endl;
	return 0;
}
