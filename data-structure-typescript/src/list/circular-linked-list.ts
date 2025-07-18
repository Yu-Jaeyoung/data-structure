import { Node } from "@/list/common/node";
import type { List } from "./common/list.interface";

export class CircularLinkedList<T> implements List<T> {
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
        newNode.next = newNode;
        newNode.prev = newNode;
      } else {
        const tail = this.head.prev;

        if (tail) {
          tail.next = newNode;
          newNode.prev = tail;
          newNode.next = this.head;
          this.head.prev = newNode;
        }
      }

      this.itemCount++;
    } else if (args.length === 2) {
      const [index, element] = args;

      if (index < 0 || index >= this.itemCount) {
        throw new Error("Index out of bounds.");
      }

      if (this.head === null) {
        const newNode = new Node(element);
        newNode.next = newNode;
        newNode.prev = newNode;
        this.head = newNode;
        this.itemCount++;
        return;
      }

      const newNode = new Node(element);

      const tail = this.head.prev;

      if (index === 0) {
        if (tail) {
          tail.next = newNode;
          newNode.prev = tail;
          newNode.next = this.head;
          this.head.prev = newNode;
          this.head = newNode;
        }
      } else if (index === this.itemCount) {
        this.add(element);

        return;
      } else {
        let current: Node<T> | null;

        if (index < this.itemCount / 2) {
          current = this.head;

          for (let i = 0; i < index; i++) {
            current = current ? current.next : null;
          }
        } else {
          current = this.head.prev;

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

    if (this.itemCount === 1) {
      removedNode = this.head;
      this.head = null;
    } else {
      const head = this.head;
      const tail = head.prev;

      if (index === 0) {
        const newHead = head.next;

        if (tail && newHead) {
          tail.next = newHead;
          newHead.prev = tail;

          this.head = newHead;
        } else {
          throw new Error("Inconsistent list state: head links are broken.");
        }

        removedNode = head;
      } else {
        let current: Node<T> | null = head;

        for (let i = 0; i < index; i++) {
          current = current ? current.next : null;
        }

        if (current === null) {
          throw new Error("Index out of bounds.");
        }

        const prevNode = current.prev;
        const nextNode = current.next;

        if (prevNode && nextNode) {
          prevNode.next = nextNode;
          nextNode.prev = prevNode;
        } else {
          throw new Error(
            "Unexpected error: Node to remove or its links are null",
          );
        }

        removedNode = current;
      }
    }

    this.itemCount--;

    return removedNode.data;
  }

  get(index: number): T {
    if (index < 0 || index >= this.itemCount) {
      throw new Error("Index out of bounds.");
    }
    if (this.head === null) {
      throw new Error("Cannot get from an empty list.");
    }

    let current: Node<T> | null = this.head;

    if (index < this.itemCount / 2) {
      for (let i = 0; i < index; i++) {
        if (current) {
          current = current.next;
        } else {
          break;
        }
      }
    } else {
      current = this.head.prev;
      for (let i = this.itemCount - 1; i > index; i--) {
        if (current) {
          current = current.prev;
        } else {
          break;
        }
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
    if (this.head === null) {
      throw new Error("Cannot get from an empty list.");
    }

    let current: Node<T> | null = this.head;

    if (index < this.itemCount / 2) {
      for (let i = 0; i < index; i++) {
        if (current) {
          current = current.next;
        } else {
          break;
        }
      }
    } else {
      current = this.head.prev;
      for (let i = this.itemCount - 1; i > index; i--) {
        if (current) {
          current = current.prev;
        } else {
          break;
        }
      }
    }

    if (!current) {
      throw new Error("Unexpected error: Node not found at valid index.");
    }

    const removedData = current.data;
    current.data = element;

    return removedData;
  }

  indexOf(element: T): number {
    let current = this.head;

    if (this.head === null) {
      return -1;
    }

    for (let i = 0; i < this.itemCount; i++) {
      if (current === null) {
        throw new Error("Unexpected error: Node not found at valid index.");
      }

      if (current.data === element) {
        return i;
      }

      current = current.next;
    }

    return -1;
  }

  sizeOf(): number {
    return this.itemCount;
  }

  isEmpty(): boolean {
    return this.itemCount === 0;
  }

  clear(): void {
    this.itemCount = 0;
    this.head = null;
  }

  printAll(): void {
    throw new Error("Method not implemented.");
  }
}
