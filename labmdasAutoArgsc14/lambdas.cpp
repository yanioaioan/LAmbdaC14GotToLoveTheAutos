#include <iostream>

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

//C++14 introduces a new way of type-deducting lambdas - using auto...so convenient and pain free compared to previous explicit type specifications

/*This is a demo showing how to use auto argument deduction with C++14 along with nested lambdas,
really handy- takes away all the pain of explicitly constructing all argument related structs!*/


int main()
{
         std::vector<int> V(2);
         std::vector<int> V2(2);
          // Use std::iota to create a sequence of integers 0, 1, ...
         std::iota(V.begin(), V.end(), 1);
         std::iota(V2.begin(), V2.end(), 3);

         // Print the unsorted data using std::for_each and a lambda
//         std::cout << "Original data" << std::endl;
//         std::for_each(V.begin(), V.end(), [](auto i) { std::cout << i << " "; });
//         std::cout << std::endl;
//         std::for_each(V2.begin(), V2.end(), [](auto i) { std::cout << i << " "; });

         // Sort the data using std::sort and a lambda
//         std::sort(V.begin(), V.end(), [](auto i, auto j) { return (i > j); });

        int outter_capt=2;//is the inner lambda local variable defined to the outter lambda variable

        std::vector<int> V3;
         std::for_each(V.begin(), V.end(), [&outter_capt, &V2, &V3](int i) {

             int localToOutter_capt=i;//refer to outter i so as to use it in the inside lambda expression

             //note instead of using i to here in the nested lambda, we use outter_capt (local to outter) variable to avoid non capturing
             std::for_each(V2.begin(), V2.end(), [&/*outter_capt*/localToOutter_capt, &V3](int j){
                std::cout<</*outter_capt*/ localToOutter_capt<<","<<j<<std::endl;
                V3.push_back(localToOutter_capt+j);
             }
             );

         }) ;




//         vector<string> v1;
//         for_each(begin(v1), end(v1), [](string s1) {
//             vector<string> v2;
//             for_each(begin(v2), end(v2), [](string s2) {
//                 cout << "...";
//             });
//         });


//          Print the sorted data using std::for_each and a lambda
//         std::cout << "Final data" << std::endl;
//         std::for_each(V.begin(), V.end(), [](auto i) { std::cout << i << " "; });
//         std::cout << std::endl;
//         std::for_each(V2.begin(), V2.end(), [](auto i) { std::cout << i << " "; });


         std::cout << "Final Summed data" << std::endl;
         std::for_each(V3.begin(), V3.end(), [](auto i) { std::cout << i << " "; });

         return 0;


}
