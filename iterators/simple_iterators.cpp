#include <bits/stdc++.h>
#if defined __GNUC__
#include <cxxabi.h>
#endif
using namespace std;

int seed = 0;

// a print function that accepts another function as
// one of its arguments
void prettyPrint(function<void()> func, string title)
{
    cout << title << endl << "----------------------------------" << endl << endl;
    func();
    cout << endl << endl;
}

// ------------------------ 1. Iterator ------------------------
// create a vector of integers
// and initialize it with values
// then browse through it using
// iterator
void example1()
{
    vector<int> v = { 1, 2, 3, 4, 5 };
    auto it = v.begin(); // auto replaces vector<int>::iterator
    cout << *it << endl;
    it++;
    cout << *it << endl;
    it += 2;
    cout << *it << endl;
    it--;
    cout << *it << endl;
    it -= 2;
    cout << *it << endl;
}

// ------------------------ 2. Iterator type ------------------------
// create a vector of floats, strings and integers
// and initialize it with values
// then use .begin() and .end()
// to find type of iterators created by them
void example2()
{
    vector<float> v1 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    vector<string> v2 = { "one", "two", "three", "four", "five" };
    vector<int> v3 = { 1, 2, 3, 4, 5 };

    // same iterators declared with auto
    auto auto1 = v1.begin();
    auto auto2 = v2.begin();
    auto auto3 = v3.begin();

    // same iterators declared with explicit type
    vector<float>::iterator it1 = v1.begin();
    vector<string>::iterator it2 = v2.begin();
    vector<int>::iterator it3 = v3.begin();

#if defined __GNUC__
    cout << "au1: " << abi::__cxa_demangle(typeid(auto1).name(), 0, 0, 0) << endl;
    cout << "it1: " << abi::__cxa_demangle(typeid(it1).name(), 0, 0, 0) << endl;
    cout << "au2: " << abi::__cxa_demangle(typeid(auto2).name(), 0, 0, 0) << endl;
    cout << "it2: " << abi::__cxa_demangle(typeid(it2).name(), 0, 0, 0) << endl;
    cout << "au3: " << abi::__cxa_demangle(typeid(auto3).name(), 0, 0, 0) << endl;
    cout << "it3: " << abi::__cxa_demangle(typeid(it3).name(), 0, 0, 0) << endl;
#else
    cout << "au1: " << typeid(auto1).name() << endl;
    cout << "it1: " << typeid(it1).name() << endl;
    cout << "au2: " << typeid(auto2).name() << endl;
    cout << "it2: " << typeid(it2).name() << endl;
    cout << "au3: " << typeid(auto3).name() << endl;
    cout << "it3: " << typeid(it3).name() << endl;
#endif
}

// ------------------------ 3. Commonly used iterators ------------------------
// create a vector of integers
// and initialize it with a lot of random values (20)
// create iterators begin, end, min, max
// and use them to make different sorting examples
// also use min and max to find index of min and max values
void example3()
{
    // generate vector
    vector<int> v(20);
    srand(seed);
    generate(v.begin(), v.end(), []() { return rand() % 100; });
    // print vector
    cout << "Generated vector we're working with: " << endl;
    for (auto i : v)
        cout << i << ", ";
    cout << endl << endl;
    auto min = min_element(v.begin(), v.end());
    auto max = max_element(v.begin(), v.end());
    // print min and max
    auto begin = v.begin();
    auto end = v.end();
    cout << "min: " << *min << " at index: " << distance(begin, min) << endl;
    cout << "max: " << *max << " at index: " << distance(begin, max) << endl;
    cout << endl;
    // sort whole vector
    cout << "now look at the vector sorted from begin to end" << endl;
    vector<int> v1(v); // copy of v to preserve original for further examples
    auto begin1 = v1.begin(); // what would happen if we used v.begin() instead?
    auto end1 = v1.end(); // same question as above
    sort(begin1, end1);
    for (auto i : v1)
        cout << i << ", ";
    cout << endl;
    // sort from begin to min
    cout << "now look at the vector sorted from begin to min" << endl;
    vector<int> v2(v);
    auto begin2 = v2.begin();
    auto end2 = v2.end();
    auto min2 = min_element(begin2, end2);
    sort(begin2, min2 + 1); // why +1?
    for (auto i : v2)
        cout << i << ", ";
    cout << endl;
    // and just for fun, sort from max to end
    cout << "now look at the vector sorted from max to end" << endl;
    vector<int> v3(v);
    auto begin3 = v3.begin();
    auto end3 = v3.end();
    auto max3 = max_element(begin3, end3);
    sort(max3, end3);
    for (auto i : v3)
        cout << i << ", ";
    cout << endl;
}

int main() {
    // 1. simple vector iterator example
    prettyPrint(example1, "1. simple vector iterator example");
    // 2. get the iterator type
    cout << "Press enter to continue" << endl;
    cin.get();
    prettyPrint(example2, "2. get the iterator type");
    // 3. commonly used iterators
    cout << "Enter an integer to be used as a seed (same seed will generate the same array)" << endl;
    cin >> seed;
    prettyPrint(example3, "3. commonly used iterators");
    return 0;
}
