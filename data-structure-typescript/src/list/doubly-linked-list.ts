import type { List } from "./common/list.interface";
import { Node } from "./common/node";

export class DoublyLinkedList<T> implements List<T> {
  private head: Node<T> | null = null;
  private tail: Node<T> | null = null;
  private itemCount: number = 0;

  add(element: T): void;
  add(index: number, element: T): void;
  add(...args: [T] | [number, T]): void {
    if (args.length === 1) {
      const [element] = args;
      const newNode = new Node(element);

      if (this.head === null) {
        this.head = newNode;
        this.tail = newNode;
      } else {
        if (!this.tail) {
          throw new Error(
            "Inconsistent state: head is not null, but tail is null.",
          );
        }

        this.tail.next = newNode;
        newNode.prev = this.tail;
        this.tail = newNode;
      }

      this.itemCount++;
    } else if (args.length === 2) {
      const [index, element] = args;

      if (index < 0 || index > this.itemCount) {
        throw new Error("Index out of bounds.");
      }

      const newNode = new Node(element);

      if (index === 0) {
        if (this.head === null) {
          this.head = newNode;
          this.tail = newNode;
        } else {
          newNode.next = this.head;
          this.head.prev = newNode;
          this.head = newNode;
        }
      } else if (index === this.itemCount) {
        if (this.tail) {
          this.tail.next = newNode;
          newNode.prev = this.tail;
          this.tail = newNode;
        }
      } else {
        let current: Node<T> | null;

        if (index < this.itemCount / 2) {
          current = this.head;

          for (let i = 0; i < index; i++) {
            current = current ? current.next : null;
          }
        } else {
          current = this.tail;

          for (let i = this.itemCount - 1; i > index; i--) {
            current = current ? current.prev : null;
          }
        }

        if (current?.prev) {
          const prevNode = current.prev;
          prevNode.next = newNode;
          newNode.prev = prevNode;
          newNode.next = current;
          current.prev = newNode;
        }
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

    if (this.head === null) {
      throw new Error("Cannot remove from an empty list.");
    }

    let removedNode: Node<T>;

    if (index === 0) {
      removedNode = this.head;

      this.head = this.head.next;

      if (this.head) {
        this.head.prev = null;
      } else {
        this.tail = null;
      }
    } else if (index === this.itemCount - 1) {
      if (this.tail === null) {
        throw new Error("Unexpected error: tail is null.");
      }

      removedNode = this.tail;

      this.tail = this.tail.prev;
      if (this.tail) {
        this.tail.next = null;
      }
    } else {
      let current: Node<T> | null;

      if (index < this.itemCount / 2) {
        current = this.head;

        for (let i = 0; i < index; i++) {
          current = current ? current.next : null;
        }
      } else {
        current = this.tail;

        for (let i = this.itemCount - 1; i > index; i--) {
          current = current ? current.prev : null;
        }
      }

      if (current && current.prev && current.next) {
        removedNode = current;

        const prevNode = current.prev;
        const nextNode = current.next;

        prevNode.next = nextNode;
        nextNode.prev = prevNode;
      } else {
        throw new Error("Unexpected error: could not find the node to remove.");
      }
    }

    this.itemCount--;
    return removedNode.data;
  }

  get(index: number): T {
    if (index < 0 || index >= this.itemCount) {
      throw new Error("Index out of bounds.");
    }

    let current: Node<T> | null;

    if (index < this.itemCount / 2) {
      current = this.head;

      for (let i = 0; i < index; i++) {
        current = current ? current.next : null;
      }
    } else {
      current = this.tail;

      for (let i = this.itemCount - 1; i > index; i--) {
        current = current ? current.prev : null;
      }
    }

    if (!current) {
      throw new Error("Unexpected error: Node not found at valid index.");
    }

    return current.data;
  }

  set(index: number, element: T): T {
    if (index < 0 || index >= this.itemCount) {
      throw new Error("Index out of bounds.");
    }

    let current: Node<T> | null;

    if (index < this.itemCount / 2) {
      current = this.head;

      for (let i = 0; i < index; i++) {
        current = current ? current.next : null;
      }
    } else {
      current = this.tail;

      for (let i = this.itemCount - 1; i > index; i--) {
        current = current ? current.prev : null;
      }
    }

    if (!current) {
      throw new Error("Unexpected error: Node not found at valid index.");
    }

    const oldData = current.data;
    current.data = element;

    return oldData;
  }

  indexOf(element: T): number {
    let current = this.head;
    let index = 0;

    while (current !== null) {
      if (current.data === element) {
        return index;
      }
      current = current.next;
      index++;
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
    this.tail = null;
    this.itemCount = 0;
  }

  printAll(): void {
    const elements: T[] = [];

    for (let current = this.head; current !== null; current = current.next) {
      elements.push(current.data);
    }

    if (elements.length === 0) {
      console.log("(empty list)");
    } else {
      console.log(elements.join(" -> "));
    }
  }
}
