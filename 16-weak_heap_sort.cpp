/*
 * C++ Program to Implement Weak Heap
 */
// http://www.sanfoundry.com/cpp-program-implement-weak-heap/
// https://en.wikipedia.org/wiki/Weak_heap

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#define GETFLAG(r, x) ((r[(x) >> 3] >> ((x) & 7)) & 1)
#define TOGGLEFLAG(r, x) (r[(x) >> 3] ^= 1 << ((x) & 7))
using namespace std;
/*
 * Class Declaration
 */
class WeakHeap
{
    private:
        vector <int> wheap;
    public:
        WeakHeap()
        {}
        int Size();
        void Insert(int element);
        void DisplaySorted();
        void WeakHeapMerge(unsigned char *r, int i, int j);
        void WeakHeapSort();
};
/*
 * Heap Size
 */
int WeakHeap::Size()
{
    return wheap.size();
}
/*
 * Insert Element into a Heap
 */
void WeakHeap::Insert(int element)
{
    wheap.push_back(element);
    WeakHeapSort();
}
 
/*
 * Merge Weak Heap
 */
void WeakHeap::WeakHeapMerge(unsigned char *r, int i, int j)
{
    if (wheap[i] < wheap[j])
    {
        TOGGLEFLAG(r, j);
        swap(wheap[i], wheap[j]);
    }
}
/*
 * Weak Heap Sort
 */
void WeakHeap::WeakHeapSort()
{
    int n = Size();
    if (n > 1)
    {
        int i, j, x, y, Gparent;
        int s = (n + 7) / 8;
        unsigned char * r = new unsigned char [s];
        for (i = 0; i < n / 8; ++i)
            r[i] = 0;
        for (i = n - 1; i > 0; --i)
        {
            j = i;
            while ((j & 1) == GETFLAG(r, j >> 1))
                j >>= 1;
            Gparent = j >> 1;
            WeakHeapMerge(r, Gparent, i);
        }
        for (i = n - 1; i >= 2; --i)
        {
            swap(wheap[0], wheap[i]);
            x = 1;
            while ((y = 2 * x + GETFLAG(r, x)) < i)
                x = y;
            while (x > 0)
            {
                WeakHeapMerge(r, 0, x);
                x >>= 1;
            }
        }
        swap(wheap[0], wheap[1]);
        delete[] r;
    }
}
/*
 * Display Sorted Heap
 */
void WeakHeap::DisplaySorted()
{
    vector <int>::iterator pos = wheap.begin();
    cout<<"Heap -->  ";
    while (pos != wheap.end())
    {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl;
}


int main()
{
    WeakHeap wh;	
	
	//char s[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', '\0'};	
	int s[] = {1, 3, 5, 7, 2, 4, 6, 8, 10};
	int i, j, m;
	char tmp2;
	m =  sizeof(s)/sizeof(s[0]);
		
	for(i = 0; i < m; i++){
		wh.Insert(s[i]);
	}	
		
	/*
    WeakHeap wh;
    while (1)
    {
        cout<<"------------------"<<endl;
        cout<<"Operations on Weak Heap"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Display Weak Heap Sorted Array"<<endl;
        cout<<"3.Exit"<<endl;
        int choice, element;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element to be inserted: ";
            cin>>element;
            wh.Insert(element);
            break;
        case 2:
            cout<<"Array Sorted by Weak Heap:  ";
            wh.DisplaySorted();
            break;
        case 3:
            exit(1);
        default:
            cout<<"Enter Correct Choice"<<endl;
        }
    }
    */
    
    wh.DisplaySorted();
    
    return 0;
}
