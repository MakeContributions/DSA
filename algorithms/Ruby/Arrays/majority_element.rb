# frozen_string_literal: true

# Given an array nums of size n, return the majority element.
# The majority element appears more than n/2 times
# Time: O(n)
# Space: O(1)
module Arrays
  def self.majority_element(nums)
    candidate, count = find_candidate(nums)
    count.positive? ? candidate : nil
  end

  def self.find_candidate(nums)
    candidate = nil
    count = 0

    nums.each do |num|
      candidate, count = update_candidate(candidate, count, num)
    end

    [candidate, count]
  end

  def self.update_candidate(candidate, count, num)
    if count.zero?
      candidate = num
      count = 1
    elsif candidate == num
      count += 1
    else
      count -= 1
    end

    [candidate, count]
  end
end

RSpec.describe Arrays do
  describe '.majority_element' do
    it 'returns the majority element in the array' do
      expect(Arrays.majority_element([3, 2, 3])).to eq(3)
      expect(Arrays.majority_element([2, 2, 1, 1, 1, 2, 2])).to eq(2)
    end

    it 'handles different input sizes' do
      expect(Arrays.majority_element([1])).to eq(1)
      expect(Arrays.majority_element([1, 1])).to eq(1)
      expect(Arrays.majority_element([1, 2, 2])).to eq(2)
      expect(Arrays.majority_element([3, 3, 4, 2, 4, 4, 2, 4, 4])).to eq(4)
    end

    it 'handles negative numbers' do
      expect(Arrays.majority_element([-1, -1, -1, 2, 2, 2, -1, -1])).to eq(-1)
      expect(Arrays.majority_element([-3, -2, -3, -3])).to eq(-3)
    end
  end
end
