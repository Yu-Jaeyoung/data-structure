function myFunc (number: number): void {
  if (number > 10) return;
  console.log(number);
  myFunc(number + 1);
}

myFunc(1);