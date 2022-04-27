function fibonacci(n) {
  const fibS = [0, 1];
  for (let i = 2; i < n; i++) {
    const num1 = fibS[fibS.length - 1];
    const num2 = fibS[fibS.length - 2];
    const next = num1 + num2;
    fibS.push(next);
  }
  return fibS;
}

console.log(fibonacci(10));
