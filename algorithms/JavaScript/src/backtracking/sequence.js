let list = [];

const subsequence = (input, output = '') => {
  if (input === '') {
    if (output !== '' && !list.includes(output)) list.push(output);
    return;
  }

  subsequence(input.substr(1), output + input.charAt(0));
  subsequence(input.substr(1), output);
};


/*
    to run the file:
        Node sequence.js

    result
        abc [
            'abc', 'ab',
            'ac',  'a',
            'bc',  'b',
            'c'
            ]
        aaa [ 'aaa', 'aa', 'a' ]
        hello [
            'hello', 'hell', 'helo', 'hel',
            'heo',   'he',   'hllo', 'hll',
            'hlo',   'hl',   'ho',   'h',
            'ello',  'ell',  'elo',  'el',
            'eo',    'e',    'llo',  'll',
            'lo',    'l',    'o'
        ]
*/

subsequence('abc');
console.log('abc', list);
list = [];

subsequence('aaa');
console.log('aaa', list);
list = [];

subsequence('hello');
console.log('hello', list);

