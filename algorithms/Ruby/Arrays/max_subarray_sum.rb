# frozen_string_literal: true

# Algorithm Name: Max Sum of Sub Array
# Time: O(n)
# Space: O(n)
module Arrays
  def self.max_subarray_sum(arr)
    arr_size = arr.length
    max_sum = arr[0]
    max_sum_curr = arr[0]

    (1...arr_size).each do |i|
      max_sum_curr = [arr[i], max_sum_curr + arr[i]].max
      max_sum = [max_sum, max_sum_curr].max
    end

    max_sum
  end
end

RSpec.describe Arrays do
  describe '.max_subarray_sum' do
    it 'returns the max subarray sum for positive numbers' do
      expect(Arrays.max_subarray_sum([1, 2, 3, 4])).to eq(10)
    end

    it 'returns the max subarray sum for negative numbers' do
      expect(Arrays.max_subarray_sum([-2, -3, -4, -1, -2, -1, -5, -3])).to eq(-1)
    end

    it 'returns the max subarray sum for a mix of positive and negative numbers' do
      expect(Arrays.max_subarray_sum([3, 2, -4, 9])).to eq(10)
    end

    it 'returns the max subarray sum for an array with a single element' do
      expect(Arrays.max_subarray_sum([5])).to eq(5)
    end
  end
end
