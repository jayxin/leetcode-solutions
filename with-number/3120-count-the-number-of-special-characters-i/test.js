function testLetter(start) {
  for (let i = start; i <= start + 25; i++) {
    console.log((i & 0x1f), (start >> 5) & 1);
  }
}

console.log('a');
testLetter(97);

console.log('==============================');

console.log('A');
testLetter(65);
