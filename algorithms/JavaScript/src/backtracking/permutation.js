/*
Problem -
    Get all possible permutations of x elements (x being one of the algorithm's parameters) in any given array of integers.
    The algorithm uses a recursive approach and enables the inclusion or the exclusion of replicates through a boolean argument.
    The algorithm has three parameters: 
        1. An input array of integers, array
        2. Number of elements per permutation, limit
        3. A boolean, acceptReplicates (true = replicates accepted and false = replicates excluded)

Example 1 -
    Input: array = [1,2,3,4,5], limit = 2, accept replicates = false
    
    Output: [
    [ 1, 2 ], [ 1, 3 ], [ 1, 4 ], [ 1, 5 ],
    [ 2, 1 ], [ 2, 3 ], [ 2, 4 ], [ 2, 5 ],
    [ 3, 1 ], [ 3, 2 ], [ 3, 4 ], [ 3, 5 ],
    [ 4, 1 ], [ 4, 2 ], [ 4, 3 ], [ 4, 5 ],
    [ 5, 1 ], [ 5, 2 ], [ 5, 3 ], [ 5, 4 ]]

    Visualization:
    For each option in the integer array, add the option in a combo array and recursively call
    the function to continue to try all options until the combo array reaches the limit.

                1                    2                     3                 4                 5  
           /   / \   \          /   / \   \           /   / \   \       /   / \   \       /   / \   \
          2   3   4   5        1   3   4   5         1   2   4   5     1   2   3   5     1   2   3   4

Example 2 -
    Input: array = [1,2,3,4], limit = 3, accept replicates = true
    
    Output: [
    [ 1, 1, 1 ], [ 1, 1, 2 ], [ 1, 1, 3 ], [ 1, 1, 4 ], [ 1, 2, 1 ],
    [ 1, 2, 2 ], [ 1, 2, 3 ], [ 1, 2, 4 ], [ 1, 3, 1 ], [ 1, 3, 2 ],
    [ 1, 3, 3 ], [ 1, 3, 4 ], [ 1, 4, 1 ], [ 1, 4, 2 ], [ 1, 4, 3 ],
    [ 1, 4, 4 ], [ 2, 1, 1 ], [ 2, 1, 2 ], [ 2, 1, 3 ], [ 2, 1, 4 ],
    [ 2, 2, 1 ], [ 2, 2, 2 ], [ 2, 2, 3 ], [ 2, 2, 4 ], [ 2, 3, 1 ],
    [ 2, 3, 2 ], [ 2, 3, 3 ], [ 2, 3, 4 ], [ 2, 4, 1 ], [ 2, 4, 2 ],
    [ 2, 4, 3 ], [ 2, 4, 4 ], [ 3, 1, 1 ], [ 3, 1, 2 ], [ 3, 1, 3 ],
    [ 3, 1, 4 ], [ 3, 2, 1 ], [ 3, 2, 2 ], [ 3, 2, 3 ], [ 3, 2, 4 ],
    [ 3, 3, 1 ], [ 3, 3, 2 ], [ 3, 3, 3 ], [ 3, 3, 4 ], [ 3, 4, 1 ],
    [ 3, 4, 2 ], [ 3, 4, 3 ], [ 3, 4, 4 ], [ 4, 1, 1 ], [ 4, 1, 2 ],
    [ 4, 1, 3 ], [ 4, 1, 4 ], [ 4, 2, 1 ], [ 4, 2, 2 ], [ 4, 2, 3 ],
    [ 4, 2, 4 ], [ 4, 3, 1 ], [ 4, 3, 2 ], [ 4, 3, 3 ], [ 4, 3, 4 ],
    [ 4, 4, 1 ], [ 4, 4, 2 ], [ 4, 4, 3 ], [ 4, 4, 4 ]]

Time Complexity - O(k * n^k) n = number of integers, k = limit
In worst case scenario there are n ^ k possible permutations.
It will take k times to get to each permutation (base case).
Overall time complexity = possible permutations (n ^ k) * time it takes to get to each permutation (k) = O(k * n ^ k);

Space Complexity - O(k) k = limit (excluding the result array)
In worst case scenario, the recursion will get to k depth
*/


function permutations(array, limit, acceptReplicates) {
    const result = [];

    dfs(array, [], new Set(), 0);

    return result;

    function dfs(options, combo, used, iteration) {

        // Base case - if the permutation reaches the limit, add the permutation to the result
        if (combo.length === limit) return result.push([...combo]);

        // Base case - if the recursion depth reaches the limit, end the current recursion
        if (iteration === limit) return;

        // Loop and try through all options
        for (const option of options) {

            if (!acceptReplicates && used.has(option)) continue;

            dfs(options, combo, used, iteration + 1);

            combo.push(option);
            used.add(option);

            dfs(options, combo, used, iteration + 1);

            combo.pop();
            used.delete(option);
        }
    }
}

const test1 = permutations([1,2,3,4,5], 2, false);
const test2 = permutations([1,2,3,4], 3, true);

console.log(test1);
console.log(test2);