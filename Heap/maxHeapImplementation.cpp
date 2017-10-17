#include<bits/stdc++.h> //O(m+n) or O(n)
using namespace std;
void swap(int *x,int *y){ int t=*x; *x=*y; *y=t; }
class maxHeap{
	int *harr; int cap; int hs;	//cap-capacity hs-heap_size *harr-pointer to heap array
	public:
		maxHeap(int c);
		void maxHeapify(int);
		int parent(int i){ return (i-1)/2; } int left(int i){ return (i*2+1); } int right(int i){ return (i*2+2); }
		int extractMax();
		void decreaseKey(int i, int val);
		int getMax() { return harr[0]; }
		void deleteKey(int i);
		void insertKey(int k);
};
maxHeap::maxHeap(int c){ hs=0; cap=c; harr=new int[cap]; }
void maxHeap::insertKey(int k){
	if(hs==cap)	return;
	hs++; int i=hs-1; harr[i]=k;
	while(i!=0 && harr[parent(i)]<harr[i]){ swap(&harr[parent(i)],&harr[i]); i=parent(i); }
}
void maxHeap::decreaseKey(int i,int k){
	harr[i]=k;
	while(i!=0 && harr[parent(i)]<harr[i]){ swap(&harr[parent(i)],&harr[i]); i=parent(i); }
}
int maxHeap::extractMax(){
	if(hs<=0)	return INT_MAX;
	if(hs==1){ hs--; return harr[hs]; }
	int r=harr[0]; harr[0]=harr[hs-1]; hs--;
	maxHeapify(0);
	return r;
}
void maxHeap::deleteKey(int i){
	decreaseKey(i,INT_MIN);
	extractMax();
}
void maxHeap::maxHeapify(int i){
	int l=left(i),r=right(i),s=i;
	if(l<hs && harr[l]>harr[s]) s=l;
	if(r<hs && harr[r]>harr[s])	s=r;
	if(s!=i){ swap(&harr[s],&harr[i]); maxHeapify(s); }
}
int main(){
	//freopen("input.txt","r",stdin);
	maxHeap h(11);
    h.insertKey(3); h.insertKey(2); h.deleteKey(1); h.insertKey(15); h.insertKey(5); h.insertKey(4); h.insertKey(45);
    cout << h.extractMax() << " ";
    cout << h.getMax() << " ";
    h.decreaseKey(2, 101);
    cout << h.getMax();
	cout<<endl;
	return 0;
}
