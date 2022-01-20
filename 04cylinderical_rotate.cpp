#include <iostream>
#include <vector>
typedef std::vector<int> vector;


void crotate(vector & nums){
    if(nums.size() <= 1 ) return ;
    int temp = nums[(int)nums.size()-1];
    for(int i = (int)nums.size()-1 ; i >= 0 ; --i){
        nums[i] = nums[i-1];
    }
    nums[0] = temp;
}
int main(){
    vector nums ={1,2};
    crotate(nums);
    for(int x : nums){
        std::cout<<x<<" ";
    }
    std::cout<<"\nWorking.";
    return 0 ;

}
