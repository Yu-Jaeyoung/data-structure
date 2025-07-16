import type { List } from "./common/list.interface";
import { Node } from "./common/node";

export class LinkedList<T> implements List<T> {
  private head: Node<T> | null = null;
  private itemCount: number = 0;

  add(element: T): void;
  add(index: number, element: T): void;

  add(...args: [T] | [number, T]): void {
    if (args.length === 1) {
      const [element] = args;
      const newNode = new Node(element);

      if (this.head === null) {
        this.head = newNode;
      } else {
        let current = this.head;

        while (current.next !== null) {
          current = current.next;
        }

        current.next = newNode;
      }
      this.itemCount++;
    } else if (args.length === 2) {
      const [index, element] = args;

      if (index < 0 || index > this.itemCount) {
        throw new Error("Index out of bounds.");
      }

      const newNode = new Node(element);

      if (index === 0) {
        newNode.next = this.head;
        this.head = newNode;
      } else {
        let current: Node<T> | null = this.head;
        let currentIndex = 0;

        while (current !== null && currentIndex < index - 1) {
          current = current.next;
          currentIndex++;
        }

        if (current === null) {
          throw new Error("Unexpected error: current node is null.");
        }

        newNode.next = current.next;
        current.next = newNode;
      }
      this.itemCount++;
    } else {
      throw new Error("Invalid number of arguments for add method.");
    }
  }

  remove(index: number): T {
    if (index < 0 || index >= this.itemCount) {
      throw new Error("Index out of bounds.");
    }

    let removedNode: Node<T>;

    if (index === 0) {
      if (this.head === null) {
        throw new Error("Cannot remove from an empty list.");
      }

      removedNode = this.head;
      this.head = this.head.next;
    } else {
      let previous: Node<T> | null = this.head;
      let currentIndex = 0;

      while (previous !== null && currentIndex < index - 1) {
        previous = previous.next;
        currentIndex++;
      }

      if (previous === null || previous.next === null) {
        throw new Error("Unexpected error: could not find node to remove.");
      }

      removedNode = previous.next;
      previous.next = removedNode.next;
    }

    this.itemCount--;
    return removedNode.data;
  }

  get(index: number): T {
    if (index < 0 || index >= this.itemCount) {
      throw new Error("Index out of bounds.");
    }

    let current = this.head;
    let currentIndex = 0;

    while (current !== null && currentIndex < index) {
      current = current.next;
      currentIndex++;
    }

    if (current === null) {
      throw new Error(
        "Unexpected error: could not find node at the given index.",
      );
    }

    return current.data;
  }

  set(index: number, element: T): T {
    if (index < 0 || index >= this.itemCount) {
      throw new Error("Index out of bounds.");
    }

    let current = this.head;
    let currentIndex = 0;

    while (current !== null && currentIndex < index) {
      current = current.next;
      currentIndex++;
    }

    if (current === null) {
      throw new Error(
        "Unexpected error: could not find node at the given index.",
      );
    }

    const oldData = current.data;
    current.data = element;

    return oldData;
  }

  indexOf(element: T): number {
    let current = this.head;
    let currentIndex = 0;

    while (current !== null) {
      if (current.data === element) {
        return currentIndex;
      }

      current = current.next;
      currentIndex++;
    }

    return -1;
  }

  sizeOf(): number {
    return this.itemCount;
  }

  isEmpty(): boolean {
    return this.head === null;
  }

  clear(): void {
    this.head = null;
    this.itemCount = 0;
  }

  printAll(): void {
    let current = this.head;
    const elements: T[] = [];

    while (current !== null) {
      elements.push(current.data);
      current = current.next;
    }

    console.log(elements.join(" -> "));
  }
}
