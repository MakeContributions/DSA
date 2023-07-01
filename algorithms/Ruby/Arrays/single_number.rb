# frozen_string_literal: true

# Given a non-empty array of int, every element appears twice except for 1. Find that element.
# Time: O(n)
# Space: O(n)
module Arrays
  def self.single_number(arr)
    frequency = Hash.new(0)

    arr.each do |num|
      frequency[num] += 1
    end

    frequency.each do |num, count|
      return num if count == 1
    end

    nil
  end
end

RSpec.describe Arrays do
  describe '.single_number' do
    it 'returns the single number in the array' do
      expect(Arrays.single_number([1])).to eq(1)
      expect(Arrays.single_number([1, 2, 2])).to eq(1)
      expect(Arrays.single_number([1, 2, 1])).to eq(2)
      expect(Arrays.single_number([4, 2, 2, 3, 4, 1, 1])).to eq(3)
      expect(Arrays.single_number([5, 5, 6, 6, 7, 7, 8])).to eq(8)
    end

    it 'returns nil when no single number is found' do
      expect(Arrays.single_number([1, 1, 2, 2, 3, 3])).to be_nil
      expect(Arrays.single_number([1, 1, 2, 2, 3, 3, 4, 4])).to be_nil
    end
  end
end
