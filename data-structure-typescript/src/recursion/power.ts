function power (
  x: number,
  n: number,
): number {
  if (n === 0) return 1;
  return x * power(x, n - 1);
}

console.log(power(2, 5));