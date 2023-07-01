# frozen_string_literal: true

# Given an integer array nums, return true if any value appears at least,
# twice in the array and return false if every element is distinct.
# Example:
# 	Input: nums = [1, 2, 3, 1]
# 	Output: true
# Time: O(n)
# Space: O(n)
module Arrays
  def self.contains_duplicate(nums)
    !nums.uniq!.nil?
  end
end

RSpec.describe Arrays do
  describe '.contains_duplicate(nums)' do
    it 'returns true if any value appears at least twice in the array' do
      expect(Arrays.contains_duplicate([1, 2, 3, 1])).to be true
    end

    it 'returns false if every element is distinct' do
      expect(Arrays.contains_duplicate([1, 2, 3, 4])).to be false
    end

    it 'returns false for an empty array' do
      expect(Arrays.contains_duplicate([])).to be false
    end
  end
end
