#include<iostream>
#include<vector>

typedef std::vector<int> vector;

int gcd(int a , int b){
    if(b == 0 ){
        return a ;
    }
    return gcd(b,a%b);
}
void juggling_algo(vector&nums , int pos){
    if(pos <= 0 || pos == (int)nums.size() ) return ;
    int temp = 0 ;
    int d =0 ;
    int j =0  ;
    int n = nums.size();
    int times = gcd(n,pos);
    for(int i = 0 ; i < times; ++i){
        j = i;
        temp = nums[i];
        while(true){
            d = (j+pos)%n;
            if(d ==i){
                break;
            }
            nums[j] = nums[d];
            j = d;
        }
        nums[j] = temp;
    }
}

void reverse(vector & nums, int start , int end){
    while(start < end ){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void reversal_algo(vector& nums , int pos ){
    if(pos <= 0 || pos == (int)nums.size() ) return ;
    reverse(nums,0,pos-1);
    reverse(nums,pos,nums.size()-1);
    reverse(nums,0,nums.size()-1);

}


void swap(int *nums , int fi , int si , int size){
    for(int i = 0 ; i < size ; ++i){
        int temp  = nums[fi+i];
        nums[fi+i] = nums[si+i] ;
        nums[si+i] = temp;
    }
}

void block_swap(int * nums , int pos, int size){
    if(pos <= 0 || pos == size ) return ;
    if(size -pos == pos){
        swap(nums,0,size-pos,pos);
        return;
    }
    if(pos < size-pos){  // A is shorter
        swap(nums,0,size-pos,pos);
        block_swap(nums,pos,size-pos);
    }else{ // B is shorter
        swap(nums,0,pos,size-pos);
        block_swap(nums+size-pos,2*pos-size,pos);
    }

}
// int main(){
//     vector nums = {1,2,3,4,5,6,7,8,9};
//     int pos =2;
//     rotate(nums,pos);
//     for(int x : nums){
//         std::cout<<x<<" ";
//     }
//     return 0;
// }
