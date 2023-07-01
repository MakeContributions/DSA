# frozen_string_literal: true

# Problem Statement: given an array of integers nums and an integer target,
# return indices of the two numbers such that they add up to target.
#
# You may assume that each input would have exactly one solution,
# and you may not use the same element twice.
#
# Input: An array of integers and a target (int)
# Output: array of indexes of len(2) with sum of element at that index equal to target or nil
#
# Time: O(n)
# Space: O(n)
module Arrays
  def self.two_sum(nums, target)
    complement_hash = {}

    nums.each_with_index do |num, index|
      complement = target - num

      return [complement_hash[complement], index] if complement_hash.key?(complement)

      complement_hash[num] = index
    end

    nil
  end
end

RSpec.describe Arrays do
  describe '.two_sum' do
    it 'returns the correct indices' do
      expect(Arrays.two_sum([2, 7, 11, 15], 9)).to eq([0, 1])
      expect(Arrays.two_sum([3, 2, 4], 6)).to eq([1, 2])
      expect(Arrays.two_sum([3, 3], 6)).to eq([0, 1])
    end

    it 'returns nil if no solution is found' do
      expect(Arrays.two_sum([1, 2, 3, 4], 9)).to be_nil
      expect(Arrays.two_sum([], 5)).to be_nil
    end
  end
end
