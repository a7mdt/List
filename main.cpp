#include "bits/stdc++.h"
using namespace std;

bool removeifFunction(int i)
{
    return i%2;
}

int main()
{
    // List => is different from Vectors and Deque because u can add&delete in any place.

    // How can I change an value ? note : I can't do this list[1]=5 ..
    list<int>myList = {1,3,3,4,5,6,7};
    list<int>::iterator ii = myList.begin();
    ii++;
    *ii = 2;
    for(ii=myList.begin();ii!=myList.end();ii++) // Don't forget to back ur iterator to its value (.begin())
        cout<<*ii<<" ";

    cout<<"\n--------------------------------------------------\n";

    list<int>li(20); // The same Declarition of Vectors,Deque.
    li.push_back(6); // 1,2,3,4,5,6 ==> to remove use pop_back()
    li.push_front(0); // 0,1,2,3,4,5,6 ==> to remove use pop_front
    cout<<"li.front() : "<<li.front()<<endl;
    cout<<"li.back() : "<<li.back()<<endl;
    li.remove(2); // it Will remove each 2 in the list.
    li.erase(li.begin()); // it Will remove the first element
    // What if I want to erase all of the list without the first element ?
    auto it = li.begin(); // I can't write li.begin()+1
    it++; // li.begin()+1.
    li.erase(it,li.end()); // // I can't write li.begin()+1 , li.end()-1 for example.
    li.insert(it,1); // We will make the second index in our list == 1
    it++; // li.begin()+2
    li.insert(it,2,3); // We will put the value 3 two times from the third index
    li.assign(5,2); // We will assign 5 places and make them equales 2
    cout<<"li.size() : "<<li.size()<<endl; // How many busy indexes.
    cout<<"li.empty() : "<<li.empty()<<endl; // Give u Bool value (0/1)
    li.resize(25);

    cout<<"\n--------------------------------------------------\n";

    // Concat 2 Lists :
    list<int>li1 = {1,3,5,7,9};
    list<int>li2 = {2,4,6,8,10};
    // 1) MERGE :
    li1.merge(li2); // it will merge the 2 lists and sort them. ==> 1,2,3,4,5,6,7,8,9,10 in li1. and li2 wil be empty.
    // 2) SPLICE : // We choose a point we want to add to.
    li1.splice(li1.begin(),li2); // li1 == 2,4,6,8,10,1,3,5,7,9 || li2 empty.

    // 3) UNIQUE :
    list<int>li3 = {1,2,2,2,3,5,9,8,7,7,1,4,6};
    cout<<"The List before li3.unique() : ";
    for(auto i=li3.begin() ; i!=li3.end() ; i++)
        cout<<*i<<" ";
    cout<<endl;
    li3.unique();
    cout<<"The List after li3.unique() : ";
    for(int i : li3)
        cout<<i<<" ";
    cout<<endl;

    // 4) REMOVE_IF :
    list<int>li4 = {1,2,3,4,5,6,7,8,9};
    li4.remove_if(removeifFunction); // Look at the first function.
    for(int i : li4)
        cout<<i<<" "; // It will print the even nums only because of the remove_if function.
    cout<<endl;

    // 5) SORT :
    list<int>li5 = {5,9,-1,0,-22,6,55,8,1001,1};
    li5.sort(); // -22,-1,0,1,5,6,8,9,55,1001
    li5.sort(greater<int>()); // 1001,55,9,8,6,5,1,0,-1,-22

    // 6) REVERSE :
    list<int>li6 = {1,2,3,4,5,6,7,8,9};
    li6.reverse(); // 9,8,7,6,5,4,3,2,1


    return 0;
}
