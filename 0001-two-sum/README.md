# Two Sum (Leetcode #1)

Leetcode's 'Two Sum' problem is one of the most commonly asked coding interview questions, and it's a great introduction to hashmaps and efficient algorithm design. Let's dive into this problem step-by-step, starting with the question itself, exploring the brute force approach, and then explaining the optimal solution with provided code.

## **Understanding the Problem Statement**

The 'Two Sum' problem requires finding two distinct indices in an array that add up to a given target value. Given an array of integers `nums` and an integer `target`, we need to find the indices of two numbers such that they add up to the target value.

For example, given `nums = [2, 7, 11, 15]` and `target = 9`, the solution should return `[0, 1]` because `nums[0] + nums[1] = 2 + 7 = 9`.

## **Brute Force Approach**

One straightforward way to solve this problem is by using a nested loop. We simply iterate over each element in the array and, for each element, iterate again to find another element that sums up to the target. Here's a brief summary of this brute force approach:

* Iterate over each element in `nums`.
    
* For each element, iterate through the rest of the array to check if the sum matches the target.
    
* If the target is found, return the corresponding indices.
    

The brute force solution has a **time complexity of O(n^2)**, which becomes inefficient for larger input arrays.

## **Hint to Solve the Problem Efficiently**

The brute force approach works, but it's slow. A better way to solve this problem is by using a hashmap. The key is to store each value's index as we iterate through the array, allowing us to quickly determine if the complement of the current value (i.e., `target - nums[i]`) has already been seen.

## **Efficient Solution**

The efficient approach makes use of a dictionary (hashmap) to store each value from the `nums` array along with its index as we traverse the list. Here is the code provided for the efficient solution:

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}

        for i in range(len(nums)):
            complement = target - nums[i]

            if complement in hashmap:
                return [hashmap[complement], i]

            hashmap[nums[i]] = i
```

How This Solution Works

1. We initialize an empty dictionary (`hashmap = {}`).
    
2. We iterate over the `nums` list with index `i`.
    
3. For each element `nums[i]`, we calculate its **complement** (i.e., `target - nums[i]`), which is the value needed to add up to the target.
    
4. We check if the complement is already in the hashmap.
    
    * If it is, then we have already encountered the other value needed to reach the target, so we return the current index and the stored index of the complement.
        
    * If it isn’t, we store the value `nums[i]` and its index in the hashmap.
        

## **Time and Space Complexity**

* **Time Complexity**: The time complexity of this solution is **O(n)**, where `n` is the number of elements in `nums`. This is because we traverse the list once, and each lookup operation in the hashmap takes O(1) time.
    
* **Space Complexity**: The space complexity is also **O(n)**, as we store up to `n` elements in the hashmap.
    

By leveraging the hashmap, this solution ensures that we only need one pass over the list, making it significantly faster than the brute force approach, especially for larger datasets.

## **Conclusion**

The 'Two Sum' problem is a great example of how understanding data structures like hashmaps can drastically improve the efficiency of your solution. The brute force approach is simple but inefficient while using a hashmap allows us to solve the problem in linear time.