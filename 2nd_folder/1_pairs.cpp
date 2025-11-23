#include <bits/stdc++.h>
using namespace std;

void explainPair() {
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second;

    pair<int, pair<int, int>> p1 = {1, {3, 4}};
    cout << p1.first << " " << p1.second.second << " " << p1.second.first;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second;
}

void explainVector() {
    vector<int> v;
    v.push_back(1);     
    v.emplace_back(2);  // emplace_back is faster than push_back
    // push_back is generally for inserting the first element and emplace_back is for next insertions

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2); // automatically assumes as "{}"

    vector<int> v2(5, 100); // i.e., initializes with size 5 with all values as 100.

    vector<int> v3(5); // i.e., initializes with size 5, all values as 0's.

    vector<int> v4(v2); // i.e., initialising another vector v4 same as v2. copying v2 into v4

    // You can also simply do by
    vector<int> nums = {10, 20, 30, 40, 50};
}

void explainIterator() {
    vector<int> v;
    v.push_back(20);
    v.emplace_back(10);
    v.emplace_back(15);
    v.emplace_back(6);
    v.emplace_back(7);

    cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << " " << endl;

    vector<int>::iterator it = v.begin(); // iterator means points to the memory address but not to the values present in it. So, here v.begin() points to the memory, if we are trying to print it, we are printing the address not the value inside it.
    it++;
    cout << *(it) << " "; // '*' makes print the value inside the address.
    it += 2;
    cout << *(it) << " " << endl;

    // We also have other iterators apart from ".begin()" 
    vector<int>::iterator it2 = v.end(); // ".end()" points to the address right after the last element but not the last element. So use "it--" for the last element.
    cout << *(--it2) << " " << endl;

    cout << v.back() << " " << endl; // '.back()' is for the last element.

    vector<int> nums1 = {10, 20, 30, 40, 50};

    for(vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    // Instead simply use "auto", it automatically detects the datatype of the vector without the need of explicitly mentioning it like above.
    for(auto it = nums1.begin(); it != nums1.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    for (int x : nums1) {
        cout << x << " ";
    }
    cout << endl;

    for(auto it : nums1) {
        cout << it << " " << endl;
    }
}

void otherProperties() {
    vector<int> v = {10, 20 ,12, 23, 34, 13, 57, 87};
    v.erase(v.begin() + 1); // When we delete a element from the vector we use .erase() function. To use ".earse()" function we have to mention it's address by iterator, then after reshuffling occurs i.e., all the other elements shift their positions by one element left.
    cout << v[0] << " " << v[1] << " " << endl;

    // If we delete a group of elements, then give the address of 1st element to be deleted and also the address of the +1th element of the last to be deleted.
    v.erase(v.begin() + 2, v.begin() + 5); // i.e.,when we want to delete 3rd, 4th and 5th elements.(v.begin() + 2 is 3rd element, v.begin() + 3 is 4th one, + 4 is the 5th one. as the last one is 4 mention + 5 as it is not included in the deletion).

    // INSERTION
    vector<int> n(2, 100); // {100, 100}
    n.insert(n.begin(), 300); // {300, 100, 100};
    n.insert(n.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}
    
    vector<int> copy(2, 50); // {50, 50}
    n.insert(n.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    // For knowing the size of the vector
    cout << n.size() << endl; // 7

    n.pop_back(); // {100} i.e., pops out the last element.

    vector<int> v1 = {10, 20};
    vector<int> v2 = {30, 40};
    v1.swap(v2); // v1 -> {30, 40}, v2 -> {10, 20}

    n.clear(); // erases the entire vector

    cout << v1.empty() << " "; // returns '1' if our vector is not empty otherwise '0'.
    cout << n.empty() << endl;
}

void explainList() {
    list<int> ls;
    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2, 4}

    // Only difference from the vector, we also use the front operations. Even thought it has "insert" function, insertion is costlier in vector as it uses singly linked list. whereas list has doubly linked list and push_front is of less cost.
    ls.push_front(5); // {5, 2, 4}
    ls.emplace_front(); // {2, 4};

    // rest fucntions same as vector
    //begin, end, rbegin, rend, clear, insert, size, swap
}

void explainDeque() {
    deque<int> dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1, 2}
    dq.push_front(4); // {4, 1, 2}
    dq.emplace_front(3); // {3, 4, 1, 2}

    dq.pop_back(); // {3, 4, 1}
    dq.pop_front(); // {4, 1}

    // ** once check below ones
    std::cout << "Back: " << dq.back() << "\n";
    std::cout << "Front: " << dq.front() << "\n";

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void explainStack() {
    // LIFO(Last In First Out)
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.push(3); // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    // In stack indexing access is not allowed. In stack, we deal with 3 functions => push, pop, top
    cout << st.top(); // prints 5 "** st[2] is invalid as indexing is not here"
    st.pop(); // st looks like {3, 3, 2, 1}

    cout << st.top(); // 3
    cout << st.size(); // 4
    cout << st.empty(); // False

    stack<int> st2;
    st2.push(1); 
    st2.push(2); 
    st2.emplace(3);  
    st.swap(st2);  

    // All push, pop and top operations will be done in constant time -> O(n)
}

void explainQueue() {
    // Similar to stack but FIFO(First In First Out)
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.emplace(4); // {1, 2, 4}

    q.back() += 5;
    cout << q.back(); // 9

    // q is {1, 2, 9}
    cout << q.front(); // 1

    q.pop(); // {2, 9}
    cout << q.front(); // 2

    // size swap same as stack

    // For all operations it takes constant time -> O(n)
}

void explainPQ() {
    // same as queue, but guy with largest value stays on top. if we are using characters max character stays on top. If we are using strings, lexicographically large string stays on top.

    priority_queue<int>pq;
    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top(); // prints 10

    pq.pop(); // {8, 5, 2}

    cout<< pq.top(); // 8

    // size swap empty function same as others
    // Until this is Maximum priority queue also can be referred to as Max Heap

    // Minimum Priority Queue or Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(5); //{5}
    pq1.push(2); // {2, 5}
    pq1.push(8); // {2, 5, 8}
    pq1.emplace(10); // {2, 5, 8, 10}

    cout << pq1.top(); // 2

    /* Here, Time complexities are
    push -> log(n)
    top  -> O(1)
    pop  -> log(n)
    */
}

void explainSet() {
    // Set is, it stores everything in a sorted order and stores unique
    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1, 2}
    st.insert(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1, 2, 3, 4}
    st.insert(5); // {1, 2, 3, 4, 5}

    auto it1 = st.find(3); // Here, st.find(3) returns an iterator which is pointing to 3. i.e., address of 3
    auto it2 = st.find(6); // If an element is not in set, then it returns st.end() i.e., address of last element + 1, i.e., right after the end

    // For erasing, 3 ways. Either directly we can give the element or we can give the iterator pointing to it. or For group of elements give starting and ending + 1 elements 
    st.erase(5); // erases 5, takes log(n) time
    st.erase(it1); 

    st.insert(3);
    st.insert(5);
    auto ite1 = st.find(2);
    auto ite2 = st.find(4);
    st.erase(ite1, ite2); // {1, 4, 5} [first, last)

    int cnt = st.count(1); // as here only uniques are present, here ".count()" returns either "1" if present or "0" if not.

    // auto it = st.lower_bound(value); // Returns an iterator pointing to the first element in the set that is greater than or equal to value.
    // If such an element does not exist, it returns st.end().
    
    // auto it = st.upper_bound(value); // Returns an iterator pointing to the first element in the set that is strictly greater than value.
    // If no such element exists, it returns st.end()
    set<int> st2 = {1, 2, 3, 5, 7};
    auto it3 = st2.lower_bound(3);  // points to 3
    auto it4 = st2.upper_bound(3);  // points to 5
    auto it5 = st2.lower_bound(6);  // points to 7
    auto it6 = st2.upper_bound(7);  // points to st.end() (past-the-end)

    // And Here, for the insertion, erasing, etc., it takes log(n) time.
    // remaining all functions are similar to vector, size, empty, swap, begin, etc.,
}

void explainMultiSet() {
    // Everything is same as set
    // only difference is, it also stores duplicates also

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}
    int cnt = ms.count(1);

    ms.erase(1); // all 1's erased

    ms = {1, 1, 1, 2, 2, 3, 3, 3};
    ms.erase(ms.find(1)); // finds the first occurrence of 1 and erases only it.

   // To erase a range, you need to get iterators first
    auto it1 = ms.find(1);
    auto it2 = it1;
    advance(it2, 2); // move it2 forward by 2 positions
    ms.erase(it1, it2); // erases first two 1's
}

void explainUSet() {
    // It is unordered set. i.e., we may insert in any order, but we don't know in which order it arranges it, randomised arrangement.
    // All operations same as SET, "lower_bound" & "upper_bound" funcions doesn't work.

    unordered_set<int> st;
    // all operations take O(1) time. Very rare but worst case is O(N).
}

void explainMap() {
    // It stores in KEY, VALUE pairs, values can be any thing but keys are unique. Ex: values are names of students and keys are roll no.s
    // KEYS can be of any datatypes. and MAP stores unique keys in sorted order.
    map<int, int> mpp;
    map<int, pair<int, int>> mpp2;
    map<pair<int, int>, int> mpp3;
    // always first one is for KEY and next one after comma is for value.

    mpp[1] = 2; // {{1,2}}
    mpp.emplace(3, 1); // {{1, 2}, {3, 1}}
    mpp.insert({2, 4}); // {{1, 2}, {2, 4}, {3, 1}}

    mpp3[{2, 3}] = 10; // {{{2, 3}, 10}}

    for(auto it: mpp) {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1] << " ";
    cout << mpp[5] << " " << endl;

    auto it = mpp.find(3);
    if (it != mpp.end()) {
        cout << it->second << " " << endl; // Correct way to access value through iterator
    }

    auto it2 = mpp.find(5); // -> mpp.end();

    auto it3 = mpp.lower_bound(2);
    auto it4 = mpp.upper_bound(3);
}

void explainMultiMap() {
    // everything same as map, only it can store multiple keys.
    // only mpp[key] cannot be used here
}

void explainUnorderedMap() {
    // same as set and unordered_set difference.
    // and also have only unique keys.
}
// Map works in log(n) time, where as unorderedmap takes O(1) time in almost all functions. Only in rare worst cases it takes log(n) time.

bool comp(pair<int, int> p1, pair<int, int> p2) {
    // This comparator says whether two guys are in correct order or not.
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;

    // if they are same
    if (p1.first > p2.first) return true;
    return false;
}

void explainExtra() {
    // Sample array and vector initialization for demonstration
    int a[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> v = {4, 2, 8, 5, 1};

    // In STL, if we want to sort something, just use sort(a, b) where a is iterator to the starting one,
    // b is iterator next to the last element which we want to sort.
    sort(a, a + n);
    sort(v.begin(), v.end()); // if we are using vectors

    sort(a + 2, a + 4); // If we only want to sort a particular portion not the complete one.

    sort(a, a + n, greater<int>()); // If we want to do in descending order.

    // What if we want to sort in a my way. i.e., sort according to different our required logic. EX: check below
    pair<int, int> b[] = {{1, 2}, {2, 1}, {4, 1}};
    int m = sizeof(b) / sizeof(b[0]);
    // Sort it according to second element. If second element is same, then sort it according to first element but in descending
    // Then we add a comparator as another argument to the sort function. This comparator is nothing but a boolean function.
    sort(b, b + m, comp);

    // Built-in popcount functions
    int num = 7;
    int cnt = __builtin_popcount(num); // This says how many set bits i.e., how many 1's are there in 7 in our 32 bit system. it will be 3 
    long long num2 = 165786578687;
    cnt = __builtin_popcountll(num2);

    // Permutations
    string s = "123";
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end())); // it will give permutations until no more are left i.e., until the last big one. If we want all the permutations start with the sorted one.

    // Maximum and minimum element
    int maxi = *max_element(a, a + n);
    int mini = *min_element(a, a + n);

    // Printing for confirmation
    cout << "Max Element: " << maxi << endl;
    cout << "Min Element: " << mini << endl;
    cout << "Set Bits in num2: " << cnt << endl;
}


int main() {
    // explainPair();
    // explainVector();
    // explainIterator();
    // otherProperties();
    // explainList();
    explainDeque();
    // explainStack();
    // explainQueue();
    // explainPQ();
    // explainSet();
    // explainMultiSet();
    // explainMap();
    // explainExtra();
}


/* How to RUN
PS C:\Users\vasir\CPP> g++ 1_pairs.cpp -o 1_pairs                                     
PS C:\Users\vasir\CPP> ./1_pairs
*/