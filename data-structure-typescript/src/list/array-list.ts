import type { List } from "./common/list.interface";

export class ArrayList<T> implements List<T> {
  private elements: Array<T>;
  private itemCount: number = 0;

  constructor(capacity: number = 10) {
    this.elements = new Array<T>(capacity);
    this.itemCount = 0;
  }

  add(element: T): void;
  add(index: number, element: T): void;

  add(...args: [T] | [number, T]): void {
    if (args.length !== 1 && args.length !== 2) {
      throw new Error("Invalid number of arguments for add method.");
    }

    if (args.length === 2) {
      const [index, element] = args;
      this.elements.splice(index, 0, element);
      this.itemCount++;
      return;
    }

    if (args.length === 1) {
      const [element] = args;
      this.elements[this.itemCount] = element;
      this.itemCount++;
    }
  }

  remove(index: number): T {
    if (index < 0 || index >= this.itemCount) {
      throw new Error("Index out of bounds.");
    }

    this.itemCount--;
    return this.elements.splice(index, 1)[0];
  }

  get(index: number): T {
    if (index < 0 || index >= this.itemCount) {
      throw new Error("Index out of bounds.");
    }

    return this.elements[index];
  }

  set(index: number, element: T): T {
    if (index < 0 || index >= this.itemCount) {
      throw new Error("Index out of bounds.");
    }

    this.elements[index] = element;

    return this.elements[index];
  }

  indexOf(element: T): number {
    if (this.itemCount === 0) {
      return -1;
    }

    return this.elements.indexOf(element);
  }

  clear(): void {
    this.elements = [];
    this.itemCount = 0;
  }

  isEmpty(): boolean {
    return this.itemCount === 0;
  }

  sizeOf(): number {
    return this.itemCount;
  }

  printAll(): void {
    const elementsToPrint: T[] = this.elements.slice(0, this.itemCount);

    console.log(elementsToPrint);
  }
}
