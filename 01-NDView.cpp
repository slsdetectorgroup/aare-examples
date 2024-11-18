#include <iostream>
#include <vector>
#include "aare/NDView.hpp"
#include "aare/NDArray.hpp"

using aare::NDView;
using aare::NDArray;

int main(){
    //Look at data as a N dimensional array

    //Create a vector to hold the data but could as well
    //use new/delete
    std::vector<double> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Create a 3x3 view of the data (data.data() returns a pointer)
    NDView<double, 2> view(data.data(), {3, 3});

    std::cout << view << '\n';

    //Access elements
    view(1,1) = 1.23;

    std::cout << view << std::endl;

    // The view changes the underlying data
    for (const auto& it : data){
        std::cout << it << " ";
    }
    std::cout << '\n';

    // We can also do math with the underlying data
    NDArray<double, 2> res = view*view;
    std::cout << res << std::endl;

}