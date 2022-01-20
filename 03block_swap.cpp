#include <iostream>
#include <vector>
#include "../util/array_rotate.cpp"


int main(){
    int nums[] ={1,2,3,4,5,6,7};
    int pos = 6;
    int size = sizeof(nums)/sizeof(nums[0]);
    block_swap(nums,pos,size);
    for(int x : nums){
        std::cout<<x<<" ";
    }
    return 0 ;

}
