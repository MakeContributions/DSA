use std::{collections::HashMap, hash::Hash, ops::Sub};

pub fn two_sum<T: Sub<Output = T> + Eq + Hash + Clone, L: IntoIterator<Item = T>>(
    list: L,
    sum: T,
) -> Option<(usize, usize)> {
    let mut encountered = HashMap::<T, usize>::new();

    for (idx, item) in list.into_iter().enumerate() {
        let diff = sum.clone() - item.clone();
        if let Some(&first_idx) = encountered.get(&diff) {
            return Some((first_idx, idx));
        }
        encountered.insert(item, idx);
    }

    None
}

fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_empty() {
        assert!(two_sum(vec![], 20).is_none());
    }

    #[test]
    fn test_match() {
        assert_eq!(two_sum(vec![2, 7, 11, 15], 9), Some((0, 1)));
        assert_eq!(two_sum(vec![3, 2, 4], 6), Some((1, 2)));
        assert_eq!(two_sum(vec![3, 3], 6), Some((0, 1)));
    }

    #[test]
    fn test_no_match() {
        assert!(two_sum(vec![2, 7, 11, 15], 1).is_none());
        assert!(two_sum(vec![3, 2, 4], 1).is_none());
        assert!(two_sum(vec![3, 3, 123, 2891731, 0], 282191923).is_none());
    }
}
