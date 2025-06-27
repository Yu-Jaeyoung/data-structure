function hanoiTower (
  count: number,
  from: string,
  to: string,
  temp: string,
): void {
  if (count === 0) return;
  hanoiTower(count - 1, from, temp, to);
  console.log(`원반 ${ count }를 ${ from }에서 ${ to }로 이동`);
  hanoiTower(count - 1, temp, to, from);
}

const count: number = 3;
const from: string = "A";
const to: string = "C";
const temp: string = "B";

hanoiTower(count, from, to, temp);