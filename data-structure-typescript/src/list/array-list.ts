import { List } from "./common/list.interface";

export class ArrayList<T> implements List<T> {
  private elements: T[] = [];
  private itemCount: number = 0;

  constructor (capacity: number = 10) {
    this.elements = new Array<T>(capacity);
    this.itemCount = 0;
  }

  add (element: T): void;
  add (
    index: number,
    element: T,
  ): void;
  add (
    indexOrElement: T | number,
    element?: T,
  ): void {
    if (typeof indexOrElement === "number" && typeof element !== undefined) {
      this.elements.splice(indexOrElement, 0, element);
      this.itemCount++;
    } else if (indexOrElement !== null && element === undefined) {
      this.elements.push(indexOrElement);
      this.itemCount++;
    }
  }

  remove (index: number) {
    // TODO: 잘못된 접근에 대한 처리 로직 필요
    this.elements.splice(index, 1);
  }

  get (index: number): T {
    return this.elements[index];
  }

  set (
    index: number,
    element: T,
  ): T {
    return this.elements[index] = element;
  }

  indexOf (element: T): number {
    return this.elements.findIndex(element=>element === element);
  }

  clear (): void {
    this.elements = [];
    this.itemCount = 0;
  }

  isEmpty (): boolean {
    return this.itemCount === 0;
  }

  size (): number {
    return this.itemCount;
  }

  printAll () {
    let valueArray = [];
    this.elements.map((value: T)=>{
      valueArray.push(value);
    });

    console.log(valueArray);
  }
}