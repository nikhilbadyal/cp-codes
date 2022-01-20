#include <iostream>
#include <vector>
#include "../util/array_rotate.cpp"


int main(){
    std::vector<int>nums ={1,2,3,4,5,6,7};
    int pos = 0;
    reversal_algo(nums,pos);
    for(int x : nums){
        std::cout<<x<<"  ";
    }
    return 0 ;

}
