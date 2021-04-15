const rewire = require('rewire');
const userRewire = rewire('../../src/arrays/counting-inversions');
const countInversions = userRewire.__get__('countingInversions');

test('Pass array should get expected value', () => {
  const arr = [8, 2, 1, 5, 7, 3, 9, 2, 0, 1];
  expect(countInversions(arr)).toBe(30);
});
