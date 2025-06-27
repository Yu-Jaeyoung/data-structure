function fibonacciRecursive (n: number): number {
  if (n <= 1) return n;

  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

function fibonacciIterative (n: number): number {
  if (n <= 1) return n;

  let [ prev, current ] = [ 0, 1 ];
  for (let i = 2; i <= n; i++) {
    [ prev, current ] = [ current, prev + current ];
  }
  return current;
}

const n: number = 10;
console.log(`f(${ n }) = ${ fibonacciRecursive(n) }`);
console.log(`f(${ n }) = ${ fibonacciIterative(n) }`);
