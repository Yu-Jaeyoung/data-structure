import type { StackInterface } from "@/stack/common/stack.interface";

export class ArrayStack<E> implements StackInterface<E> {
  private arrayStack: E[];
  private itemCount: number;
  private maxArraySize: number = 10;

  constructor() {
    this.arrayStack = [];
    this.itemCount = 0;
  }

  push(newItem: E): void {
    if (this.isFull()) {
      throw new Error("Stack is Full");
    }

    this.arrayStack.push(newItem);
    this.itemCount++;
  }

  pop(): E {
    if (this.isEmpty()) {
      throw new Error("Stack is Empty");
    }

    const lastItem = this.arrayStack[this.itemCount - 1];

    this.itemCount--;

    this.arrayStack.length = this.itemCount;

    return lastItem;
  }

  peek(): E {
    if (this.isEmpty()) {
      throw new Error("Stack is Empty");
    }

    return this.arrayStack[this.itemCount - 1];
  }

  isEmpty(): boolean {
    return this.itemCount === 0;
  }

  isFull(): boolean {
    return this.itemCount === this.maxArraySize;
  }

  clear(): void {
    this.arrayStack = [];
    this.itemCount = 0;
  }

  size(): number {
    return this.itemCount;
  }
}
