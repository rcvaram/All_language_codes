You can contribute any programs whic can worthy

#Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]



class Solution {
 public List permute(int[] nums) {
  List result = new ArrayList<>();
  if (nums.length > 0) {
   if (nums.length == 1) {
    List composition = new ArrayList<>();
    composition.add(Integer.valueOf(nums[0]));
    result.add(composition);
   } else {
    for (int i = nums.length - 1; i >= 0; i--) {
     // take out the last element
     int num = nums[i];
     int[] temp_nums = new int[nums.length - 1];
     for (int j = 0; j < i; j++) {
      temp_nums[j] = nums[j];
     }
     for (int j = i + 1; j < nums.length; j++) {
      temp_nums[j - 1] = nums[j];
     }
     // iteratively generate the permutation for nums without the taken element
     List temp_result = this.permute(temp_nums);
     for (List temp_composition : temp_result) {
      // add the taken element into the temp_permutation
      temp_composition.add(Integer.valueOf(num));
      result.add(temp_composition);
     }
    }
   }
  }
  return result;
 }
}
