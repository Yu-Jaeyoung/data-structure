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

  add(indexOrElement: T | number, element?: T): void {
    if (typeof indexOrElement === "number") {
      const index: number = indexOrElement;

      if (element === undefined) {
        throw new Error("Element must be provided when an index is specified.");
      }

      this.elements.splice(index, 0, element);
      this.itemCount++;
      return;
    }

    this.elements[this.itemCount] = indexOrElement;
    this.itemCount++;
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
