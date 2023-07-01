# frozen_string_literal: true

# Description: This program reverses array elements by swapping the first half part of the array
# Time Complexity : O(n/2), where n is the array size
# Auxiliary Space : O(1)
module Arrays
  def self.reverse_array(arr)
    n = arr.length
    mid = n / 2
    (0...mid).each { |i| arr[i], arr[n - i - 1] = arr[n - i - 1], arr[i] }
    arr
  end
end

RSpec.describe Arrays do
  describe '.reverse_array' do
    it 'reverses the elements of an array' do
      expect(Arrays.reverse_array([1, 2, 3, 4, 5])).to eq([5, 4, 3, 2, 1])
      expect(Arrays.reverse_array([1, 2, 3, 4])).to eq([4, 3, 2, 1])
      expect(Arrays.reverse_array([1])).to eq([1])
      expect(Arrays.reverse_array([])).to eq([])
    end
  end
end
