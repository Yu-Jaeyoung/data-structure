export interface StackInterface<E> {
  push(newItem: E): void;

  pop(): E;

  peek(): E;

  isEmpty(): boolean;

  isFull(): boolean;

  clear(): void;

  size(): number;
}
