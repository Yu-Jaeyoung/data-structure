import { LinkedList } from "@/list/linked-list";
import type { StackInterface } from "@/stack/common/stack.interface";

export class LinkedListStack<E> implements StackInterface<E> {
  private list: LinkedList<E> = new LinkedList<E>();

  push(newItem: E): void {
    this.list.add(0, newItem);
  }

  pop(): E {
    if (this.isEmpty()) {
      throw new Error("Stack is empty");
    }

    return this.list.remove(0);
  }

  peek(): E {
    if (this.isEmpty()) {
      throw new Error("Stack is empty");
    }

    return this.list.get(0);
  }

  isEmpty(): boolean {
    return this.list.isEmpty();
  }

  isFull(): boolean {
    return false;
  }

  clear(): void {
    this.list.clear();
  }

  size(): number {
    return this.list.sizeOf();
  }
}
