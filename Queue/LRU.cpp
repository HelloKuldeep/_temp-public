/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
unordered_map<int,int> m;
deque<int> q;
deque<int>::iterator it;
int sz;
LRUCache::LRUCache(int N){
    sz=N;   q.clear();  m.clear();
}
void LRUCache::set(int x, int y){
    it=find(q.begin(),q.end(),x);
    if(it==q.end()){
        if(q.size()==sz) q.pop_back();
    }
    else q.erase(it);
    q.push_front(x);
    m[x]=y;
}
int LRUCache::get(int x){
    it=find(q.begin(),q.end(),x);
    if(it==q.end()) return -1;
    else{ q.erase(it); q.push_front(x); }
    return m[x];
}
