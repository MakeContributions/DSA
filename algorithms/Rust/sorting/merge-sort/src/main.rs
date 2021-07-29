use rand::{distributions::Uniform, Rng};

fn main() {
    // Create random numbers
    let range = Uniform::from(0..=100);
    let values: Vec<i32> = rand::thread_rng().sample_iter(&range).take(100).collect();
    println!("Sorting: {:?}",values);
    let result = merge_sort(values);
    println!("Sorted:  {:?}", result);
}

// Limit type to only objects that can be ordered, cloned and copied
fn merge_sort<T: std::cmp::Ord + Copy>(nums: Vec<T>) -> Vec<T> {
    // If array only has one item, it is already sorted :-)
    if nums.len() == 1 {
        return vec![nums[0]];
    }

    // If array has 2 items, just compare the values and sort
    if nums.len() == 2 {
        if nums[0] <= nums[1] {
            return vec![nums[0], nums[1]];
        } else {
            return vec![nums[1], nums[0]];
        }
    }

    // Split into 2
    let half = nums.len() / 2;
    let mut left = merge_sort((&nums[0..half]).to_vec());
    let mut right = merge_sort((&nums[half..]).to_vec());

    let mut sorted: Vec<T> = Vec::new();

    loop {
        // If either array is empty, the values in the other array must be larger
        // and so we should dump the remaining array's content into the sorted array
        if left.is_empty() {
            for i in right {
                sorted.push(i);
            }
            break;
        }
        if right.is_empty() {
            for i in left {
                sorted.push(i);
            }
            break;
        }

        // Merge arrays
        if left[0] >= right[0] {
            sorted.push(right[0]);
            right.remove(0);
            continue;
        }
        if left[0] <= right[0] {
            sorted.push(left[0]);
            left.remove(0);
            continue;
        }
    }

    // return sorted array
    sorted
}
